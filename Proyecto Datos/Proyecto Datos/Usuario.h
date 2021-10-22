#pragma once
class Usuario
{
private:
	char nombre;
	int prioridad;

public:
	Usuario(char n, int p) : nombre(n), prioridad(p){}

	const char getNomnbre() { return nombre;}
	const int getPrioridad() { return prioridad; }
};

