#include "AdminArchivos.h"

#include "GestorPrestamos.h"

enum TipoMaterial {
    TIPO_LIBRO,
    TIPO_REVISTA,
    TIPO_DIGITAL_ENLINEA,
    TIPO_DIGITAL_FISICO,
};


void AdminArchivos::escribir_String(std::ofstream& archivo, const std::string& str) {
    size_t longS = str.size();
    archivo.write(reinterpret_cast<const char*>(&longS), sizeof(longS));
    archivo.write(str.c_str(), longS);
}

std::string AdminArchivos::leer_String(std::ifstream &archivo) {
    size_t longS;
    archivo.read(reinterpret_cast<char*>(&longS), sizeof(longS));
    std::string str(longS, '\0');
    archivo.read(&str[0], longS);
    return str;
}

void AdminArchivos::ser_Material(std::ofstream &archivo, const Material *material) {
    TipoMaterial tipo;

    if (dynamic_cast<const Libro*>(material)) {
        tipo = TIPO_LIBRO;
    } else if (dynamic_cast<const Revista*>(material)) {
        tipo = TIPO_REVISTA;
    } else if (dynamic_cast<const EnLinea*>(material)) {
        tipo = TIPO_DIGITAL_ENLINEA;
    } else if (dynamic_cast<const Fisico*>(material)) {
        tipo = TIPO_DIGITAL_FISICO;
    }

    archivo.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));
    int num_Clasificacion = material->get_num_clasificacion();
    int num_Catalogo = material->get_num_catalogo();
    archivo.write(reinterpret_cast<const char*>(&num_Clasificacion), sizeof(num_Clasificacion));
    archivo.write(reinterpret_cast<const char*>(&num_Catalogo), sizeof(num_Catalogo));
    escribir_String(archivo, material->get_titulo());
    escribir_String(archivo, material->get_autores());
    escribir_String(archivo, material->get_palabras_clave());
    escribir_String(archivo, material->get_tipo_material());
    escribir_String(archivo, material->get_estado_material());
}

void AdminArchivos::des_Material(std::ifstream &archivo, DatosMaterial &datos){
    archivo.read(reinterpret_cast<char*>(&datos.numClasificacion), sizeof(datos.numClasificacion));
    archivo.read(reinterpret_cast<char*>(&datos.numCatalogo), sizeof(datos.numCatalogo));
    datos.titulo = leer_String(archivo);
    datos.autores = leer_String(archivo);
    datos.palabrasClave = leer_String(archivo);
    datos.tipoMaterial = leer_String(archivo);
    datos.estadoMaterial = leer_String(archivo);
}

void AdminArchivos::ser_Libro(std::ofstream &archivo, const Libro *libro) {
    ser_Material(archivo,libro);
    escribir_String(archivo, libro->get_ubicacion());
}

Material *AdminArchivos::des_Libro(std::ifstream &archivo) {
    DatosMaterial datos;
    des_Material(archivo, datos);
    std::string ubicacion = leer_String(archivo);
    return new Libro(datos.numClasificacion, datos.numCatalogo, datos.titulo, datos.autores, datos.palabrasClave, datos.tipoMaterial, datos.estadoMaterial, ubicacion);
}

void AdminArchivos::ser_Revista(std::ofstream &archivo, const Revista *revista) {

}

Material *AdminArchivos::des_Revista(std::ifstream &archivo) {

}

void AdminArchivos::ser_MaterialDigital(std::ofstream &archivo, const MaterialDigital *material) {

}

Material *AdminArchivos::des_MaterialDigital(std::ifstream &archivo) {

}

void AdminArchivos::ser_EnLinea(std::ofstream &archivo, const EnLinea *enlinea) {

}

Material *AdminArchivos::des_EnLinea(std::ifstream &archivo) {

}

void AdminArchivos::ser_Fisico(std::ofstream &archivo, const Fisico *fisico) {

}

Material *AdminArchivos::des_Fisico(std::ifstream &archivo) {

}



/*-------------------------------------------------------------------------------------------------------------------------------------*/


void AdminArchivos::guardarMateriales(GestorMateriales &gestor) {
    std::ofstream archivo("materiales.bin", std::ios::binary);

    if (!archivo.is_open()) {
        throw ErrorAbrirArchivo("materiales.bin");
    }

    for (int i = 0;  i < gestor.get_lista_materiales()->tamano(); i++) {
        Material* material = gestor.obtener_material(i);

        if (Libro* libro = dynamic_cast<Libro*>(material)) {
            ser_Libro(archivo, libro);
        }
    }
    archivo.close();
}


void AdminArchivos::guardarUsuarios(GestorUsuarios &gestor) {

}

void AdminArchivos::cargarMateriales(GestorMateriales &gestor) {
 std::ifstream archivo("materiales.bin", std::ios::binary);
    if (!archivo.is_open()) {
        throw ErrorAbrirArchivo("materiales.bin");
    }

    TipoMaterial tipo;

    while (archivo.read(reinterpret_cast<char*>(&tipo), sizeof(tipo))) {
        Material* mat = nullptr;

            switch (tipo) {
                case TIPO_LIBRO:
                    mat = des_Libro(archivo);
                    break;
            }
        if (mat) {
            gestor.agregarMaterial(mat);
        }
    }
    archivo.close();
}

void AdminArchivos::cargarUsuarios(GestorUsuarios &gestor) {

}

