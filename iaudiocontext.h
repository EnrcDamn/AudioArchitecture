#pragma once

#include "audioobject.h"

class IAudioContext
{
public:
	virtual ~IAudioContext() {}
	virtual void PlayAudio(AudioObject& ao) = 0;
	virtual void PauseAudio(AudioObject& ao) = 0;
	virtual void StopAudio(AudioObject& ao) = 0;
private:
};