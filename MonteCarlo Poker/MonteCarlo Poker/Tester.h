/*****************************************************
 Samuel Mendheim and Nic Grube ~ COMP233 Fall 2019 ~ Monte Carlo
*****************************************************/

#pragma once
class Tester
{
public:

	void runAllTests();

	void cardDefaultConstructorTest();
	void cardParamConstructorTest();
	void setFaceTest();
	void setSuitTest();
	void getFaceTest();
	void getSuitTest();

	
	void compareToTest();
	void toStringTest();

	void deckDefaultConstructorTest();
	void deckParamConstructorTest();
	void isEmptyTest();
	void isFullTest();
	void getNumCardsTest();
	void dealCardTest();
	void addCardTest();
	void peekCardTest();
	void shuffleDeckTest();
	void cutDeckTest();
	void resetDeckTest();
	void deepCopyTest();
	void deepAssignmentTest();
	void deepDestructorTest();
};

//int main();
