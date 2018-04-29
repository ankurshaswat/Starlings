#ifndef __simulTimer_h__
#define __simulTimer_h__

class simulTimer
{
public:
	simulTimer();
	void tick();
	const float getDeltaTime();
	const float getFPS();
private:
	double mPrevious;
	double mCurrent;
	double mDeltaTime;
	double mFPS;
	double mFPSCount;
	int mFrames;
};


#endif 