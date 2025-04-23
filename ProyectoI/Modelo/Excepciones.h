#include <iostream>
#include <exception>

class Excepcion : public std::exception {
private:
	std::string mensaje;
public:
	Excepcion(const std::string& msg) : mensaje(msg) {}
	virtual const char* what() const noexcept override {
		return mensaje.c_str();
	}
};

class NodoNoEncontrado : public Excepcion {
public:
	NodoNoEncontrado() : Excepcion("Nodo no encontrado") {}
};

class UsuarioNoencontrado : public Excepcion {
public:
	UsuarioNoencontrado() : Excepcion("Usuario no encontrado") {}
};

class MaterialNoEncontrado : public Excepcion {
public:
	MaterialNoEncontrado() : Excepcion("Material no encontrado") {}
};

class ErrorModificarMaterial : public Excepcion {
public:
	ErrorModificarMaterial() : Excepcion("No se pudo modificar el material") {}
};

class ErrorElimiarNodo : public Excepcion {
public:
	ErrorElimiarNodo() : Excepcion("No se pudo eliminar el nodo") {}
};

class ErrorAbrirArchivo : public Excepcion {
public:
	ErrorAbrirArchivo(std::string nombre = "") : Excepcion("Error al abrir el archivo: " + nombre) {}
};

