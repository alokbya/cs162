#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

enum Suit{diamond, club, heart, spade};

class Card
{
public:
	Card(Suit suit=spade, int rank=1);
	Suit getSuit() const;
	int getRank() const;
	void print() const;

private:
	Suit	suit;
	int		rank;
};

#endif