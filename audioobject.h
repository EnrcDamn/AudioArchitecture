#pragma once

#include "iaudiodata.h"
#include "sampleinfo.h"

class AudioObject
{
public:
	// Constructor
	AudioObject(const SampleInfo& info, IAudioData* data);

	bool generateSamples(float* stream, size_t streamLength);
	void setPos(double pos); // 0 -> 1

private:
	size_t		audioPos;
	size_t		audioLength;
	SampleInfo  sampleInfo;
	IAudioData* audioData;

	size_t posToAbsolutePos(double pos); // pos conversion to normilized
};
