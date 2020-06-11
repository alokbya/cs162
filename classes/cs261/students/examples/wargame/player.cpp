#include "player.h"
#include <ctime>
#include <cstdlib>

Player::Player():winningPile(0){}

bool Player::drawCard(Deck& deck)
{
	Card * aCard;
	if (!deck.dealCard(aCard))
		return false;
	hand.addCard(aCard);
	return true;
}

bool Player::playCard(Card*& aCard)
{
	int position;
	srand(time(nullptr));
	position = rand() % hand.size();
	if (!hand.removeCard(position, aCard))
		return false;
	return true;
}

void Player::setAsideCard(Card* card)
{
	winningPile++;
	delete card;
}

int	Player::getScore() const
{
	return winningPile;
}

void Player::print() const
{
	cout << "Current Hand: " << endl;
	hand.print();
	cout << "Current scores: " << winningPile << endl;
}