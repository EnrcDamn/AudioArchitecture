#pragma once

#include <string>
#include "iaudiodata.h"

class IAudioDevice
{
public:
	virtual ~IAudioDevice() {}
	virtual IAudioData* createAudioFromFile(const std::string& filePath) = 0;
	virtual void releaseAudio(IAudioData* audioData) = 0;

private:
};