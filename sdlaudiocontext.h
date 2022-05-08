#pragma once

#include "iaudiocontext.h"
#include <vector>
#include <SDL.h>

class SDLAudioContext : public IAudioContext
{
public:
	SDLAudioContext();
	virtual ~SDLAudioContext();

	virtual void playAudio(AudioObject& ao) = 0;
	virtual void pauseAudio(AudioObject& ao) = 0;
	virtual void stopAudio(AudioObject& ao) = 0;

	void generateSamples(Uint8* stream, int streamLength);
private:
	SDL_AudioDeviceID device;
	std::vector<float> vector;
	std::vector<AudioObject*> playingAudio;

	bool removeAudio(AudioObject& ao);
};