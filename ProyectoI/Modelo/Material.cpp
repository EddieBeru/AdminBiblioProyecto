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
#include "Material.h"

//Definicion del constructor con valores por defecto
Material::Material(const int numClasificacion,
                   const int numCatalogo,
                   const std::string &titulo,
                   const std::string &autores,
                   const std::string &palabrasClave,
                   const std::string &tipoMaterial,
                   const std::string &estadoMaterial)
    :numClasificacion(numClasificacion),
      numCatalogo(numCatalogo),
      titulo(titulo),
      autores(autores),
      palabrasClave(palabrasClave),
      tipoMaterial(tipoMaterial),
      estadoMaterial(estadoMaterial) {
}

Material::~Material() {
}

//Setters y Getters
int Material::get_num_clasificacion() const {
    return numClasificacion;
}

void Material::set_num_clasificacion(const int num_clasificacion) {
    numClasificacion = num_clasificacion;
}

int Material::get_num_catalogo() const {
    return numCatalogo;
}

void Material::set_num_catalogo(const int num_catalogo) {
    numCatalogo = num_catalogo;
}

std::string Material::get_titulo() const {
  return titulo;
}
void Material::set_titulo(const std::string &titulo){
  this->titulo = titulo;
}

std::string Material::get_autores() const {
    return autores;
}

void Material::set_autores(const std::string &autores) {
    this->autores = autores;
}

std::string Material::get_palabras_clave() const {
    return palabrasClave;
}

void Material::set_palabras_clave(const std::string &palabras_clave) {
    palabrasClave = palabras_clave;
}

std::string Material::get_tipo_material() const {
    return tipoMaterial;
}

void Material::set_tipo_material(const std::string &tipo_material) {
    tipoMaterial = tipo_material;
}

std::string Material::get_estado_material() const {
    return estadoMaterial;
}

void Material::set_estado_material(const std::string &estado_material) {
    estadoMaterial = estado_material;
}

//Sobrecarga del operador de salida
std::ostream & operator<<(std::ostream &os, const Material &obj) {
    return os << obj.imprimir();
}

//Sobrecarga de distintos operadores de comparaci�n
bool operator<(const Material& a, const Material& b) {
    return a.get_titulo() < b.get_titulo();
}
bool operator<=(const Material& a, const Material& b) {
    return a.get_titulo() <= b.get_titulo();
}
bool operator>(const Material& a, const Material& b) {
    return a.get_titulo() > b.get_titulo();
}
bool operator>=(const Material& a, const Material& b) {
    return a.get_titulo() >= b.get_titulo();
}
bool operator==(const Material& a, const Material& b) {
    return (a.titulo == b.titulo) &&
        (a.numClasificacion == b.numClasificacion) &&
        (a.numCatalogo == b.numCatalogo) &&
        (a.getTipo() == b.getTipo());
}
bool operator!=(const Material& a, const Material& b) {
    return (a.titulo != b.titulo) ||
        (a.numClasificacion != b.numClasificacion) ||
        (a.numCatalogo != b.numCatalogo) ||
        (a.getTipo() != b.getTipo());
}