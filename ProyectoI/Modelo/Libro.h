//
// Created by arias on 4/11/2025.
//

#ifndef LIBRO_H
#define LIBRO_H

#include "Material.h"

class Libro: public Material {
private:
    std::string ubicacion;

public:
    Libro(const int numClasificacion,
        const int numCatalogo,
        const std::string &titulo,
        const std::string &autores,
        const std::string &palabrasClave,
        const std::string &tipoMaterial,
        const std::string &estadoMaterial,
        const std::string &ubicacion = "");

    ~Libro() override;

    std::string get_ubicacion() const;

    void set_ubicacion(const std::string &ubicacion);

    std::string getTipo() const override;
    int getDuracionPrestamo() const override;

    std::string imprimir() const override;

};



#endif //LIBRO_H
