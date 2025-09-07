import java.io.*;
import java.net.*;

public class chatClient {
	//private ServerSocket serverSocket = null;
	private Socket socket = null;
	private InputStream instream = null;
	private OutputStream outstream = null;
	
	public chatClient() {} //constructor
	
	//methods
	public void createSocket() {
		try {
			socket = new Socket("localHost", 3339);
			System.out.println("Connected");
			instream = socket.getInputStream();
			outstream = socket.getOutputStream();
			createReadThread();
			createWriteThread();
		} catch(UnknownHostException e) {
			e.printStackTrace();
		}  catch(IOException i) {
			i.printStackTrace();
		}
	}
	
	public void createReadThread() {
		Thread readThread = new Thread() {
			public void run() {
				while(socket.isConnected()) {
					try {
						byte[] readBuffer = new byte[200];
						int num = instream.read(readBuffer);
						if(num > 0) {
							byte[] arrayBytes = new byte[num];
							System.arraycopy(readBuffer, 0, arrayBytes, 0, num);
							String receivedMessage = new String(arrayBytes, "UTF-8");
							System.out.println("Received message "+receivedMessage);
						} else {
							notify();
						}
					} catch(SocketException se) {
						System.exit(0);
					} catch(IOException i) {
						i.printStackTrace();
					}
				}	
			}
		};
		readThread.setPriority(Thread.MAX_PRIORITY);
		readThread.start();
	}
	
	public void createWriteThread() {
		Thread writeThread = new Thread() {
			public void run() {
				while(socket.isConnected()) {
					try {
						BufferedReader inputReader = new BufferedReader(new InputStreamReader(System.in));
						sleep(100);
						String typedMessage = inputReader.readLine();
						if(typedMessage != null && typedMessage.length()>0) {
							synchronized(socket) {
								outstream.write(typedMessage.getBytes("UTF-8"));
								sleep(100);
							}
						}
					} catch(IOException i) {
						i.printStackTrace();
					} catch(InterruptedException ie) {
						ie.printStackTrace();
					} 
				}
			}
		};
		writeThread.setPriority(Thread.MAX_PRIORITY);
		writeThread.start();
	}
	
	public static void main(String args[]) {
		chatClient chat = new chatClient();
		chat.createSocket();
	}
}



















