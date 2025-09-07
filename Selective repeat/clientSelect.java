import java.lang.System;
import java.io.*;
import java.net.*;
import java.text.*;
//import java.util.Random;
import java.util.*;

public class clientSelect {
	static Socket connection;
	public static void main(String args[]) throws SocketException {
		try {
			int v[] = new int[10];
			int n = 0;
			Random rands = new Random();
			int rand = 0;
			InetAddress addr = InetAddress.getByName("LocalHost");
			System.out.println(addr);
			connection = new Socket(addr, 8011);
			DataOutputStream out = new DataOutputStream(connection.getOutputStream());
			DataInputStream in = new DataInputStream(connection.getInputStream());
			int p = in.read();
			System.out.println("No: of frames "+p);
			for(int i=0; i<p; i++) {
				v[i] = in.read();
				System.out.println(v[i]);
			}
			rand = rands.nextInt(p);
			v[rand] = -1;
			for(int i=0; i<p; i++) {
				if(v[i] == -1) {
					System.out.println("Request to retransmit packet no:"+(i+1)+" again");
					n = i;
					out.write(n);
					out.flush();
				}
			}
			System.out.println();
			v[n] = in.read();
			System.out.println("Received frame is "+v[n]);
			System.out.println("Quitting...");
		} catch(IOException e) {
			System.out.println(e);
		}
	}
}


/*
Server output
Waiting for connection
No: of packets send:8

Client output
LocalHost/127.0.0.1
No: of frames 8
10
20
30
40
50
60
70
80
Request to retransmit packet no:5 again
Received frame is 50
Quitting...
*/


