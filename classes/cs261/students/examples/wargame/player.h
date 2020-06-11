#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"
#include "deck.h"

class Player
{
public:
	Player();
	bool drawCard(Deck& deck);
	bool playCard(Card*& aCard);
	void setAsideCard(Card* card);
	int	getScore() const;
	void print() const;

private:
	Hand	hand;
	int		winningPile;
};
#endif