#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

class ScoreManager
{
private:
public:
//#######################################################
//    Function    :    Constructor
//    Purpose        :    Initializes the score manager.
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::run();
//#######################################################
	ScoreManager();

	int currentScore;

//#######################################################
//    Function    :    AddScore
//    Purpose        :    Increases the player's score.
//    Parameters    :    int
//    Returns        :    None
//    Notes        :     None
//    See also    :    Enemy::onGetHit();
//#######################################################
	void addScore( int amount );
};

#endif