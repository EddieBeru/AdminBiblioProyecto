//
// Created by arias on 4/15/2025.
//

#include "GestorUsuarios.h"

GestorUsuarios::GestorUsuarios() {
    listaUsuarios=new Contenedor<Usuario>();
}

void GestorUsuarios::agregarUsuario(Usuario *usuario) {
    listaUsuarios->agregarFinal(new Nodo<Usuario>(usuario));
}
