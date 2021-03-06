#ifndef __BluetoothGattCharacteristic_H__
#define __BluetoothGattCharacteristic_H__

namespace NSDEVICE
{

class BluetoothGattCharacteristic : public Object
{
friend NSNATIVE::NKrossFriend;

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
        NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNDelta00, (NParam)this, NKrossParam(uuid).n, (NParam)properties, (NParam)permissions);
    }

    virtual ~BluetoothGattCharacteristic()
    {
    }

    virtual bool addDescriptor(BluetoothGattDescriptor* descriptor)
    {
        return NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNUpsilon01, (NParam)this, (NParam)descriptor);
    }

    virtual BluetoothGattDescriptor* getDescriptor(const String& uuid)
    {
        BluetoothGattDescriptor* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothGattDescriptor>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNGamma01, (NParam)this, (NParam)b, NKrossParam(uuid).n));
    }

    virtual NArray<BluetoothGattDescriptor*> getDescriptors()
    {
        NReturn index = NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNBeta01, (NParam)this);
        NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1);
        NArray<BluetoothGattDescriptor*> vNArray = NArray<BluetoothGattDescriptor*>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            BluetoothGattDescriptor* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothGattDescriptor>();
            vNArray.maData[i] = NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, (NParam)i, (NParam)b));
        }
        return vNArray;
    }

    virtual int getProperties()
    {
        return NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNEpsilon01, (NParam)this);
    }

    virtual String getUuid()
    {
        NReturn index = NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNDzeta01, (NParam)this);
        return NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject((NParam)index));
    }

    virtual NArray<nubyte> getValue()
    {
        NReturn index = NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNEpsilon00, (NParam)this);
        NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1);
        NArray<nubyte> vNArray =  NArray<nubyte>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            vNArray.maData[i] = (nubyte)NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, (NParam)i);
        }
        return vNArray;
    }

    virtual String getStringValue(int offset)
    {
        NReturn index = NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNDzeta00, (NParam)this, (NParam)offset);
        return NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject((NParam)index));
    }

    virtual bool setValue(NArray<nubyte> value)
    {
        nuint vcIndex;
        nlong vcKey = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNBeta01, 0, value.mcData);

        for (vcIndex = 0 ; vcIndex < value.mcData ; ++vcIndex) {
            NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNBeta01, vcKey, vcIndex, value.maData[vcIndex]);
        };
        return NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNEta00, (NParam)this, (NParam)vcKey);
    }

    virtual bool setValue(const String& value)
    {
        return NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNTheta00, (NParam)this, NKrossParam(value).n);
    }

    virtual void setWriteType(int writeType)
    {
        NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNIota00, (NParam)this, (NParam)writeType);
    }

private:
    BluetoothGattCharacteristic(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
