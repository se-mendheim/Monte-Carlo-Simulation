/*****************************************************
Nic Grube ~ COMP233 Fall 2019 ~ Monte Carlo
*****************************************************/
/*
#include "MonteCarloSimulation.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Returns an integer, 1 if there is a two pair, 0 otherwise
int MonteCarloSimulation::checkTwoPair() {

	//Variable Dictionary
	int listOfCards[13]; //Increments position in this list based on face value of card
	int numPairs = 0; //Tracks the number of pairs in the hand
	int isThereTwoPair = 0; //return value -> 1 if there 2 pairs, 0 otherwise
	Deck deckOfCards = Deck(); //Deck that hand will be constructed from
	Deck hand = Deck(5); //Hand of cards
	int randomIntegers[5]; //Will contain 5 random, unique integers
	int uniqueFlag = 0; //used to signify uniqueness

	for (int counter = 0; counter < 13; counter++) {
		listOfCards[counter] = 0; //fill with zeros since hand is empty
	}

	for (int counter = 0; counter < 5; counter++) {
		randomIntegers[counter] = -1; //fills array with -1 so that I am not comparing to null below
	}

	for (int numRand = 0; numRand < 5; numRand++) { //cycle through array, generating 5 rand ints
		int loopControl = 1; //used for loop control

		while (loopControl == 1) {
			int position = rand() % 52; //generates int in [0..51]
			uniqueFlag = 1; //Assume uniqueness

			for (int counter = 0; counter < 5; counter++) { //compare position to all other positions
				if (position == randomIntegers[counter]) {
					uniqueFlag = 0; //if position is already in randomInts, then its not unique position
				}
			}

			if (uniqueFlag == 1) { //executes if position is not already in randomIntegers
				randomIntegers[numRand] = position;
				loopControl = 0; //end the loop so next random int can be generated
			}
		}


	}

	//Get 5 cards from deck -> add to the hand and increment listOfCards to keep track of face values
	for (int randIntIndex = 0; randIntIndex < 5; randIntIndex++) {
		Card c = deckOfCards.peekCard(randomIntegers[randIntIndex]); //Get card from deck at random position
		hand.addCard(c); //add Card from deck to hand
		int faceValue = c.getFace();
		listOfCards[faceValue - 1] = listOfCards[faceValue - 1] + 1; //Increment array that keeps track of numCards of same face
	}

	//Check for the number of pairs in the hand
	for (int card = 0; card < 13; card++) {
		if (listOfCards[card] == 2) {
			numPairs++;
		}
	}

	if (numPairs == 2) {
		isThereTwoPair = 1;
	}


	return isThereTwoPair;
}


int main() {
	cout << "\nNicholas Grube ~ COMP 233A ~ Monte Carlo Simulation\n";
	cout << "This program will run a Monte Carlo Simulation on different numbers of hands.\n\n";
	MonteCarloSimulation sim = MonteCarloSimulation();
	cout << "Starting Simulation...\n\n";

	//Headings of table
	cout << left << setw(25) << "# Hands" << setw(25) << "# Two-Pairs";
	cout << setw(25) << "% Two-Pair" << "\n";

	//run through the simulation with different number of hands each time
	for (int numRuns = 512; numRuns <= pow(2, 24); numRuns = numRuns*2) { //512, 1024, ...
		int numTwoPairs = 0;
		for (int count = 0; count < numRuns; count++) {
			if (sim.checkTwoPair() == 1) { //check for if each hand has a two-pair
				numTwoPairs++;
			}
		}
		float percentage = ((double)numTwoPairs / numRuns) * 100;

		//print out rows of table
		cout << left << setw(25) << numRuns << setw(25) << numTwoPairs;
		cout << setw(25) << setprecision(3) << percentage << "\n";
	}
	
	cout << "\n<Program terminated>\n";


	return 0;
}
*/