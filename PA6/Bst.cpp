#include "Bst.h"

/****************************constructor/copy/deconstructor*************************/
Bst::Bst()
{
	char line[25] = "";
	char letter;
	string morse;
	table.open("MorseTable.txt");
	while (!table.eof())
	{
		table.getline(line, 25, ' '); letter = line[0];
		table.getline(line, 25, '\n'); morse = line;
		Line(letter, morse);
	}
	table.close();
}

Bst::Bst(Bst * copy)
{
	copy->root = root;
}

Bst::~Bst()
{
	if (table.is_open())
	{
		table.close();
	}
	deleteT(root);
}
void Bst::deleteT(BstNode * tree)
{
	if (tree)
	{
		deleteT(tree->gLeft());
		deleteT(tree->gRight());
		delete tree;
	}
}

/*********************************************************************************/

/*******************************sets head to root and inserts letter*********************************/
void Bst::sH(BstNode* nH)
{
	root = nH;
}
void Bst::Line(char letter, string morse)
{
	insert(root, letter, morse);
}
void Bst::insert(BstNode* &newNode, char letter, string morse)
{
	if (newNode == nullptr)
	{
		BstNode* pMem = new BstNode(letter, morse);
		newNode = pMem;
	}
	else
	{
		if (letter < newNode->Letter())
		{
			insert(newNode->gLeft(), letter, morse);
		}
		else if (letter > newNode->Letter())
		{
			insert(newNode->gRight(), letter, morse);
		}

	}

}
/***************************************************************************************************/


/**********************************print*****************************************/
void Bst::print()
{
	print(root);
}
void Bst::print(BstNode * tree)
{
	if (tree != nullptr)
	{
		print(tree->gLeft());
		cout << "The Char Is: " << tree->Letter() 
			<< "\tThe Morse Code is: " 
			<< tree->gmCode() << endl;
		print(tree->gRight());
	}
}
BstNode* Bst::gH()
{
	return this->root;
}

/************************************************************************/

/*******************************Search*****************************************/
void Bst::search()
{
	std::locale loc;

	string word;
	int a = 0; int b = 0;
	char line[100];	fstream change;
	change.open("Convert.txt");
	while (!change.eof())
	{
		change >> std::noskipws >> line[a]; 
		if (line[a] >= 97 && line[a] <= 122)
		{
			line[a] = line[a] - 32;
		}
		a++;
	}
	while (b <= a)
	{
		if (line[b] != '\n')
		{
			word = search(root, line[b]);
		}
		else
		{
			cout << endl << "(Echoed to Screen)" << endl;
		}
		b++;
	}
	change.close();
}

string Bst::search(BstNode* tree, char letter)
{
	string morse;

	if (tree != nullptr)
	{
		search(tree->gLeft(), letter);
		search(tree->gRight(), letter);
		if (tree->Letter() == letter)
		{
			morse = tree->gmCode();
			if (tree->Letter() == ' ')
			{
				cout << tree->gmCode() 
					<< "   ";
			}
			else
			{
				cout << tree->gmCode() 
					<< " ";
			}

		}
	}

	return morse;
}

/************************************************************************/