//
// Created by ugald on 24/4/2025.
//

#ifndef MENUUSUARIOS_H
#define MENUUSUARIOS_H

#include "../Controlador/GestorUsuarios.h"
#include <iostream>
#include <limits>
#include <string>

class MenuUsuarios {
private:
GestorUsuarios *gestor;

//metodos de soporte o auxiliar
    void limpiarPantalla();
    void pausar();
    int solicitarEntero(const std::string& mensaje);
    std::string solicitarTexto(const std::string& mensaje);

//Metodos de operacion segun menu
    void agregarUsuario();
    void modificarUsuario();
    void mostrarUsuarios();
    void buscarUsuario();
public:
    MenuUsuarios(GestorUsuarios *gestorUsuarios);
    ~MenuUsuarios();

    void mostrarMenu();
};



#endif //MENUUSUARIOS_H
