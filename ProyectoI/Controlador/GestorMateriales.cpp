//
// Created by arias on 4/15/2025.
//

#include "GestorMateriales.h"

GestorMateriales::GestorMateriales(){
    listaMateriales = new Contenedor<Material>();
}

void GestorMateriales::agregarMaterial(Material *material) {
    listaMateriales->agregarFinal(new Nodo<Material>(material));
}

Material *GestorMateriales::buscarMaterialPorTitulo(const std::string &titulo) const {
    Material *mat = listaMateriales->find_if([&](Material *m) {
        if (auto matAux = dynamic_cast<Material *>(m)) {
            return matAux->get_titulo() == titulo;
        }
        return false;
    });
    return static_cast<Material *>(mat);
}

Material *GestorMateriales::buscarMaterialPorClasificacion(const int numClasificacion) const {
    Material *mat = listaMateriales->find_if([&](Material *m) {
       if (auto matAux = dynamic_cast<Material *>(m)) {
           return matAux->get_num_clasificacion() == numClasificacion;
       }
        return false;
    });
    return static_cast<Material *>(mat);
}








