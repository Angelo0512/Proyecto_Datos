#include<iostream>
#include "DoubleList.h"
#include "PriorityQueue.h"

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

	// Crear cola de prioridad de enteros
	PriorityQueue<int>* p = new PriorityQueue<int>(false);

	// Añadir unos cuantos números
	p->enqueue(2);
	p->enqueue(5);
	p->enqueue(1);
	p->enqueue(4);
	p->enqueue(12);
	p->enqueue(4);
	p->enqueue(6);
	p->enqueue(5);

	// Imprime y saca de la cola de prioridad
	// Maneja las posibles excepciones
	try {
		cout << p->dequeue() << endl;
		cout << p->dequeue() << endl;
		cout << p->dequeue() << endl;
		cout << p->dequeue() << endl;
		cout << p->dequeue() << endl;
		cout << p->dequeue() << endl;
		cout << p->dequeue() << endl;
		cout << p->dequeue() << endl;
		cout << p->dequeue() << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	// la cola está vacía, añadir un par de números 
	p->enqueue(1);
	p->enqueue(3);

	// Construye una cola de prioridad copia

	PriorityQueue<int>* q = new PriorityQueue<int>(p);

	// Imprime los elementos que se copiaron 
	try {
		cout << q->dequeue() << endl; // NO SE COPIAN LOS ELEMENTOS DE LA LISTA 
		cout << q->dequeue() << endl;
		cout << q->dequeue() << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	return 0;
}