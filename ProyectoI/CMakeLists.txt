cmake_minimum_required(VERSION 3.30)
project(ProyectoI)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoI main.cpp
        Contenedor.h
        Nodo.h
        Modelo/Material.cpp
        Modelo/Material.h
        Modelo/Libro.cpp
        Modelo/Libro.h
        Modelo/Revista.cpp
        Modelo/Revista.h
        Modelo/MaterialDigital.cpp
        Modelo/MaterialDigital.h
        Modelo/Fisico.cpp
        Modelo/Fisico.h
        Modelo/EnLinea.cpp
        Modelo/EnLinea.h
        Modelo/Usuario.cpp
        Modelo/Usuario.h 
        Modelo/Prestamo.h 
        Modelo/Prestamo.cpp)
