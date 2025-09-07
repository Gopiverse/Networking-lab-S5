import java.lang.System;
import java.net.*;
/*import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException; 
*/
import java.io.*;
import java.text.*;
//import java.util.Random;
import java.util.*;

public class GoClient {
	static Socket connection;
	public static void main(String args[]) throws SocketException {
		try {
			int v[] = new int[10];
			int n=0;
			Random rands = new Random();
			int rand = 0;
			InetAddress addr = InetAddress.getByName("LocalHost");
			System.out.println(addr);
			connection = new Socket(addr, 8011);
			DataOutputStream out = new DataOutputStream(connection.getOutputStream());
			DataInputStream in = new DataInputStream(connection.getInputStream());
			int p = in.read(); //length
			System.out.println("No: of frames:"+p);
			for(int i=0; i<p; i++) {
				v[i] = in.read();
				System.out.println(v[i]);
			}
			rand = rands.nextInt(p);
			v[rand] = -1;
			for(int i=0; i<p; i++) {
				if(v[i] == -1) {
					System.out.println("Request to retransmit from packet no:"+(i+1)+" again");
					n = i;
					out.write(n);
					out.flush();
				}
			}
			System.out.println();
			for(int j=n; j<p; j++) {
				v[j] = in.read();
				System.out.println("Received frame is"+v[j]);
			}
			System.out.println("Quitting...");
		} catch(IOException e) {
			System.out.println(e);
		}
	}
}
