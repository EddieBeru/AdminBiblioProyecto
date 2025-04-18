//
// Created by arias on 4/15/2025.
//

#ifndef GESTORUSUARIOS_H
#define GESTORUSUARIOS_H

#include <ostream>

#include "../Modelo/Usuario.h"
#include "../Modelo/Contenedor.h"
#include "../Modelo/Nodo.h"

class GestorUsuarios {
private:
    Contenedor<Usuario>* listaUsuarios; //contenedor de usuarios
    public:
    GestorUsuarios();
    void agregarUsuario(Usuario* usuario);

    friend std::ostream & operator<<(std::ostream &os, const GestorUsuarios *obj) {
        return os << "listaUsuarios: " << obj->listaUsuarios;
    }
};



#endif //GESTORUSUARIOS_H
