#include "algoritmos.h"
#include <iostream>
#include <vector>

using namespace std;

int busquedaLineal(const vector<int>& arreglo, int objetivo) {
    for (size_t i = 0; i < arreglo.size(); i++) {
        if (arreglo[i] == objetivo) return i; // Devuelve el indice si lo encuentra
    }

    return -1; // Devuelve -1 si no lo encuentra
}


int busquedaBinaria(const vector<int>& arr, int objetivo) {
    int izquierda = 0;
    int derecha = arr.size() - 1;

    while (izquierda <= derecha) {
        int mitad = izquierda + (derecha - izquierda)/2;

        if (arr[mitad] == objetivo) {
            return mitad;
        }

        if (arr[mitad] < objetivo) {
            izquierda = mitad + 1;
        } else {
            derecha = mitad - 1;
        }
    }
    return -1;
}

int busquedaTrinaria(const vector<int>& arreglo, int objetivo) {
    int izquierda = 0;
    int derecha = arreglo.size() - 1;

    while (izquierda <= derecha) {
        int tercioUno = izquierda + (derecha - izquierda) / 3;
        int tercioDos = derecha - (derecha - izquierda) / 3;

        if (arreglo[tercioUno] == objetivo) return tercioUno;
        if (arreglo[tercioDos] == objetivo) return tercioDos;

        // Reducir el espacio de búsqueda a uno de los tres segmentos
        if (objetivo < arreglo[tercioUno]) {
            derecha = tercioUno - 1;
        } else if (objetivo > arreglo[tercioDos]) {
            izquierda = tercioDos + 1;
        } else {
            izquierda = tercioUno + 1;
            derecha = tercioDos - 1;
        }
    }
    return -1;
}