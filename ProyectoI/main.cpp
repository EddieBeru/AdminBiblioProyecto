#include <iostream>

#include "Modelo/Libro.h"
#include "Nodo.h"
#include "Contenedor.h"

int main() {
	/*
 Libro libro(12345, 67890, "ejemplo titulo","Autor Ejemplo", "Palabra1, Palabra2", "Tipo Ejemplo", "Estado Ejemplo", "Ubicacion Ejemplo");
    Revista revista(12345, 67890, "ejemplo titulo","autor ejemplo", "Palabra1, Palabra2", "Tipo Ejemplo", "Estado Ejemplo", "ubicacion ejenplo", 1, 1);
    MaterialDigital mdigital(12345, 67890,"ejemplo titulo", "Autor Ejemplo", "Palabra1, Palabra2", "Tipo Ejemplo", "Estado Ejemplo", "ejemplo formato");
    Fisico fisico(12345, 67890,"ejemplo titulo", "Autor Ejemplo", "Palabra1, Palabra2", "Tipo Ejemplo", "Estado Ejemplo", "ejemplo formato", "estilo ejemplo");
    EnLinea enlinea(12345, 67890,"ejemplo titulo", "Autor Ejemplo", "Palabra1, Palabra2", "Tipo Ejemplo", "Estado Ejemplo", "ejemplo formato", true);
    std::cout << libro << std::endl;
    std::cout << revista << std::endl;
    std::cout << mdigital << std::endl;
    std::cout << fisico << std::endl;
    std::cout << enlinea << std::endl;
    std::cout << enlinea.getDuracionPrestamo() << std::endl;
    */
    Libro* p = new Libro(111, 1, "Don Quijote", "", "", "", "", "");
    std::cout << *p << std::endl;
    Libro* p2 = new Libro(21, 1, "El Principito", "", "", "", "", "");
    std::cout << *p2 << std::endl;
    Libro* p3 = new Libro(21, 1, "Diario de Ana Frank", "", "", "", "", "");
    std::cout << *p2 << std::endl;

    std::cout << ((p < p2) ? "p es menor" : "p2 es mayor o igual") << std::endl;
    std::cout << ((p <= p2) ? "p es menor o igual" : "p2 es mayor") << std::endl;
    std::cout << ((p > p2) ? "p es mayor" : "p2 es menor o igual") << std::endl;
    std::cout << ((p >= p2) ? "p es mayor o igual" : "p2 es menor") << std::endl;
    std::cout << ((p == p2) ? "p es igual a p2" : "p2 no es igual a p") << std::endl;
    std::cout << ((p != p2) ? "p no es igual a p2" : "p2 es igual a p") << std::endl;

    Contenedor<Libro>* contenedor = new Contenedor<Libro>();
	contenedor->agregarPrincipio(new Nodo<Libro>(*p2));
    contenedor->agregarPrincipio(new Nodo<Libro>(*p));
	contenedor->agregarFinal(new Nodo<Libro>(*p3));
    std::cout << *contenedor << std::endl;
	system("pause");

	contenedor->ordenarAscendente();
	std::cout << *contenedor << std::endl;

    return 0;
}