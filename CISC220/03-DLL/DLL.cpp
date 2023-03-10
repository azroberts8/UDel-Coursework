/*
 * DLL.cpp
 *
 *      Author: Andrew Roberts & John Serino
 */
//Part 1:(20 pts) (addFirst (3pts) ,addAtFront(4 pts),push (4 pts),pop(4 pts)) + getting secret message:5 pts
//In the DLL.cpp class, get push, pop, and addFirst and addAtFront working for a doubly linked list as specified in DLL.hpp and DLL.cpp.
//For this section I've given you the test cases.  You should get the output I've given you for part 1. When you get those methods working, running this will decode the secret code 1
//
//Once you have that working, start on part 2 (note you will have to go into Coder.cpp and toggle
//comments for lines 64-110 to run part 2)
//
//Part 2: (15 pts)(insertAt(5 pts), removeAtK(5 pts)) +secret message: 5 pts
//Get  the DLL.cpp methods insertAt and removeAtK methods working for a doubly linked list.
//I've given you the test cases and the output.  When you get them working, you should be able to run this and decode the second secret code
//
//Once you have that working, start on part 3 (note that you will have to go to Coder.cpp and toggle comments for lines 112-137 to run part 3)
//
//Part 3: (8 pts) (reverse (4 pts)) + secret message: 4 pts
//For this part, you will get the method reverse working for the DLL doubly linked list class.
//This method reverses the list.  Note: it doesn't just print out the list in reverse order, it actually reverses the list, so if the original list was 3<->2<->4<->8, with 3 being first and 8 being last, the reversed list would be 8<->4<->2<->3 with 8 being first and 3 being last.
//
//once you have that working, start on part 4 (note that you will have to go to Coder.cpp and toggle
//comments for lines 139-215 to run part 4)
//
//Part 4: (11 pts) (removeX (5 pts), call by pointer) + secret message: 6 pts
//For this part, you will get the method removeX to work.  removeX removes the value x from the linked list, and uses call by pointer to change the index parameter to be the index (count) of where x occurred in the list.  So, for instance if you had:
//7<->8<->3<->5<->2<->6<->1
//And you called: removeX(3,&ind)
//When  you leave the method, you???d have
//7<->8<->5<->2<->6<->1
//And ind would hold 2
//
//Once you have this working, start on part 5.  For this you will have to go to Coder.cpp and toggle comments for lines  217- 251
//
//Part 5: (21 pts)(skip ??? recursive (13 pts) + secret message: 8 pts
//For this part, you will get the method skip working for the DLL doubly linked list class. This method RECURSIVELY deletes every other node.  If the boolean flag is set to true, it will delete every even node (i.e.,if the list was
//3<->2<->4<->5<->1<->7,
//the list that would result after the skip method was called would be:
//3<->4<->1.
//If the flag is set to false, the resulting list will be
//2<->5<->7
//NOTE:  For efficiency's sake, this method SHOULD NOT call removeAtK



#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

DLL::DLL(){  // constructor - initializes an empty list
	last = NULL;
	first = NULL;
	size = 0;
}
DLL::DLL(int x){  // constructor, initializes a list with one new node with data x
	DNode *n = new DNode (x);
	first = n;
	last = n;
	size=1;
}
/***************************************************************************************************/
/*Part 1																																		*/
/***************************************************************************************************/
/* write push, pop, addAtFront */

void DLL::addFirst(int x) {
	DNode* node = new DNode(x);
	first = node;
	last = node;
	size = 1;
}

void DLL::addAtFront(int x) {
	DNode* node = new DNode(x);
	node->next = first;
	first->prev = node;
	first = node;
	size++;
}

void DLL::push(int x) {
	DNode* node = new DNode(x);
	if(first == NULL) {
		first = node;
		last = node;
	} else {
		node->prev = last;
		last->next = node;
		last = node;
	}
	size++;
}

int DLL::pop() {
	DNode* node = last;

	if(node == first) {
		first = NULL;
		last = NULL;
		size = 0;
		return node->data;
	} else {
		last = node->prev;
		last->next = NULL;
		size--;
		return node->data;
	}
}

/***************************************************************************************************/
/*Part 2																																		*/
/***************************************************************************************************/
/* write insertAt, removeAtK  here */

void DLL::insertAt(int ind, int x) {
	if(size == 0) {
		addFirst(x);
	} else if(ind >= size) {
		push(x);
	} else if(ind == 0) {
		addAtFront(x);
	} else {
		DNode* node = first;
		for(int i = 0; i < ind; i++) {
			node = node->next;
		}
		DNode* newNode = new DNode(x);
		newNode->prev = node->prev;
		newNode->next = node;
		node->prev->next = newNode;
		node->prev = newNode;
		size++;
	}
}

int DLL::removeAtK(int ind) {
	if(size <= 0 || ind >= size) return 0; // protects from out of bounds

	DNode* node = first;
	if(ind == 0) {
		// first element
		if(node->next != NULL) {
			first = node->next;
			node->next->prev = NULL;
		} else {
			first = NULL;
		}
	} else if(ind == size-1) {
		// last element
		return pop();
	} else {
		// any element in between
		for(int i = 0; i < ind; i++) {
			node = node->next;
		}
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	size--;
	return node->data;
}

/****************************************************************************************/
/* Part 3                                                                                                                       */
/****************************************************************************************/

void DLL::reverse() {
	DNode* temp;
	DNode* current = first;
	first = last;
	last = current;

	while(current != NULL) {
		temp = current->next;
		current->next = current->prev;
		current->prev = temp;
		current = temp;
	}

}

/****************************************************************************************/
/* Part 4                                                                                                                       */
/****************************************************************************************/
/* write removeX here */

void DLL::removeX(int x, int* ind) {

	*ind = 0;
	DNode* node = first;
	while(*ind < size && node->data != x) {
		node = node->next;
		*ind = *ind + 1;
	}

	if(*ind < size) {
		removeAtK(*ind);
	}

}
	
	
/****************************************************************************************/
/* Part 5                                                                                                                     */
/****************************************************************************************/
/* write skip here */

void DLL::skip(bool flag) {
	DNode* current;
	if(flag) {
		current = first->next;
		first = current;
	} else {
		current = first;
	}
	while(current != NULL) {
		if(current->next != NULL) {
			current->next = current->next->next;
		} else {
			current->next = NULL;
		}
		if(current->prev != NULL) {
			current->prev = current->prev->prev;
		} else {
			current->prev = NULL;
		}
		last = current;
		current = current->next;
	}
}




/***************************************************************************************************/
/*End of your part																														*/
/***************************************************************************************************/

void DLL::printList() {
	DNode *tmp = first;
	while (tmp != NULL) {
		cout << tmp->data << ", ";
		tmp = tmp->next;
	}
	cout << endl;
}
void DLL::printCode() {
	DNode *tmp = first;
	while (tmp != NULL) {
		cout << alpha[tmp->data];
		tmp = tmp->next;
	}
	cout << endl;
}
DLL::~DLL(){
	DNode *tmp = first;
	DNode *tmp2 = first->next;
	while (tmp != NULL) {
		delete tmp;
		tmp = tmp2;
		if(tmp2 != NULL) {
			tmp2 = tmp2->next;
		}
	}
}



