#ifndef __BluetoothGattCharacteristic_H__
#define __BluetoothGattCharacteristic_H__

namespace NSDEVICE
{

class BluetoothGattCharacteristic : public Object
{
friend NSNATIVE::NNoObject;

public:
    static const int PERMISSION_READ = 0x00000001;
    static const int PERMISSION_READ_ENCRYPTED = 0x00000002;
    static const int PERMISSION_READ_ENCRYPTED_MITM = 0x00000004;
    static const int PERMISSION_WRITE = 0x00000010;
    static const int PERMISSION_WRITE_ENCRYPTED = 0x00000020;
    static const int PERMISSION_WRITE_ENCRYPTED_MITM = 0x00000040;
    static const int PERMISSION_WRITE_SIGNED = 0x00000080;
    static const int PERMISSION_WRITE_SIGNED_MITM = 0x00000100;
    static const int PROPERTY_BROADCAST = 0x00000001;
    static const int PROPERTY_EXTENDED_PROPS = 0x00000080;
    static const int PROPERTY_INDICATE = 0x00000020;
    static const int PROPERTY_NOTIFY = 0x00000010;
    static const int PROPERTY_READ = 0x00000002;
    static const int PROPERTY_SIGNED_WRITE = 0x00000008;
    static const int PROPERTY_WRITE = 0x00000004;
    static const int PROPERTY_WRITE_NO_RESPONSE = 0x00000004;
    static const int WRITE_TYPE_DEFAULT = 0x00000002;
    static const int WRITE_TYPE_NO_RESPONSE = 0x00000001;
    static const int WRITE_TYPE_SIGNED = 0x00000004;

    BluetoothGattCharacteristic(const String& uuid, int properties, int permissions)
    {
        NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNDelta00, (NParam)this, NParamBox(NWrapper::w, uuid).n, (NParam)properties, (NParam)permissions);
    }

    virtual ~BluetoothGattCharacteristic()
    {
    }

    virtual bool addDescriptor(BluetoothGattDescriptor* descriptor)
    {
        return NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNUpsilon01, (NParam)this, (NParam)descriptor);
    }

    virtual BluetoothGattDescriptor* getDescriptor(const String& uuid)
    {
        BluetoothGattDescriptor* b = NWrapper::w->mNNoObject->pointer<BluetoothGattDescriptor>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNGamma01, (NParam)this, (NParam)b, NParamBox(NWrapper::w, uuid).n));
    }

    virtual NArray<BluetoothGattDescriptor*> getDescriptors()
    {
        NReturn index = NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNBeta01, (NParam)this);
        NReturn size = NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, -1, -1);
        NArray<BluetoothGattDescriptor*> vNArray = NArray<BluetoothGattDescriptor*>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            BluetoothGattDescriptor* b = NWrapper::w->mNNoObject->pointer<BluetoothGattDescriptor>();
            vNArray.maData[i] = NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, (NParam)i, (NParam)b));
        }
        return vNArray;
    }

    virtual int getProperties()
    {
        return NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNEpsilon01, (NParam)this);
    }

    virtual String getUuid()
    {
        NReturn index = NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNDzeta01, (NParam)this);
        return NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)index));
    }

    virtual NArray<nubyte> getValue()
    {
        NReturn index = NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNEpsilon00, (NParam)this);
        NReturn size = NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, -1, -1);
        NArray<nubyte> vNArray =  NArray<nubyte>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            vNArray.maData[i] = (nubyte)NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, (NParam)i, -1);
        }
        return vNArray;
    }

    virtual String getStringValue(int offset)
    {
        NReturn index = NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNDzeta00, (NParam)this, (NParam)offset);
        return NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)index));
    }

    virtual bool setValue(NArray<nubyte> value)
    {
        nuint vcIndex;
        nlong vcKey = NWrapper::w->nFrame->tRun(NWrapper::w->mNBeta01, 0, value.mSize);

        for (vcIndex = 0 ; vcIndex < value.mSize ; ++vcIndex) {
            NWrapper::w->nFrame->tRun(NWrapper::w->mNBeta01, vcKey, vcIndex, value.maData[vcIndex]);
        };
        return NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNEta00, (NParam)this, (NParam)vcKey);
    }

    virtual bool setValue(const String& value)
    {
        return NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNTheta00, (NParam)this, NParamBox(NWrapper::w, value).n);
    }

    virtual void setWriteType(int writeType)
    {
        NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNIota00, (NParam)this, (NParam)writeType);
    }

private:
    BluetoothGattCharacteristic(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
