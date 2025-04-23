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

    Contenedor<Usuario> * get_lista_usuarios() const;
    Usuario* get_usuario(int index) const;

    GestorUsuarios();
    void agregarUsuario(Usuario* usuario);

    friend std::ostream & operator<<(std::ostream &os, const GestorUsuarios &obj) {
        os << "Lista de materiales:\n";
        os << *obj.listaUsuarios;
        return os;
    }

    Usuario* buscarPorId(int id);
    bool modificarUsuario(int id, Usuario* datosNuevos);


};



#endif //GESTORUSUARIOS_H
