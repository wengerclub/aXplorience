package y.b;

import android.content.res.Configuration;
import android.content.res.Resources;
import android.graphics.drawable.Drawable;

public class TVisitorContentRes extends TKrossVisitor
{
    public TVisitorContentRes(TWrapper w) {
        super(w);
    }

    //*******************************************************************************
    //**************************** Configuration ************************************
    //*******************************************************************************
    // float getFontScale()
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        return Double.doubleToRawLongBits(((Configuration)w.sObject.get(a)).fontScale);
    }

    // int getScreenWidthDp()
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        return ((Configuration)w.sObject.get(a)).screenWidthDp;
    }

    // int getOrientation()
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        return ((Configuration)w.sObject.get(a)).orientation;
    }

    // int getSmallestScreenWidthDp()
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        return ((Configuration)w.sObject.get(a)).smallestScreenWidthDp;
    }

    //*******************************************************************************
    //******************************* Resources *************************************
    //*******************************************************************************
    // DisplayMetrics* getDisplayMetrics()
    public long visit(TAlpha01 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putKey(b, ((Resources)w.sObject.get(a)).getDisplayMetrics());
    }

    // Configuration* getConfiguration()
    public long visit(TBeta01 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putKey(b, ((Resources)w.sObject.get(a)).getConfiguration());
    }

    // Drawable* getDrawable(const String& vString)
    public long visit(TGamma01 element, long a, long b, long c, long d, long e)
    {
        Drawable ret = null;

        try {
            ret = ((Resources)w.sObject.get(a)).getDrawable(w.mTKrossSystem.getDrawableId((String)w.mTKrossSystem.nRunObject(c)));
        }
        catch (Resources.NotFoundException vException) {
            if (w.doDebug) vException.printStackTrace();
            ret = null;
        }
        return w.mTKrossSystem.putKey(b, ret);
    }
}
