package z.a;

import java.util.ArrayList;
import java.util.UUID;

import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;

public class TCore extends Thread
{
	public TWrapper w;

	public boolean mAlive;
	public int mcProcessedDevice;

	public TCore(TWrapper w)
	{
		this.w = w;
    	w.serviceName = "Proximity service";
		w.boSeed = new BO_Seed(w);
		w.aTServer = new ArrayList<TServer>();
    	w.aBODrop = new ArrayList<BO_Drop>();
    	w.aBOSeed = new ArrayList<BO_Drop>();
		w.aTPeer = new ArrayList<TPeer>();
    	w.aDiscoveredDevice = new ArrayList<BluetoothDevice>();
    	w.aUUID = new UUID[] {
      	    	 new UUID(2010L,2000L),
      	    	 new UUID(2011L,2000L),
      	    	 new UUID(2012L,2000L),
      	};
		mcProcessedDevice = 0;
		mAlive = true;
	}

	public void run()
	{
		int i;

		w.tConfig.init();
		w.tBluetooth.init();
		w.tBluetooth.enable(30000);
		w.tBluetooth.discoverable();

		for (i = 0 ; i < w.aUUID.length ; ++i) {
			w.aTServer.add(factoryTServer(w.aUUID[i]));
		}
		w.tClient = factoryTClient();
        System.out.println("Bluetooth is discoverable : " + w.tBluetooth.isDiscoverable());
        System.out.println("Timeout is : " + w.tBluetooth.getDiscoverableTimeout());
        System.out.println("waiting for new message");

        while (mAlive) {
        	if (!w.tBluetooth.mConfig[w.tBluetooth.INDEX_ENABLED]) {
        		cancel();
        	}
        	if (w.aDiscoveredDevice.size() > mcProcessedDevice) {
        		add(w.aDiscoveredDevice.get(mcProcessedDevice));
        		mcProcessedDevice++;
        	}
        	try {
        		Thread.sleep(300);
        	}
    		catch (Exception e) {
    			e.printStackTrace();
    		}
        }
	}

	public void add(BluetoothDevice device)
	{
		int i;
		BluetoothSocket clientSocket = null;

		for ( i = 0 ; i < w.aUUID.length && clientSocket == null ; ++i ) {
			clientSocket = w.tBluetooth.connect(device, w.aUUID[i]);
		}
		if (clientSocket != null) {
			w.aTPeer.add(factoryTPeer(clientSocket));
		}
	}

    public TPeer factoryTPeer(BluetoothSocket tPeerSocket)
    {
    	TPeerListener tPeerListener = new TPeerListener(w, tPeerSocket);
		TPeer tPeer = new TPeer(w, tPeerListener);
		tPeer.start();
		tPeerListener.start();
		return tPeer;
    }

	public TServer factoryTServer(UUID uuid)
	{
		// Create a server
		TServer tServer = new TServer(w,uuid);
		tServer.start();
		return tServer;
	}

	public TClient factoryTClient()
	{
		// Create a server
		TClient TClient = new TClient(w);
		TClient.start();
		return TClient;
	}

    public void cancel()
    {
    	for (TPeer tPeer : w.aTPeer) {
    		tPeer.cancel();
    	}
    	for (TServer tServer : w.aTServer) {
    		tServer.cancel();
    	}
    	w.tClient.cancel();
    	mAlive = false;
    }
}

/*

public class THandle extends Thread
{
	public Looper mLooper;

	public TWrapper w;

	public THandle(TWrapper w)
	{
		this.w = w;
	}

	public void run()
	{
        Looper.prepare();
        mLooper = Looper.myLooper();
        w.tHandler = new THandler(w);
        Looper.loop();
        System.out.println("Handler stopped");
	}
}

        	if (w.tHandler.mMessage != msg) {
        		msg = w.tHandler.mMessage;
                System.out.println(msg);
        	}
*/