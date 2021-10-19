#include<iostream>
#include "LinkedList.h"
using namespace std;

int main() {
	LinkedList<int>* l1 = new LinkedList<int>();
	l1->insertarFinal(0);
	l1->insertarFinal(1);
	l1->insertarFinal(5);
	l1->insertarFinal(3);

	cout << l1->getNodo(0)->cont << '\n';

	l1->imprimir();


	l1->swap(0, 3);

	cout << endl;

	l1->imprimir();
	return 0;
}