//
// Created by ugald on 11/4/2025.
//

#include "Revista.h"

std::string Revista::get_ubicacion() const {
    return ubicacion;
}

void Revista::set_ubicacion(const std::string &ubicacion) {
    this->ubicacion = ubicacion;
}

int Revista::get_numero() const {
    return numero;
}

void Revista::set_numero(int numero) {
    this->numero = numero;
}

int Revista::get_volumen() const {
    return volumen;
}

void Revista::set_volumen(int volumen) {
    this->volumen = volumen;
}

int Revista::getDuracionPrestamo() const {
    return 2; //2 dias maximo de prestamo
}

std::string Revista::getTipo() const {
    return "Revista"; //tipo es revista
}

std::string Revista::imprimir() const {
    return "Revista:\n\t\tClasificacion: " + std::to_string(get_num_clasificacion()) +
           "\n\t\tCatalogo: " + std::to_string(get_num_catalogo()) +
           "\n\t\tTitulo: " + titulo +
           "\n\t\tAutor(es): " + autores +
           "\n\t\tPalabras clave: " + palabrasClave +
           "\n\t\tTipo de material: " + tipoMaterial +
           "\n\t\tEstado: " + estadoMaterial +
           "\n\t\tUbicacion: " + ubicacion +
           "\n\t\tNumero: " + std::to_string(get_numero()) +
           "\n\t\tVolumen: " + std::to_string(get_volumen());
}