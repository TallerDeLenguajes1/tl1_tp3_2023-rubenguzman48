#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Defino un arreglo de tipo char donde guardo el tipo de producto
char *TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

//Defino la estructura para los productos
typedef struct Producto
{
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; //Entre 1 y 10
    char *TipoProducto; //Algun valor del arreglo TiposProductos
    float PrecioUnitario; //Entre 10-100
}Produc;

//Defino la estructura para los clientes
typedef struct Cliente
{
    int ClienteID; //Numerado en el ciclo iterativo
    char *NombreCliente; //Ingresad por usuario
    int CantidadProductosAPedir; //Aleatorio entre 1 y 5
    struct Producto *Productos; //El tamaño de este arreglo depende de la variable
                                //"CantidadProductosApedir"
}Client;

int main()
{
    int cantClientes;
    
    printf("Ingrese la cantidad de clientes a cargar: "); //Solicito al usuario la cantidad de clientes a ingresar
    scanf("%d", &cantClientes);

    Client *Clientes = (Client *)malloc(sizeof(Client)*cantClientes); //defino un puntero de tipo Client(struct Cliente) y reservo memoria para una cantidad de clientes "cantClientes"

    //Cargo los datos de los clientes
    srand(time(NULL)); //Inicializo la semilla para numeros aleatorios

    for (int i = 0; i < cantClientes; i++)
    {
        Clientes[i].ClienteID = i+1;
        Clientes[i].CantidadProductosAPedir = 1+rand()%5+1;
        Clientes[i].Productos = (Produc *)malloc(sizeof(Produc)*Clientes[i].CantidadProductosAPedir);

        char buffer[100]; //Buffer para leer el nombre del cliente
        printf("Ingrese el nombre del cliente %d: ", i+1); //pido el nombre del cliente
        scanf("%s", buffer); //lo guardo en la variable char "buffer"

        Clientes[i].NombreCliente = (char *)malloc(sizeof(char)*(strlen(buffer)+1)); //reservo memoria para el nombre del cliente segun la longitud de "buffer"
        strcpy(Clientes[i].NombreCliente,buffer); //Copio el contenido de "buffer" en "NombreCliente" 

        printf("Cliente Nro %d\n", i+1);

        //Cargo los datos de los productos
        for (int j = 0; j < Clientes[i].CantidadProductosAPedir; j++)
        {
            Clientes[i].Productos[j].ProductoID = j+1;
            Clientes[i].Productos[j].Cantidad = 1+rand()%10+1; //Genera un cantidad aleatorio entre 1 y 10
            Clientes[i].Productos[j].TipoProducto = TiposProductos[rand()%5]; //Seleccionar un tipo de producto aleatorio
            Clientes[i].Productos[j].PrecioUnitario = (10+rand()%100+10); //Generar precio aleatorio

            printf("\nCliente Nro %d\n", i+1);
            printf("Producto ID %d\n", Clientes[i].Productos[j].ProductoID);
            printf("Tipo de producto: %s\n", Clientes[i].Productos[j].TipoProducto);
            printf("Cantidad de producto: %d\n", Clientes[i].Productos[j].Cantidad);
            printf("Precio unitario $%.2f\n", Clientes[i].Productos[j].PrecioUnitario);
        }
        
        

    }
    
    return 0;
}
