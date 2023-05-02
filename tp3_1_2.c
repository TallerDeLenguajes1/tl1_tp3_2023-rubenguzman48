#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define filas 5
#define columnas 12
#define minGanancia 100000
#define maxGanancia 500000

//Funcion para generar un numero aleatorio entre un rango dado
int generarNum(int min, int max);



int main()
{
    //a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
    //reserva de memoria de la matriz
    int** matriz = (int**)malloc(sizeof(int)*filas);
    for (int i = 0; i < filas; i++)
    {
        matriz[i]=(int*)malloc(sizeof(int)*columnas);
        //hago 12 reservas de memoria cada una de las filas
    }
    
    //cargo la matriz con valores aleatorios
    srand(time(0)); //semilla para generar nuneros aleatorios
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j] = generarNum(minGanancia, maxGanancia);
        }  
    }
    
    //b. Muestre por pantalla los valores cargados
    //Muestro los valores por pantalla
    printf("Valores cargados:\n");
    for (int i = 0; i < filas; i++)
    {
        printf("Año %d\n", i+1);
        for (int j = 0; j < columnas; j++)
        {
            printf("Mes %d: $%d | ", j+1, matriz[i][j]);
        }
        printf("\n");
    }
    
    //c. Saque el promedio de ganancia por año y muestrelos por pantalla
    //Calculo el promedio de ganancias por año y muestro por pantalla
    printf("Promedio de ganancia por año:\n");
    for (int i = 0; i < filas; i++)
    {
        int suma=0;
        for (int j = 0; j < columnas; j++)
        {
            suma+=matriz[i][j];
        }
        float promedio;
        promedio=suma/columnas;
        printf("Alo %d: %.2f\n", i+1, promedio);
    }
    




    return 0;
}

int generarNum(int min, int max)
{
    int aleatorio;
    aleatorio = min+rand()%(max-min+1);
    return aleatorio;

}