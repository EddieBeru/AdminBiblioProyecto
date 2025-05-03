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
#include "Prestamo.h"

Prestamo::Prestamo(Usuario& us, Material& mat, std::string fecPres, std::string fecDev) 
	: usuario(&us), material(&mat), fechaPrestamo(fecPres), fechaDevolucion(fecDev) {}

Usuario* Prestamo::get_usuario() { return usuario; }
void Prestamo::set_usuario(Usuario& us) { usuario = &us; }

Material* Prestamo::get_material() { return material; }
void Prestamo::set_material(Material& mat) { material = &mat; }

std::string Prestamo::get_fecha_prestamo() const { return fechaPrestamo; }
void Prestamo::set_fecha_prestamo(const std::string fecPres) { fechaPrestamo = fecPres; }

std::string Prestamo::get_fecha_devolucion() const { return fechaDevolucion; }
void Prestamo::set_fecha_devolucion(const std::string fecDev) { fechaDevolucion = fecDev; }

bool operator<(const Prestamo& a, const Prestamo& b) { return a.fechaDevolucion < b.fechaDevolucion; }
bool operator<=(const Prestamo& a, const Prestamo& b) { return a.fechaDevolucion <= b.fechaDevolucion; }
bool operator>(const Prestamo& a, const Prestamo& b) { return a.fechaDevolucion > b.fechaDevolucion; }
bool operator>=(const Prestamo& a, const Prestamo& b) { return a.fechaDevolucion >= b.fechaDevolucion; }
bool operator==(const Prestamo& a, const Prestamo& b) { 
	return (a.fechaDevolucion == b.fechaDevolucion) &&
		(a.fechaPrestamo == b.fechaPrestamo) &&
		(a.usuario == b.usuario) &&
		(a.material == a.material); 
}
bool operator!=(const Prestamo& a, const Prestamo& b) {
	return (a.fechaDevolucion != b.fechaDevolucion) ||
		(a.fechaPrestamo != b.fechaPrestamo) ||
		(a.usuario != b.usuario) ||
		(a.material != a.material);
}

std::ostream& operator<<(std::ostream& os, const Prestamo& a) {
	return os << "Prestamo: " << std::endl
		<< "\t Usuario: " << *(a.usuario) << std::endl
		<< "\t Material: " << *(a.material) << std::endl
		<< "\n\t Fecha Prestamo: " << a.fechaPrestamo << std::endl
		<< "\t Fecha Devolucion: " << a.fechaDevolucion << std::endl;
}