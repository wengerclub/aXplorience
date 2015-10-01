#include "native/NCommon.h"

namespace NSDEVICE
{

BluetoothAdapter::LeScanCallback::LeScanCallback()
{
    NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNDzeta02, (NParam)this);
}

BluetoothAdapter::LeScanCallback::~LeScanCallback()
{
    NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
}

BluetoothAdapter* BluetoothAdapter::getDefaultAdapter()
{
    BluetoothAdapter* b = NWrapper::w->mNNoObject->pointer<BluetoothAdapter>();
    return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNAlpha00, (NParam)b));
}

bool BluetoothAdapter::checkBluetoothAddress(const String& address)
{
    return (bool)NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNRho00, NParamBox(NWrapper::w, address).n);
}

BluetoothAdapter::~BluetoothAdapter()
{
}

BluetoothLeAdvertiser* BluetoothAdapter::getBluetoothLeAdvertiser()
{
    BluetoothLeAdvertiser* b = NWrapper::w->mNNoObject->pointer<BluetoothLeAdvertiser>();
    return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNPsi00, (NParam)this, (NParam)b));
}

BluetoothLeScanner* BluetoothAdapter::getBluetoothLeScanner()
{
    BluetoothLeScanner* b = NWrapper::w->mNNoObject->pointer<BluetoothLeScanner>();
    return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNOmega00, (NParam)this, (NParam)b));
}

BluetoothDevice* BluetoothAdapter::getRemoteDevice(const String& address)
{
    BluetoothDevice* b = NWrapper::w->mNNoObject->pointer<BluetoothDevice>();
    return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNBeta00, (NParam)this, (NParam)b, NParamBox(NWrapper::w, address).n));
}

bool BluetoothAdapter::isEnabled()
{
    return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNGamma00, (NParam)this);
}

bool BluetoothAdapter::isMultipleAdvertisementSupported()
{
    return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNRho01, (NParam)this);
}

int BluetoothAdapter::getState()
{
    return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNDelta00, (NParam)this);
}

bool BluetoothAdapter::enable()
{
    return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNEpsilon00, (NParam)this);
}

bool BluetoothAdapter::disable()
{
    return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNDzeta00, (NParam)this);
}

String BluetoothAdapter::getAddress()
{
    NReturn index = NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNEta00, (NParam)this);
    return NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)index));
}

String BluetoothAdapter::getName()
{
    NReturn index = NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNTheta00, (NParam)this);
    return NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)index));
}

bool BluetoothAdapter::setName(const String& name)
{
    return (bool)NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNIota00, (NParam)this, NParamBox(NWrapper::w, name).n);
}

int BluetoothAdapter::getScanMode()
{
    return (nint)NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNKappa00, (NParam)this);
}

bool BluetoothAdapter::startDiscovery()
{
    return (bool)NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNLambda00, (NParam)this);
}

bool BluetoothAdapter::startLeScan(BluetoothAdapter::LeScanCallback* callback)
{
    return (bool)NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNKhi00, (NParam)this, (NParam)callback);
}

bool BluetoothAdapter::startLeScan(NArray<String> serviceUuids, BluetoothAdapter::LeScanCallback* callback)
{
    nuint vcIndex;
    nlong vcKey = NWrapper::w->nFrame->tRun(NWrapper::w->mNBeta01, 0, serviceUuids.mSize);
    NParamObject* vaTString = new NParamObject[serviceUuids.mSize]();

    for (vcIndex = 0 ; vcIndex < serviceUuids.mSize ; ++vcIndex) {
        vaTString[vcIndex] = NWrapper::w->nFrame->tRunString(serviceUuids.maData[vcIndex]);
        NWrapper::w->nFrame->tRun(NWrapper::w->mNBeta01, vcKey, vcIndex, (NParam)&vaTString[vcIndex]);
    };
    vcKey = (nuint)NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNUpsilon00, (NParam)this, (NParam)vcKey, (NParam)callback);

    for (vcIndex = 0 ; vcIndex < serviceUuids.mSize ; ++vcIndex) {
        NWrapper::w->nFrame->tDeleteGlobalRef(vaTString[vcIndex]);
    };
    return (bool)vcKey;
}

void BluetoothAdapter::stopLeScan(BluetoothAdapter::LeScanCallback* callback)
{
    NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNPhi00, (NParam)this, (NParam)callback);
}

bool BluetoothAdapter::cancelDiscovery()
{
    return (bool)NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNMu00, (NParam)this);
}

bool BluetoothAdapter::isDiscovering()
{
    return (bool)NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNNu00, (NParam)this);
}

void* BluetoothAdapter::getBondedDevices()
{
    //TODO: implement
    //Set<BluetoothDevice>
    //return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNxi00, (NParam)this);
    return NULL;
}

BluetoothServerSocket* BluetoothAdapter::listenUsingInsecureRfcommOn(int channel)
{
    BluetoothServerSocket* b = NWrapper::w->mNNoObject->pointer<BluetoothServerSocket>();
    return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNTau00, (NParam)this, (NParam)b, (NParam)channel));
}

BluetoothServerSocket* BluetoothAdapter::listenUsingInsecureRfcommWithServiceRecord(const String& name, const String& uuid)
{
    BluetoothServerSocket* b = NWrapper::w->mNNoObject->pointer<BluetoothServerSocket>();
    return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNPi00, (NParam)this, (NParam)b, NParamBox(NWrapper::w, name).n, NParamBox(NWrapper::w, uuid).n));
}

BluetoothServerSocket* BluetoothAdapter::listenUsingRfcommWithServiceRecord(const String& name, const String& uuid)
{
    BluetoothServerSocket* b = NWrapper::w->mNNoObject->pointer<BluetoothServerSocket>();
    return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNOmicron00, (NParam)this, (NParam)b, NParamBox(NWrapper::w, name).n, NParamBox(NWrapper::w, uuid).n));
}

void BluetoothAdapter::discoverable()
{
    discoverable(0);
}

void BluetoothAdapter::discoverable(int cTimeout)
{
    NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNSigma00, cTimeout);
}

} // End namespace
