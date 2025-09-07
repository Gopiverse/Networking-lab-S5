import java.io.*;
import java.util.*;
import java.net.*;
public class TCPEchoClient
{
	private static InetAddress host;
	private static final  int PORT = 1234;
	public static void main(String args[])
	{
		try
		{
			host = InetAddress.getLocalHost();
		}
		catch(IOException ioEx)
		{
			System.out.println("Host ID not found");
			System.exit(1);
			}
			accessServer();
		}
		public static void accessServer()
		{
			Socket link = null;
			try
			{
				link = new Socket(host,PORT);
				Scanner input = new Scanner(link.getInputStream());
				PrintWriter output = new PrintWriter(link.getOutputStream(),true);
				Scanner userEntry = new Scanner(System.in);
				String message,response;
				do{
				System.out.println("Enter message:");
				message=userEntry.nextLine();
				output.println(message);
				response=input.nextLine();
				System.out.println("SERVER "+response);
			}
			while(!message.equals("CLOSE"));
			}
			
		
		catch(IOException ioEx){
		ioEx.printStackTrace();
		}
		
		finally{
		try{
		System.out.println("Closing connection");
		link.close();
		}
		catch(IOException ioEx)
		{
			System.out.println("Unable to disconnect");
			System.exit(1);
		}
		}
		}
		}
		
/*Server output				Client output
Opening port				Enter message:
Message recieved			Hi
Message recieved			SERVER Message 1.Hi
Closing connection			Enter message:
							How r u
							SERVER Message 2.How r u
							Enter message:
							CLOSE
							SERVER 2messages recieved
							Closing connection

*/
