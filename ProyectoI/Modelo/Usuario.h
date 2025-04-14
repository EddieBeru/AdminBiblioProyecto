#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

class Usuario {
private:
	int cedula;
	std::string nombreCompleto;
	bool estado;
public:
	Usuario(int = 0, const std::string = "", bool = false);
	virtual ~Usuario() = default;

	void setCedula(int);
	int getCedula() const;

	void setNombreCompleto(const std::string&);
	std::string getNombreCompleto() const;

	void setEstado(bool);
	bool getEstado() const;

	friend bool operator<(const Usuario& a, const Usuario& b);
	friend bool operator<=(const Usuario& a, const Usuario& b);
	friend bool operator>(const Usuario& a, const Usuario& b);
	friend bool operator>=(const Usuario& a, const Usuario& b);
	friend bool operator==(const Usuario& a, const Usuario& b);
	friend bool operator!=(const Usuario& a, const Usuario& b);

	friend std::ostream& operator<<(std::ostream& os, const Usuario& a);
};

#endif