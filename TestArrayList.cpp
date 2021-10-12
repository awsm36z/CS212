#include "ArrayList.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// Testing program for "simple" <template> in C++
// by W.P. Iverson, May 2021
// for BC CS212 class

int main()
{
	ArrayList<int> list1; // Program #7 assignment
	vector<int> vlist1;   // example of the C++ standard vector

	ArrayList<int> list2;  // list2() is not used in C++
	vector<int> vlist2{2,9,6,1,3,9,0}; // easy initialization in C++

	ArrayList<int> list3(33); // initialize array to specified capacity
	vector<int> vlist3(33);

	int a[] = { 2, 9, 6, 1, 3, 9, 0 }; // sample data
	for (int i = 0; i < 7; i++) {
		list2.add(a[i]);
	}

	list1 = list3;  // So list 1 now points to list3, same thing

	list2.add(3, 33); // add at index
	vlist2.insert(vlist2.begin() + 3, 33); // requires iterator math (+3)

	list2.addAll(list1); // add everything from list1
	vlist2.insert(vlist2.end(), vlist1.begin(), vlist1.end());

	list1.clear(); // remove everything
	vlist1.clear();

	cout << list2.contains(6) << endl; // true is 1 in C++
	cout << (find(vlist2.begin(), vlist2.end(), 6) != vlist2.end()) << endl;

	cout << list2.get(6) << endl; // 0
	cout << vlist2.at(6) << endl; // 0

	cout << list2.indexOf(6) << endl; // 2
	cout << (find(vlist2.begin(), vlist2.end(), 6) - vlist2.begin()) << endl;

	cout << list2.isEmpty() << endl; // 0
	cout << vlist2.empty() <<  endl;

	list2.remove(6); // Oracle Java returns the item removed
	vlist2.erase(vlist2.begin() + 6); // vector erase returns an iterator
	
	list2.set(6, 66); // Oracle Java returns the item replaced
	vlist2.at(6) = 66; // C++ has access by reference
	 
	cout << list2.size() << endl;  // 7
	cout << vlist2.size() << endl;
	 
	cout << list2.to_string() << endl;	//   2  9  6  33  1  3  66
	for (vector<int>::iterator it = vlist2.begin(); it != vlist2.end(); ++it) cout << ' ' << *it; 
	// If done well, list2 and vlist2 should be equivalent at this point

	return 0;
}
