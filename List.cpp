#include <iostream>
#include <string>

using namespace std;

class List {
public:
	string value;
	List(const string& pValue, List* pPrevious = 0, List* pNext = 0) : value(pValue), previous(pPrevious), next(pNext) {}
	List* insert(List* item)
	{
		if (item == 0) return this;
		if (this == 0) return item;
		item->next = this;
		if (previous) previous->next = item;
		item->previous = previous;
		previous = item;
		return item;
	}
	List* remove(List* item)
	{
		if (item == 0) return 0;
		if (item->next) item->next->previous = item->previous;
		if (item->previous) item->previous->next = item->next;
		return item->next;
	}
	List* search(List* list, const string& value)
	{
		while (list) {
			if (list->value == value) return list;
			list = list->next;
		}
		return 0;
	}
	List* changeLocation(List* list, int count)
	{
		if (list == 0) return 0;
		if (0 < count)
		{
			while (count--)
			{
				if (list->next == 0) return 0;
				list = list->next;
			}
		}
		else
			if (count < 0) {
				while (count++) {
					if (list->previous == 0) return 0;
					list = list->previous;
				}
			}
		return list;
	}
	void printList(List* list)
	{
		while (list) {
			cout << list->value;
			if (list = list->next) cout << " | ";
		}
	}
private:
	List* previous;
	List* next;
};
