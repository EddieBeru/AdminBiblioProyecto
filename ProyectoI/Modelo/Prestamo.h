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
#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <iostream>
#include "Usuario.h"
#include "Material.h"

class Prestamo {
private:
	Usuario* usuario;
	Material* material;
	std::string fechaPrestamo;
	std::string fechaDevolucion;
public:
	Prestamo(Usuario&, Material&, std::string = "Desconocido", std::string = "Desconocido");
	virtual ~Prestamo() = default;

	Usuario* get_usuario();
	void set_usuario(Usuario&);

	Material* get_material() ;
	void set_material(Material&);

	std::string get_fecha_prestamo()const;
	void set_fecha_prestamo(const std::string);

	std::string get_fecha_devolucion() const;
	void set_fecha_devolucion(const std::string);

	friend bool operator<(const Prestamo& a, const Prestamo& b);
	friend bool operator<=(const Prestamo& a, const Prestamo& b);
	friend bool operator>(const Prestamo& a, const Prestamo& b);
	friend bool operator>=(const Prestamo& a, const Prestamo& b);
	friend bool operator==(const Prestamo& a, const Prestamo& b);
	friend bool operator!=(const Prestamo& a, const Prestamo& b);

	friend std::ostream& operator<<(std::ostream&, const Prestamo&);
};

#endif