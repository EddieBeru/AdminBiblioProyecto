//
// Created by arias on 4/15/2025.
//

#ifndef GESTORPRESTAMOS_H
#define GESTORPRESTAMOS_H

#include <ostream>

#include "../Modelo/Prestamo.h"
#include "../Modelo/Contenedor.h"

class GestorPrestamos {
private:
    Contenedor<Prestamo>* listaPrestamos; //contenedor de prestamos
    public:
GestorPrestamos();

    void agregarPrestamo(Prestamo* prestamo); //agrega un prestamo al contenedor
    friend std::ostream & operator<<(std::ostream &os, const GestorPrestamos *obj) {
        return os << "listaPrestamos: " << obj->listaPrestamos;
    }
};


#endif //GESTORPRESTAMOS_H
