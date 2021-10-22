#ifndef LISTA_DOBLE
#define LISTA_DOBLE


#include <sstream>

template<class T>
class DoubleList {
private:
	struct Node {
		T info;
		int indice;
		Node* next;
		Node* prev;

		Node(T val, Node* ant = nullptr, Node* sig = nullptr) : info{ val }, prev{ ant }, next{ sig }{
			indice = -1;//Inicializado para que no de warning
		}
	};

	Node* inicio;
	int cantidad;
	void Inicializar() {
		inicio = nullptr;
		cantidad = 0;

	}

public:

	typedef Node* listaptr;
	typedef Node* const_listaptr;


	DoubleList() { Inicializar(); }

	// Constructor de copia
	explicit DoubleList(const DoubleList& obj) {
		cantidad = 0;//inicializada para evitar warning de Visual Studio
		if (obj.inicio == nullptr)
			inicio = nullptr;
		else {
			Node* nuevo = nullptr;
			cantidad = obj.cantidad;
			nuevo = new Node(obj.inicio->info);
			nuevo->indice = obj.inicio->indice;
			inicio = nuevo;
			listaptr actual = inicio;
			listaptr actualObj = obj.inicio->next;
			while (actualObj != nullptr) {
				nuevo = new Node(actualObj->info);
				nuevo->indice = actualObj->indice;
				actual->next = nuevo;
				actual->next->prev = actual;
				actual = actual->next;
				actualObj = actualObj->next;
			}
		}
	}

	~DoubleList() { BorrarLista(); }

	// Retorna la cantidad de elementos que se encuentran en la lista
	int getCantidad() {
		return cantidad;
	}
	 
	//  Inserta un elemento 
	void insertar(const T& val) {
		listaptr nuevo;

		try {
			nuevo = new Node(val);
		}
		catch (std::bad_alloc exception) {
			return;
		}

		if (inicio == nullptr) {
			inicio = nuevo;
			inicio->indice = 1;
			cantidad++;
		}
		else {
			listaptr tmp = inicio;
			while (tmp->next != nullptr)
				tmp = tmp->next;
			nuevo->indice = (tmp->indice) + 1;
			tmp->next = nuevo;
			nuevo->prev = tmp;
			cantidad++;
		}
	}


	void Eliminar(listaptr puntero) {
		if (puntero == nullptr || inicio == nullptr)
			return;

		if (inicio == puntero) {
			if (inicio->next) {
				inicio = inicio->next;
				inicio->prev = nullptr;
			}
			else {
				inicio = inicio->next;
			}
			delete puntero;
			cantidad--;

		}

		else {
			listaptr tmp = inicio;
			listaptr tmp2 = tmp->next;

			while (tmp2 != nullptr) {
				if (tmp2 == puntero) {
					tmp->next = tmp2->next;

					if (tmp2->next != nullptr)
						tmp2->next->prev = tmp;

					delete tmp2;
					cantidad--;
					return;
				}
				tmp = tmp2;
				tmp2 = tmp2->next;
			}
		}
	}

	//Elimina el elemento en la posición seleccionada
	void EliminarEnPos(int pos)
	{
		if (pos <= 0)
			return;

		listaptr tmp = inicio;
		for (int i = 1; i < pos; ++i) {
			tmp = tmp->next;
			if (tmp == nullptr)
				return;
		}
		Eliminar(tmp);
	}

	// Borra la lista
	void BorrarLista() {
		listaptr tmp;
		while (inicio != nullptr) {
			tmp = inicio;
			inicio = inicio->next;
			delete tmp;
		}
		cantidad = 0;
	}

	// Retorna el índice final
	int obtieneIndiceFinal() {

		listaptr tmp = inicio;

		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}

		return tmp->indice;
	}

	// Si existe el nodo en la posición indicada se retorna, si no, se retorna nullptr
	Node* obtenerEnPoscicion(int posicion) {
		if (posicion <= 0)
			return nullptr;
		if (inicio) {
			listaptr tmp = inicio;
			for (int i = 1; i < posicion; ++i) {
				tmp = tmp->next;
				if (tmp == nullptr)
					return nullptr;
			}
			return tmp;
		}
		else
			return nullptr;

	}

	//Compara los nodos en la posicion "i" y "j" y retorna la posicion del mayor
	int compararMayor(int i, int j) {
		Node* a = obtenerEnPoscicion(i);
		Node* b = obtenerEnPoscicion(j);

		if (a && b) {
			if (b->info > a->info)
				return b->indice;
			return a->indice;
		}
		if (a && !b) {
			return a->indice;
		}
		return -1;
	}

	//Compara los nodos en la posicion "i" y "j" y retorna la posicion del menor
	int compararMenor(int i, int j) {
		Node* a = obtenerEnPoscicion(i);
		Node* b = obtenerEnPoscicion(j);

		if (a && b) {
			if (b->info < a->info)
				return b->indice;
			return a->indice;
		}
		if (a && !b) {
			return a->indice;
		}
		return -1;
	}

	//Intercambia los nodo en pos1 y pos2
	void intercambiar(int pos1, int pos2) {
		Node* i = obtenerEnPoscicion(pos1);
		Node* j = obtenerEnPoscicion(pos2);
		Node* aux = nullptr;

		if (i && j) {

			cambiarIndice(i, j);
			if (esAdyacente(i, j)) {//Verifica si los nodos son adyacentes
				if (i->prev)  i->prev->next = j;
				if (j->next) j->next->prev = i;
				j->prev = i->prev;
				i->prev = j;
				aux = j->next;
				j->next = i;
				i->next = aux;
				if (inicio == i)//En caso de que haya que reajustar el nodo inicio
					inicio = j;
			}
			else {
				if (i->prev)  i->prev->next = j;
				if (j->prev)  j->prev->next = i;
				if (i->next) i->next->prev = j;
				if (j->next) j->next->prev = i;
				Node* temp;
				temp = i->prev;
				i->prev = j->prev;
				j->prev = temp;
				temp = i->next;
				i->next = j->next;
				j->next = temp;
				if (inicio == i)//En caso de que haya que reajustar el nodo inicio
					inicio = j;
			}

		}
	}

	//Retorna verdadero si los nodos recibidos son adyacentes
	bool esAdyacente(Node* i, Node* j) {

		if (i->next == j || i->prev == j)
			return true;
		if (j->next == i || j->prev == i)
			return true;
		return false;
	}

	//Cambia el indice de los nodos "i" y "j"
	void cambiarIndice(Node* i, Node* j) {
		int indiceAux = i->indice;
		i->indice = j->indice;
		j->indice = indiceAux;
	}

	// 
	T obtenerInfoDelPrimero() {
		if (!estaVacia()) {
			T info = inicio->info;
			intercambiar(1, cantidad);
			EliminarEnPos(cantidad);
			return info;
		}
		return inicio->info;
	}

	// Retorna verdadero si la lista está vacía
	bool estaVacia() {
		if (!inicio)
			return true;
		return false;
	}

	// Genera un toString con todos los nodos de la lista 
	std::string toString() {
		std::stringstream s;

		listaptr tmp = inicio;

		while (tmp != nullptr) {
			s << "[" << tmp->info << "] ";
			tmp = tmp->next;
		}
		s << std::endl;

		return s.str();
	}

};

#endif // !LISTA_DOBLE
