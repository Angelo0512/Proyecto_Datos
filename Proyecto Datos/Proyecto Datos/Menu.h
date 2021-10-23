#pragma once
#include "IPriorityQueue.h"
#include "Usuario.h"
#include <iostream>
class Menu{
private:
	IPriorityQueue PriorityQueue = PriorityQueue ();
public:
	void mostrar();

	void insertar();

	void eliminar();
};