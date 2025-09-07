import java.io.*;
import java.net.*;
import java.util.*;

public class UDPEchoClient {
	public static void main(String args[]) throws IOException {
		DatagramSocket ds = new DatagramSocket(1234);
		byte[] receive = new byte[65535];
		DatagramPacket DpReceive = null;
		while(true) {
			DpReceive = new DatagramPacket(receive, receive.length);
			ds.receive(DpReceive);
			System.out.println("From server "+data(receive));
			if(data(receive).toString().equals("bye")) {
				System.out.println("Exiting");
				break;
			}
			receive = new byte[65535];
		}
	}
	
	public static StringBuilder data(byte[] a) {
		if(a == null) return null;
		StringBuilder ret = new StringBuilder();
		int i=0;
		while(a[i] != 0) {
			ret.append((char)a[i]);
			i++;
		}
		return ret;
	}
}
