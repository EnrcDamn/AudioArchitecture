#pragma once

#include "audioobject.h"

class IAudioContext
{
public:
	virtual ~IAudioContext() {}
	virtual void playAudio(AudioObject& ao) = 0;
	virtual void pauseAudio(AudioObject& ao) = 0;
	virtual void stopAudio(AudioObject& ao) = 0;
private:
};