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