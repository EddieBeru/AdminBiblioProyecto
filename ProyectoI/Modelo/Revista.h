//
// Created by arias on 4/11/2025.
//

#ifndef REVISTA_H
#define REVISTA_H

#include "Material.h"

class Revista: public Material {
private:
    std::string ubicacion;
    int numero;
    int volumen;

public:
    Revista(const int numClasificacion = 0, const int numCatalogo = 0, const std::string &autores = "",
            const std::string &palabrasClave = "", const std::string &tipoMaterial = "",
            const std::string &estadoMaterial = "", const std::string &nombre = "", const int numero = 0,
            const int volumen = 0);

    ~Revista() override = default;

    std::string get_nombre() const;

    void set_nombre(const std::string &nombre);

    int get_numero() const;

    void set_numero(const int numero);

    int get_volumen() const;

    void set_volumen(const int volumen);

    int getDuracionPrestamo() const override;
    std::string getTipo() const override;

    std::string imprimir() const override;

};



#endif //REVISTA_H
