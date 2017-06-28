#include "list.h"
	
List::List(){
	head = NULL;
	curr = NULL;
	temp = NULL;
}

List::~List(){
	deleteList();	
}

void List::addNode(int number){
		
	node* n = new node;
	n -> value = number;

	if (head == NULL){
	//caso em que a lista ta vazia.

		head = n;
		n -> next = NULL;
	}
	else{
		//caso que é pra ser inserido antes.	
		if (n -> value <= head -> value){
			n -> next = head;
			head = n;
		}
		else{
		// caso é pra ser inserido no meio ou final.
			curr = head;
			while (curr != NULL && curr -> value < n -> value){
				temp = curr;
				curr = curr -> next;
			}	
			temp -> next = n;
			n -> next = curr;
		}
	}

}

void List::printList(){
	node* n = head;
	while (n != NULL){
		std::cout << n -> value << std::endl;
		n = n -> next;
	}
}

void List::deleteNode(int number){
	node* n = NULL;
	temp = head;
	curr = head;
	
	while (curr != NULL && curr -> value != number ){
		temp = curr;
		curr = curr -> next;
	}	
	if (curr != NULL){
		n = curr;
		curr = curr -> next;
		temp -> next = curr;
	}
	if (n == head){
		head = head -> next;
	}
	delete[] n;
}

void List::deleteList(){
	if (head != NULL){
		node* curr = head;
		while (curr -> next != NULL){
			head = curr;
			curr = curr -> next;
			delete[] head;
		}
		head = NULL;
		delete[] head;

		curr = NULL;
		delete[] curr;

		temp = NULL;
		delete[] temp;
	}
}

