#include "AudioLoader.h"

AudioLoader::AudioLoader() {

}

void AudioLoader::loadAudio(std::string path)
{
	backgroundMusic.openFromFile(path);
	backgroundMusic.play();
}
