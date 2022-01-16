#include "AudioLoader.h"

AudioLoader::AudioLoader() {

}

void AudioLoader::LoadAudio(std::string path)
{
	backgroundMusic.openFromFile(path);
}
