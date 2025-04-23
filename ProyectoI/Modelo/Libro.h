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
#ifndef LIBRO_H
#define LIBRO_H

#include "Material.h"

class Libro: public Material {
private:
    std::string ubicacion;

public:
    Libro(const int numClasificacion = 0,
        const int numCatalogo = 0,
        const std::string &titulo = "",
        const std::string &autores = "",
        const std::string &palabrasClave = "",
        const std::string &tipoMaterial = "",
        const std::string &estadoMaterial = "",
        const std::string &ubicacion = "");

    ~Libro() override;

    std::string get_ubicacion() const;

    void set_ubicacion(const std::string &ubicacion);

    std::string getTipo() const override;
    int getDuracionPrestamo() const override;

    std::string imprimir() const override;

};


#endif //LIBRO_H
