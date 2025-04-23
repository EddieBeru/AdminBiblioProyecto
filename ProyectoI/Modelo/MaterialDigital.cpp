#include "MaterialDigital.h"

std::string MaterialDigital::get_tipo_formato() const {
    return tipoFormato;
}

void MaterialDigital::set_tipo_formato(const std::string &tipo_formato) {
    tipoFormato = tipo_formato;
}

int MaterialDigital::getDuracionPrestamo() const {
    return 5; //se prestan a lo mucho 5 dias
}

std::string MaterialDigital::getTipo() const {
    return "Material Digital: ";
}

std::string MaterialDigital::imprimir() const {
    return "Material Digital: " + std::to_string(get_num_clasificacion()) + ", " + std::to_string(get_num_catalogo()) + ", " + titulo + ", " +
           autores + ", " + palabrasClave + ", " + tipoMaterial + ", " + estadoMaterial + ", " + tipoFormato;
}

