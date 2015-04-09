#ifndef __InputType_H__
#define __InputType_H__

namespace NSDEVICE
{

class InputType
{
friend NSNATIVE::NNoObject;

public:
    static const int TYPE_CLASS_DATETIME = 0x00000004;
    static const int TYPE_CLASS_NUMBER = 0x00000002;
    static const int TYPE_CLASS_PHONE = 0x00000003;
    static const int TYPE_CLASS_TEXT = 0x00000001;
    static const int TYPE_DATETIME_VARIATION_DATE = 0x00000010;
    static const int TYPE_DATETIME_VARIATION_NORMAL = 0x00000000;
    static const int TYPE_DATETIME_VARIATION_TIME = 0x00000020;
    static const int TYPE_MASK_CLASS = 0x0000000f;
    static const int TYPE_MASK_FLAGS = 0x00fff000;
    static const int TYPE_MASK_VARIATION = 0x00000ff0;
    static const int TYPE_NULL = 0x00000000;
    static const int TYPE_NUMBER_FLAG_DECIMAL = 0x00002000;
    static const int TYPE_NUMBER_FLAG_SIGNED = 0x00001000;
    static const int TYPE_NUMBER_VARIATION_NORMAL = 0x00000000;
    static const int TYPE_NUMBER_VARIATION_PASSWORD = 0x00000010;
    static const int TYPE_TEXT_FLAG_AUTO_COMPLETE = 0x00010000;
    static const int TYPE_TEXT_FLAG_AUTO_CORRECT = 0x00008000;
    static const int TYPE_TEXT_FLAG_CAP_CHARACTERS = 0x00001000;
    static const int TYPE_TEXT_FLAG_CAP_SENTENCES = 0x00004000;
    static const int TYPE_TEXT_FLAG_CAP_WORDS = 0x00002000;
    static const int TYPE_TEXT_FLAG_IME_MULTI_LINE = 0x00040000;
    static const int TYPE_TEXT_FLAG_MULTI_LINE = 0x00020000;
    static const int TYPE_TEXT_FLAG_NO_SUGGESTIONS = 0x00080000;
    static const int TYPE_TEXT_VARIATION_EMAIL_ADDRESS = 0x00000020;
    static const int TYPE_TEXT_VARIATION_EMAIL_SUBJECT = 0x00000030;
    static const int TYPE_TEXT_VARIATION_FILTER = 0x000000b0;
    static const int TYPE_TEXT_VARIATION_LONG_MESSAGE = 0x00000050;
    static const int TYPE_TEXT_VARIATION_NORMAL = 0x00000000;
    static const int TYPE_TEXT_VARIATION_PASSWORD = 0x00000080;
    static const int TYPE_TEXT_VARIATION_PERSON_NAME = 0x00000060;
    static const int TYPE_TEXT_VARIATION_PHONETIC = 0x000000c0;
    static const int TYPE_TEXT_VARIATION_POSTAL_ADDRESS = 0x00000070;
    static const int TYPE_TEXT_VARIATION_SHORT_MESSAGE = 0x00000040;
    static const int TYPE_TEXT_VARIATION_URI = 0x00000010;
    static const int TYPE_TEXT_VARIATION_VISIBLE_PASSWORD = 0x00000090;
    static const int TYPE_TEXT_VARIATION_WEB_EDIT_TEXT = 0x000000a0;
    static const int TYPE_TEXT_VARIATION_WEB_EMAIL_ADDRESS = 0x000000d0;
    static const int TYPE_TEXT_VARIATION_WEB_PASSWORD = 0x000000e0;

    virtual ~InputType()
    {
    }

protected:
    InputType()
    {
    }

private:
    InputType(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
