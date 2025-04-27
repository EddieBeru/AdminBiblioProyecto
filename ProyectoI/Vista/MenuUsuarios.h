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
