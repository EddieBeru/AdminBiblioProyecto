/*
* (c) 2025
* EIF204 - Programaci�n 2
* 1er Ciclo - 2025
* NRC 41372 - Grupo 8
* Proyecto 1
*
* 6-0499-0591; Berm�dez Ure�a, Edie
* 4-0264-0704; Arias Med�a, Roy
* 5-0460-0104; Ugalde, Felipe
*
* Version 1.0.0 2025-04-22
*/
#ifndef REVISTA_H
#define REVISTA_H

#include "Material.h"
using namespace std;

class Revista : public Material {
private:
    string ubicacion;
    int numero;
    int volumen;
    public:
    Revista(int numClasificacion = 0, int numCatalogo = 0, const std::string &titulo = "", const std::string &autores = "",
        const std::string &palabrasClave = "", const std::string &tipoMaterial = "", const std::string &estadoMaterial = "",
        const string &ubicacion = "", int numero = 0, int volumen = 0)
        : Material(numClasificacion, numCatalogo, titulo, autores, palabrasClave, tipoMaterial, estadoMaterial),
          ubicacion(ubicacion),
          numero(numero),
          volumen(volumen) {
    }

    string get_ubicacion() const;

    void set_ubicacion(const string &ubicacion);

    int get_numero() const;

    void set_numero(int numero);

    int get_volumen() const;

    void set_volumen(int volumen);

    //metodos virtuales puros siendo heredos de clase padre
    virtual int getDuracionPrestamo() const override;
    virtual string getTipo() const override;

    virtual std::string imprimir() const override;
};



#endif //REVISTA_H
