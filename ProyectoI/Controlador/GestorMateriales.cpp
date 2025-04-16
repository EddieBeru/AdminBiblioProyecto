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






