#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

#include "Heap.h"

template <class T>
class PriorityQueue : public IPriorityQueue {
private:
	Heap<T>* elementos;
	bool tipoPriorityQueue;

public:
	
	PriorityQueue(bool tipo = true) {
		tipoPriorityQueue = tipo;
		elementos = new Heap<T>(tipo);
	}

	explicit PriorityQueue(const PriorityQueue& obj) {
		tipoPriorityQueue = obj.tipoPriorityQueue;
		elementos = new Heap<T>(*obj.elementos);
	}

	PriorityQueue(ListaDoble<T>* list, bool tipo = maxPriorityTail) {
		//Se crea una copia de la lista para que la lista utilizada por la cola de prioridad
		//no sea la misma que la enviada por parametro
		ListaDoble<T>* copiaLista = new ListaDoble<T>(*list);
		tipoPriorityQueue = tipo;
		elementos = new Heap<T>(copiaLista, tipo);
	}

	~PriorityQueue() {
		delete elementos;
	}


	void enqueue(T dato) {
		elementos->insertar(dato);
	}

	T dequeue() {
		if (!estaVacia())
			return elementos->obtenerElementoPrioritario();
		else
			throw std::out_of_range("Cola vacia");
	}

	void eliminar(int pos) {
		elementos->eliminar(pos);
	}

	bool estaVacia() {
		return elementos->estaVacia();
	}
};
#endif
