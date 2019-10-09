/*****************************************************
 Samuel Mendheim and Nic Grube ~ COMP233 Fall 2019 ~ Monte Carlo
*****************************************************/

#include "Card.h"
#include <stdexcept>
using namespace std;

//@Author Samuel Mendheim
//Default Constructor
Card::Card() {
	face = 1; //Ace
	suit = 'C'; //Clubs
}

//@Author Samuel Mendheim
//Parameterized Constructor
Card::Card(int f, char s) throw (runtime_error) {

	//Call mutators to set the values to given parameters
	setFace(f);
	setSuit(s);
}

//@Author Samuel Mendheim
//Mutator (Setter) for face
void Card::setFace(int f) throw (runtime_error) {

	//if-else statement is used for bound-checking
	if (f > 0 && f < 14) {
		face = f;
	}
	else {
		throw runtime_error("Card is out of bounds");
	}
}

//@Author Samuel Mendheim
//Mutator (Setter) for suit
void Card::setSuit(char s) {

	//if-else statement to check for valid parameter
	if (s == 'C' || s == 'S' || s == 'H' || s == 'D') {
		suit = s;
	}
	else {
		throw runtime_error("Suit is not valid");
	}
}

//@Author Nic Grube
//Accessor (Getter) for face
int Card::getFace() {
	return face;
}

//@Author Nic Grube
//Accessor (Getter) for suit
char Card::getSuit() {
	return suit;
}

//@Author Samuel Mendheim
//Comparer for cards
int Card::compareTo(Card other, bool aceIsHigh) {
	if (aceIsHigh) {
		if (Card::getFace() == other.getFace()) {
			return 0;
		}
		else if (Card::getFace() == 1) { //Calling card is smaller than param
			return 1;
		}
		else if (other.getFace() == 1) {
			return -1;
		}
		else if (Card::getFace() < other.getFace()) { //Calling card is equal to param
			return -1;
		}
		else { //Calling card is greater than param
			return 1;
		}
	}

	else {
		if (Card::getFace() < other.getFace()) { //Calling card is smaller than param
			return -1;
		}
		else if (Card::getFace() == other.getFace()) { //Calling card is equal to param
			return 0;
		}
		else { //Calling card is greater than param
			return 1;
		}
	}
	
}

//@Author Samuel Mendheim
//toString method for cards
std::string Card::toString() {
	string f = ""; //f is for face
	string s = ""; //s is for suit
	string output; //output to be returned

	//Switch statement for setting the face part of string
	switch (Card::getFace()) {
	case 1: f = "Ace";
		break;
	case 2: f = "Two";
		break;
	case 3: f = "Three";
		break;
	case 4: f = "Four";
		break;
	case 5: f = "five";
		break;
	case 6: f = "Six";
		break;
	case 7: f = "Seven";
		break;
	case 8: f = "Eight";
		break;
	case 9: f = "Nine";
		break;
	case 10: f = "Ten";
		break;
	case 11: f = "Jack";
		break;
	case 12: f = "Queen";
		break;
	case 13: f = "King";
		break;
	}

	//Switch statement for setting suit part of string
	switch (Card::getSuit()) {
	case 'C': s = "Clubs";
		break;
	case 'S': s = "Spades";
		break;
	case 'H': s = "Hearts";
		break;
	case 'D': s = "Diamonds";
		break;
	}

	output = f + " of " + s; //Create final string to be returned

	return output;
}


