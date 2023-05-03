#include <stdio.h>
#include <stdlib.h>

int main() {
    char **nombres;   // Declaración del vector de punteros
    int i;

    nombres = (char **) malloc(5 * sizeof(char *));   // Reserva de memoria

    // Lectura de los nombres
    for (i = 0; i < 5; i++) {
        nombres[i] = (char *) malloc(20 * sizeof(char));   // Reserva de memoria para cada nombre
        printf("Ingrese el nombre %d: ", i + 1);
        scanf("%s", nombres[i]);
    }

    // Impresión de los nombres
    printf("\nLos nombres ingresados son:\n");
    for (i = 0; i < 5; i++) {
        printf("%s\n", nombres[i]);
    }

    // Liberación de memoria
    for (i = 0; i < 5; i++) {
        free(nombres[i]);
    }
    free(nombres);

    return 0;
}































/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char **nombres;
  char buff[100];
  int i;

  nombres = (char **) malloc(5 * sizeof(char *)); // Reservar memoria para el vector de punteros

  for (i = 0; i < 5; i++) {
    printf("Ingrese el nombre %d: ", i + 1);
    fgets(buff, 100, stdin);
    nombres[i] = (char *) malloc(strlen(buff) + 1); // Reservar memoria para la cadena de caracteres
    strcpy(nombres[i], buff); // Copiar la cadena de caracteres desde la variable auxiliar a la memoria reservada
  }

  printf("\nLos nombres ingresados son:\n");

  for (i = 0; i < 5; i++) {
    printf("%s", nombres[i]); // Imprimir cada nombre
    free(nombres[i]); // Liberar memoria de cada cadena de caracteres
  }

  free(nombres); // Liberar memoria del vector de punteros

  return 0;
}

*/