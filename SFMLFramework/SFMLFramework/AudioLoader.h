#ifndef AUDIOLOADER_H
#define AUDIOLOADER_H

#include <SFML/Audio.hpp>

// how to play audio: https://www.sfml-dev.org/tutorials/2.5/audio-sounds.php
class AudioLoader
{
private:

	sf::Music backgroundMusic;

public:

	AudioLoader();

	void LoadAudio( std::string path );
};

#endif