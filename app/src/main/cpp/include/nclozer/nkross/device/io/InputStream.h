#ifndef __InputStream_H__
#define __InputStream_H__

namespace NSDEVICE
{

class InputStream : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~InputStream()
    {
    }

    int close()
    {
        return (nint)NSNKROSS::w->mNVisitorIO->tRun(NSNKROSS::w->mNAlpha00, (NParam)this);
    }

    int read(String& buffer, int byteOffset, int byteCount)
    {
        // Blocks and returns the number of bytes read
        // -1 if end of the stream is reached
        // -2 if stream is closed or another IO exception occurred
        // -3 if UTF-8 is not supported
        NReturn err = NSNKROSS::w->mNVisitorIO->tRun(NSNKROSS::w->mNBeta00, (NParam)this, (NParam)nullptr, (NParam)byteOffset, (NParam)byteCount);

        if (err >= 0) {
            nint vIndex;
            NReturn size = (NReturn)buffer.size();
            String vRead = NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject((NParam)err));
            err = vRead.size();

            for (vIndex = size ; vIndex < byteOffset ; ++vIndex) {
                buffer += '\0';
            }
            buffer = buffer.substr(0, byteOffset) + vRead + buffer.substr(byteOffset + err < size ? byteOffset + err : size );
        }
        return err;
    }

private:
    InputStream(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
