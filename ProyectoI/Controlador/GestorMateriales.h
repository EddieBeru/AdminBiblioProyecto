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
  Contenedor<Material> * get_lista_materiales() const;

  GestorMateriales();

  void agregarMaterial(Material *material); // Agrega un material al contenedor

  Material* buscarMaterialPorTitulo(const std::string& titulo) const;

  Material* buscarMaterialPorClasificacion(const int numClasificacion) const;

  bool modificarMaterial(int numClasificacion, const Material& datosNuevos);

  bool modificarLibro(int numClasificacion, const Libro& datosNuevos);

  bool modificarRevista(int numClasificacion, const Revista& datosNuevos);

  bool modificarDigital(int numClasificacion, const MaterialDigital& datosNuevos);

  bool modificarFisico(int numClasificacion, const Fisico& datosNuevos);

  bool modificarEnLinea(int numClasificacion, const EnLinea& datosNuevos);

  Material* obtener_material(int index);

  friend std::ostream& operator<<(std::ostream& os, const GestorMateriales& a);

};



#endif //GESTORMATERIALES_H
