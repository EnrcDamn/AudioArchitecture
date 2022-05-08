#include "sdlaudiocontext.h"

static void SDLAudioContext_AudioCallback(void* userData, Uint8* streamIn, int length)
{
	SDLAudioContext* context = (SDLAudioContext*)userData;
	context->generateSamples(streamIn, length);
}

SDLAudioContext::SDLAudioContext()
{
	SDL_AudioSpec spec;
	SDL_zero(spec);
	spec.freq = 44100;
	spec.format = AUDIO_S16SYS;
	spec.channels = 1;
	spec.samples = 2048;
	spec.callback = SDLAudioContext_AudioCallback;
	spec.userdata = this;

	SDL_AudioDeviceID device = SDL_OpenAudioDevice(NULL, 0, &spec, NULL, 0);
	if (device == 0)
	{
		throw SDL_GetError();
		// std::cerr << "Failed to open audio: " << SDL_GetError() << std::endl;
		// return 1;
	}

	SDL_PauseAudioDevice(device, 0);
}

SDLAudioContext::~SDLAudioContext()
{
	SDL_CloseAudioDevice(device);
}

void SDLAudioContext::playAudio(AudioObject& ao)
{

}

void SDLAudioContext::pauseAudio(AudioObject& ao)
{

}

void SDLAudioContext::stopAudio(AudioObject& ao)
{

}

void SDLAudioContext::generateSamples(Uint8* stream, int streamLength)
{

}