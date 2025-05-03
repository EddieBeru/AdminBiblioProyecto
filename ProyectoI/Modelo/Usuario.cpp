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
#include "Usuario.h"

Usuario::Usuario(int ced, const std::string nom, bool est) : cedula(ced), nombreCompleto(nom), estado(est){}

void Usuario::setCedula(int ced) { cedula = ced; }
int Usuario::getCedula() const { return cedula; }

void Usuario::setNombreCompleto(const std::string& nom) { nombreCompleto = nom; }
std::string Usuario::getNombreCompleto() const { return nombreCompleto; }

void Usuario::setEstado(bool est) { estado = est; }
bool Usuario::getEstado() const { return estado; }

bool operator<(const Usuario& a, const Usuario& b) { return a.cedula < b.cedula; }
bool operator<=(const Usuario& a, const Usuario& b) { return a.cedula <= b.cedula; }
bool operator>(const Usuario& a, const Usuario& b) { return a.cedula > b.cedula; }
bool operator>=(const Usuario& a, const Usuario& b) { return a.cedula >= b.cedula; }
bool operator==(const Usuario& a, const Usuario& b) {
	return
		(a.cedula == b.cedula) &&
		(a.nombreCompleto == b.nombreCompleto) &&
		(a.estado == b.estado);
}
bool operator!=(const Usuario& a, const Usuario& b) {
	return
		(a.cedula != b.cedula) ||
		(a.nombreCompleto != b.nombreCompleto) ||
		(a.estado != b.estado);
}

std::ostream& operator<<(std::ostream& os, const Usuario& a) {
	return os << "Usuario: " << std::endl
		<< "\t Cedula: " << a.cedula << std::endl
		<< "\t Nombre Completo: " << a.nombreCompleto << std::endl
		<< "\t Estado: " << (a.estado ? "Activo" : "Inactivo") << std::endl;

} 