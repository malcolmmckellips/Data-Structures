#include <iostream>
using namespace std;

struct Node
{
	string item;
	Node *next;
};

int main()
{
	string a[] = {"uno", "dos", "tres", "cuatro"};

	// for(int i = 0; i < 4; i++)
	// {
	// 	cout << a[i] << endl;
	// }


	Node *head, *current, *tmp;
	head = new Node;
	current = new Node;


	head->item = a[0];
	head->next = nullptr;
	// if( head->next == nullptr )
	// 	cout << "head->next = nullptr" << endl;

	current = head;

	int i = 1;
	while( i < 4 )
	{
		// create new node; use tmp to point to it
		tmp = new Node;

		// populate the payload of tmp with i-th array element
		tmp->item = a[i];
		// in case it's the last element, set current node to indicate end
		tmp->next = nullptr;

		// at this point "current" is still pointing to previous element
		// (could be head)
		// connect the previous element such that it is pointing to the newly created one (tmp)
		current->next = tmp; 

		// move forward. Make current point to the new element
		current = tmp;

		i++;

	}

	cout << "Traverse and print the LL: " << endl;
	current = head;

	while( current != nullptr )
	{
		cout << current->item << endl;
		cout << current << endl;
		current = current->next;
	}


	return 0;
}













