#include<iostream>
#include "LinkedList.h"
using namespace std;

int main() {
	LinkedList<int>* l1 = new LinkedList<int>();
	l1->insertarFinal(0);
	l1->insertarFinal(1);
	l1->insertarFinal(5);
	l1->insertarFinal(3);


	cout << l1->get(3);
	return 0;
}