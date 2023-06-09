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
        printf("Año %d: %.2f\n", i+1, promedio);
    }
    
    //d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de cuándo ocurrió.
    //Encuentre el valor maximo, minimo y su posicion en la matriz
    int maximo = matriz[0][0];
    int minimo = matriz[0][0];
    int maximoAnio = 0;
    int maximoMes = 0;
    int minimoAnio = 0;
    int minimoMes = 0;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if(matriz[i][j]>maximo)
            {
                maximo = matriz[i][j];
                maximoAnio = i + 1;
                maximoMes = j + 1;
            }
            if(matriz[i][j]<minimo)
            {
                minimo = matriz[i][j];
                minimoAnio = i + 1;
                minimoMes = j + 1;
            }
        }
        
    }
    
    //Muestro por pantalla el maximo y minimo con su mes y año
    printf("Valor maximo obtenido: %d (Año %d, Mes %d)\n", maximo, maximoAnio, maximoMes);
    printf("Valor minimo obtenido: %d (Año %d, Mes %d)\n", minimo, minimoAnio, minimoMes);


    return 0;
}

int generarNum(int min, int max)
{
    int aleatorio;
    aleatorio = min+rand()%(max-min+1);
    return aleatorio;

}