//
// Created by arias on 4/15/2025.
//

#include "GestorPrestamos.h"

GestorPrestamos::GestorPrestamos() {
    listaPrestamos=new Contenedor<Prestamo>();
}



void GestorPrestamos::agregarPrestamo(Prestamo *prestamo) {
    listaPrestamos->agregarFinal(new Nodo<Prestamo>(prestamo));
}
