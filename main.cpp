#include "list.h"

int main(){
	
	List <float> xxx;
	
	xxx.push(3, 7.2);
	xxx.push(5, 8.3);
	xxx.push(1, 0.2);
	xxx.push(7, 1.3);

	xxx.pop(5);

	xxx.push(9, 0.3);
	xxx.push(2, 6.8);


	xxx.print();

	return 0;
}
