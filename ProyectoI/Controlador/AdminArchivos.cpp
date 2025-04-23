#include "AdminArchivos.h"

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

void AdminArchivos::des_Libro(std::ofstream &archivo, const Libro *libro) {

    TipoMaterial tipo = TIPO_LIBRO;

    int num_Clasificacion = libro->get_num_clasificacion();
    int num_Catalogo = libro->get_num_catalogo();

    archivo.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));

    archivo.write(reinterpret_cast<const char*>(&num_Clasificacion), sizeof(num_Clasificacion));
    archivo.write(reinterpret_cast<const char*>(&num_Catalogo), sizeof(num_Catalogo));

    escribir_String(archivo, libro->get_titulo());
    escribir_String(archivo, libro->get_autores());
    escribir_String(archivo, libro->get_palabras_clave());
    escribir_String(archivo, libro->get_tipo_material());
    escribir_String(archivo, libro->get_estado_material());
    escribir_String(archivo, libro->get_ubicacion());
}

Libro *AdminArchivos::ser_Libro(std::ifstream &archivo) {
    int num_Clasificacion, num_Catalogo;

    archivo.read(reinterpret_cast<char*>(&num_Clasificacion), sizeof(int));
    archivo.read(reinterpret_cast<char*>(&num_Catalogo), sizeof(int));

    std::string titulo = leer_String(archivo);
    std::string autores = leer_String(archivo);
    std::string palabras_clave = leer_String(archivo);
    std::string tipo_material = leer_String(archivo);
    std::string estado_material = leer_String(archivo);
    std::string ubicacion = leer_String(archivo);

    return new Libro(num_Clasificacion, num_Catalogo, titulo, autores, palabras_clave, tipo_material, estado_material, ubicacion);
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
            des_Libro(archivo, libro);
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

    }
}

void AdminArchivos::cargarUsuarios(GestorUsuarios &gestor) {

}

