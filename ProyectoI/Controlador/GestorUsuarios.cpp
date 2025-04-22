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
