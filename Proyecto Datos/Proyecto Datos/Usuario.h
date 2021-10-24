#ifndef USUARIO_H
#define USUARIO_H

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

	bool operator > (Usuario const& u) {
		return prioridad > u.prioridad ? true : false;
	}

	bool operator < (Usuario const& u) {
		return prioridad < u.prioridad ? true : false;
	}
};
#endif // !USUARIO_H




