#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include "Heap.h"

template <class T>
class PriorityQueue {
private:
	Heap<T>* elements;
	bool type;

public:
	//Se crea una cola de prioridad determinando la prioridad donde true es maxHeap y false minHeap
	PriorityQueue(bool type = true) {
		this->type = type;
		elements = new Heap<T>(type);
	}

	//Se crea una cola de prioridad con un constructor copia (A partir de otro objeto del mismo tipo)
	explicit PriorityQueue(const PriorityQueue& queue) {
		type = queue.type;
		elements = new Heap<T>(*queue.elements);
	}

	//Se crea una cola de prioridad a partir de un puntero de una lista doble
	PriorityQueue(DoubleList<T>* list, bool type = true) {
		DoubleList<T>* listAux = new DoubleList<T>(*list);
		this->type = type;
		elements = new Heap<T>(listAux, type);
	}

	//Se borra el objeto heap
	~PriorityQueue() {
		delete elements;
	}

	//Este metodo agrega un objeto al heap de la cola
	void enqueue(T val) {
		elements->add(val);
	}

	//Este metodo funciona como un pop en la manera que hace pop del objeto con mayor prioridad
	T dequeue() {
		return !isEmpty() ? elements->getMaxPriorityElement() : throw std::out_of_range("Cola vacia");
	}

	//Este metodo elimina un objeto en la posicion reciba por parametro
	void remove(int pos) {
		elements->remove(pos);
	}

	//Este metodo checkea si el heap esta vacio
	bool isEmpty() {
		return elements->isEmpty();
	}

	//Este metodo comparada dos objetos y determina si el primero es mayor
	template<typename T>
	bool compare(T& obj_a, T& obj_b) {
		return (obj_a > obj_b) ? true : false;
	}
};
#endif // !COLA_PRIORIDAD
