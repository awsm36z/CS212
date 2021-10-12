#include "TreeSet.h"

// CS212, Spring 2021, Program #10
// W.P. Iverson, instructor
int main()
{
	// Create a tree for strings
	//set<string> tree;  // STL example
	TreeSet<string> tree;

	// Add elements to the tree
	tree.insert("Kansas");
	tree.insert("Colorado");
	tree.insert("Maine");
	tree.insert("Alaska");
	tree.insert("Kansas");

	// Create an iterator from this set, then add Alabama
	Iterator<string> iter = tree.begin();
	//set<string>::iterator iter = tree.begin(); // STL example
	tree.insert("Alabama");

	// iterate through tree
	while (iter != tree.end()) 
	{
		cout << *iter << "   ";
		++iter;
	}
	cout << endl;  // Alabama is missing!!!!

	// iterate again
	for (iter = tree.begin(); iter != tree.end(); ++iter)
	{
		cout << *iter << "   ";
	}
	cout << endl;  // Alabama is in Tree!!!
	return 0;
}