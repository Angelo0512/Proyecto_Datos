#ifndef DOUBLE_LIST
#define DOUBLE_LIST
#include <sstream>

template<class T>
class DoubleList {
private:
	struct Node {
		T value;
		int index;
		Node* next;
		Node* prev;
		//Constructor del Nodo, index empieza en 1 pero como al inicio no hay objeto en la lista index va a ser 0
		Node(T val, Node* ant = nullptr, Node* sig = nullptr) : value{ val }, index{ 0 }, prev{ ant }, next{ sig }{ }
	};

	Node* begin = nullptr;
	int amount = 0;

public:

	typedef Node* listptr;
	typedef Node* const_listptr;

	//Constructor por defecto
	DoubleList() = default;

	//Constructor copia
	explicit DoubleList(const DoubleList& list) {
		if (list.begin) {
			Node* newNode = new Node(list.begin->value);
			amount = list.amount;
			newNode->index = list.begin->index;
			begin = newNode;
			listptr current = begin, currentList = list.begin->next;

			while (currentList != nullptr) {
				newNode = new Node(currentList->value);
				newNode->index = currentList->index;
				current->next = newNode;
				current->next->prev = current;
				current = current->next;
				currentList = currentList->next;
			}
		}
	}

	//Elimina los elementos de la lista doble
	~DoubleList() {
		listptr tmp;

		while (begin) {
			tmp = begin;
			begin = begin->next;
			delete tmp;
		}
		amount = 0;
	}

	//Este metodo devuelve la cantidad de elementos en la lista doble
	int getAmount() {
		return amount;
	}

	//Agregar un elementos en la lista doble
	void add(const T& val) {
		listptr newNode;

		try {
			newNode = new Node(val);
		}
		catch (std::bad_alloc exception) {
			return;
		}

		if (!begin) {
			begin = newNode;
			begin->index = 1;
			amount++;
		}
		else {
			listptr tmp = begin;
			while (tmp->next)
				tmp = tmp->next;
			newNode->index = (tmp->index) + 1;
			tmp->next = newNode;
			newNode->prev = tmp;
			amount++;
		}
	}

	// Elimina un elemento de la lista doble a partir de un puntero de un nodo
	void remove(listptr ptr) {
		if (!ptr || !begin)
			return;

		if (begin == ptr) {
			if (begin->next) {
				begin = begin->next;
				begin->prev = nullptr;
			}
			else {
				begin = begin->next;
			}
			delete ptr;
			amount--;
		}

		else {
			listptr tmp = begin;
			listptr tmp2 = tmp->next;

			while (tmp2) {
				if (tmp2 == ptr) {
					tmp->next = tmp2->next;

					if (tmp2->next)
						tmp2->next->prev = tmp;

					delete tmp2;
					amount--;
					return;
				}
				tmp = tmp2;
				tmp2 = tmp2->next;
			}
		}
	}

	// Elimina un elemento de la lista doble a partir de una posicion
	void removePos(int pos)
	{
		if (pos <= 0)
			return;

		listptr tmp = begin;
		for (int i = 1; i < pos; ++i) {
			tmp = tmp->next;
			if (!tmp)
				return;
		}
		remove(tmp);
	}

	// Devuelve el index del ultimo elemento en la lista
	int getLastIndex() {

		listptr tmp = begin;

		while (tmp->next) {
			tmp = tmp->next;
		}

		return tmp->index;
	}

	// Devuelve un elemento en la posicion indicada
	Node* getElementPos(int pos) {
		if (pos <= 0)
			return nullptr;
		if (begin) {
			listptr tmp = begin;
			for (int i = 1; i < pos; ++i) {
				tmp = tmp->next;
				if (!tmp)
					return nullptr;
			}
			return tmp;
		}
		else
			return nullptr;

	}

	//Recibe dos posiciones y determinar cual nodo, en la posicion indicada, es mayor
	int compareMax(int i, int j) {
		Node* a = getElementPos(i);
		Node* b = getElementPos(j);

		if (a && b) {
			if (b->value > a->value)
				return b->index;
			return a->index;
		}
		if (a && !b) {
			return a->index;
		}
		return -1;
	}

	//Recibe dos posiciones y determinar cual nodo, en la posicion indicada, es menor
	int compareMin(int i, int j) {
		Node* a = getElementPos(i);
		Node* b = getElementPos(j);

		if (a && b) {
			if (b->value < a->value)
				return b->index;
			return a->index;
		}
		if (a && !b) {
			return a->index;
		}
		return -1;
	}

	//Intercambia los nodos en la posiciones indicadas
	void swap(int pos1, int pos2) {
		Node* i = getElementPos(pos1);
		Node* j = getElementPos(pos2);
		Node* aux = nullptr;

		if (i && j) {

			changeIndex(i, j);
			if (isAdjacent(i, j)) {
				if (i->prev)  i->prev->next = j;
				if (j->next) j->next->prev = i;
				j->prev = i->prev;
				i->prev = j;
				aux = j->next;
				j->next = i;
				i->next = aux;
				if (begin == i)
					begin = j;
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
				if (begin == i)
					begin = j;
			}

		}
	}

	//Verifica si dos nodos son adyacentes
	bool isAdjacent(Node* i, Node* j) {

		if (i->next == j || i->prev == j)
			return true;
		if (j->next == i || j->prev == i)
			return true;
		return false;
	}

	//Intercambia los indices de dos nodos
	void changeIndex(Node* i, Node* j) {
		int indexAux = i->index;
		i->index = j->index;
		j->index = indexAux;
	}

	//Pop del primer valor de la lista doble
	T getFirstValue() {
		if (!isEmpty()) {
			T value = begin->value;
			swap(1, amount);
			removePos(amount);
			return value;
		}
		return begin->value;
	}

	//Determina si la lisat doble esta vacia
	bool isEmpty() {
		if (!begin)
			return true;
		return false;
	}

	//toString
	std::string toString() {
		std::stringstream s;

		listptr tmp = begin;

		while (tmp) {
			s << "[" << tmp->value << "] ";
			tmp = tmp->next;
		}
		s << std::endl;

		return s.str();
	}
};

#endif // !DOUBLE_LIST