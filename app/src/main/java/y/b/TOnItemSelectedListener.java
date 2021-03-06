package y.b;

import android.view.View;
import android.widget.AdapterView;

//*******************************************************************************************
//*********************************** OnItemSelectedListener ********************************
//*******************************************************************************************
public class TOnItemSelectedListener implements AdapterView.OnItemSelectedListener
{
    public TWrapper w;
    public long n;

    public TOnItemSelectedListener(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    public void onItemSelected(AdapterView<?> parent, View view, int position, long id)
    {
        long vcKey;
        w.mTVisitorWidgetView.nRun(w.mTAlpha03, n,
            (vcKey = w.mTKrossSystem.getKey(parent)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorWidgetView.nRun(w.mTAlpha03, n, -1, 2), parent),
            (vcKey = w.mTKrossSystem.getKey(view)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorWidgetView.nRun(w.mTAlpha03, n, -1, 1), view),
            position,
            id
        );
    }

    public void onNothingSelected(AdapterView<?> parent)
    {
        long vcKey;
        w.mTVisitorWidgetView.nRun(w.mTBeta03, n,
            (vcKey = w.mTKrossSystem.getKey(parent)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorWidgetView.nRun(w.mTBeta03, n, -1, 1), parent)
        );
    }
}