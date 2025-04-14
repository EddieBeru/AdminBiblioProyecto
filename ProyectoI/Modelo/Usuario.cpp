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