//
// Created by Roy Arias on 25/3/2025.
//

#include "FilesManager.h"

template<class T>
void FilesManager<T>::saveFiles(const T& data) {
    std::ofstream file;
    try {
        file.open("catalog.bin", std::ios::binary | std::ios::out);
        if (!file.is_open()) {
            throw std::runtime_error("Error al abrir el archivo.");
        }
        data.serialize(file);  // Llama a la serialización del objeto
        file.close();

    }catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
template<class T>
void FilesManager<T>::openFiles() {
    std::ifstream file("catalog.bin", std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Error al abrir el archivo.");
    }

    T data;
    while (file.peek() != EOF) {
        data.deserialize(file);  // Llama a la deserialización del objeto
        std::cout << data << std::endl;
    }
    file.close();
}

