//
// Created by arias on 4/21/2025.
//

#include "AdminArchivos.h"

void AdminArchivos::guardarMateriales(GestorMateriales &gestor) {
    std::fstream archivo;
    archivo.open("materiales.bin", std::ios::binary | std::ios::out);
    if (!archivo.is_open()) {
        throw ErrorAbrirArchivo("usuarios.bin");
    }
    for (int i = 0; i < gestor.get_lista_materiales()->tamano(); i++) {
        Material* material = gestor.obtener_material(i);
        archivo.write(reinterpret_cast<char*>(material), sizeof(Material));
    }
    archivo.close();
}

void AdminArchivos::guardarUsuarios(GestorUsuarios &gestor) {
    std::fstream archivo;
    archivo.open("usuarios.bin", std::ios::binary | std::ios::out);
    if (!archivo.is_open()) {
        throw ErrorAbrirArchivo("usuarios.bin");
    }
    for (int i = 0; i < gestor.get_lista_usuarios()->tamano(); i++) {
        Usuario* usuario = gestor.get_usuario(i);
        archivo.write((char*)&usuario, sizeof(Usuario));
    }
    archivo.close();
}

void AdminArchivos::cargarMateriales(GestorMateriales &gestor) {
    std::fstream archivo;
    archivo.open("materiales.bin", std::ios::binary | std::ios::in);
    if (!archivo.is_open()) {
        throw ErrorAbrirArchivo("usuarios.bin");
    }
    while (!archivo.eof()) {
        Material* material;
        archivo.read(reinterpret_cast<char*>(material), sizeof(Material));
        if (archivo.gcount() == sizeof(Material)) {
            gestor.agregarMaterial(material);
        } else {
            delete material; // Eliminar el objeto si no se pudo leer correctamente
        }
    }
}

void AdminArchivos::cargarUsuarios(GestorUsuarios &gestor) {
    std::fstream archivo;
    archivo.open("usuarios.bin", std::ios::binary | std::ios::in);
    if (!archivo.is_open()) {
		throw ErrorAbrirArchivo("usuarios.bin");
    }
    while (!archivo.eof()) {
        Usuario *usuario = new Usuario();
        archivo.read((char*)&usuario, sizeof(Usuario));
        if (archivo.gcount() == sizeof(Usuario)) {
            gestor.agregarUsuario(usuario);
        } else {
           // delete usuario; // Eliminar el objeto si no se pudo leer correctamente
        }
    }
    archivo.close();
}

