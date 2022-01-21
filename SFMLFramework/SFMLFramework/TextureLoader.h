#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <SFML/Graphics/Texture.hpp>
#include "Player.h"
#include "EnemyManager.h"
#include "UIManager.h"
#include "Background.h"

class TextureLoader
{
private:
//#######################################################
//    Function    :    SetOrigin
//    Purpose        :    Sets the pivot point of an object to the center of its texture.
//    Parameters    :    Texture*, Transformable*
//    Returns        :    None
//    Notes        :     None
//    See also    :    TextureLoader::loadTextures();
//#######################################################
	void setOrigin( sf::Texture* texture, sf::Transformable* object );

public:
//#######################################################
//    Function    :    Constructor
//    Purpose        :    Initializes the texture loader.
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::run();
//#######################################################
	TextureLoader();


//#######################################################
//    Function    :    LoadTextures
//    Purpose        :    Loads textures from their paths and stores them in their objects.
//    Parameters    :    Player*, EnemyManager*, UIManager*, Background*
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::run();
//#######################################################
	void loadTextures( Player* player, EnemyManager* enemyManager, UIManager* uiManager, Background* background);

};
#endif
