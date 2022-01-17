#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

class ScoreManager
{
private:
public:
	ScoreManager();

	int currentScore;

	void addScore( int amount );
};

#endif