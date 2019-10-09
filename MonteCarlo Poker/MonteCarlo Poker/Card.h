/*****************************************************
 Samuel Mendheim and Nic Grube ~ COMP233 Fall 2019 ~ Monte Carlo
*****************************************************/

#pragma once
#include <stdexcept>

class Card {
private:
	int face; //[1..13]
	char suit; //[C D H S]

public:

	//Default Constructor -> will generate Ace of Clubs
	Card();

	//Paramterized Constructor -> throws error if parameter is out of bounds
	Card(int f, char s);

	//Set of Mutators
	void setFace(int f);
	void setSuit(char s);

	//Set of Accessors
	int getFace();
	char getSuit();

	/* 2nd param is for if ace is considered high card
	returns:
	neg if calling card is smaller than param
	zero if same face value
	pos if calling card is larger than param*/
	int compareTo(Card other, bool aceIsHigh = false);

	//Return appropriate stringe value of card (e.g. "Ace of Clubs")
	std::string toString();
};