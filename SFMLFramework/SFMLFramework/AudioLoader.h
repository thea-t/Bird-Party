#ifndef AUDIOLOADER_H
#define AUDIOLOADER_H

#include <SFML/Audio.hpp>

// how to play audio: https://www.sfml-dev.org/tutorials/2.5/audio-sounds.php
class AudioLoader
{
private:

	sf::Music backgroundMusic;
	sf::SoundBuffer birdHitBuffer;
	sf::SoundBuffer birdHitSoftBuffer;
	sf::SoundBuffer birdHitHeavyBuffer;

	sf::Sound birdHitSound;
	sf::Sound birdHitSoftSound;
	sf::Sound birdHitHeavySound;
public:

//#######################################################
//    Function    :    Constructor
//    Purpose        :    Initializes audio loader.
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::run();
//#######################################################
	AudioLoader();

//#######################################################
//    Function    :    LoadMusic
//    Purpose        :    Loads and plays the background music.
//    Parameters    :    string
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::run();
//#######################################################
	void loadMusic( std::string path );

//#######################################################
//    Function    :    PlayRandomBirdHitSound
//    Purpose        :    Picks and plays a random sound when the birds get hit by a projectile.
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    Enemy::onGetHit();
//#######################################################
	void playRandomBirdHitSound();
};

#endif