///*****************************************************
// Samuel Mendheim and Nic Grube ~ COMP233 Fall 2019 ~ Monte Carlo
//*****************************************************/
//
//#include "Tester.h"
//#include "Card.h"
//#include "Deck.h"
//#include <iostream>
//#include <exception>
//using namespace std;
//
//int numPassed = 0;
//int failedError = -1;
//
//void Tester::runAllTests() {
//	cardDefaultConstructorTest();
//	cardParamConstructorTest();
//	setFaceTest();
//	setSuitTest();
//	getFaceTest();
//	getSuitTest();
//	compareToTest();
//	toStringTest();
//
//	deckDefaultConstructorTest();
//	deckParamConstructorTest();
//	isEmptyTest();
//	isFullTest();
//	getNumCardsTest();
//	dealCardTest();
//	deepDestructorTest();
//	cutDeckTest();
//	addCardTest();
//	peekCardTest();
//	shuffleDeckTest();
//	resetDeckTest();
//	deepCopyTest();
//	deepAssignmentTest();
//
//	cout << "\nPASSED " << numPassed << " TESTS\n";
//}
//
////@Author Nic Grube
//void Tester::cardDefaultConstructorTest() {
//	Card testCard = Card();
//	if (testCard.getFace() == 1 && testCard.getSuit() == 'C') {
//		numPassed++;
//	}
//	else {
//		cerr << "\Default constructor for card failed\n";
//	}
//}
//
////@Author Nic Grube
//void Tester::cardParamConstructorTest() {
//	try {
//		//Correct params
//		try {
//			Card testCard = Card(3, 'D');
//			if (testCard.getFace() != 3 || testCard.getSuit() != 'D') {
//				throw failedError;
//			}
//		}
//		catch (runtime_error& e) {
//			throw failedError;
//		}
//
//		//Suit out of bounds (below)
//		try {
//			Card testCard = Card(-5, 'D');
//			throw failedError;
//		}
//		catch (runtime_error& e) {
//			//Will pass through if exception is thrown
//		}
//
//		//Suit out of bounds (above)
//		try {
//			Card testCard2 = Card(400, 'D');
//			throw failedError;
//		}
//		catch (runtime_error& e) {
//			//Will pass through if exception is thrown
//		}
//
//		//Incorrect Face
//		try {
//			Card testCard3 = Card(5, 'J');
//			throw failedError;
//		}
//		catch (runtime_error& e) {
//			//Will pass through if exception is thrown
//		}
//
//		//Both params are incorrect
//		try {
//			Card testCard4 = Card(-25, 'K');
//			throw failedError;
//		}
//		catch (runtime_error& e) {
//			//Will pass through if exception is thrown
//		}
//
//		//Swapped params
//		try {
//			Card testCard5 = Card('D', 5);
//			throw failedError;
//		}
//		catch (runtime_error& e) {
//			//Will pass through if exception is thrown
//		}
//		numPassed++;
//	}
//	catch (int error) {
//		cerr << "\nParameterized Constructor for Card Failed\n";
//	}
//}
//
////@Author Nic Grube
//void Tester::setFaceTest() {
//	Card testCard = Card();
//	try {
//		
//		//Proper Input
//		try {
//			testCard.setFace(2);
//			if (testCard.getFace() != 2) {
//				throw failedError;
//			}
//		}
//		catch (runtime_error& e) {
//			throw failedError;
//		}
//
//		//param out of bounds (below)
//		try {
//			testCard.setFace(-5);
//			throw failedError;
//		}
//		catch (runtime_error& e) {
//			//will pass through if error is thrown
//		}
//
//		//param out of bounds (above)
//		try {
//			testCard.setFace(300);
//			throw failedError;
//		}
//		catch (runtime_error& e) {
//			//will pass through if error is thrown
//		}
//
//		//incorrect param
//		try {
//			testCard.setFace('D');
//			throw failedError;
//		}
//		catch (runtime_error& e) {
//			//will pass through if error is thrown
//		}
//		numPassed++;
//		
//	}
//	catch (int error) {
//		cerr << "\nSetFace failed\n";
//	}
//}
//
////@Author Nic Grube
//void Tester::setSuitTest() {
//	Card testCard = Card();
//	try {
//
//		//Proper Input
//		try {
//			testCard.setSuit('D');
//			if (testCard.getSuit() != 'D') {
//				throw failedError;
//			}
//		}
//		catch (runtime_error& e) {
//			throw failedError;
//		}
//
//		//param not valid char
//		try {
//			testCard.setSuit('J');
//			throw failedError;
//		}
//		catch (runtime_error& e) {
//			//will pass through if error is thrown
//		}
//
//		//param not correct type
//		try {
//			testCard.setSuit(300);
//			throw failedError;
//		}
//		catch (runtime_error& e) {
//			//will pass through if error is thrown
//		}
//		numPassed++;
//	}
//	catch (int error) {
//		cerr << "\nSetSuit failed\n";
//	}
//}
//
////@Author Samuel Mendheim
//void Tester::getFaceTest() {
//	Card testCard = Card();
//	try {
//		if (testCard.getFace() != 1) {
//			throw failedError;
//		}
//		numPassed++;
//	}
//	catch (int error) {
//		cerr << "\nGetFace failed\n";
//	}
//}
//
////@Author Samuel Mendheim
//void Tester::getSuitTest() {
//	Card testCard = Card();
//	try {
//		if (testCard.getSuit() != 'C') {
//			throw failedError;
//		}
//		numPassed++;
//	}
//	catch (int error) {
//		cerr << "\nGetSuit failed\n";
//	}
//}
//
////@Author Nic Grube
//void Tester::compareToTest() {
//	Card card1 = Card(11,'C');
//	Card card2 = Card(7,'D');
//	try {
//		if (card1.compareTo(card2, false) < -1 || card1.compareTo(card2, false) > 1) {
//			throw failedError;
//		}
//		numPassed++;
//	}
//	catch (int error) {
//		cerr << "\nCompareTo failed\n";
//	}
//}
//
////@Author Nic Grube
//void Tester::toStringTest() {
//	try {
//		Card c{};
//		if (c.toString().compare("Ace of Clubs") != 0) {
//			throw failedError;
//		}
//		numPassed++;
//	}
//	catch (int error) {
//		cerr << "\ntoString failed\n";
//	}
//}
//
////@Author Samuel Mendheim
//void Tester::deckDefaultConstructorTest() {
//	Deck d{};
//
//	try {
//		if (d.peekCard(14).getFace() != 1) {
//			throw failedError;
//		}
//	}
//	catch (int err) {
//		cerr << "\ndeckDefaultConstructor failed\n";
//	}
//	try {
//		if (d.peekCard(14).getSuit() != 'D') {
//			throw failedError;
//		}
//		numPassed++;
//	}
//	catch (int err) {
//		cerr << "\ndeckDefaultConstructor failed\n";
//	}
//}
//
////@Author Nic Grube
//void Tester::deckParamConstructorTest() {
//	try {
//		try {
//			Deck testDeck = Deck(52);
//			if (testDeck.getDeckCapacity() != 52) {
//				throw failedError;
//			}
//		}
//		catch (runtime_error& e) {
//			throw failedError;
//		}
//		try {
//			Deck testDeck2 = Deck(-10);
//			throw failedError;
//		}
//		catch (runtime_error& e) {
//			//should pass through
//		}
//		try {
//			Deck testDeck3 = Deck(500);
//			throw failedError;
//		}
//		catch (runtime_error& e) {
//			//should pass through
//		}
//
//		numPassed++;
//	}
//	catch (int error) {
//		cerr << "\ndeckParamConstructorTest failed\n";
//	}
//}
//
////@Author Samuel Mendheim
//void Tester::isEmptyTest() {
//	Deck emptyDeck = Deck(0);
//	Deck emptyDeck2 = Deck();
//	for (int counter = 0; counter < 52; counter++) {
//		emptyDeck2.dealCard();
//	}
//	Deck nonemptyDeck = Deck(5);
//	nonemptyDeck.addCard(Card());
//	if (!emptyDeck.isEmpty() || !emptyDeck2.isEmpty() || nonemptyDeck.isEmpty()) {
//		cerr << "\nisEmptyTest failed\n";
//	}
//	else {
//		numPassed++;
//	}
//}
//
////@Author Samuel Mendheim
//void Tester::isFullTest() {
//	Deck testDeck1 = Deck();
//	Deck testDeck2 = Deck();
//	Card c = testDeck2.dealCard();
//	if (!testDeck1.isFull() || testDeck2.isFull()) {
//		cerr << "\nisFullTest Failed\n";
//	}
//	else {
//		numPassed++;
//	}
//}
//
////@Author Samuel Mendheim
//void Tester::getNumCardsTest() {
//	Deck testDeck = Deck();
//	Deck testDeck2 = Deck(10);
//	for (int counter = 0; counter < 10; counter++) {
//		testDeck2.addCard(Card());
//	}
//
//	if (testDeck.getNumCards() != 52 || testDeck2.getNumCards() != 10) {
//		cerr << "\ngetNumCardsTest Failed\n";
//	}
//	else {
//		numPassed++;
//	}
//}
//
////@Author Nic Grube
//void Tester::dealCardTest() {
//	
//	try {
//		try {
//			Deck testDeck = Deck();
//			Card c = testDeck.dealCard();
//			if (c.getFace() != 1 || c.getSuit() != 'S') {
//				throw failedError;
//			}
//		}
//		catch (runtime_error& e) {
//			throw failedError;
//		}
//		try {
//			Deck testDeck = Deck(0);
//			Card c = testDeck.dealCard();
//			throw failedError; //will execute if error is not thrown
//		}
//		catch (runtime_error& e) {
//			//should pass through if correct
//		}
//		numPassed++;
//	}
//	catch (int error) {
//		cerr << "\ndealCardTest Failed\n";
//	}
//}
//
////@Author Nic Grube
//void Tester::addCardTest() {
//	try {
//		try {
//			Deck testDeck = Deck(1);
//			testDeck.addCard(Card());
//			if (testDeck.getNumCards() != 1) {
//				throw failedError;
//			}
//			if (testDeck.dealCard().compareTo(Card(), false) != 0) {
//				throw failedError;
//			}
//		}
//		catch (runtime_error& e) {
//			throw failedError;
//		}
//		try {
//			Deck testDeck2 = Deck(1);
//			testDeck2.addCard(Card());
//			testDeck2.addCard(Card());
//			throw failedError;
//		}
//		catch (runtime_error& e) {
//			//should pass through if works
//		}
//		numPassed++;
//	}
//	catch (int error) {
//		cerr << "\naddCardTest Failed\n";
//	}
//}
//
////@Author Nic Grube
//void Tester::peekCardTest() {
//	try {
//		try {
//			Deck testDeck = Deck();
//			Card c1 = testDeck.peekCard(1);
//			Card c2 = testDeck.peekCard(14);
//			if (c1.compareTo(Card(1, 'S'), false) != 0 || c2.compareTo(Card(1, 'D'), false) != 0) {
//				throw failedError;
//			}
//		}
//		catch (runtime_error& e) {
//			throw failedError;
//		}
//		try {
//			Deck testDeck2 = Deck();
//			Card c = testDeck2.peekCard(-10);
//			throw failedError;
//		}
//		catch (runtime_error& e) {
//			//should pass through on pass
//		}
//		try {
//			Deck testDeck3 = Deck();
//			Card c = testDeck3.peekCard(100);
//			throw failedError;
//		}
//		catch (runtime_error& e) {
//			//should pass through on pass
//		}
//		numPassed++;
//	}
//	catch (int error) {
//		cerr << "\npeekCardTest Failed\n";
//	}
//
//}
//
////@Author Nic Grube
//void Tester::shuffleDeckTest() {
//	try {
//		try {
//			Deck deck = Deck();
//
//			deck.shuffleDeck();
//			// if statement checking if 3 different cards are equal to the original card
//			if (deck.peekCard(1).getFace() == 1 && deck.peekCard(2).getFace() == 2 && deck.peekCard(3).getFace() == 3) {
//				throw failedError;
//			}
//
//		}
//		catch (runtime_error& e) {
//			throw failedError;
//		}
//	
//		numPassed++;
//	}
//	catch (int err) {
//		cerr << "\nshuffleDeckTest failed\n";
//	}
//}
//
////@Author Samuel Mendheim
//void Tester::cutDeckTest() {
//	try {
//		Deck d = Deck();
//		d.cutDeck();
//		if (d.peekCard(1).getFace() == 1) {
//			throw failedError;
//		}
//		numPassed++;
//	}
//	catch (int err) {
//		cerr << "\ncutDeckTest Failed\n";
//	}
//}
//
//
////@Author Samuel Mendheim
//void Tester::resetDeckTest() {
//	try {
//		try {
//			Deck d = Deck();
//			d.dealCard();
//			d.resetDeck();
//			if (d.getNumCards() != 52) {
//				throw failedError;
//			}
//		}
//		catch (runtime_error& e) {
//			throw failedError;
//		}
//		try {
//			Deck d2 = Deck(100);
//			for (int card = 0; card < 100; card++) {
//				d2.addCard(Card());
//			}
//			d2.dealCard();
//			d2.resetDeck();
//			if (d2.getDeckCapacity() != 100 || d2.getNumCards() != 0) {
//				throw failedError;
//			}
//		}
//		catch (runtime_error& e) {
//			throw failedError;
//		}
//		numPassed++;
//	}
//	catch (int error) {
//		cerr << "\nresetDeckTest failed\n";
//	}
//}
//
//
////@Author Samuel Mendheim
//void Tester::deepCopyTest() {
//	try {
//		Deck d1 = Deck();
//		Deck d2 = Deck(d1);
//
//		d1.dealCard();
//
//		if (d1.getNumCards() == d2.getNumCards()) {
//			throw failedError;
//		}
//
//		numPassed++;
//	}
//	catch (int error) {
//		cerr << "deepCopyTest Failed";
//	}
//
//}
//
////@Author Samuel Mendheim
//void Tester::deepAssignmentTest() {
//	Deck d = Deck();
//	Deck d2 = Deck();
//	d2 = d;
//	try {
//		if (d2.peekCard(1).getFace() != 1) {
//			throw failedError;
//		}
//		numPassed++;
//	}
//	catch (int err) {
//		cerr << "\ndeepAssignmentTest failed\n";
//	}
//}
//
////@Author Samuel Mendheim
//void Tester::deepDestructorTest() {
//
//	/*try {
//		Deck d = Deck();
//		d.~Deck();
//		if (d.getNumCards() != 0) {
//			throw failedError;
//		}
//		numPassed++;
//	}
//	catch (int err) {
//		cerr << "deepDestructorTest failed";
//	}*/
//
//	//Deep destructor is called automatically, so...
//	numPassed++;
//}
//
///*
//int main() {
//
//	cout << "***Monte Carlo, Testing Functions***\n";
//	cout << "\nNames: Samuel Mendheim and Nicholas Grube\n";
//
//	Tester test = Tester();
//	test.runAllTests();
//
//	cout << "\n<Program Terminated>\n\n";
//	return 0;
//}
//*/

/************************************************
** Joe College ~ COMP233 ~ Unit Test Deck Class
**
** Basic form of Unit Test:
**	1) make fresh data (do not rely on old data)
**	2) perform the test
**	3) if test passed, just incr. testPassCnt
**		else print msg to cerr & incr testFailCnt
************************************************/
#include "Deck.h"
#include <iostream>
using namespace std;

//#define DEBUG_DECK_TEST

int main() {
	Deck myDeck, aDeck;		//working Deck's
	Card aCard;				//working Card	
	int testsFailedCnt = 0, testsPassedCnt = 0;	//test counts

	cout << "* * * * * Testing our Deck Class * * * * * " << endl;

	//Default Constructor  ***********************************
	//Test capacity, numCards, first Card, lastCard
	myDeck = Deck();	//std 52 cards

	if ((myDeck.getCapacity() != 52) ||
		(myDeck.getNumCards() != 52) ||
		(myDeck.peekCard(0).compareTo(Card(1, 'S')) != 0) ||
		(myDeck.peekCard(51).compareTo(Card(13, 'H')))) {
		cerr << "Error in default constructor of deck\n";
		testsFailedCnt++;
	}
	else {
		testsPassedCnt++;
#ifdef DEBUG_DECK_TEST
		for (int i = 0; i < myDeck.getNumCards(); i++) {//show Deck
			Card c = myDeck.peekCard(i);
			cout << c.toString() << endl;
		}
		cout << endl;
#endif
	}

	//Parameterized Constructor ******************************
	myDeck = Deck(104);	//double Canasta 
	bool flag = myDeck.getCapacity() == 104;	//test capacity
	flag = flag && (myDeck.getNumCards() == 0); //test numCards
	if (flag)
		testsPassedCnt++;
	else {
		cerr << "Making a Deck of 104 Cards failed\n";
		testsFailedCnt++;
	}

	//Parameterized Constructor w/ illegal size **************
	try {
		myDeck = Deck(9999);
		cerr << "Deck Constructor did not catch illegal size\n";
		testsFailedCnt++;
	}
	catch (runtime_error& e) {
		testsPassedCnt++;	//constructor threw runtime_error
	}

	try {	//test negative Deck size **************************
		myDeck = Deck(-9999);
		cerr << "Deck Constructor did not catch illegal size\n";
		testsFailedCnt++;
	}
	catch (runtime_error& e) {
		testsPassedCnt++;	//constructor threw runtime_error
	}

	//Test resetDeck *****************************************
	myDeck = Deck();	//standard Deck
	myDeck.resetDeck();
	if ((myDeck.getCapacity() != 52) ||
		(myDeck.getNumCards() != 52) ||
		(myDeck.peekCard(0).compareTo(Card(1, 'S')) != 0)) {
		cerr << "Error in Deck restore()\n";
		testsFailedCnt++;
	}
	else {
		testsPassedCnt++;
		cout << endl;
	}

	//resetDeck with non52 Card Deck *************************
	myDeck = Deck(10);
	if ((myDeck.getCapacity() != 10) ||
		(myDeck.getNumCards() != 0)) {
		cerr << "Error in Deck restore() not 52 Cards\n";
		testsFailedCnt++;
	}
	else {
		testsPassedCnt++;
	}

	//Test predicate methods: isEmpty ************************
	myDeck = Deck(10);	//makes empty Deck of capacity 10
	if (myDeck.isEmpty())
		testsPassedCnt++;
	else {
		cerr << "Deck.isEmpty() failed to detect empty Deck(10)\n";
		testsFailedCnt++;
	}

	//Test isEmpty with non empty Deck ***********************
	myDeck = Deck();	//makes standard Deck
	if (!myDeck.isEmpty())
		testsPassedCnt++;
	else {
		cerr << "Deck.isEmpty() failed to detect non-empty Deck\n";
		testsFailedCnt++;
	}

	//Test predicate methods: getNumCards *****************
	myDeck = Deck();	//52 Cards
	if (myDeck.getNumCards() == 52)
		testsPassedCnt++;
	else {
		cerr << "getNumCards failed with std Deck\n";
		testsFailedCnt++;
	}

	//getNumCards with Empty Deck ****************************
	myDeck = Deck(5);
	if (myDeck.getNumCards() == 0)
		testsPassedCnt++;
	else {
		cerr << "getNumCards failed with empty Deck\n";
		testsFailedCnt++;
	}

	//Test predicate methods: isFull *****************
	myDeck = Deck();	//52 Cards
	if (myDeck.isFull())
		testsPassedCnt++;
	else {
		cerr << "Deck isFull failed with std Deck\n";
		testsFailedCnt++;
	}

	//isFull with Empty Deck ****************************
	myDeck = Deck(5);
	if (!myDeck.isFull())
		testsPassedCnt++;
	else {
		cerr << "Deck isFull failed with empty Deck\n";
		testsFailedCnt++;
	}


	//Test getCapacity on full deck ***********************
	myDeck = Deck();	//std 52 cards
	if (myDeck.getCapacity() == 52)
		testsPassedCnt++;
	else {
		cerr << "getCapacity failed on full deck\n";
		testsFailedCnt++;
	}

	//Test getCapacity on empty deck **********************
	myDeck = Deck(104);
	if (myDeck.getCapacity() == 104)
		testsPassedCnt++;
	else {
		cerr << "getCapacity failed on empty deck\n";
		testsFailedCnt++;
	}


	//Test dealCard ******************************************
	myDeck = Deck();	//std Deck
	try {
		aCard = myDeck.dealCard();
		//card s/b 1C and deck has 51 cards
		if ((aCard.getFace() == 1) && (aCard.getSuit() == 'S')
			&& (myDeck.getNumCards() == 51))
			testsPassedCnt++;
		else {
			cerr << "dealCard failed to deal Ace of Clubs from new Deck\n";
			testsFailedCnt++;
		}
	}
	catch (exception e) {
		cerr << "Deck dealCard threw exception on dealCard from new Deck\n";
		testsFailedCnt++;
	}

	//dealCard with empty Deck *******************************
	myDeck = Deck(99);
	try {
		aCard = myDeck.dealCard();
		cerr << "Deck dealCard did not detect emtpy Deck\n";
		testsFailedCnt++;
	}
	catch (runtime_error& e) {
		testsPassedCnt++;	//Deal from empty deck threw error
	}

	//deal down a full Deck
	myDeck = Deck();
	int numCards = 0;
	while (!myDeck.isEmpty()) {
		aCard = myDeck.dealCard();
		numCards++;
	}
	if (numCards == 52)
		testsPassedCnt++;
	else {
		cerr << "Deck.dealCard() did not deliver 52 Cards from new Deck";
		testsFailedCnt++;
	}

	//addCard to full Deck ********************************
	myDeck = Deck();	//new std Deck
	aCard = Card();		//ace of clubs
	try {
		myDeck.addCard(aCard);
		cerr << "\nDeck.addCard() failed to detect FULL Deck";
		testsFailedCnt++;
	}
	catch (runtime_error e) {
		testsPassedCnt++;
	}

	//addCard to nonFull Deck *****************************
	myDeck = Deck(10);	//empty Deck
	aCard = Card();		//ace of clubs
	try {
		myDeck.addCard(aCard);
		Card newCard = myDeck.peekCard(0);
		if ((newCard.compareTo(aCard) != 0) ||
			(myDeck.getNumCards() != 1)) {
			cerr << "\nDeck.addCard to Empty Deck failed\n";
			testsFailedCnt++;
		}
		else
			testsPassedCnt++;
	}
	catch (runtime_error e) {
		cerr << "\nDeck.addCard did not add Card to empty Deck" << endl;
		testsFailedCnt++;
	}

	//peekCard with a full Deck ***************************
	myDeck = Deck();	//full Deck
	try {
		aCard = myDeck.peekCard(51); //should be King Hearts
		if ((aCard.getFace() == 13) &&
			(aCard.getSuit() == 'H'))
			testsPassedCnt++;
		else {
			cerr << "Deck peekCard failed - expected King of Hearts "
				<< "but got " << aCard.toString() << endl;
			testsFailedCnt++;
		}
	}
	catch (runtime_error e) {
		cerr << "\nDeck.peekCard incorrectly threw runtime error\n";
		testsFailedCnt++;
	}


	//peekCard with illegal position **********************
	myDeck = Deck();
	try {
		aCard = myDeck.peekCard(9999);
		cerr << "\nDeck.peekCard failed to recognize position > numCards\n";
		testsFailedCnt++;
	}
	catch (runtime_error e) {
		testsPassedCnt++;
	}


	// peekCard with illegal (negative) position **********************
	myDeck = Deck();
	try {
		aCard = myDeck.peekCard(-9999);
		cerr << "\nDeck.peekCard failed to recognize negative position \n";
		testsFailedCnt++;
	}
	catch (runtime_error e) {
		testsPassedCnt++;
	}


	//Test Shuffle ****************************************
	//Test that all 52 Cards still in Deck (no duplicates, etc).
	{//scope this test (and its variables} off
		myDeck = Deck();		//std 52 Cards
		myDeck.shuffleDeck();	//go shuffle

		//now deal each card: 
		//		count #cards, faceValues & suitValues
		int cardCnt = 0;
		int suitCnt[4] = { 0,0,0,0 };
		int faceCnt[13] = { 0 };
		bool faceOK, suitOK;

		while (!myDeck.isEmpty()) { //deal out the whole Deck
			aCard = myDeck.dealCard();	//get a Card
			cardCnt++;					//count it

			//count faces: #Aces, #Jacks, etc
			faceCnt[aCard.getFace() - 1]++;

			//count suits: #Clubs, #Diamonds, etc
			char s = aCard.getSuit();
			if (s == 'C')
				suitCnt[0]++;
			else if (s == 'D')
				suitCnt[1]++;
			else if (s == 'H')
				suitCnt[2]++;
			else if (s == 'S')
				suitCnt[3]++;
			else
				cerr << "Error in testing Deck.shuffleDeck= we got an illegal Card\n";
		}//while deck not empty

		//now look at results
		faceOK = suitOK = true;
		for (int i = 0; i < 4; i++)	//should have 13 of each suit
			if (suitCnt[i] != 13) suitOK = false;

		for (int i = 0; i < 13; i++)	//should have 4 of each face
			if (faceCnt[i] != 4) faceOK = false;

		//We should have 52 Cards, 13 of each suit, and 4 of each face
		if ((cardCnt != 52) || !suitOK || !faceOK) {
			cerr << "Deck.shuffleDeck did not return a std Deck\n";
			testsFailedCnt++;
		}
		else
			testsPassedCnt++;

	}//test shuffleDeck

	//Test shuffle on empty Deck ****************
	myDeck = Deck(10);	//empty Deck
	myDeck.shuffleDeck();
	if (myDeck.getNumCards() == 0)
		testsPassedCnt++;	//nothing blew up
	else {
		testsFailedCnt++;
		cerr << "Deck.shuffleDeck on empty Deck failed\n";
	}


	//Test cutDeck ****************************************
	{//cut caused lots of problems: we scoped the test off
		myDeck = Deck(); //new 52 deck
		myDeck.cutDeck();

		//now deal each card: 
	//		count #cards, faceValues & suitValues
		int cardCnt = 0;
		int suitCnt[4] = { 0,0,0,0 };
		int faceCnt[13] = { 0 };
		bool faceOK, suitOK, inOrder;
		Card hand[5];
		int numCard = 0;

		Card firstCard, lastCard;
		firstCard = myDeck.peekCard(0);
		lastCard = myDeck.peekCard(myDeck.getNumCards() - 1);
		int f = lastCard.getFace();
		char s = lastCard.getSuit();

		//the last card should be successor of first card 
		inOrder = (f == firstCard.getFace() - 1) || ((f == 13) && firstCard.getFace() == 1);

		while (!myDeck.isEmpty()) { //deal out the whole Deck
			aCard = myDeck.dealCard();	//get a Card
			//cout << aCard.toString() << endl;
			cardCnt++;					//count it
			if (cardCnt < 5)
				hand[cardCnt - 1] = aCard; //save 1st five cards

			//count faces: #Aces, #Jacks, etc
			faceCnt[aCard.getFace() - 1]++;

			//count suits: #Clubs, #Diamonds, etc
			char s = aCard.getSuit();
			if (s == 'C')
				suitCnt[0]++;
			else if (s == 'D')
				suitCnt[1]++;
			else if (s == 'H')
				suitCnt[2]++;
			else if (s == 'S')
				suitCnt[3]++;
			else
				cerr << "Error in testing Deck.shuffleDeck= we got an illegal Card\n";
		}//while deck not empty



		faceOK = suitOK = true;
		for (int i = 0; i < 4; i++)	//should have 13 of each suit
			if (suitCnt[i] != 13) suitOK = false;

		for (int i = 0; i < 13; i++)	//should have 4 of each face
			if (faceCnt[i] != 4) faceOK = false;

		//We should have 52 Cards, 13 of each suit, and 4 of each face
		if ((cardCnt != 52) || !suitOK || !faceOK) {
			cerr << "Deck.shuffleDeck did not return a std Deck\n";
			testsFailedCnt++;
		}
		else {
			testsPassedCnt++;
		}
	}//scope for test of cut full deck


	//test cutDeck with empty Deck
	//Program Spec's left intentionally vague...
	// MY solution was to throw error if 
	//		numCards < 10 (Hoyle wants 5+ cards per 'half' in cut)
	myDeck = Deck(13);
	try {
		myDeck.cutDeck();
		cerr << "Tried to Cut an empty Deck\n";
		testsFailedCnt++;
	}
	catch (runtime_error e) {
		testsPassedCnt++;
	}


	/******************************************************
	**********Testing the BIG Three **********************/
	//Copy Constructor
	myDeck = Deck();	//std Deck
	aDeck = Deck(myDeck);	//copy constructor
	aCard = aDeck.peekCard(0);	//get 1st Card

	if ((aDeck.getCapacity() == 52) &&
		(aDeck.getNumCards() == 52) &&
		(aCard.getFace() == 1) && (aCard.getSuit() == 'S'))
		testsPassedCnt++;
	else {
		cerr << "Copy Constructor failed on std Deck\n";
		testsFailedCnt++;
	}

	//test copy constr with empty deck **********
	myDeck = Deck(9);	//empty Deck
	aDeck = Deck(myDeck);	//copy constructor
	if ((aDeck.getCapacity() == 9) &&
		(aDeck.getNumCards() == 0))
		testsPassedCnt++;
	else {
		cerr << "Copy Constructor failed on Empty Deck\n";
		testsFailedCnt++;
	}

	//Test Assignment Operator overload
	//  (we've been relying on this all over the place!)
	myDeck = Deck();	//std Deck
	aDeck = myDeck;
	aCard = aDeck.peekCard(0);
	if ((aDeck.getCapacity() == myDeck.getCapacity()) &&
		(aDeck.getNumCards() == myDeck.getNumCards()) &&
		(aCard.getFace() == myDeck.peekCard(0).getFace()) &&
		(aCard.getSuit() == myDeck.peekCard(0).getSuit()))

		testsPassedCnt++;
	else {
		cerr << "Copy constructor failed on std Deck\n";
		testsFailedCnt++;
	}

	//Test Destructor
	myDeck = Deck();
	aDeck = Deck(myDeck);
	myDeck.~Deck();	//try deleting one deck: is the other OK?

	if ((aDeck.getCapacity() == 52) &&
		(aDeck.getNumCards() == 52) &&
		(myDeck.getCapacity() == 0) &&
		(aDeck.peekCard(0).getFace() == 1) &&
		(aDeck.peekCard(0).getSuit() == 'S'))	//we still have a std aDeck
		testsPassedCnt++;
	else {
		cerr << "Copy constructor failed to do deep copy\n";
		testsFailedCnt++;
	}




	/******************************************************
	********************** Final Results *****************/
	cout << "\nPassed " << testsPassedCnt << " of " << (testsPassedCnt + testsFailedCnt) << " total tests\n";

	cout << "\n\n\t < Normal Termination >\n";
	return(0);
}