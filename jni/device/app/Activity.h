#ifndef __ACTIVITY_H__
#define __ACTIVITY_H__

namespace NSDEVICE
{

class Activity : public ContextThemeWrapper
{
friend NSNATIVE::NVisitorAppActivity;
friend NSNATIVE::NNoObject;

public:
	Activity()
        : ContextThemeWrapper(NWrapper::w->mNNoObject->instance<ContextThemeWrapper>())
	{
        NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNAlpha00, (NParam)this);
	}

	virtual ~Activity()
	{
	}

	Activity* getInstance(NWrapper* const vNWrapper);

    virtual ActionBar* getActionBar()
    {

        ActionBar* vActionBar = NWrapper::w->mNNoObject->pointer<ActionBar>();
        bool error = NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNBeta00, (NParam)this, (NParam)vActionBar);
        return ( error ? nullptr : vActionBar);
    }

    virtual Resources* getResources()
    {
        Resources* vResources = NWrapper::w->mNNoObject->pointer<Resources>();
        NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNGamma00, (NParam)this, (NParam)vResources);
        return vResources;
    }

    virtual FragmentManager* getFragmentManager()
    {
        FragmentManager* vFragmentManager = NWrapper::w->mNNoObject->pointer<FragmentManager>();
        NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNDelta00, (NParam)this, (NParam)vFragmentManager);
        return vFragmentManager;
    }

	virtual void setContentView(View* view)
	{
		NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNEpsilon00, (NParam)this, (NParam)view);
	}

	virtual void sendMessage(NParam a = 0, NParam b = 0, NParam c = 0)
	{
		NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNDzeta00, (NParam)this, (NParam)a, (NParam)b, (NParam)c);
	}

protected:
    //******************************************************************************************
    //************************************* Activity events ************************************
    //* This passes the call back to the default implementation if the method is not overriden *
    //******************************************************************************************
	virtual void onCreate()
	{
		NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNAlpha03, (NParam)this);
	}

	virtual void onDestroy()
	{
		// Called only if the system must not recover memory in an emergency
		// Clean memory here
		NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNBeta03, (NParam)this);
	}

	virtual void onPause()
	{
		// This is the last method garanteed to be called before the process may be killed
		// Stop things that may be consuming CPU (like animations) here
		NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNGamma03, (NParam)this);
	}

	virtual void onRestart()
	{
		NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNDelta03, (NParam)this);
	}

	virtual void onResume()
	{
		// Resume here animations and other things that may be consuming CPU
		NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNEpsilon03, (NParam)this);
	}

	virtual void onStart()
	{
		NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNDzeta03, (NParam)this);
	}

	virtual void onStop()
	{
		NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNEta03, (NParam)this);
	}

    virtual void onActivityResult(int action, int requestCode, int resultCode, int extra)
    {
    }

	virtual void onReceiveDiscoveryFinished()
	{
	}

	virtual void onReceiveDiscoveryStarted()
	{
	}

	virtual void onReceiveFoundDevice(BluetoothDevice* dBluetoothDevice)
	{
	}

	virtual void onReceiveLocalName(String localName)
	{
	}

	virtual void onReceiveState(int state, int statePrevious)
	{
	}

	virtual void onReceiveScanMode(int mode, int modePrevious)
	{
	}

	virtual void handleMessage(NParam a, NParam b, NParam c)
	{
	}

private:
    Activity(NNoObject* vNNoObject)
        : ContextThemeWrapper(NWrapper::w->mNNoObject->instance<ContextThemeWrapper>())
    {
    }
};

} // End namespace

#endif


//HINT:
// Methods requiring an xml resource ID as parameter will not be implemented, because there is no android xml parser on iOs
// - inflater
// - setTextAppearance(Context context, int resid)
