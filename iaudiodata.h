#pragma once

#include "sampleinfo.h"

class IAudioData
{
public:
	virtual ~IAudioData() {}
	virtual size_t generateSamples(float* stream, size_t streamLength,
			size_t pos, const SampleInfo& info) = 0;
	virtual size_t getAudioLength() = 0;

private:

};