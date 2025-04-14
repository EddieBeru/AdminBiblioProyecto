//
// Created by arias on 4/11/2025.
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
    return "Revista" + std::to_string(get_num_clasificacion()) + ", " + std::to_string(get_num_catalogo()) + ", " + titulo + ", " +
           autores + ", " + palabrasClave + ", " + tipoMaterial + ", " + estadoMaterial + ", " + ubicacion + ", " + std::to_string(get_numero()) + ", " + std::to_string(get_volumen());
}