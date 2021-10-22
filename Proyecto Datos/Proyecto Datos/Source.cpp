#include<iostream>
#include "DoubleList.h"

/*
Enlaces visitados:
	http://algorithmics.lsi.upc.edu/docs/pqueues.pdf
	https://www.youtube.com/watch?v=RBSGKlAvoiM&t=6746s
	https://blog.martincruz.me/2012/11/cola-con-prrioridad-en-c.html
	https://www.geeksforgeeks.org/binary-heap/
	https://ioecapsule.com/linked-list-template-implementation-of-doubly-linked-list-using-c/
	https://www.geeksforgeeks.org/priority-queue-using-doubly-linked-list/
	https://www.youtube.com/watch?v=cuL8gXCSA58
*/
using namespace std;

int main() {
	DoubleList<int>* l1 = new DoubleList<int>();
	l1.push_bach(1);
	l1.push_bach(2);
	l1.push_bach(3);

	return 0;
}