//
// Created by arias on 4/21/2025.
//

#include "AdminArchivos.h"

void AdminArchivos::guardarMateriales(GestorMateriales &gestor) {
    std::fstream archivo;
    archivo.open("materiales.bin", std::ios::binary | std::ios::out);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo materiales.bin" << std::endl;
        return;
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
        std::cerr << "Error al abrir el archivo usuarios.bin" << std::endl;
        return;
    }
    for (int i = 0; i < gestor.get_lista_usuarios()->tamano(); i++) {
        Usuario* usuario = gestor.get_usuario(i);
        archivo.write(reinterpret_cast<char*>(usuario), sizeof(Usuario));
    }
    archivo.close();
}

