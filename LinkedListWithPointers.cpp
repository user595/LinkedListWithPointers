// LinkedListWithPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "List.cpp"

using namespace std;


int main()
{
	std::cout << "start\n";

	List* list = new List("first");
	list = list->insert(new List("second"));
	list = list->insert(new List("BLUE"));
	list = list->insert(new List("third"));
	list = list->insert(new List("fourth"));
	list = list->insert(new List("fifth"));

	List* found = list->search(list, "BLUE");

	if (found)
	{
		cout << "\nfound\n";

		list->printList(found);

		list->remove(found);

		found = list->search(list, "BLUE");
		if (found == 0) cout << "\nerased\n";
		else cout << "\nERASE FAIL\n";
	}
	else cout << "\nNOT FOUND\n";

	list->printList(list);

	found = list->search(list, "fifth");
	List* advanceTest = list->changeLocation(found, 3);
	cout << "\nAdvanced three from 'fifth' : " << advanceTest->value << "\n";

	found = list->search(list, "first");
	advanceTest = list->changeLocation(found, -3);
	cout << "\nAdvanced NEGATIVE three from 'first' : " << advanceTest->value << "\n";

	std::cout << "\nend\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
