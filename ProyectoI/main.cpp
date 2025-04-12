#include <iostream>

#include "Modelo/Libro.h"

int main() {

    // Create an instance of the Libro class
    Libro libro(12345, 67890, "Autor Ejemplo", "Palabra1, Palabra2", "Tipo Ejemplo", "Estado Ejemplo", "Ubicacion Ejemplo");

    std::cout << libro << std::endl;
    return 0;
}

