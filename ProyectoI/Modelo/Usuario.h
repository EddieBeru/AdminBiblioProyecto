/*
* (c) 2025
* EIF204 - Programación 2
* 1er Ciclo - 2025
* NRC 41372 - Grupo 8
* Proyecto 1
*
* 6-0499-0591; Bermúdez Ureña, Edie
* 4-0264-0704; Arias Medía, Roy
* 5-0460-0104; Ugalde, Felipe
*
* Version 1.0.0 2025-04-22
*/
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