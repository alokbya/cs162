#include "card.h"
#include <string>

Card::Card(Suit suit, int rank) :suit(suit), rank(rank){}

Suit Card::getSuit() const
{
	return suit;
}

int Card::getRank() const
{
	return rank;
}

void Card::print() const
{
	string suitStr;
	switch (suit)
	{
	case diamond:
		suitStr = "Diamond";
		break;
	case heart:
		suitStr = "Heart";
		break;
	case club:
		suitStr = "Club";
		break;
	case spade:
		suitStr = "Spade";
		break;
	default:
		suitStr = "illegal";
		break;
	}
	cout << suitStr << '-' << rank;
}