// Original code from Daniel Liang (2003)
// now animated at yongdanielliang.github.io/animation/web/LinkedList.html
// 
// Extensively modified by W.P. Iverson
// Bellevue College, May 2020
// for CS212

#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

int main()
{
	// Create a list for strings
	LinkedList<string> list;
	list.add("Bellevue");
	list.add("Tofino");
	list.add("Newcastle");
	list.add("Cle Elum");
	list.add("Pullman");

	// Create another list for strings
	LinkedList<string> list2;
	list2.add("Bellevue");
	list2.add("Ellensburg");
	list2.add("Pullman");
	list2.add("Boston");
	list2.add("Tacoma");

	LinkedList<string> list1(list); // copy constructor
	cout << "list1: ";
	list1.printList();
	cout << "list2: ";
	list2.printList();

	list1.addAll(list2); // 1. adds all of list2 into list1
	cout << "list is : ";
	list.printList();
	cout << "After list1.addAll(list2), list1 is ";
	list1.printList();
	cout<< "size is: " << list1.getSize();

	list1 = list;  // 5. needs to copy all list data (deep copy)
	cout << "list1: ";
	list1.printList();
	cout << "list2: ";
	list2.printList();

	list1.removeAll(list2); // 2. removes from list1, the data that appears in list2
	cout << "After list1.removeAll(list2), list1 is ";
	list1.printList();
	list1 = list; // 5. again, need a deep copy
	cout << "list1: ";
	list1.printList();
	cout << "list2: ";
	list2.printList();

	list1.retainAll(list2); // 3. list1 only keeps elements that are also in list2
	cout << "After list1.retainAll(list2), list1 is ";
	list1.printList();
	list1 = list;
	cout << "list1: ";
	list1.printList();
	cout << "list2: ";
	list2.printList();

	list1 = list1 + list2; // 4. add lists together is called union
	cout << "After list1 = list1 + list2, list1 is ";
	list1.printList();
	list1 = list; // a deep copy (copy data not just reference)
	cout << "list1: ";
	list1.printList();
	cout << "list2: ";
	list2.printList();

	list1 = list1 - list2; // 4. subtract can use removeAll
	cout << "After list1 = list1 - list2, list1 is ";
	list1.printList();
	list1 = list;
	cout << "list1: ";
	list1.printList();
	cout << "list2: ";

	list1 = list1 ^ list2; // 5. carrot ^ is standard intersection
	cout << "After list1 = list1 ^ list2, list1 is ";
	list1.printList();
	list1 = list;

	cout << list1[0] << endl; // 6. like random access, but we know it's not
	list1[0] = "Paris";
	cout << list1[0] << endl;

	// 7. So contains, remove, and last index will be easy once all of above are working
	cout << "Contains Seattle? " << list1.contains("Seattle") << endl;
	cout << "Last index of Seattle: " << list1.lastIndexOf("Seattle") << endl;
	cout << "Last index of Paris: " << list1.lastIndexOf("Paris") << endl;
	list1.remove("Paris");
	cout << "Last index of Paris: " << list1.lastIndexOf("Paris") << endl;
 	return 0;
}