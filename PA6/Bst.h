#pragma once
#include "BstN.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <locale>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::fstream;

class Bst
{
public:
	/******************************constructor/destructor**********************************/
	Bst();
	Bst(Bst* copy);
	~Bst();
	void deleteT(BstNode * tree);

	/*************************************************************************************************************/
	/*****************************print/search/insert letter/ H= head****************************************************/
	void print();
	void print(BstNode* tree);
	void search();
	string search(BstNode* tree, char letter);
	void sH(BstNode* nH);  
	void Line(char letter, string morse);
	void insert(BstNode* &newNode, char letter, string morse);
	BstNode* gH();
private:
	BstNode *root;
	fstream table;
};
/*************************************************************************************************************/

