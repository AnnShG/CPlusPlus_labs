#include <iostream>
//#include<stdio.h>
//#include<stdlib.h>

/*
* type of list: Cyclic bidirectional or doubly circular linked list (DCL) - DONE
* implementation method: Dynamic - DONE
* Functions: bypassing the list (the process of traversing or iterating through the list elements one by one),
*			adding three new elements to the list after the second element - DONE,
*			traversing the list by calculating the average value of the list elements,
*			deletion of all elements from the list, which are smaller than the average
					value of the list elements.
*/
using namespace std;

// a node structure that holdss our data and the pointers.
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

// create a function to insert new nodes into the list
void insertEnd(struct Node** start, int value) { // double pointer to a Node structure
	// If the list is empty, create a single node
	if (*start == NULL) { // *start is a first pointer (that points to a head)
		// create the first node in the list
		struct Node* new_node = new Node; // new_node is a new instance and a ponter a new instance
		new_node->data = value; // access the data member of the struct Node instance (new_node) pointed to by new_node.
		new_node->next = new_node->prev = new_node; // sets both the next and prev pointers of the new_node to point to new_node itself. 
		*start = new_node; // assigns the new_node pointer to the head pointer of the list. This essentially updates the head of the list to point to the new_node.
		return;
	}

	// If list is not empty

	// Find last node
	Node* last = (*start)->prev; // is created a new Node pointer - last, the pointer assigns to the last node in the list

	// Create Node dynamically
	struct Node* new_node = new Node;
	new_node->data = value; // assigns the given value to the data member of the new_node.

	// Start is going to be next of new_node
	new_node->next = *start; // sets the next pointer to point to the head node of the list.

	// Make new node previous of start
	(*start)->prev = new_node; // the prev pointer of the head node now points to the new_node.

	// Make last previous of new node
	new_node->prev = last; // sets the prev pointer to point to the previous last node in the list
	
	// Make new node next of old last
	last->next = new_node; // connect the previous last with the new node by next pointer
}

// Function to insert Node at the beginning of the List
void insertBegin(struct Node** start, int value) {

	// Pointer points to last Node
	struct Node* last = (*start)->prev; // retrieves the pointer to the last node in the list and stores it in a new pointer variable called last
	
	struct Node* new_node = new Node;
	new_node->data = value; // Inserting the data

	// setting up previous and next of new node
	new_node->next = *start; // set the next pointer of the new node to point to the previous head node.
	new_node->prev = last; // Set the prev pointer of the new node to point to the last node in the list.

	// Update next and previous pointers of start and last.
	last->next = (*start)->prev = new_node; // it means that the next pointer of the last node points to the newly new_mode and the prev pointer of the previous head node points to the new head node

	// Update start pointer
	*start = new_node; // so now the new_node that became the head node now is start nokde aka head node
}

// Function to insert node with value as value1.
// The new node is inserted after the node with value2
void insertAfter(struct Node** start, int value1, int value2)
{
	struct Node* new_node = new Node;
	new_node->data = value1; // Inserting the data

	//the double pointer is used to dereference it to get the actual pointer to the head node to modify the head node
	// Find node having value2 and next node of it
	struct Node* temp = *start; // new pointer variable temp initializes with the head of the list (temp points to the head pointer)
	while (temp->data != value2) // checks if the data member of the current node (temp) is not equal to value2
		temp = temp->next; // temp pointer is updated to point to the next node
	struct Node* next = temp->next; // temp pointer is updated to point to the next node

	// insert new_node between temp and next.
	temp->next = new_node; // updates the next pointer of the current node to point to the newly inserted new_node
	new_node->prev = temp; // updates the prev pointer of the newly inserted node to point to the current node
	new_node->next = next; // updates the next ponter of the inserted new_node to pont to the node that wass origionally next
	next->prev = new_node; // updates the prev pointer of the node that was origionally the next node to the the inserted new_node
}

void display(struct Node* start) {

	//the single pointer ussed to access the head node directly and traverse it
	struct Node* temp = start; //  initializes a new pointer temp and assigns it the value of start, that is a pointer to the head node

	printf("\nTraversal in forward direction \n");
	while (temp->next != start) { // checks whether either temp points to the head node or temp points to the last node
		printf("%d ", temp->data); // prints data of the current node
		temp = temp->next; // update the temp pointer (the current node) to point to the next node, effectively moving forward in the list.
	}
	printf("%d ", temp->data); //prints the value of the current node (temp) 

	printf("\nTraversal in reverse direction \n");
	Node* last = start->prev; // initializes a new pointer last that points to a previous node (last) of the start
	temp = last; //  assigns the value of the last pointer to the temp pointer, making temp point to the last node
	while (temp->prev != last) { // checks whether the prev pointer of the current node points to the last node
		printf("%d ", temp->data); // prints the data of the current node
		temp = temp->prev; // update the temp pointer (the current node) to point to the next node, effectively moving reversed in the list.
	}
	printf("%d ", temp->data);
}

void deleteNodesSmallerThanAverage(struct Node** start) {
	struct Node* temp = *start;
	int sum = 0, count = 0;

	// Calculate the sum of all node values and the number of nodes in the list
	do {
		sum += temp->data; // adding the data value of the current node (temp) to the sum variable
		count++;
		temp = temp->next; // move forward
	} while (temp != *start);

	// Calculate the average value
	double average = (double)sum / count;

	// Delete nodes smaller than the average
	temp = *start; // sets the pointer variable temp to the address of the head node 
	while (temp->next != *start) {
		if (temp->data < average) { // checks whether the value of the data member of the current node (temp) is less than the average value of all nodes in the list
			struct Node* prev = temp->prev;
			struct Node* next = temp->next;
			prev->next = next; // The next pointer of prev is updated to point to next, which effectively removes temp from the list
			next->prev = prev; // the prev pointer of next is updated to point to prev, which also removes temp from the list.
			if (*start == temp) { // If the node to be deleted is the head node
				*start = next; // then the start pointer is updated to point to the next node, which becomes the new head node. 
			}
			free(temp); // frees the memory
			temp = next; // sets the temp to point to the next node
		}
		else {
			temp = temp->next; // move to the next node
		}
	}

	// Handle the last node separately
	if (temp->data < average) { 
		struct Node* prev = temp->prev;
		struct Node* next = temp->next;
		prev->next = next;
		next->prev = prev;
		if (*start == temp) {
			*start = next;
		}
		free(temp);
	}

	cout << "Average is: " << average << endl;
	// Display the updated list
	display(*start);
	cout << endl;
}

int main(int argc, char** argv) {

	// create a head pointer and initialize it to null.
	struct Node* start = NULL; // start with the empty list

	// Insert 10. So linked list becomes 10>NULL
	insertEnd(&start, 10); // &start is the address of the start pointer, which iss a pointer to a head node

	// Insert 3 at the beginning. So linked list becomes 3->10
	insertBegin(&start, 3);

	// Insert 7 at the end. So linked list becomes 3->10->7
	insertEnd(&start, 7);
	
	// Insert 2 at the end. So linked list becomes 3->10->7->2
	insertEnd(&start, 2);

	// Insert 6, 8 and 9 after 10. So linked list becomes 3->10-> 6->8->9-> 7->2
	//insertAfter(&start, 6, 8, 9, 10);
	insertAfter(&start, 6, 10);
	insertAfter(&start, 8, 10);
	insertAfter(&start, 9, 10);

	printf("Created circular doubly linked list is: ");
	display(start);
	cout << endl;

	// Delete nodes smaller than the average value
	printf("\nDeleting nodes smaller than the average value:\n");
	deleteNodesSmallerThanAverage(&start);

	return 0;
}