#ifndef HEAP_H
#define HEAP_H
#include"Doublelist.h"

#define Max_Heap 1
#define Min_Heap 2


template <class T>
class Heap {

private:
	DoubleList<T>* list;
	bool type;

public:
	//En este constructor recibe un booleano que determina el tipo heap: true = maxHeap, false = minHeap
	Heap(bool type = true) {
		this->type = type;
		list = new DoubleList<T>();
	}

	//En este constructor recibe un puntero de una lista para ser copia en la lista del heap y recibe un booleano para determinar el tipo de heap
	Heap(DoubleList<T>* list, bool type = true) {
		this->type = type;
		this->list = list;
		createHeap();
	}

	//Constructor copia
	explicit Heap(const Heap& obj) {
		type = obj.type;
		list = new DoubleList<T>(*obj.list);
	}

	//Borra la lista doble del heap
	~Heap() {
		delete list;
	}

	//Este metodo agrega un valor en la lista doble
	void add(const T& val) {
		list->add(val);
		int index = list->getLastIndex();
		heapifyUp(index);
	}

	//Los tres siguientes metodos obtiene la posicion de:
	//Del padre
	int getParent(int i) {
		return (i) / 2;
	}
	//Del hijo izquierdo
	int getLeft(int i) {
		return i * 2;
	}
	//Del hijo derecho
	int getRight(int i) {
		return i * 2 + 1;
	}

	//Utilizado para mantener la propiedad de un heap cada vez que se inserta
	void heapifyUp(int i) {
		int parent = getParent(i);
		int left = getLeft(parent);
		int right = getRight(parent);
		int maxPriority = -1;
		if (i > 0) { //El padre siempre es mayor que cero ya que el indice de list inicia en 1
			if (type)
				maxPriority = list->compareMax(left, right);
			else
				maxPriority = list->compareMin(left, right);
			if (maxPriority != -1) {
				if (type)
					maxPriority = list->compareMax(maxPriority, parent);
				else
					maxPriority = list->compareMin(maxPriority, parent);
				if (maxPriority != parent) {
					list->swap(parent, maxPriority);
					heapifyUp(parent); //Se intercambia la posicion del padre con la del hijo

				}
			}
		}
	}

	//Utilizado para reordenar el heap una vez eliminado el elemento con mayor prioridad
	void heapifyDown(int i = 1) {
		int left = getLeft(i);
		int right = getRight(i);
		int maxPriority = -1;
		if (i > 0) { //El padre siempre es mayor que cero ya que el indice inicia en 1
			if (type)
				maxPriority = list->compareMax(left, right);
			else
				maxPriority = list->compareMin(left, right);
			if (maxPriority != -1) {
				if (type)
					maxPriority = list->compareMax(maxPriority, i);
				else
					maxPriority = list->compareMin(maxPriority, i);
				if (maxPriority != i) {
					list->swap(i, maxPriority);
					heapifyDown(maxPriority);  //Se intercambia la posicion del padre con la del hijo
				}
			}
		}
	}

	//Utilizado para crear heap a partir de una list enlazada doble desordenada
	void createHeap() {
		int lastParent = list->getAmount() / 2;
		for (int i = lastParent; i > 0; i--) {
			heapifyDown(i);
		}
	}

	//Devuelve el objeto con mayor prioridad en el heap
	T getMaxPriorityElement() {
		if (!isEmpty()) {
			T value = list->getFirstValue();
			heapifyDown();
			return value;
		}
		return list->getFirstValue();
	}

	//Este metodo determina si la lista doble del heap esta vacia
	bool isEmpty() {
		return list->isEmpty();
	}

	//Este metodo elimina el objeto en la lista doble del heap en la posicion indicada por parametro
	void remove(int pos) {
		int last = list->getAmount();
		if (pos != last)
			list->swap(pos, last);
		list->removePos(last);
		heapifyDown(pos);
	}
};

#endif