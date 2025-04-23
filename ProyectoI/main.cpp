#include <iostream>

#include "Modelo/Libro.h"
#include "Modelo/Nodo.h"
#include "Modelo/Contenedor.h"
#include "Controlador/GestorMateriales.h"
#include "Controlador/GestorPrestamos.h"
#include "Controlador/GestorUsuarios.h"
#include "Controlador/AdminArchivos.h"

int main() {
	/*
 Libro libro(12345, 67890, "ejemplo titulo","Autor Ejemplo", "Palabra1, Palabra2", "Tipo Ejemplo", "Estado Ejemplo", "Ubicacion Ejemplo");
	Revista revista(12345, 67890, "ejemplo titulo","autor ejemplo", "Palabra1, Palabra2", "Tipo Ejemplo", "Estado Ejemplo", "ubicacion ejenplo", 1, 1);
	MaterialDigital mdigital(12345, 67890,"ejemplo titulo", "Autor Ejemplo", "Palabra1, Palabra2", "Tipo Ejemplo", "Estado Ejemplo", "ejemplo formato");
	Fisico fisico(12345, 67890,"ejemplo titulo", "Autor Ejemplo", "Palabra1, Palabra2", "Tipo Ejemplo", "Estado Ejemplo", "ejemplo formato", "estilo ejemplo");
	EnLinea enlinea(12345, 67890,"ejemplo titulo", "Autor Ejemplo", "Palabra1, Palabra2", "Tipo Ejemplo", "Estado Ejemplo", "ejemplo formato", true);
	std::cout << libro << std::endl;
	std::cout << revista << std::endl;
	std::cout << mdigital << std::endl;
	std::cout << fisico << std::endl;
	std::cout << enlinea << std::endl;
	std::cout << enlinea.getDuracionPrestamo() << std::endl;
	*/
	/*Libro* p = new Libro(111, 1, "Don Quijote", "", "", "", "", "");
	std::cout << *p << std::endl;
	Libro* p2 = new Libro(21, 1, "El Principito", "", "", "", "", "");
	std::cout << *p2 << std::endl;
	Libro* p3 = new Libro(21, 1, "Diario de Ana Frank", "", "", "", "", "");
	std::cout << *p2 << std::endl;

	std::cout << ((p < p2) ? "p es menor" : "p2 es mayor o igual") << std::endl;
	std::cout << ((p <= p2) ? "p es menor o igual" : "p2 es mayor") << std::endl;
	std::cout << ((p > p2) ? "p es mayor" : "p2 es menor o igual") << std::endl;
	std::cout << ((p >= p2) ? "p es mayor o igual" : "p2 es menor") << std::endl;
	std::cout << ((p == p2) ? "p es igual a p2" : "p2 no es igual a p") << std::endl;
	std::cout << ((p != p2) ? "p no es igual a p2" : "p2 es igual a p") << std::endl;

	Contenedor<Libro>* contenedor = new Contenedor<Libro>();
	contenedor->agregarPrincipio(new Nodo<Libro>(*p2));
	contenedor->agregarPrincipio(new Nodo<Libro>(*p));
	contenedor->agregarFinal(new Nodo<Libro>(*p3));
	std::cout << *contenedor << std::endl;
	system("pause");

	contenedor->ordenarAscendente();
	std::cout << *contenedor << std::endl;*/

	//prueba de gestor de materiales
	/*Material* libro = new Libro(12345, 67890, "ejemplo titulo", "Autor Ejemplo", "Palabra1, Palabra2", "Tipo Ejemplo", "Estado Ejemplo", "Ubicacion Ejemplo");
	//Crear revista con datos diferentes al libro
	Material* revista = new Revista(54321, 98765, "Titulo Revista", "Autor Revista", "Palabra3, Palabra4", "Tipo Revista", "Estado Revista", "Ubicacion Revista", 10, 5);
	//Crear material digital
	Material* materialDigitalEnLinea = new EnLinea(77889, 99001, "Curso de Programacion en C++", "Jane Smith", "Programacion, Tecnologia", "Curso en Linea", "Disponible", "Formato PDF", true);
	gestor->agregarMaterial(revista);
	gestor->agregarMaterial(libro);
	gestor->agregarMaterial(materialDigitalEnLinea);

	std::cout << *gestor << std::endl;

	//Prueba de busqueda por titulo
	//std::cout << *(gestor->buscarMaterialPorTitulo("ejemplo titulo")) << endl;

	//Prueba de busqueda por clasificacion
	//std::cout << *(gestor->buscarMaterialPorClasificacion(12345)) << endl;

	//Prueba de modificacion
	//Se modifica autor y ubicacion del libro
	Libro libroModificado(12345, 67890, "ejemplo titulo", "Autor Modificado", "Palabra1, Palabra2", "Tipo Ejemplo", "Estado Ejemplo", "Ubicacion Modificada");
	gestor->modificarLibro(12345, libroModificado);
	std::cout << *(gestor->buscarMaterialPorTitulo("ejemplo titulo")) << endl;

	//Prueba de modificacion de revista
	Revista revistaModificada(54321, 98765, "Titulo Revista", "Autor Modificado", "Palabra3, Palabra4", "Tipo Revista", "Estado Modificado", "Ubicacion Modificada", 20, 10);
	gestor->modificarRevista(54321, revistaModificada);
	std::cout << *(gestor->buscarMaterialPorClasificacion(54321)) << endl;

	//Prueba de modificacion de material digital
	EnLinea materialDigitalModificado(77889, 99001, "Curso de Programacion en C++", "Jane Smith", "Programacion, Tecnologia", "Curso en Linea", "No Disponible", "Formato PDF", false);
	gestor->modificarEnLinea(77889, materialDigitalModificado);
	std::cout << *(gestor->buscarMaterialPorClasificacion(77889)) << endl;


	GestorUsuarios* gestor2 = new GestorUsuarios();
	Usuario* usuario = new Usuario(12345678, "Juan Perez", true);
	gestor2->agregarUsuario(usuario);

	//std::cout << *gestor2 << std::endl;

	std::cout << *gestor2->buscarPorId(12345678) << std::endl;

	//Prueba de modificacion de usuario
	Usuario usuarioModificado(12345678, "Juan Perez Modificado", false);
	gestor2->modificarUsuario(12345678, &usuarioModificado);
	std::cout << *gestor2->buscarPorId(12345678) << std::endl;

	try {
		if (gestor2->buscarPorId(222)) {
			std::cout << "Usuario encontrado" << std::endl;
			std::cout << *gestor2->buscarPorId(222) << std::endl;
		}
	}
	catch (const Excepcion& e) {
		std::cerr << e.what() << std::endl;
		//return 1;
	}
	catch (const std::exception& e) {
		std::cerr << "Excepción: " << e.what() << std::endl;
		//return 2;
	}
	catch (...) {
		std::cerr << "Error desconocido." << std::endl;
		//return 3;
	}
	AdminArchivos::guardarMateriales(*gestor);
	AdminArchivos::guardarUsuarios(*gestor2);

	delete gestor;
	delete gestor2;

	/**GestorPrestamos* prestamoGestor = new GestorPrestamos();
	Usuario* usuario1=new Usuario();
	Prestamo* prestamo1=new Prestamo(*usuario1, *libro, "fecha ejemplo", "fecha Ejemplo");
	prestamoGestor->agregarPrestamo(prestamo1);

	std::cout << *prestamoGestor << std::endl;*/


	//AdminArchivos::guardarUsuarios(*gestorUsuarios);


	GestorMateriales* gestor = new GestorMateriales();

	Material *matEj = new Libro(12345, 67890, "ejemplo titulo", "Autor Ejemplo", "Palabra1, Palabra2", "Tipo Ejemplo", "Estado Ejemplo", "Ubicacion Ejemplo");
	Material *matEj2 = new Revista(54321, 98765, "Titulo Revista", "Autor Revista", "Palabra3, Palabra4", "Tipo Revista", "Estado Revista", "Ubicacion Revista", 10, 5);
	Material *matEj3 = new EnLinea(77889, 99001, "Curso de Programacion en C++", "Jane Smith", "Programacion, Tecnologia", "Curso en Linea", "Disponible", "EnLinea", true);
	Material *matEj4 = new Fisico(12345, 67890, "ejemplo titulo", "Autor Ejemplo", "Palabra1, Palabra2", "Tipo Ejemplo", "Estado Ejemplo", "Fisico", "estilo ejemplo");

	//gestor->agregarMaterial(matEj);
	//gestor->agregarMaterial(matEj2);
	//gestor->agregarMaterial(matEj3);
	//gestor->agregarMaterial(matEj4);



	std::cout << *gestor << std::endl;

	//AdminArchivos::guardarMateriales(*gestor);

	AdminArchivos::cargarMateriales(*gestor);

	std::cout << *gestor << std::endl;

	GestorUsuarios* gestorUsuarios = new GestorUsuarios();
	//Usuario* usuarioEj = new Usuario(12345678, "Juan Perez", true);
	//gestorUsuarios->agregarUsuario(usuarioEj);

	std::cout << *gestorUsuarios << std::endl;
	//AdminArchivos::guardarUsuarios(*gestorUsuarios);

	AdminArchivos::cargarUsuarios(*gestorUsuarios);

	std::cout << *gestorUsuarios << std::endl;


	delete gestor;
	delete matEj;
	delete matEj2;
	delete matEj3;
	delete matEj4;
	delete gestorUsuarios;
	//delete usuarioEj;

    return 0;
}

