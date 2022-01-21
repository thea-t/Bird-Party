#include "AudioLoader.h"

AudioLoader::AudioLoader() 
{
	// load sounds and musics
	birdHitBuffer.loadFromFile( "Audios/bird-hit.wav" );
	birdHitSoftBuffer.loadFromFile( "Audios/bird-hit-soft.wav" );
	birdHitHeavyBuffer.loadFromFile( "Audios/bird-hit-heavy.wav" );
	birdHitSound.setBuffer( birdHitBuffer );
	birdHitSoftSound.setBuffer( birdHitSoftBuffer );
	birdHitHeavySound.setBuffer( birdHitHeavyBuffer );
}



void AudioLoader::loadMusic( std::string path )
{
	backgroundMusic.openFromFile( path );
	backgroundMusic.play();
}

void AudioLoader::playRandomBirdHitSound()
{
	// this is called when an enemy is hit.
	// randomly select a number between 0 and 2 to play a random sound.
	int _rand = rand() % 3;
	if ( _rand == 0 ) 
	{
		birdHitSound.play();
	}
	else if ( _rand == 1 ) 
	{
		birdHitSoftSound.play();
	}
	else if( _rand == 2 )
	{
		birdHitHeavySound.play();
	}
}
