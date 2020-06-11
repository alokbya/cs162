#include "hand.h"

Hand::Hand(){}

Hand::~Hand()
{
	for (vector<Card*>::iterator it = cards.begin(); it != cards.end(); it++)
	{
		delete *it;
	}
}

void Hand::addCard(Card* aCard)
{
	cards.push_back(aCard);
}

bool Hand::removeCard(int position, Card*& aCard)
{
	if (position < 0 || position >= cards.size())
		return false;
	int index = 0;
	for (vector<Card*>::iterator it = cards.begin(); it != cards.end(); it++, index++)
	{
		if (index == position)
		{
			aCard = *it;
			cards.erase(it);
			break;
		}			
	}
	return true;
}

void Hand::print() const
{
	for (auto it = cards.cbegin(); it != cards.cend(); it++)
	{
		(*it)->print();
		cout << " ";
	}
	cout << endl;
}

int Hand::size() const
{
	return cards.size();
}