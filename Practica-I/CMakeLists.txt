cmake_minimum_required(VERSION 3.30)
project(Practica_I)

set(CMAKE_CXX_STANDARD 20)

add_executable(Practica_I main.cpp
        Material.cpp
        Material.h
        Utilities.h
        Book.cpp
        Book.h
        Magazine.cpp
        Magazine.h
        FilesManager.cpp
        FilesManager.h
)
