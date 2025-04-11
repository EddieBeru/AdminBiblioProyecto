//
// Created by arias on 4/11/2025.
//

#include "Libro.h"

Libro::Libro(const int numClasificacion, const int numCatalogo, const std::string &autores,
        const std::string &palabrasClave, const std::string &tipoMaterial, const std::string &estadoMaterial,
        const std::string &ubicacion)
        : Material(numClasificacion, numCatalogo, autores, palabrasClave, tipoMaterial, estadoMaterial),
          ubicacion(ubicacion) {
}

Libro::~Libro() {
}

std::string Libro::getTipo() const {
    return "Libro";
}

int Libro::getDuracionPrestamo() const {
    return 7; // 7 dias
}

std::string Libro::get_ubicacion() const {
    return ubicacion;
}

void Libro::set_ubicacion(const std::string &ubicacion) {
    this->ubicacion = ubicacion;
}
