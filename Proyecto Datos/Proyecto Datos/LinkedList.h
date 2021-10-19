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
        this->sig = NULL;
        this->ant = NULL;
    }

    Nodo() {
        cont = 0;
        this->sig = NULL;
        this->ant = NULL;
    }
};

template<typename T>
class LinkedList {
private:
    Nodo<T>* head;
public:
    LinkedList() {
        this->head = NULL;
    }

    void insertarFinal(T elem) {
        Nodo<T>* nodo = new Nodo<T>;
        nodo->cont = elem;
        if (head == NULL) {
            head = nodo;
            return;
        }
        Nodo<T>* temp = head;
        Nodo<T>* prev = nullptr;
        while (temp->sig != NULL) {
            prev = temp;
            temp = temp->sig;
        }
        temp->sig = nodo;
        temp->ant = prev;
    }


    void insertarInicio(T item) {
        Nodo<T>* n = new Nodo<T>[1];
        n->cont = item;
        if (head == NULL) {
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
        while (temp != NULL) {
            len++;
            temp = temp->sig;
        }
        return len;
    }

    void imprimir() {
        if (head == NULL) {
            cout << "No hay elementos en la lista" << endl;
            return;
        }
        Nodo<T>* temp = head;
        while (temp != NULL) {
            cout << temp->cont << ", ";
            temp = temp->sig;
        }
    }

    void eliminar() {
        if (head == NULL) {
            cout << "lista vacia" << endl;
            return;
        }
        if (head->sig == NULL) {
            head = NULL;
            return;
        }
        Nodo<T>* temp = head;
        while (temp != NULL) {
            if (temp->sig->sig == NULL) {
                temp->sig = NULL;
                break;
            }
            temp = temp->sig;
        }

    }

    void eliminar(int pos) {
        if (head == NULL) {
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
        while (temp != NULL) {
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
        if (head == NULL) {
            cout << "lista vacia" << endl;
            return;
        }
        head = head->sig;
        head->sig->ant = head;
    }

    T get(int index) {
        if (head == NULL) {
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
        while (temp != NULL) {
            if (count++ == index) {
                res = temp->cont;
                break;
            }
            temp = temp->sig;
        }
        return res;
    }

};