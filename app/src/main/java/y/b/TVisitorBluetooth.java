package y.b;

import java.io.InputStream;
import java.io.OutputStream;
import java.util.UUID;
import java.lang.reflect.Method;
import java.lang.reflect.Field;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothServerSocket;
import android.bluetooth.BluetoothSocket;
import android.bluetooth.BluetoothGatt;
import android.bluetooth.BluetoothGattCallback;
import android.bluetooth.BluetoothGattServerCallback;
import android.bluetooth.BluetoothManager;
import android.content.Context;
import android.content.Intent;

public class TVisitorBluetooth extends TKrossVisitor
{
    public TVisitorBluetooth(TWrapper w) {
        super(w);
    }

    //*******************************************************************************
    //********************** BluetoothAdapter::LeScanCallback ***********************
    //*******************************************************************************

    //BluetoothAdapter::LeScanCallback::LeScanCallback()
    public long visit(TDzeta02 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(a, new TLeScanCallback(w, a));
    }

    //*******************************************************************************
    //**************************** BluetoothAdapter *********************************
    //*******************************************************************************

    //static bool checkBluetoothAddress(String address)
    public long visit(TRho00 element, long a, long b, long c, long d, long e)
    {
        return ( BluetoothAdapter.checkBluetoothAddress((String)w.mTKrossSystem.nRunObject(a)) ? 1 : 0 );
    }

    //static BluetoothAdapter* getDefaultAdapter()
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(a, BluetoothAdapter.getDefaultAdapter());
    }

    //BluetoothLeAdvertiser* getBluetoothLeAdvertiser()
    public long visit(TPsi00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((BluetoothAdapter)w.sObject.get(a)).getBluetoothLeAdvertiser());
    }

    //BluetoothLeScanner* getBluetoothLeScanner()
    public long visit(TOmega00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((BluetoothAdapter)w.sObject.get(a)).getBluetoothLeScanner());
    }

    //BluetoothDevice* getRemoteDevice(String address)
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((BluetoothAdapter)w.sObject.get(a)).getRemoteDevice((String)w.mTKrossSystem.nRunObject(c)));
    }

    //bool isEnabled()
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothAdapter)w.sObject.get(a)).isEnabled() ? 1 : 0 );
    }

    //bool isMultipleAdvertisementSupported()
    public long visit(TRho01 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothAdapter)w.sObject.get(a)).isMultipleAdvertisementSupported() ? 1 : 0 );
    }

    //int getState()
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        return ((BluetoothAdapter)w.sObject.get(a)).getState();
    }

    //bool enable()
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothAdapter)w.sObject.get(a)).enable() ? 1 : 0 );
    }

    //bool disable()
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothAdapter)w.sObject.get(a)).disable() ? 1 : 0 );
    }

    //String getAddress()
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putNext(((BluetoothAdapter)w.sObject.get(a)).getAddress());
    }

    //String getName()
    public long visit(TTheta00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putNext(((BluetoothAdapter)w.sObject.get(a)).getName());
    }

    //bool setName(String name)
    public long visit(TIota00 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothAdapter)w.sObject.get(a)).setName((String)w.mTKrossSystem.nRunObject(b)) ? 1 : 0 );
    }

    //int getScanMode()
    public long visit(TKappa00 element, long a, long b, long c, long d, long e)
    {
        return ((BluetoothAdapter)w.sObject.get(a)).getScanMode();
    }

    //bool startDiscovery()
    public long visit(TLambda00 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothAdapter)w.sObject.get(a)).startDiscovery() ? 1 : 0 );
    }

    //bool startLeScan(BluetoothAdapter::LeScanCallback* callback)
    public long visit(TKhi00 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothAdapter)w.sObject.get(a)).startLeScan(w.mTKrossSystem.getValue(b, BluetoothAdapter.LeScanCallback.class)) ? 1 : 0 );
    }

    //bool startLeScan(NArray<String>* serviceUuids, BluetoothAdapter::LeScanCallback* callback)
    public long visit(TUpsilon00 element, long a, long b, long c, long d, long e)
    {
        int vcIndex;
        int vaUUIDString[] = (int[])w.aObject.remove((int)b);
        UUID vaUUID[] = new UUID[vaUUIDString.length];

        for (vcIndex = 0 ; vcIndex < vaUUIDString.length ; ++vcIndex) {
            vaUUID[vcIndex] = UUID.fromString((String)w.mTKrossSystem.nRunObject(vaUUIDString[vcIndex]));
        };
        return ( ((BluetoothAdapter)w.sObject.get(a)).startLeScan(vaUUID, w.mTKrossSystem.getValue(c, BluetoothAdapter.LeScanCallback.class)) ? 1 : 0 );
    }

    //void stopLeScan(BluetoothAdapter::LeScanCallback* callback)
    public long visit(TPhi00 element, long a, long b, long c, long d, long e)
    {
        ((BluetoothAdapter)w.sObject.get(a)).stopLeScan(w.mTKrossSystem.getValue(b, BluetoothAdapter.LeScanCallback.class));
        return 0;
    }

    //bool cancelDiscovery()
    public long visit(TMu00 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothAdapter)w.sObject.get(a)).cancelDiscovery() ? 1 : 0 );
    }

    //bool isDiscovering()
    public long visit(TNu00 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothAdapter)w.sObject.get(a)).isDiscovering() ? 1 : 0 );
    }

    //Set<BluetoothDevice> getBondedDevices()
    public long visit(TXi00 element, long a, long b, long c, long d, long e)
    {
        //TODO: implements
        //w.sObject.put(b, ((BluetoothAdapter)w.sObject.get(a)).getBondedDevices());
        return 0;
    }

    //BluetoothServerSocket* listenUsingInsecureRfcommOn(int channel)
    public long visit(TTau00 element, long a, long b, long c, long d, long e)
    {
        BluetoothServerSocket vBluetoothServerSocket = null;
        BluetoothAdapter vBluetoothAdapter = (BluetoothAdapter)w.sObject.get(a);
        Class<?> vClass;
        Method vMethod;

        try {
            vClass = vBluetoothAdapter.getClass();
            vMethod = vClass.getDeclaredMethod("listenUsingInsecureRfcommOn", new Class[] { Integer.TYPE });
            vMethod.setAccessible(true);
            vBluetoothServerSocket = (BluetoothServerSocket)vMethod.invoke(vBluetoothAdapter, new Object[] { (Integer)((int)c) });
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            vBluetoothServerSocket = null;
        }
        return w.mTKrossSystem.emplaceKey(b, vBluetoothServerSocket);
    }

    //BluetoothServerSocket* listenUsingInsecureRfcommWithServiceRecord(String name, String uuid)
    public long visit(TPi00 element, long a, long b, long c, long d, long e)
    {
        BluetoothServerSocket vBluetoothServerSocket = null;
        try {
            vBluetoothServerSocket = ((BluetoothAdapter)w.sObject.get(a)).listenUsingInsecureRfcommWithServiceRecord((String)w.mTKrossSystem.nRunObject(c), UUID.fromString((String)w.mTKrossSystem.nRunObject(d)));
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            vBluetoothServerSocket = null;
        }
        return w.mTKrossSystem.emplaceKey(b, vBluetoothServerSocket);
    }

    //BluetoothServerSocket* listenUsingRfcommWithServiceRecord(String name, String uuid)
    public long visit(TOmicron00 element, long a, long b, long c, long d, long e)
    {
        BluetoothServerSocket vBluetoothServerSocket = null;
        try {
            vBluetoothServerSocket = ((BluetoothAdapter)w.sObject.get(a)).listenUsingRfcommWithServiceRecord((String)w.mTKrossSystem.nRunObject(c), UUID.fromString((String)w.mTKrossSystem.nRunObject(d)));
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            vBluetoothServerSocket = null;
        }
        return w.mTKrossSystem.emplaceKey(b, vBluetoothServerSocket);
    }

    //void discoverable(int nTimeout)
    public long visit(TSigma00 element, long a, long b, long c, long d, long e)
    {
        Intent intentDiscoverable = new Intent(BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE);
        intentDiscoverable.putExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, (int)a);
        w.tActivity.startActivityForResult(intentDiscoverable, 1);
        return 0;
    }

    //*******************************************************************************
    //***************************** BluetoothDevice *********************************
    //*******************************************************************************

    //BluetoothGatt* connectGatt(Context* context, bool autoConnect, BluetoothGattCallback* callback)
    public long visit(TXi01 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((BluetoothDevice)w.sObject.get(a)).connectGatt(w.mTKrossSystem.getValue(c, Context.class), d != 0, w.mTKrossSystem.getValue(e, BluetoothGattCallback.class)));
    }

    //BluetoothGatt* connectGatt(Context* context, bool autoConnect, BluetoothGattCallback* callback, int transport)
    public long visit(TOmicron01 element, long a, long b, long c, long d, long e)
    {
        BluetoothGatt vBluetoothGatt = null;
        BluetoothDevice vBluetoothDevice = (BluetoothDevice)w.sObject.get(a);
        Class<?> vClass;
        Method vMethod;

        try {
            vClass = vBluetoothDevice.getClass();
            vMethod = vClass.getDeclaredMethod("connectGatt", new Class[] { Context.class, Boolean.TYPE, BluetoothGattCallback.class, Integer.TYPE });
            vMethod.setAccessible(true);
            vBluetoothGatt = (BluetoothGatt)vMethod.invoke(vBluetoothDevice, new Object[] {
                w.mTKrossSystem.getValue(c, Context.class),
                (Boolean)((d&1) != 0),
                w.mTKrossSystem.getValue(e, BluetoothGattCallback.class),
                (Integer)((int)d>>32)
            });
        }
        catch (Exception vException) {
            vBluetoothGatt = null;
        }
        if (vBluetoothGatt == null) {
            vBluetoothGatt = vBluetoothDevice.connectGatt(w.mTKrossSystem.getValue(c, Context.class), (d&1) != 0, w.mTKrossSystem.getValue(e, BluetoothGattCallback.class));
        }
        return w.mTKrossSystem.emplaceKey(b, vBluetoothGatt);
    }

    //bool equals(BluetoothDevice* dBluetoothDevice);
    public long visit(TAlpha01 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothDevice)w.sObject.get(a)).equals(w.mTKrossSystem.getValue(b, BluetoothDevice.class)) ? 1 : 0 );
    }

    //int hashCode();
    public long visit(TBeta01 element, long a, long b, long c, long d, long e)
    {
        return ((BluetoothDevice)w.sObject.get(a)).hashCode();
    }

    //String toString();
    public long visit(TGamma01 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putNext(((BluetoothDevice)w.sObject.get(a)).toString());
    }

    //int describeContents();
    public long visit(TDelta01 element, long a, long b, long c, long d, long e)
    {
        return ((BluetoothDevice)w.sObject.get(a)).describeContents();
    }

    //void writeToParcel(void* out, int flags);
    public long visit(TEpsilon01 element, long a, long b, long c, long d, long e)
    {
        //TODO: implements
        return 0;
    }

    //String getAddress();
    public long visit(TDzeta01 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putNext(((BluetoothDevice)w.sObject.get(a)).getAddress());
    }

    //String getName();
    public long visit(TEta01 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putNext(((BluetoothDevice)w.sObject.get(a)).getName());
    }

    //int getBondState();
    public long visit(TTheta01 element, long a, long b, long c, long d, long e)
    {
        return ((BluetoothDevice)w.sObject.get(a)).getBondState();
    }

    //BluetoothClass* getBluetoothClass();
    public long visit(TIota01 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((BluetoothDevice)w.sObject.get(a)).getBluetoothClass());
    }

    //int getType()
    public long visit(TPi01 element, long a, long b, long c, long d, long e)
    {
        return ((BluetoothDevice)w.sObject.get(a)).getType();
    }

    //BluetoothSocket* createInsecureRfcommSocket(int port);
    public long visit(TNu01 element, long a, long b, long c, long d, long e)
    {
        BluetoothSocket vBluetoothSocket = null;
        BluetoothDevice vBluetoothDevice = (BluetoothDevice)w.sObject.get(a);
        Class<?> vClass;
        Method vMethod;

        try {
            vClass = vBluetoothDevice.getClass();
            vMethod = vClass.getDeclaredMethod("createInsecureRfcommSocket", new Class[] { Integer.TYPE });
            vMethod.setAccessible(true);
            vBluetoothSocket = (BluetoothSocket)vMethod.invoke(vBluetoothDevice, new Object[] { (Integer)((int)c) });
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            vBluetoothSocket = null;
        }
        return w.mTKrossSystem.emplaceKey(b, vBluetoothSocket);
    }

    //BluetoothSocket* createInsecureRfcommSocketToServiceRecord(const String& uuid);
    public long visit(TLambda01 element, long a, long b, long c, long d, long e)
    {
        BluetoothSocket vBluetoothSocket = null;
        try {
            vBluetoothSocket = ((BluetoothDevice)w.sObject.get(a)).createInsecureRfcommSocketToServiceRecord(UUID.fromString((String)w.mTKrossSystem.nRunObject(c)));
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            vBluetoothSocket = null;
        }
        return w.mTKrossSystem.emplaceKey(b, vBluetoothSocket);
    }

    //BluetoothSocket* createRfcommSocketToServiceRecord(const String& uuid);
    public long visit(TKappa01 element, long a, long b, long c, long d, long e)
    {
        BluetoothSocket vBluetoothSocket = null;
        try {
            vBluetoothSocket = ((BluetoothDevice)w.sObject.get(a)).createRfcommSocketToServiceRecord(UUID.fromString((String)w.mTKrossSystem.nRunObject(c)));
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            vBluetoothSocket = null;
        }
        return w.mTKrossSystem.emplaceKey(b, vBluetoothSocket);
    }

    // vector<ParcelUuid*> getUuids();
    public long visit(TMu01 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putNext(((BluetoothDevice)w.sObject.get(a)).getUuids());
    }

    //*******************************************************************************
    //********************************** BluetoothManager ***************************
    //*******************************************************************************
    //BluetoothGattServer* openGattServer(Context* context, BluetoothGattServerCallback* callback)
    public long visit(TEpsilon02 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((BluetoothManager)w.sObject.get(a)).openGattServer(w.mTKrossSystem.getValue(c, Context.class), w.mTKrossSystem.getValue(d, BluetoothGattServerCallback.class)));
    }

    //*******************************************************************************
    //************************* BluetoothServerSocket *******************************
    //*******************************************************************************

    //BluetoothSocket* accept();
    public long visit(TAlpha02 element, long a, long b, long c, long d, long e)
    {
        BluetoothSocket vBluetoothSocket = null;
        try {
            vBluetoothSocket = ((BluetoothServerSocket)w.sObject.get(a)).accept();
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            vBluetoothSocket = null;
        }
        return w.mTKrossSystem.emplaceKey(b, vBluetoothSocket);
    }

    //BluetoothSocket* accept(int timeout);
    public long visit(TBeta02 element, long a, long b, long c, long d, long e)
    {
        BluetoothSocket vBluetoothSocket = null;
        try {
            vBluetoothSocket = ((BluetoothServerSocket)w.sObject.get(a)).accept((int)c);
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            vBluetoothSocket = null;
        }
        return w.mTKrossSystem.emplaceKey(b, vBluetoothSocket);
    }

    //void close();
    public long visit(TGamma02 element, long a, long b, long c, long d, long e)
    {
        long err = 0;
        try {
            ((BluetoothServerSocket)w.sObject.get(a)).close();
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            err = 1;
        }
        return err;
    }

    //int getChannel()
    public long visit(TDelta02 element, long a, long b, long c, long d, long e)
    {
        int vcChannel = -1;
        BluetoothServerSocket vBluetoothServerSocket = (BluetoothServerSocket)w.sObject.get(a);
        Class<?> vClass;
        Field vField;

        try {
            vClass = vBluetoothServerSocket.getClass();
            vField = vClass.getDeclaredField("mChannel");
            vField.setAccessible(true);
            vcChannel = vField.getInt(vBluetoothServerSocket);
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            vcChannel = -1;
        }
        return vcChannel;
    }

    //*******************************************************************************
    //***************************** BluetoothSocket *********************************
    //*******************************************************************************

    //void connect()
    public long visit(TAlpha03 element, long a, long b, long c, long d, long e)
    {
        long err = 0;
        try {
            ((BluetoothSocket)w.sObject.get(a)).connect();
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            err = 1;
        }
        return err;
    }

    //void close()
    public long visit(TBeta03 element, long a, long b, long c, long d, long e)
    {
        long err = 0;
        try {
            ((BluetoothSocket)w.sObject.get(a)).close();
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            err = 1;
        }
        return err;
    }

    //BluetoothDevice* getRemoteDevice()
    public long visit(TGamma03 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((BluetoothSocket)w.sObject.get(a)).getRemoteDevice());
    }

    //InputStream* getInputStream()
    public long visit(TDelta03 element, long a, long b, long c, long d, long e)
    {
        InputStream vInputStream = null;
        try {
            vInputStream = ((BluetoothSocket)w.sObject.get(a)).getInputStream();
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            vInputStream = null;
        }
        return w.mTKrossSystem.emplaceKey(b, vInputStream);
    }

    //OutputStream* getOutputStream()
    public long visit(TEpsilon03 element, long a, long b, long c, long d, long e)
    {
        OutputStream vOutputStream = null;
        try {
            vOutputStream = ((BluetoothSocket)w.sObject.get(a)).getOutputStream();
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            vOutputStream = null;
        }
        return w.mTKrossSystem.emplaceKey(b, vOutputStream);
    }

    //int getPort()
    public long visit(TDzeta03 element, long a, long b, long c, long d, long e)
    {
        int vcPort = -1;
        BluetoothSocket vBluetoothSocket = (BluetoothSocket)w.sObject.get(a);
        Class<?> vClass;
        Field vField;

        try {
            vClass = vBluetoothSocket.getClass();
            vField = vClass.getDeclaredField("mPort");
            vField.setAccessible(true);
            vcPort = vField.getInt(vBluetoothSocket);
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            vcPort = -1;
        }
        return vcPort;
    }
}
