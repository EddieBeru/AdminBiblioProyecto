//
// Created by arias on 4/11/2025.
//

#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <ostream>
#include <string>


class Material {
protected:
    int numClasificacion;
    int numCatalogo;
    std::string autores;
    std::string palabrasClave;
    std::string tipoMaterial;
    std::string estadoMaterial;
public:
    // Constructor
    Material(int numClasificacion , int numCatalogo , std::string autores , std::string palabrasClave,
             std::string tipoMaterial , std::string estadoMaterial);
    // Destructor
    virtual ~Material() = default;

    //setters y getters
    int get_num_clasificacion() const;
    void set_num_clasificacion(const int num_clasificacion);

    int get_num_catalogo() const;
    void set_num_catalogo(const int num_catalogo);

    std::string get_autores() const;
    void set_autores(const std::string &autores);

    std::string get_palabras_clave() const;
    void set_palabras_clave(const std::string &palabras_clave);

    std::string get_tipo_material() const;
    void set_tipo_material(const std::string &tipo_material);

    std::string get_estado_material() const;
    void set_estado_material(const std::string &estado_material);

    //Metodos virtuales
    virtual std::string getTipo() const = 0; // Método virtual puro para obtener el tipo de material
    virtual int getDuracionPrestamo() const = 0; // Método virtual puro para obtener la duración del préstamo, se va a trabajar en dias.

    friend std::ostream & operator<<(std::ostream &os, const Material &obj) {
        return os
               << "numClasificacion: " << obj.numClasificacion
               << " numCatalogo: " << obj.numCatalogo
               << " autores: " << obj.autores
               << " palabrasClave: " << obj.palabrasClave
               << " tipoMaterial: " << obj.tipoMaterial
               << " estadoMaterial: " << obj.estadoMaterial;
    }
};



#endif //MATERIAL_H
