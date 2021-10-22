#ifndef HEAP_H
#define HEAP_H
#include"Doublelist.h"

#define Max_Heap 1
#define Min_Heap 2


template <class T>
class Heap {

private:
	ListaDoble<T>* lista;
	bool tipoHeap; //Si es 1 es un maxHeap, si es 2 es un minHeap

public:

	static const int maxHeap = Max_Heap;
	static const int minHeap = Min_Heap;

	//Recibe por parametro el tipo de Heap: de maximos o minimos
	Heap(bool tipo = true) {
		tipoHeap = tipo;
		lista = new ListaDoble<T>();
	}

	//Crea un heap a partir de una lista enlazada doble, tambien recibe por parametro el tipo de Heap: de maximos o minimos
	Heap(ListaDoble<T>* list, bool tipo = true) {
		tipoHeap = tipo;
		lista = list;
		crearHeap();
	}

	//Constructor copia
	explicit Heap(const Heap& obj) {
		tipoHeap = obj.tipoHeap;
		lista = new ListaDoble<T>(*obj.lista);
	}

	~Heap() {
		delete lista;
	}

	void insertar(const T& t) {
		lista->insertar(t);
		int indice = lista->obtieneIndiceFinal();
		heapifyBubbleUp(indice);
	}

	int obtenerPadre(int i) {
		return (i) / 2;
	}

	int obtenerIzq(int i) {
		return i * 2;
	}

	int obtenerDer(int i) {
		return i * 2 + 1;
	}

	//Utilizado para mantener la propirdad de un heap cada vez que se inserta
	void heapifyBubbleUp(int i) {
		int padre = obtenerPadre(i);
		int izq = obtenerIzq(padre);
		int der = obtenerDer(padre);
		int mayorPrioridad = -1;
		if (i > 0) { //El padre siempre es mayor que cero ya que el indice de lista inicia en 1
			if (tipoHeap)
				mayorPrioridad = lista->compararMayor(izq, der);//Se busca el mayor entre los hermanos
			if (!tipoHeap)
				mayorPrioridad = lista->compararMenor(izq, der);//Se busca el mayor entre los hermanos
			if (mayorPrioridad != -1) {
				if (tipoHeap)
					mayorPrioridad = lista->compararMayor(mayorPrioridad, padre);//Se busca el mayor entre el hijo y el padre
				if (!tipoHeap)
					mayorPrioridad = lista->compararMenor(mayorPrioridad, padre);//Se busca el mayor entre el hijo y el padre
				if (mayorPrioridad != padre) {//Si el mayor es diferente al padre
					lista->intercambiar(padre, mayorPrioridad);
					heapifyBubbleUp(padre); //Como hubo un intercambio entre el padre y el hijo, la posicion del antiguo padre cambio con la del hijo
											//Entonces el que ahora es padre tomo el indice del padre anterior, por eso se repite recursivamente heapify
				}
			}
		}
	}

	//Utilizado para reordenar el heap una vez eliminado el elemento con mayor prioridad
	void heapifyBubbleDown(int i = 1) {
		int izq = obtenerIzq(i);
		int der = obtenerDer(i);
		int mayorPrioridad = -1;
		if (i > 0) { //El padre siempre es mayor que cero ya que el indice inicia en 1
			if (tipoHeap)
				mayorPrioridad = lista->compararMayor(izq, der);//Se busca el mayor entre el hijo y el padre
			if (!tipoHeap)
				mayorPrioridad = lista->compararMenor(izq, der);//Se busca el mayor entre los hermanos
			if (mayorPrioridad != -1) {
				if (tipoHeap)
					mayorPrioridad = lista->compararMayor(mayorPrioridad, i);//Se busca el mayor entre el hijo y el padre
				if (!tipoHeap)
					mayorPrioridad = lista->compararMenor(mayorPrioridad, i);//Se busca el mayor entre el hijo y el padre
				if (mayorPrioridad != i) {//Si el mayor es diferente al padre
					lista->intercambiar(i, mayorPrioridad);
					heapifyBubbleDown(mayorPrioridad);  //Como hubo un intercambio entre el padre y el hijo, la posicion del antiguo padre cambio con la del hijo
														//Entonces el que ahora es padre tomo el indice del padre anterior, por eso se repite recursivamente heapify
				}
			}
		}
	}

	//Utilizado para crear heap a partir de una lista enlazada doble desordenada
	void crearHeap() {
		int ultimoPadre = lista->getCantidad() / 2;

		for (int i = ultimoPadre; i > 0; i--) {
			heapifyBubbleDown(i);
		}
	}

	//Retorna el elemento de mayor prioridad del heap
	T obtenerElementoPrioritario() {
		if (!estaVacia()) {
			T info = lista->obtenerInfoDelPrimero();
			heapifyBubbleDown();

			return info;
		}
		return lista->obtenerInfoDelPrimero();
	}

	bool estaVacia() {
		return lista->estaVacia();
	}


	void eliminar(int pos) {
		int ultimo = lista->getCantidad();
		if (pos != ultimo)
			lista->intercambiar(pos, ultimo);
		lista->EliminarEnPos(ultimo);
		heapifyBubbleDown(pos);
	}

};

#endif