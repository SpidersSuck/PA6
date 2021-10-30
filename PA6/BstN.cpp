#include "BstN.h"

BstNode::BstNode()
{
	this->nL = ' ';
	this->Mo = "";
	this->Left = nullptr;
	this->Right = nullptr;
}
BstNode::BstNode(char FindLetter, string Morse)
{
	this->nL = FindLetter;
	this->Mo = Morse;
	this->Left = nullptr;
	this->Right = nullptr;
}
BstNode::~BstNode()
{
}
void BstNode::setLetter(char const input)
{
	this->nL = input;
}
void BstNode::mR(BstNode* const MoveRight)
{
	this->Right = MoveRight;
}
char BstNode::Letter() const
{
	return this->nL;
}
string BstNode::gmCode() const
{
	return this->Mo;
}
BstNode*& BstNode::gLeft()
{
	return this->Left;
}
BstNode*& BstNode::gRight()
{
	return this->Right;
}
void BstNode::setMorse(string const input)
{
	this->Mo = input;
}
void BstNode::mL(BstNode* const MoveLeft)
{
	this->Left = MoveLeft;
}


