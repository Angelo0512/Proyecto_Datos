#include<iostream>
#include "DoubleList.h"
#include "Usuario.h"

/*
	Estudiantes:
	Angelo Calvo Murillo
	Gabriel Alvarado Martinez
	Santiago Osorio Castaneda

*/
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

	Usuario u1(2, 'n');
	Usuario u2(4, 'n');

	if (u1 < u2) {
		cout << "yay" << endl;
	}

	return 0;
}