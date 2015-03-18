package z.a;

import android.view.View;
import android.widget.AdapterView;

//*******************************************************************************************
//*********************************** OnItemClickListener ***********************************
//*******************************************************************************************
public class TOnItemClickListener implements AdapterView.OnItemClickListener
{
    public TWrapper w;
    public long n;

    public TOnItemClickListener(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    public void onItemClick(AdapterView<?> parent, View view, int position, long id)
    {
        w.mTVisitorWidgetView.nRun(w.mTGamma03, n,
            w.tFrame.putKey(w.mTVisitorView.nRun(w.mTGamma03, n, -1, 2), parent),
            w.tFrame.putKey(w.mTVisitorView.nRun(w.mTGamma03, n, -1, 1), view),
            position,
            id
        );
    }
}
