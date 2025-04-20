//
// Created by arias on 4/11/2025.
//

#include "Libro.h"

Libro::Libro(const int numClasificacion,
        const int numCatalogo,
        const std::string &titulo,
        const std::string &autores,
        const std::string &palabrasClave,
        const std::string &tipoMaterial,
        const std::string &estadoMaterial,
        const std::string &ubicacion)
        : Material(numClasificacion, numCatalogo, titulo, autores, palabrasClave, tipoMaterial, estadoMaterial),
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

std::string Libro::imprimir() const {
    return "Libro:\n\t\tClasificacion: " + std::to_string(get_num_clasificacion()) +
           "\n\t\tCatalogo: " + std::to_string(get_num_catalogo()) +
           "\n\t\tTitulo: " + titulo +
           "\n\t\tAutor(es): " + autores +
           "\n\t\tPalabras clave: " + palabrasClave +
           "\n\t\tTipo de material: " + tipoMaterial +
           "\n\t\tEstado: " + estadoMaterial +
           "\n\t\tUbicacion: " + ubicacion;
}




