#ifndef CONTENEDOR_H
#define CONTENEDOR_H
#include <iostream>
#include "Nodo.h"
#include <sstream>
using namespace std;

template <class T>
class Contenedor; // Forward declaration of Nodo class

template <class T>
std::ostream& operator<<(std::ostream& os, const Contenedor<T>& obj);

template<class T>
class Contenedor {
private:
    Nodo<T>* inicio;
public:
    Contenedor(Nodo<T>* = nullptr);
    ~Contenedor();

    void agregarPrincipio(Nodo<T>*);
    void agregarFinal(Nodo<T>*);
    Nodo<T>* getInicio();
    int tamano();
	Nodo<T>* buscar(int);
    bool existe(Nodo<T>*);
    void eliminar(int);
    void eliminar(Nodo<T>*);
    void ordenarAscendente();

    friend std::ostream& operator<< <>(std::ostream& os, const Contenedor<T>& obj);


    string toString();
};


template<class T>
Contenedor<T>::Contenedor(Nodo<T>* i) {
    inicio = i;
}

template<class T>
Contenedor<T>::~Contenedor() {
    Nodo<T>* aux = inicio;
    while (aux != nullptr) {
        Nodo<T>* aBorrar = aux;
        aux = aux->sig;
        delete aBorrar;
    }
    delete inicio;
}

template<class T>
void Contenedor<T>::agregarPrincipio(Nodo<T>* n) {
    if (inicio != nullptr) {
        n->setSig(inicio);
    }
    inicio = n;
}

template<class T>
void Contenedor<T>::agregarFinal(Nodo<T>* n) {
    Nodo<T>* aux = inicio;
    if (aux != nullptr) {
        while (aux->getSig() != nullptr) {

            aux = aux->getSig();
        }
        aux->setSig(n);
    }
}

template<class T>
Nodo<T>* Contenedor<T>::getInicio() {
    return inicio;
}

template <class T>
Nodo<T>* Contenedor<T>::buscar(int i) {
	Nodo<T>* aux = inicio;
	int index = 0;
	while (aux != nullptr && index < i) {
		aux = aux->getSig();
		index++;
	}
	return aux;
}

template<class T>
int Contenedor<T>::tamano() {
	int count = 0;
	Nodo<T>* aux = inicio;
	while (aux != nullptr) {
		count++;
		aux = aux->getSig();
	}
	return count;
}

template<class T>
bool Contenedor<T>::existe(Nodo<T>* n) {
    Nodo<T>* aux = inicio;
	while (aux != nullptr) {
		if (aux == n) {
			return true;
		}
		aux = aux->getSig();
	}
    return false;
}

template<class T>
void Contenedor<T>::eliminar(int i) {
    int index = 0;
    Nodo<T>* aux = inicio;
    while (aux != nullptr && index < i - 1) {
        aux = aux->getSig();
        index++;
    }
    if (aux != nullptr && aux->getSig() != nullptr) {
        Nodo<T>* aBorrar = aux->getSig();
        aux->setSig(aux->getSig()->getSig());
        delete aBorrar;
    }
}

template<class T>
void Contenedor<T>::eliminar(Nodo<T>* n) {
    Nodo<T>* aux = inicio;
    while (aux != nullptr && n != aux->getSig()) {
        aux = aux->getSig();
    }
    if (aux != nullptr && aux->getSig() != nullptr) {
        Nodo<T>* aBorrar = aux->getSig();
        aux->setSig(aux->getSig()->getSig());
        delete aBorrar;
    }
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Contenedor<T>& obj) {
	Nodo<T>* aux = obj.inicio;
	while (aux != nullptr) {
		os << aux->getItem() << std::endl;
		aux = aux->getSig();
	}
	return os;
}

template<class T>
void Contenedor<T>::ordenarAscendente() {
    int n = tamano();
    for (int i = n-1; i >= 0; i--) { // Número de pasadas
        for (int j = 0; j <= i - 1 ; j++) { // Comparaciones en cada pasada
            if (buscar(j)->getItem() < buscar(j + 1)->getItem()) { // Si están en mal orden, los cambio
				Nodo<T>* aux = buscar(j);
				Nodo<T>* aux2 = buscar(j + 1);

                if (aux == inicio) {
                    Nodo<T>* aux3 = aux2->getSig();
					inicio = aux2;
                    aux2->setSig(aux);
                    aux -> setSig(aux3);
				} else {
                    Nodo<T>* aux0 = buscar(j - 1);
                    Nodo<T>* aux3 = aux2->getSig();
                    aux0->setSig(aux2);
                    aux->setSig(aux3);
					aux2->setSig(aux);
                }

            }
        }
    }
}
#endif