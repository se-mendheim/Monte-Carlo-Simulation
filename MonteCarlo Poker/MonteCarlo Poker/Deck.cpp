/*****************************************************
 Samuel Mendheim and Nic Grube ~ COMP233 Fall 2019 ~ Monte Carlo
*****************************************************/

#include "Deck.h"
#include <xutility>
#include <cstdlib>
using namespace std;

#define NORMAL_DECK_SIZE 52


//@author Nic Grube
//Default constructor -> will generate deck of 52 cards, ogranized 1-13 and S, D, C, H
Deck::Deck() {
	// setting all variables to a fresh new deck
	headIndex = 0;
	tailIndex = 0;
	deckSize = 0;
	// setting deck capacity to 52 cards
	deckCapacity = NORMAL_DECK_SIZE;
	// mallocing the memory for the deck of cards
	deckOfCards = (Card*)malloc((NORMAL_DECK_SIZE + 1) * sizeof(Card)); //+1 on deck size for empty slot
	// for loop to run through 4 different suits --> Spaces, Diamonds, Clubs, Hearts
	for (int suitCounter = 0; suitCounter < numSuits; suitCounter++) {
		// for loop to run through 13 different cards of each suit
		for (int faceCounter = 0; faceCounter < numCardsInSuit; faceCounter++) {
			switch (suitCounter) {
			// if suit is equal to zero deal out the 13 spades cards
			case 0:
				*(deckOfCards + tailIndex) = Card(faceCounter + 1, 'S');
				break;
			// if suit is equal to one deal out the 13 hearts cards
			case 1:
				*(deckOfCards + tailIndex) = Card(faceCounter + 1, 'D');
				break;
			// if suit is equal to two deal out the 13 clubs cards
			case 2:
				*(deckOfCards + tailIndex) = Card(faceCounter + 1, 'C');
				break;
			// if suit is equal to three deal out the 13 hearts cards
			case 3:
				*(deckOfCards + tailIndex) = Card(faceCounter + 1, 'H');
				break;
			}
			// increase tail index with the size of the deck
			tailIndex++;
			deckSize++;
		}
	}
}


//@Author Samuel Mendheim
/*Parameterized Constructor -> receives integer indicating capacity of new deck
Legal capacities: [0..416]*/
Deck::Deck(int capacity) throw (runtime_error) {
	// if statement to check if the capacity is within range
	if (0 <= capacity && capacity <= maxDeckCapacity) {
		// setting the deck capacity to the capacity entered
		deckCapacity = capacity;
		// mallocing the amount of memory for a deck size of capacity
		deckOfCards = (Card*)malloc((deckCapacity + 1) * sizeof(Card));
		// setting the head index and tail index equal to zero (the deck is empty)
		headIndex = 0;
		tailIndex = 0;
	}
	else {
		throw runtime_error("That is not a possible card deck");
	}
}

//@Author Nic Grube
//Returns true if deck is empty
bool Deck::isEmpty() {
	if (tailIndex == headIndex) {
		return true;
	}
	else {
		return false;
	}
}

//@Author Nic Grube
//Returns true if deck is full
bool Deck::isFull() {
	// if the tail index is 1 behind the head index then the deck is full
	if ((tailIndex - headIndex) % deckSize == 0 && tailIndex != headIndex) {
		return true;
	}
	else {
		return false;
	}

}

//@Author Nic Grube
//Returns the number of cards
int Deck::getNumCards() {
	return (tailIndex - headIndex);
}

//@Author Samuel Mendheim
//Removes and returns top card of deck
Card Deck::dealCard() throw (runtime_error) {
	if (tailIndex >= 1) {
		// dealing the card at the head index and increasing headIndex to the next card
		Card c = deckOfCards[headIndex%deckSize];
		headIndex++;
		return c;
	}
	else {
		throw runtime_error("Card deck is empty");
	}
}

//@Author Samuel Mendheim
//Add new card to bottom of deck
void Deck::addCard(Card c) throw (runtime_error) {
	if (!isFull()) {
		// adding the card to the tail index and increasing the tail index
		deckOfCards[tailIndex%deckSize] = c;
		tailIndex++;
	}
	else {
		throw runtime_error("Card deck is full");
	}
}

//@Author Samuel Mendheim
//returns copy of card at indicated position
Card Deck::peekCard(int position) throw (runtime_error) {
	// getting the actual position of the card within the deck
	int actualPosition = headIndex + position;
	// if the position is within the deck
	if (actualPosition >= 0 && actualPosition < tailIndex) {
		// get the face and suit of the card
		int face = deckOfCards[actualPosition].getFace();
		char suit = deckOfCards[actualPosition].getSuit();
		// return the desired card
		return Card(face,suit);
	}
	else {
		throw runtime_error("That position is not within the deck");
	}
}

//@Author Samuel Mendheim
//randomizes order of cards
void Deck::shuffleDeck() {
	if (!isEmpty()) {
		// for loop to run through the number of cards
		for (int shuffleCounter = 0; shuffleCounter < getNumCards(); shuffleCounter++) {
			// two random variables within the size of the deck to be shuffled
			int firstCard = (rand() % getNumCards()) + headIndex;
			int secondCard = (rand() % getNumCards()) + headIndex;
			// taking both cards and swapping the position
			Card temp = deckOfCards[firstCard];
			deckOfCards[firstCard] = deckOfCards[secondCard];
			deckOfCards[secondCard] = temp;
		}
	}

}

//@Author Nic Grube
//cuts deck
void Deck::cutDeck() throw (runtime_error) {
	// making sure the deck of cards is greater than 10
	if (getNumCards() > 10) {
		// randomly picking a single card within the deck
		int cutDeckCard = rand() % getNumCards();
		// swapping all the elements before the chosen card with the elements after
		for (int currCard = 0; currCard < cutDeckCard; currCard++) {
			Card temp = dealCard();
			addCard(temp);
		}
	}
	else {
		throw runtime_error("Deck is too small to be cut");
	}


}


//@Author Nic Grube
//resets desk based on predetermined set of rules
void Deck::resetDeck() throw (runtime_error) {
	if (deckCapacity == NORMAL_DECK_SIZE) {
		// freeing up the deck and setting all variables to a fresh new deck
		free(deckOfCards);
		headIndex = 0;
		tailIndex = 0;
		deckSize = 0;
		// setting the deck capacity equal to 52
		deckCapacity = NORMAL_DECK_SIZE;
		// malloc enough memory for the new deck
		deckOfCards = (Card*)malloc((NORMAL_DECK_SIZE + 1) * sizeof(Card)); //+1 on deck size for empty slot
		// for loop to run through 4 different suits --> Spaces, Diamonds, Clubs, Hearts
		for (int suitCounter = 0; suitCounter < numSuits; suitCounter++) {
			// for loop running through 13 different cards for each suit
			for (int faceCounter = 0; faceCounter < numCardsInSuit; faceCounter++) {
				switch (suitCounter) {
					// if suit is equal to zero deal out the 13 spades cards
				case 0:
					*(deckOfCards + tailIndex) = Card(faceCounter + 1, 'S');
					break;
					// if suit is equal to one deal out the 13 hearts cards
				case 1:
					*(deckOfCards + tailIndex) = Card(faceCounter + 1, 'D');
					break;
					// if suit is equal to two deal out the 13 clubs cards
				case 2:
					*(deckOfCards + tailIndex) = Card(faceCounter + 1, 'C');
					break;
					// if suit is equal to three deal out the 13 hearts cards
				case 3:
					*(deckOfCards + tailIndex) = Card(faceCounter + 1, 'H');
					break;
				}
				// tail index set to the decksize
				tailIndex++;
				deckSize++;
			}
		}
	}
	else if (0 <= deckCapacity && deckCapacity <= maxDeckCapacity) {
		// free the deck of cards
		free(deckOfCards);
		// malloc memory for a new blank deck
		deckOfCards = (Card*)malloc((deckCapacity + 1) * sizeof(Card));
		// set the variables to an empty deck
		deckSize = 0;
		headIndex = 0;
		tailIndex = 0;
	}
	else {
		throw runtime_error("The deck was unable to be reset");
	}
}


//@Author Nic Grube
//Deep copy constructor
Deck::Deck(const Deck& d) {
	// copying the new deck to everything in the deck
	deckCapacity = d.deckCapacity;
	deckSize = d.deckSize;
	deckCapacity = d.deckCapacity;
	tailIndex = d.tailIndex;
	headIndex = d.headIndex;
	// malloc the amount of memory needed for a new deck
	deckOfCards = (Card*)malloc((deckCapacity + 1) * sizeof(Card));
	for (int currCard = headIndex; currCard < tailIndex; currCard++) {
		// setting all of the elements in the original deck equal to the new deck
		deckOfCards[currCard] = d.deckOfCards[currCard];
	}

}


//@Author Nic Grube
//Deep Assignment Operator overload
Deck& Deck::operator =(const Deck& d) {
	if (this != &d) {
		deckCapacity = d.deckCapacity;
		tailIndex = d.tailIndex;
		headIndex = d.headIndex;
		*deckOfCards = *(d.deckOfCards);

	}
	return *this;
}

//@Author Nic Grube
//Deep Destructor
Deck::~Deck() {
	// freeing up the deck of cards
	free(deckOfCards);
	// setting the pointer equal to NULL
	deckOfCards = NULL;
	// resetting all the variables to an empty deck
	deckSize = 0;
	deckCapacity = 0;
	tailIndex = 0;
	headIndex = 0;
}

//Below are extra methods that were required for testing purposes (at least in our code)
int Deck::getCapacity() {
	return deckCapacity;
}