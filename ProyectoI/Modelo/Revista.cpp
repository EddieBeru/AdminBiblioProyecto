//
// Created by arias on 4/11/2025.
//

#include "Revista.h"

std::string Revista::get_nombre() const {
    return nombre;
}

void Revista::set_nombre(const std::string &nombre) {
    this->nombre = nombre;
}

int Revista::get_numero() const {
    return numero;
}

void Revista::set_numero(const int numero) {
    this->numero = numero;
}

int Revista::get_volumen() const {
    return volumen;
}

void Revista::set_volumen(const int volumen) {
    this->volumen = volumen;
}

Revista::Revista(const int numClasificacion, const int numCatalogo, const std::string &autores,
                 const std::string &palabrasClave, const std::string &tipoMaterial, const std::string &estadoMaterial,
                 const std::string &nombre, const int numero, const int volumen)
        : Material(numClasificacion, numCatalogo, autores, palabrasClave, tipoMaterial, estadoMaterial),
          nombre(nombre),
          numero(numero),
          volumen(volumen) {
}
