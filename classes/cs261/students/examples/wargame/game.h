#ifndef GAME_H
#define GAME_H

#include  "card.h"
#include "deck.h"
#include "player.h"

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	Player * player1;
	Player * player2;
	Deck * deck;
};
#endif