#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int matriz[5][12];
    srand(time(NULL));

    //a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
    //Carga de la Matriz
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<12; j++)
        {
            matriz[i][j] = 10000 + rand() % 50001;
        }
    }

    //b. Muestre por pantalla los valores cargados
    //Muestra de la Matriz
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<12; j++)
        {
            printf(" $%d ", matriz[i][j]);
        }
        printf("\n");
    }

    //c. Saque el promedio de ganancia por año y muestrelos por pantalla
    //Suma por año de la matriz
    int suma[5];
    int aux;

    for(int i=0; i<5; i++)
    {
        aux=0;
        for(int j=0; j<12; j++)
        {
            aux = aux + matriz[i][j];
        }
        suma[i]=aux;
    }
    printf("\n\nEl promedio de ganancia por anios: ");

    for(int i=0; i<5; i++)
    {
        printf("\n\tAnio %d: %d", i+1, suma[i]);
    }

    //Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” decuándo ocurrió.

    //Valor maximo y valor minimo obtenido informando el año y el mes
    int minAnio,minMes,maxAnio,maxMes;

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<12; j++)
        {
            if(i==0 && j==0)
            {
                minAnio=i;
                minMes=j;
                maxAnio=i;
                maxMes=i;
            }
            else{
                if(matriz[i][j] < matriz[minAnio][minMes])
                {
                    minAnio = i;
                    minMes = j;
                }
                if(matriz[i][j] > matriz[minAnio][minMes])
                {
                    maxAnio=i;
                    maxMes=j;
                }
            }
        }
    }

    printf("\nEl valor minimo obtenido es : %d correspondiente al anio %d y mes %d\n",matriz[minAnio][minMes],minAnio+1,minMes+1);
    printf("\nEl valor maximo obtenido es : %d correspondiente al anio %d y mes %d\n",matriz[maxAnio][maxMes],maxAnio+1,maxMes+1);
    
    return 0;
}

