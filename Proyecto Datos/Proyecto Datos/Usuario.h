#ifndef USUARIO_H
#define USUARIO_H

#include <sstream>

class Usuario {
private:
	int prioridad;
	char id;

public:
	Usuario() : prioridad(0), id('!') {}
	Usuario(int p, char i) : prioridad(p), id(i) {}
	int getPrioridad() { return prioridad; }
	char getId() { return id; }

	void setPrioridad(int p) { this->prioridad = p; }
	void setId(char i) { this->id = i; }

	//Sobrecarga del operador >, compara si la prioridad es mayor
	bool operator > (Usuario const& u) { return prioridad > u.prioridad ? true : false; }

	//Sobrecarga del operador <, compara si la prioridad es menor
	bool operator < (Usuario const& u) { return prioridad < u.prioridad ? true : false; }

	//Sobrecarga el operador ==, compara si la prioridad es igual
	bool operator == (Usuario const& u) {
		return prioridad == u.prioridad ? true : false;
	}
	std::string toString() {
		std::stringstream s;
		s << "Usuario:\tId: " << id << "\tPrioridad: " << prioridad;
		return s.str();
	}

};	

std::ostream& operator<<(std::ostream& out, Usuario& u) {
	return out << u.toString();
}
#endif // !USUARIO_H




