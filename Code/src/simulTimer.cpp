
#include "simulTimer.h"
#include <GLFW/glfw3.h>


simulTimer::simulTimer()
{
	mFrames = 0;
	mCurrent = 0.0;
	mPrevious = 0.0;
	mDeltaTime = 0.0;
	mFPSCount = 0.0;
	mFPS = 0.0;

}

void simulTimer::tick()
{
	mCurrent = glfwGetTime();
	mDeltaTime = (mCurrent-mPrevious);
	mPrevious = mCurrent;

	mFPSCount += mDeltaTime;
	if(mFPSCount > 1.0)
	{
		mFPS = (double)mFrames/mFPSCount;
		mFPSCount = 0.0;
		mFrames = 0;
	}

	mFrames++;
}

const float simulTimer::getDeltaTime()
{
	return mDeltaTime*1000;
}
const float simulTimer::getFPS()
{
	return mFPS;
}