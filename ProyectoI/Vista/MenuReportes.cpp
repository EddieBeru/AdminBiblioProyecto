//
// Created by ugald on 24/4/2025.
//

#include "MenuReportes.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

MenuReportes::MenuReportes(GestorMateriales *materiales, GestorUsuarios *usuarios, GestorPrestamos *prestamos) :gestorMateriales(materiales), gestorUsuarios(usuarios), gestorPrestamos(prestamos) {
}
MenuReportes::~MenuReportes() {}

void MenuReportes::limpiarPantalla() {
    std::system("cls");
}
void MenuReportes::pausar() {
    std::cout<<"Presiones Enter para continuar: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
int MenuReportes::solicitarEntero(const std::string& mensaje) {
    int valor;
    while (true) {
        std::cout<<mensaje;
        if (std::cin>>valor) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Error: Ingrese un numero entero valido\n";
        }
    }
}
std::string MenuReportes::solicitarTexto(const std::string& mensaje) {
    std::string texto;
    std::cout << mensaje;
    std::getline(std::cin, texto);
    return texto;
}

void MenuReportes::mostrarMenu() {
    int opcion;
    bool volver = false;

    while (!volver) {
        limpiarPantalla();
        std::cout << "\n==============================================\n";
        std::cout << "          REPORTES DEL SISTEMA                \n";
        std::cout << "==============================================\n";
        std::cout << "1. Reporte de Inventario de materiales\n";
        std::cout << "2. Reporte de Usuarios\n";
        std::cout << "3. Materiales en Prestamo\n";
        std::cout << "4. Usuarios con Préstamos Activos\n";
        std::cout << "0. Volver al Menú Principal\n";
        std::cout << "==============================================\n";
        std::cout << "Seleccione una opción: ";

        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opción no válida\n";
            pausar();
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                //reporteMaterialesPorEstado();
            break;
            case 2:
                //reporteHistorialPrestamos();
            break;
            case 3:
                reporteMaterialesEnPrestamo();
            break;
            case 4:
                reportePrestamosPorUsuario();
            break;
            case 0:
                volver = true;
            break;
            default:
                std::cout << "Opción no válida\n";
            pausar();
            break;
        }
    }
}

void MenuReportes::reporteMaterialesEnPrestamo() {

}
void MenuReportes::reportePrestamosPorUsuario() {

}