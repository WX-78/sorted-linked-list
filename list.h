#ifndef LIST_H_
#define LIST_H_

#include <stddef.h>
#include <iostream>

class List{
public:
	List();
	~List();
	void addNode(int number);
	void printList();
	void deleteNode(int number);	
	void deleteList();

private:
	struct node{
		int value;	
		node* next;
	};

	node* head;
	node* curr;
	node* temp;
};
#endif
