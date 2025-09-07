import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;

public class serve {
	static ServerSocket serverSocket;
	static DataInputStream dis;
	static DataOutputStream dos;
	public static void main(String args[]) throws SocketException {
		try {
			int a[] = {30, 40, 50, 60, 70, 80, 90, 100};
			serverSocket = new ServerSocket(8011);
			System.out.println("Waiting for connection");
			Socket link = serverSocket.accept();
			dis = new DataInputStream(link.getInputStream());
			dos = new DataOutputStream(link.getOutputStream());
			System.out.println("No: of packets send:"+a.length);
			int y = a.length;
			dos.write(y);
			dos.flush();
			for(int i=0; i<y; i++) {
				dos.write(a[i]);
				dos.flush();
			}
			int k = dis.read();
			for(int i=k; i<y; i++) {
				dos.write(a[i]);
				dos.flush();
			}
		} catch(IOException e) {
			System.out.println(e);
		} finally {
			try {
				dis.close();
				dos.close();
			} catch(IOException e) {
				e.printStackTrace();
			}
		}
	}

}
