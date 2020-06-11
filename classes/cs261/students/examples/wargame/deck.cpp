#include "deck.h"
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock


Deck::Deck()
{
	for (Suit suit = diamond; suit <= spade; suit = static_cast<Suit>(suit+1))
	{
		for (int rank = 1; rank <= 13; rank++)
		{
			cards.push_back(new Card(suit, rank));
		}
	}
}
Deck::~Deck()
{
	for (vector<Card*>::iterator it = cards.begin(); it != cards.end(); it++)
	{
		delete *it;
	}
}

void Deck::shuffleCards()
{
	// obtain a time-based seed:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

bool Deck::dealCard(Card*& aCard)
{
	if (cards.size() == 0)
		return false;
	aCard = cards.back();
	cards.pop_back();
	return true;
}

bool Deck::isEmpty() const
{
	return cards.size() == 0;
}

void Deck::print() const
{
	for (auto it = cards.cbegin(); it != cards.cend(); it++)
	{
		(*it)->print();
		cout << " ";
	}
	cout << endl;
}