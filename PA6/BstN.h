
#pragma once
#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

/******************************getter/setter/constructor/destructor**********************************/
class BstNode
{
public:
	BstNode();
	BstNode(char FindLetter, string Morse); 
	~BstNode();
	void setLetter(char const input);
	void setMorse(string const input);
	void mL(BstNode* const MoveLeft);
	void mR(BstNode* const MoveRight);
	char Letter() const;
	string gmCode() const;
	BstNode*& gLeft();
	BstNode*& gRight();
private:
	char nL; //L=Letter
	string Mo;  //short for Morse is all
	BstNode* Left;
	BstNode* Right;
};

/*************************************************************************************************************/