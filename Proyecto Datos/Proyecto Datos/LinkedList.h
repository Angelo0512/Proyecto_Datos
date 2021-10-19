#include<iostream>
using namespace std;

template<typename T>
class Nodo {
public:
    T cont;
    Nodo<T>* sig;
    Nodo<T>* ant;

    Nodo(T c) {
        cont = c;
        this->sig = nullptr;
        this->ant = nullptr;
    }

    Nodo() {
        cont = 0;
        this->sig = nullptr;
        this->ant = nullptr;
    }
};

template<typename T>
class LinkedList {
private:
    Nodo<T>* head;
    Nodo<T>* last;
public:
    LinkedList() {
        this->head = nullptr;
        this->last = this->head;
    }

    void insertarFinal(T elem) {
        Nodo<T>* nodo = new Nodo<T>;
        nodo->cont = elem;
        if (head == nullptr) {
            head = nodo;
            return;
        }
        Nodo<T>* temp = head;
        Nodo<T>* prev = nullptr;
        while (temp->sig != nullptr) {
            prev = temp;
            temp = temp->sig;
        }
        temp->sig = nodo;
        temp->ant = prev;
    }


    void insertarInicio(T item) {
        Nodo<T>* n = new Nodo<T>[1];
        n->cont = item;
        if (head == nullptr) {
            head = n;
            return;
        }
        head->ant = n;
        n->sig = head;
        head = n;
    }

    int length() {
        int len = 0;
        Nodo<int>* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->sig;
        }
        return len;
    }

    void imprimir() {
        if (head == nullptr) {
            cout << "No hay elementos en la lista" << endl;
            return;
        }
        Nodo<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->cont << ", ";
            temp = temp->sig;
        }
    }

    void eliminar() {
        //Lista vacia
        if (head == nullptr) {
            cout << "lista vacia" << endl;
            return;
        }
        //Elimina primero
        if (head->sig == nullptr) {
            delete head;
            return;
        }
        //Busca pos y elimina
        Nodo<T>* temp = head;
        while (temp != nullptr) {
            if (temp->sig->sig == nullptr) {
                last = last->ant;
                delete temp->sig;
                break;
            }
            temp = temp->sig;
        }

    }

    void eliminar(int pos) {
        if (head == nullptr) {
            cout << "linked list is empty !" << endl;
            return;
        }
        if (pos >= length() || pos < 0) {
            cout << "index out of bound !" << endl;
            return;
        }
        if (pos == 0) {
            eliminarFinal();
            cout << "item removed at index " << pos << endl;
            return;
        }
        int count = 0;
        Nodo<T>* temp = head;
        while (temp != nullptr) {
            if (count == pos - 1) {
                temp->sig = temp->sig->sig;
                cout << "item removed at index " << pos << endl;
                break;
            }
            count++;
            temp = temp->sig;
        }
    }

    void eliminarFinal() {
        if (head == nullptr) {
            cout << "lista vacia" << endl;
            return;
        }
        head = head->sig;
        head->sig->ant = head;
    }

    T get(int index) {
        if (head == nullptr) {
            cout << "lista vacia" << endl;
            return -1;
        }
        if (index >= length() || index < 0) {
            cout << "posición inválida" << endl;
            return -1;
        }
        if (index == 0) {
            return head->cont;
        }
        int count = 0;
        T res = NULL;
        Nodo<T>* temp = head;
        while (temp != nullptr) {
            if (count++ == index) {
                res = temp->cont;
                break;
            }
            temp = temp->sig;
        }
        return res;
    }

    Nodo<T>* getNodo(int index) {
        if (head == nullptr) {
            cout << "lista vacia" << endl;
            return nullptr;
        }
        if (index >= length() || index < 0) {
            cout << "posición inválida" << endl;
            return nullptr;
        }
        if (index == 0) {
            return head;
        }
        int count = 0;
        T res = NULL;
        Nodo<T>* temp = head;
        while (temp != nullptr) {
            if(count++ == index)
                return temp;
            temp = temp->sig;
        }
        return nullptr;
    }
    
    void swap(int a, int b) {
        int len = length();
        if (len && a < len && b < len && a != b) {
            Nodo<T>* nodoA =  getNodo(a);
            Nodo<T>* nodoB = getNodo(b);
            std::swap(nodoA->cont, nodoB->cont);
        }
    }
};