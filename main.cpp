#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <numeric>
#include "algoritmos.h"

using namespace std;
using namespace std::chrono;

int main() {
    vector<int> tamanos = {100000, 1000000, 10000000, 100000000};

    random_device rd;
    mt19937 gen(rd());

    cout << "Tamano_N | Lineal | Binaria | Trinaria\n";

    for (int n : tamanos) {
        vector<int> datos(n);
        iota(datos.begin(), datos.end(), 0); // Se crea el vector con valores consecutivos

        uniform_int_distribution<> distribucion(0, n - 1); // Elige los numeros aleatorios a buscar
        vector<int> objetivos(30);
        for (int i = 0; i < 30; i++) {
            objetivos[i] = datos[distribucion(gen)];
        }

        long long tiempoTotalLineal = 0;
        long long tiempoTotalBinaria = 0;
        long long tiempoTotalTrinaria = 0;

        for (int obj : objetivos) {
            auto inicio = high_resolution_clock::now();
            busquedaLineal(datos, obj);
            auto fin = high_resolution_clock::now();
            tiempoTotalLineal += duration_cast<nanoseconds>(fin - inicio).count();
        }

        for (int obj : objetivos) {
            auto inicio = high_resolution_clock::now();
            busquedaBinaria(datos, obj);
            auto fin = high_resolution_clock::now();
            tiempoTotalBinaria += duration_cast<nanoseconds>(fin - inicio).count();
        }

        for (int obj : objetivos) {
            auto inicio = high_resolution_clock::now();
            busquedaTrinaria(datos, obj);
            auto fin = high_resolution_clock::now();
            tiempoTotalTrinaria += duration_cast<nanoseconds>(fin - inicio).count();
        }

        long long promLineal = tiempoTotalLineal / 30;
        long long promBinaria = tiempoTotalBinaria / 30;
        long long promTrinaria = tiempoTotalTrinaria / 30;

        cout << n << " | "
             << promLineal << " | "
             << promBinaria << " | "
             << promTrinaria << "\n";
    }

    return 0;
}