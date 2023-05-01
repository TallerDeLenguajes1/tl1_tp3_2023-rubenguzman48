#include<stdio.h>
#include<stdlib.h>

const int dimension = 10;
const int filas = 2;
const int columnas = 3;

int main()
{
    int *pVect;
    pVect = (int *)malloc(sizeof(int)*dimension);

    //Muestro el vector con aritmetica de punteros
    for(int i=0; i<dimension; i++)
    {
        *(pVect + i) = i;
        printf("pVect[%d] = %d", i, *(pVect + i));
    }

    //Muestro el vector con notacion subindexada
    for(int i=0; i<dimension; i++)
    {
        pVect[i] = i;
        printf("pVect[%d] = %d",i, pVect[i]);
    }
    free(pVect);
    printf("\n");

    //matriz (2 dimensiones)(3*2)
    int * pMatriz1 = (int *)malloc(sizeof(int) *filas *columnas);

    for(int i=0; i<filas; i++)
    {
        for (int j = 0; j < columnas ; j++)
        {
            *(pMatriz1 + i * columnas + j) = j;
            printf("pMatriz[%d,%d] = %d ", i, j, *(pMatriz1 + i * columnas + j));

        }
        printf("\n");
    }


    //Puntero Doble
    int **pMatriz2 = (int ** )malloc(sizeof(int)*filas);
    //reservo memoria por la cantidad de filas en un puntero doble

    for (int i = 0; i < filas; i++)
    {
        pMatriz2[i] = (int *)malloc(sizeof(int) * columnas);
        //por cada puntero simple pMatriz2 reservo memoria para n comunas
        for (int j = 0; j < columnas; j++)
        {
            pMatriz2[i][j]=j;
            printf("%4d", pMatriz2[i][j]);
        }
    printf("\n");        
    }
    
 //Aqui haremos funciones


 
    return 0;
}