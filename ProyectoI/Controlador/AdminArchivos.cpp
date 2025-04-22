//
// Created by arias on 4/21/2025.
//

#include "AdminArchivos.h"

void AdminArchivos::guardarMateriales(GestorMateriales &gestor) {
    std::ofstream archivo("materiales.bin", std::ios::binary | std::ios::out| std::ios::app);
    if (archivo.is_open()) {
        for (int i = 0; i < gestor.get_lista_materiales()->tamano(); i++) {
            Material* material = gestor.obtener_material(i);
            archivo.write((char*)&material, sizeof(Material));
        }
    }
}

