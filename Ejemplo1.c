//Ejemplo de reserva dinamica de memoria
#include<stdio.h> //contiene las funciones de entrada-salida desde la consola
#include<stdlib.h> //reservas de memoria
#include<string.h>

int main()
{
    printf("-------------------Punteros-----------------\n");
    //Lo primero que necesito para hacer 
    //una reserva de memoria es un puntero   

    int *p; //Creo un puntero p
    *p = 20; 
    printf("%d",p);
    p = (int *) malloc(sizeof(int)); //con la funcion malloc
    //hago la reserva de memoria, con sizeof le digo cuanto
    //necesito reservar en este caso el tamaño de int que
    //son 4 Bytes, mallod me devuelve un puntero a void por lo
    //que debo casteaer para que devuelva un puntero a int(int *)

    printf("Contenido de %d en la direccion: %p \r\n\r\n", *p,p);
    //muestro el contenido de p y hacia donde apunta el puntero
    free(p); //libero la memoria que se reservo con malloc

    printf("Contenido de %d en la direccion: %p \r\n\r\n", *p,p);
    //una vez que liberamos la memoria *p apunta a una direccion
    //cualquiera, no a la de la variable

    printf("\n------------------------------------\n\n");

    //************************************************************
/*
    printf("----------Punteros con cadena de caracteres-----------\n");

    char *a;
    a = (char *) malloc(sizeof(char)); 

    printf("----------Punteros con cadena de caracteres-----------\n");
*/
    getchar();
    return 0;
}
