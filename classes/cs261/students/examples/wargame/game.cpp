#include "game.h"
#include <iostream>
using namespace std;
Game::Game()
{
	player1 = new Player();
	player2 = new Player();
	deck = new Deck();
}

Game::~Game()
{
	delete player1;
	delete player2;
	delete deck;
}

void Game::run()
{
	//shuffle the deck
	cout << endl << "Initial deck: " << endl;
	deck->print();
	deck->shuffleCards();
	cout << endl << "After shuffing deck content: " << endl;
	deck->print();

	//deal the initial three cards to the two players
	for (int index = 0; index < 3; index++)
	{
		player1->drawCard(*deck);
		player2->drawCard(*deck);
	}
	cout << endl << "After initial dealing player 1: " << endl;
	player1->print();
	cout << endl << "After initial dealing player 2: " << endl;
	player2->print();
	cout << endl << "After initial dealing deck content: " << endl;
	deck->print();

	//play card
	Card *card1, *card2;
	int rank1, rank2;
	Player* winningPlayer;
	bool gameFinished = false;
	int currRound = 1;
	do
	{
		if (player1->playCard(card1) && player2->playCard(card2))
		{
			rank1 = card1->getRank();
			rank2 = card2->getRank();
			if (rank1 > rank2)
			{
				winningPlayer = player1;
			}
			else if (rank1 < rank2)
			{
				winningPlayer = player2;
			}
			else
			{
				winningPlayer = nullptr;
			}
		}
		else
		{
			gameFinished = true;
			break;
		}
		if (winningPlayer)
		{
			winningPlayer->setAsideCard(card1);
			winningPlayer->setAsideCard(card2);
		}
		else
		{
			player1->setAsideCard(card1);
			player2->setAsideCard(card2);
		}

		cout << endl << "After playing round #" << currRound << ": " << endl;
		cout << endl << "Player1 state: " << endl;
		player1->print();
		cout << endl << "Player2 state: " << endl;
		player2->print();
		currRound++;
		
		if (!player1->drawCard(*deck) || !player2->drawCard(*deck))
		{
			gameFinished = true;
		}
	} while (!gameFinished);

	//print out game summary
	cout << endl << "Player 1 Score: " << player1->getScore() << endl
		<< "Player 2 Score: " << player2->getScore() << endl << endl;
	
}