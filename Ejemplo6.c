#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Arreglo con los tipos de productos
char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

// Estructura para los productos
struct Producto {
    int ProductoID; // Numerado en ciclo iterativo
    int Cantidad; // Entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // Entre 10 - 100
};

// Estructura para los clientes
struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // Aleatorio entre 1 y 5
    Producto *Productos; // El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
};

// Prototipos de funciones
float CalcularCosto(Producto prod);
void MostrarCliente(Cliente cli);

// Función principal
int main() 
{
    srand(time(NULL)); // Inicializar la semilla para los números aleatorios
    int cantClientes;
    printf("Ingrese la cantidad de clientes a cargar: ");
    scanf("%d", &cantClientes); // Solicitar al usuario la cantidad de clientes
    Cliente *Clientes = (Cliente *) malloc(cantClientes * sizeof(Cliente)); // Reservar memoria para los clientes

    // Cargar los datos de los clientes
    for (int i = 0; i < cantClientes; i++) {
        Clientes[i].ClienteID = i + 1;
        Clientes[i].CantidadProductosAPedir = rand() % 5 + 1; // Generar la cantidad aleatoria de productos
        Clientes[i].Productos = (Producto *) malloc(Clientes[i].CantidadProductosAPedir * sizeof(Producto)); // Reservar memoria para los productos
        printf("Ingrese el nombre del cliente %d: ", i + 1);
        char buffer[100]; // Buffer para leer el nombre del cliente
        scanf("%s", buffer);
        Clientes[i].NombreCliente = (char *) malloc((strlen(buffer) + 1) * sizeof(char)); // Reservar memoria para el nombre del cliente
        strcpy(Clientes[i].NombreCliente, buffer); // Copiar el nombre del buffer al cliente

        // Cargar los datos de los productos para el cliente actual
        for (int j = 0; j < Clientes[i].CantidadProductosAPedir; j++) {
            Clientes[i].Productos[j].ProductoID = j + 1;
            Clientes[i].Productos[j].Cantidad = rand() % 10 + 1; // Generar la cantidad aleatoria de productos
            Clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5]; // Seleccionar un tipo de producto aleatorio
            Clientes[i].Productos[j].PrecioUnitario = (rand() % 91) + 10; // Generar el precio aleatorio
        }
    }

    // Mostrar los datos cargados
    printf("\n--- DATOS DE LOS CLIENTES ---\n");
    for (int i = 0; i < cantClientes; i++) {
        MostrarCliente(Clientes[i]); // Mostrar los datos del cliente
        float totalCliente = 0; // Inicializar el total a pagar para el cliente actual
        for (int j =0; j < Clientes[i]->CantidadProductosAPedir; j++) {
            MostrarProducto(Clientes[i]->Productos[j]); // Mostrar los datos del producto
            float costoProducto = CalcularCostoProducto(Clientes[i]->Productos[j]); // Calcular el costo del producto actual
            totalCliente += costoProducto; // Sumar el costo del producto actual al total a pagar para el cliente actual
        }
        printf("Total a pagar por el cliente %d: $%.2f\n", Clientes[i]->ClienteID, totalCliente); // Mostrar el total a pagar para el cliente actual
        }

    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i < cantClientes; i++) {
        free(Clientes[i]->NombreCliente); // Liberar la memoria asignada para el nombre del cliente
        for (int j = 0; j < Clientes[i]->CantidadProductosAPedir; j++) {
            free(Clientes[i]->Productos[j]->TipoProducto); // Liberar la memoria asignada para el tipo de producto
            free(Clientes[i]->Productos[j]); // Liberar la memoria asignada para el producto
        }
        free(Clientes[i]->Productos); // Liberar la memoria asignada para el arreglo de productos del cliente
        free(Clientes[i]); // Liberar la memoria asignada para el cliente
    }
    free(Clientes); // Liberar la memoria asignada para el arreglo de clientes

return 0;
}


// Función que calcula el costo total de un producto
float CalcularCosto(Producto prod) {
    return prod.Cantidad * prod.PrecioUnitario;
}

// Función que muestra los datos de un cliente por consola
void MostrarCliente(Cliente cli) {
    printf("\n--- DATOS DEL CLIENTE ---\n");
    printf("ID: %d\n", cli.ClienteID);
    printf("Nombre: %s\n", cli.NombreCliente);
    printf("Cantidad de productos a pedir: %d\n", cli.CantidadProductosAPedir);
    printf("\n--- PRODUCTOS DEL CLIENTE ---\n");
    for (int i = 0; i < cli.CantidadProductosAPedir; i++) {
        printf("\n--- PRODUCTO %d ---\n", i+1);
        printf("ID: %d\n", cli.Productos[i].ProductoID);
        printf("Cantidad: %d\n", cli.Productos[i].Cantidad);
        printf("Tipo: %s\n", cli.Productos[i].TipoProducto);
        printf("Precio unitario: %.2f\n", cli.Productos[i].PrecioUnitario);
        printf("Costo total: %.2f\n", CalcularCosto(cli.Productos[i]));
    }
    printf("\n--- TOTAL A PAGAR DEL CLIENTE ---\n");
    float totalCliente = 0;
    for (int i = 0; i < cli.CantidadProductosAPedir; i++) {
        totalCliente += CalcularCosto(cli.Productos[i]);
    }
    printf("El cliente debe pagar : $%.2f\n", totalCliente);
}