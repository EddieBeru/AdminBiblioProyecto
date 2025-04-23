#include "Fisico.h"

Fisico::Fisico(int numClasificacion, int numCatalogo, const std::string &titulo, const std::string &autores,
    const std::string &palabrasClave, const std::string &tipoMaterial, const std::string &estadoMaterial,
    const std::string &tipo_formato, const std::string &estilo_formato)
    : MaterialDigital(numClasificacion, numCatalogo, titulo, autores, palabrasClave, tipoMaterial, estadoMaterial, tipo_formato),
      estiloFormato(estilo_formato) {}

std::string Fisico::get_estilo_formato() const {
    return estiloFormato;
}

void Fisico::set_estilo_formato(const std::string &estilo_formato) {
    estiloFormato = estilo_formato;
}

std::string Fisico::getTipo() const {
    return "Fisico";
}

std::string Fisico::imprimir() const {
    return "Fisico:\n\t\tClasificacion: " + std::to_string(numClasificacion) +
           "\n\t\tCatalogo: " + std::to_string(numCatalogo) +
           "\n\t\tTitulo: " + titulo +
           "\n\t\tAutor(es): " + autores +
           "\n\t\tPalabras clave: " + palabrasClave +
           "\n\t\tTipo de material: " + tipoMaterial +
           "\n\t\tEstado: " + estadoMaterial +
           "\n\t\tFormato: " + tipoFormato +
           "\n\t\tEstilo de formato: " + estiloFormato;
}