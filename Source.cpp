#include<iostream>
using namespace std;
typedef struct Element* ptr;
struct Element {
	ptr Next;
	int Data;
};
int main() {
	ptr na = NULL, Inserter = na, PlaceFinder = na, ElHolder = NULL;
	ElHolder = new Element;
	cout << "Моля въведете данна: ";
	cin >> ElHolder->Data;
	ElHolder->Next = na;
	na = ElHolder;
	cout << "Are you want to continue? Yes - 1, No - 0: ";
	bool iskam;
	cin >> iskam;
	while (iskam) {
		ElHolder = new Element;
		PlaceFinder = new Element;
		cout << "Please enter data: ";
		cin >> ElHolder->Data;
		PlaceFinder->Data = ElHolder->Data;
		Inserter = na;
		PlaceFinder->Next = na;
		while (PlaceFinder->Next != NULL && PlaceFinder->Data > PlaceFinder->Next->Data) {
			Inserter = PlaceFinder->Next;
			PlaceFinder->Next = PlaceFinder->Next->Next;
		}
		if (ElHolder->Data < na->Data) {
			ElHolder->Next = na;
			na = ElHolder;
		}
		else
		{
			ElHolder->Next = PlaceFinder->Next;
			Inserter->Next = ElHolder;
		}
		cout << "Are you want to continue? Yes - 1, No - 0: ";
		cin >> iskam;
	}
	Inserter = na;
	while (Inserter != NULL) {
		cout << Inserter->Data;
		Inserter = Inserter->Next;
	}
	return 0;
}