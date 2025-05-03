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

#include "GestorUsuarios.h"

Contenedor<Usuario> * GestorUsuarios::get_lista_usuarios() const {
    return listaUsuarios;
}

Usuario* GestorUsuarios::get_usuario(int index) const {
    return listaUsuarios->buscar(index)->getItem();
}

GestorUsuarios::GestorUsuarios() {
    listaUsuarios=new Contenedor<Usuario>();
}

void GestorUsuarios::agregarUsuario(Usuario *usuario) {
    try {
        buscarPorId(usuario->getCedula());
        throw std::runtime_error("El usuario ya existe en la lista.");
    }
    catch (NodoNoEncontrado &ex) {
        listaUsuarios->agregarFinal(new Nodo<Usuario>(usuario));
    }
    catch (std::exception& ex) {
        throw;
    }
}

Usuario* GestorUsuarios::buscarPorId(int id) {
    try {
        Usuario* usr = listaUsuarios->find_if([&](Usuario* u) {
            if (auto usrAux = u) {
                return usrAux->getCedula() == id;
            }
            return false;
            });
        return static_cast<Usuario*>(usr);
    }
	catch (NodoNoEncontrado &ex) {
        throw UsuarioNoencontrado();
	}
    catch (std::exception &ex) {
        throw;
    }
}

bool GestorUsuarios::modificarUsuario(int id, Usuario *datosNuevos) {
    try {
        Usuario* usrMod = buscarPorId(id);
        if (usrMod->getCedula() == id) {
            usrMod->setNombreCompleto(datosNuevos->getNombreCompleto());
            usrMod->setEstado(datosNuevos->getEstado());
            return true;
        }
        else {
            return false;
        }
    }
    catch (NodoNoEncontrado& ex) {
        throw UsuarioNoencontrado();
    }
    catch (std::exception& ex) {
        throw;
    }
}


