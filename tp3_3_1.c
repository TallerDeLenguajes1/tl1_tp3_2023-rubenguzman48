#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char **nombres; //Declaro el vector de punteros
    int i;

    //Reservo memoria para los 5 componentes del vector
    nombres = (char **)malloc(sizeof(char *)*5);

    //Hago un bucle for para cargar los nombres 
    for(i=0; i<5; i++)
    {
        nombres[i] = (char *)malloc(sizeof(char)*20); //Reservo memoria por cada uno de los nombres(20 caracteres por nombre)
        printf("Ingrese el nombre %d: ", i+1); //Solicito los nombres de 
        scanf("%s", nombres[i]); //los guardo en el arreglo
    }

    //Imprimo por pantalla los nombres guardados en el arreglo
    printf("\nLos nombres ingresados son: \n");
    for (i = 0; i < 5; i++)
    {
        printf("%s\n", nombres[i]);
    }
    //Liberacion de memoria
    for(i=0; i<5; i++) //libero memoria de los componentes del arreglo
    {
        free(nombres[i]);
    }
    free(nombres); //Libero la memoria reservada para 


}