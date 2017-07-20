#ifndef LIST_
#define LIST_

#include <iostream>

template <class T> class List{
public:
	List();
	~List();
	void push(int pos, T item);
	void pop(int pos);
	void print();

private:
	struct node{
		int address;
		T data;
		node* next;
	};

	node* head;
	node* curr;
	node* temp;
};

template <class T> List<T>::List(){
	head = NULL;
	curr = NULL;
	temp = NULL;
}

template <class T> List<T>::~List(){

	if(head != NULL){
		node* curr = head;
		while(curr -> next != NULL){
			curr = curr -> next;
			delete head;
			head = curr;
		}
	}
}

template <class T> void List<T>::push(int pos, T item){

	node* n = new node;
	n -> address = pos;
	n -> data = item;		

	if (head == NULL){
	//caso em que a lista ta vazia.

		head = n;
		n -> next = NULL;
	}
	else{
		//caso que é pra ser inserido antes.	
		if (n -> address <= head -> address){
			n -> next = head;
			head = n;
		}
		else{
		// caso é pra ser inserido no meio ou final.
			curr = head;
			while (curr != NULL && curr -> address < n -> address){
				temp = curr;
				curr = curr -> next;
			}	
			temp -> next = n;
			n -> next = curr;
		}
	}
}

template <class T> void List <T>::pop(int pos){

	node* n = NULL;
	temp = head;
	curr = head;

	while (curr != NULL && curr -> address != pos){
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
	delete n;
}

template <class T> void List <T>::print(){
	node* n = head;
	while(n != NULL){
		std::cout << "  " << n -> address << "  ";
		n = n -> next;
	}
	std::cout << std::endl;

	n = head;
	while(n != NULL){
		std::cout << n -> data << "  ";
		n = n -> next;
	}
	std::cout << std::endl;
}

#endif
