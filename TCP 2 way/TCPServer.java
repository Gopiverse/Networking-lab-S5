import java.io.*;
import java.util.*;
import java.net.*;

public class TCPEchoServer {
	private static ServerSocket serverSocket;
	private static final int PORT = 1234;
	public static void main(String args[]) {
		System.out.println("Opening port");
		try {
			serverSocket = new ServerSocket(PORT);
		} catch(IOException ioEx) {
			System.out.println("Unable to attach port");
			System.exit(1);
		}
		
		do {
			handleClient();
		} while(true);
	}
	
	private static void handleClient() {
		Socket link =null;
		try {
			link = serverSocket.accept();
			Scanner input = new Scanner(link.getInputStream());
			PrintWriter output = new PrintWriter(link.getOutputStream(), true);
			String message = input.nextLine();
			String response;
			
			
			do {
				System.out.println("CLIENT : " + message);
				System.out.println("Enter your message");
				Scanner userEntry = new Scanner(System.in);
				response = userEntry.nextLine();
				output.println(response);
				message = input.nextLine();
			} while(!message.equalsIgnoreCase("bye"));

		} catch(IOException ioEx) {
			ioEx.printStackTrace();
		} finally {
			try {
				System.out.println("Closing connection");
				link.close();
			} catch(IOException ioEx) {
				System.out.println("Unable to disconnect");
				System.exit(1);
			}
		}
	}
}
