#include <iostream>
#include "list.h"

struct node{
	int data;		
	node *next;	
};




int main(){

	List xxx;
 	xxx.addNode(20);
	xxx.addNode(23);
	xxx.addNode(2);
	xxx.printList();	
	xxx.addNode(8);

	return 0;
}
