//
// Created by arias on 4/15/2025.
//

#ifndef GESTORMATERIALES_H
#define GESTORMATERIALES_H

#include <ostream>

#include "../Modelo/Material.h"
#include "../Modelo/Contenedor.h"
#include "../Modelo/Libro.h"
#include "../Modelo/Revista.h"
#include "../Modelo/EnLinea.h"
#include "../Modelo/Fisico.h"
#include "../Modelo/MaterialDigital.h"


class GestorMateriales {
private:
  Contenedor<Material>* listaMateriales; // Contenedor de materiales
public:

  GestorMateriales();

  void agregarMaterial(Material *material); // Agrega un material al contenedor

  Material* buscarMaterialPorTitulo(const std::string& titulo) const;

  Material* buscarMaterialPorClasificacion(const int numClasificacion) const;

  friend std::ostream & operator<<(std::ostream &os, const GestorMateriales &obj) {
    os << "Lista de materiales:\n";
    os << *obj.listaMateriales;
    return os;
  }










};




#endif //GESTORMATERIALES_H
