#include<iostream>
#include "DoubleList.h"
#include "PriorityQueue.h"
#include "Usuario.h"
#include <stdlib.h>
#include <time.h>

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
/*
	Una pagina los usuarios hacen fila para darle uso
	Sin embargo, la pagina deja ingresar a los usuarios en un orden de prioridad
	Por lo tanto lo usarios tiene una prioridad asignada
*/
using namespace std;

template<typename T>
void mostrarColaUsuario(PriorityQueue<T> *cola) {
	while (!cola->isEmpty()) {
		Usuario newUser = cola->dequeue();
		std::cout <<  newUser << std::endl;
	}
}

int main() {
	srand(time(NULL));

	//Se crean usuarios con una prioridad random del 1 al 10
	Usuario A((rand() % (10 - 1 + 1) + 1), 'A');
	Usuario B((rand() % (10 - 1 + 1) + 1), 'B');
	Usuario C((rand() % (10 - 1 + 1) + 1), 'C');
	Usuario D((rand() % (10 - 1 + 1) + 1), 'D');
	Usuario E((rand() % (10 - 1 + 1) + 1), 'E');

	//Se crea una cola de prioridad con prioridad mayor(constructor por default)
	PriorityQueue<Usuario>* colaUsuarios = new PriorityQueue<Usuario>();

	//Se agregan los usuarios a la cola de prioridad
	colaUsuarios->enqueue(A);
	colaUsuarios->enqueue(B);
	colaUsuarios->enqueue(C);
	colaUsuarios->enqueue(D);
	colaUsuarios->enqueue(E);

	// Imprime y saca de la cola de prioridad
	// Maneja las posibles excepciones
	std::cout << "--Se imprime la cola con prioridad mayor--\n";
	try {
		mostrarColaUsuario(colaUsuarios);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	//Se reinsertan los elementos a la cola
	colaUsuarios->enqueue(A);
	colaUsuarios->enqueue(B);
	colaUsuarios->enqueue(C);
	colaUsuarios->enqueue(D);
	colaUsuarios->enqueue(E);

	PriorityQueue<Usuario>* colaCopia = new PriorityQueue<Usuario>(*colaUsuarios);
	// Imprime y saca de la cola de prioridad
	// Maneja las posibles excepciones
	std::cout << "\n--Se imprime la cola de prioridad copia--\n";
	try {
		mostrarColaUsuario(colaUsuarios);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	//Se crea una listaDoble
	DoubleList<Usuario>* listaUsuario = new DoubleList<Usuario>();

	//Se agregan los usuario a la lista
	listaUsuario->add(A);
	listaUsuario->add(B);
	listaUsuario->add(C);
	listaUsuario->add(D);
	listaUsuario->add(E);

	//Se crea la cola de prioridad a partir de la lista
	PriorityQueue<Usuario>* colaLista = new PriorityQueue<Usuario>(listaUsuario, false); //Se indica el orden menor

	// Imprime y saca de la cola de prioridad
	// Maneja las posibles excepciones
	std::cout << "\n--Se imprime la cola de prioridad a partir de una lista--\n";
	try {
		mostrarColaUsuario(colaLista);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	//Elimina la cola de prioridad
	delete colaUsuarios;
	delete colaCopia;
	delete colaLista;

	return 0;
}