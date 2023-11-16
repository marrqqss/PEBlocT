#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()

int main() {
    clock_t inicio = clock();

    srand(clock()); // Semilla para la generación de números aleatorios
    int size = rand()%1048576; // Tamaño del array
    unsigned long long arr[size];
    for (int i = 0; i < size; ++i) {
        if (i == 0) arr[i] = 0;
        else arr[i] = arr[i-1] + i;
    }

    clock_t fin = clock();
    std::cout << "C++ tamaño array: " << size << std::endl;
    double tiempo_total = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    std::cout<< "Tiempo: " << tiempo_total << "s" << std::endl;
    return 0;
}