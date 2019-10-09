/*****************************************************
 Samuel Mendheim and Nic Grube ~ COMP233 Fall 2019 ~ Monte Carlo
*****************************************************/

#pragma once
#include "Card.h"
#include <stdexcept>


class Deck {
private:
	int numSuits = 4;
	int numCardsInSuit = 13;
	int maxDeckCapacity = 416;
	int deckCapacity = 52; //capacity deck size
	int deckSize = 0; //number of cards in decks
	int headIndex = 0;
	int tailIndex = 0;
	Card* deckOfCards; //pointer to deck

public:
	//Default constructor -> will generate deck of 52 cards, ogranized 1-13 and S, D, C, H
	Deck();

	/*Parameterized Constructor -> receives integer indicating capacity of new deck
	Legal capacities: [0..416]*/
	Deck(int capacity);

	//Returns true if deck is empty
	bool isEmpty();

	//Returns true if deck is full
	bool isFull();

	//Returns the number of cards
	int getNumCards();

	//Removes top card of deck
	Card dealCard();

	//Add new card to bottom of deck
	void addCard(Card c);

	//returns copy of card at indicated position
	Card peekCard(int position);

	//randomizes order of cards
	void shuffleDeck();

	//cuts deck
	void cutDeck();

	//resets desk based on predetermined set of rules
	void resetDeck();

	//Deep copy constructor
	Deck(const Deck& d);

	//Deep Assignment Operator overload
	Deck &operator=(const Deck& d);

	//Deep Destructor
	~Deck();

	//Extra method for testing
	int getCapacity();
};