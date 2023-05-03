#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 12
#define MIN_GANANCIA 10000
#define MAX_GANANCIA 50000

// Función para generar un número aleatorio entre un rango dado
int generarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    // Reserva de memoria para la matriz
    int** matriz = (int**)malloc(FILAS * sizeof(int*));
    for (int i = 0; i < FILAS; i++) {
        matriz[i] = (int*)malloc(COLUMNAS * sizeof(int));
    }

    // Carga de la matriz con valores aleatorios
    srand(time(0)); // Semilla para generar números aleatorios
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = generarNumeroAleatorio(MIN_GANANCIA, MAX_GANANCIA);
        }
    }

    // Muestra por pantalla los valores cargados
    printf("Valores cargados:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Calcula el promedio de ganancia por año y muestra los resultados por pantalla
    printf("Promedio de ganancia por año:\n");
    for (int i = 0; i < FILAS; i++) {
        int suma = 0;
        for (int j = 0; j < COLUMNAS; j++) {
            suma += matriz[i][j];
        }
        double promedio = suma / (double)COLUMNAS;
        printf("Año %d: %.2f\n", i + 1, promedio);
    }

    // Encuentra el valor máximo y mínimo, y su posición en la matriz
    int maximo = matriz[0][0];
    int minimo = matriz[0][0];
    int maximo_anio = 0;
    int maximo_mes = 0;
    int minimo_anio = 0;
    int minimo_mes = 0;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
                maximo_anio = i + 1;
                maximo_mes = j + 1;
            }
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
                minimo_anio = i + 1;
                minimo_mes = j + 1;
            }
        }
    }

    // Muestra por pantalla el valor máximo y mínimo obtenido, con su año y mes correspondientes
    printf("Valor máximo obtenido: %d (Año %d, Mes %d)\n", maximo, maximo_anio, maximo_mes);
    printf("Valor mínimo obtenido: %d (Año %d, Mes %d)\n", minimo, minimo_anio);
} 