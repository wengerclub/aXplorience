#ifndef __VIEWGROUP_H__
#define __VIEWGROUP_H__

namespace NSDEVICE
{

class ViewGroup : public View
{
friend NSNATIVE::NKrossFriend;

public:
    class LayoutParams : public View::LayoutParams
    {
    friend NSNATIVE::NKrossFriend;

    public:
        static const int MATCH_PARENT = -1;
        static const int WRAP_CONTENT = -2;

        LayoutParams(int width, int height);
        virtual ~LayoutParams();
    private:
        LayoutParams(NKrossFriend* vNKrossFriend);
    };

    class MarginLayoutParams : public ViewGroup::LayoutParams
    {
    friend NSNATIVE::NKrossFriend;

    public:
        MarginLayoutParams(int width, int height);
        virtual ~MarginLayoutParams();
        virtual void setMargins(int left, int top, int right, int bottom);
    private:
        MarginLayoutParams(NKrossFriend* vNKrossFriend);
    };

    virtual ~ViewGroup();
    virtual void addView(View* view);
    virtual void addView(View* view, int index);
    virtual View* getChildAt(int index);
    virtual int getChildCount();
    virtual bool onInterceptTouchEvent(MotionEvent* ev);
    virtual void removeAllViews();
    virtual void removeViewAt(int index);
    virtual void requestLayout();
private:
    ViewGroup(NKrossFriend* vNKrossFriend);
};

} // End namespace

#endif
