#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include <math.h>

float sampleRate = 48000.0;
float phase = 0.0;
float frequency = 440.0;
float audioGain = 0.2f;

float updateSine()
{
	phase += (2.0 * M_PI / sampleRate) * frequency;
	if (phase > 2.0 * M_PI) phase -= 2.0 * M_PI;
	//std::cout << "Sample: " << sinf(phase) << std::endl;
	return sinf(phase) * audioGain;
}


void SDLAudioCallback(void* userdata, Uint8* stream, int streamLength)
{
	float* buf = (float*) stream;
	for (int i = 0; i < streamLength / sizeof(float); i++)
	{
		float sample = updateSine();

		buf[i] = sample;
	}
}


int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_AUDIO);

	SDL_AudioSpec audioSpec;
	audioSpec.freq = (int)sampleRate;
	audioSpec.format = AUDIO_F32;
	audioSpec.channels = 1;
	audioSpec.samples = 4096;
	audioSpec.callback = SDLAudioCallback;

	SDL_AudioDeviceID device = SDL_OpenAudioDevice(NULL, 0, &audioSpec, NULL,
		SDL_AUDIO_ALLOW_ANY_CHANGE);
	


	std::cout << "With audio device: " << device << std::endl;

	if (device == 0)
	{
		std::cerr << "Failed to open audio: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_PauseAudioDevice(device, 0);
	SDL_Delay(20000);

	SDL_CloseAudioDevice(device);
	SDL_Quit();

	return 0;
}