#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <vector>

class Hand
{
public:
	Hand();
	~Hand();
	void addCard(Card * aCard);
	bool removeCard(int position, Card*& aCard);
	void print() const;
	int size() const;
private:
	vector<Card*> cards;
};
#endif