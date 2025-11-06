#include <stdio.h>
#include "funciones.h"


int main() {
    // Arreglos para los datos basicos 
    char  nombres[10][30];
    float precios[10];

    // cuántos productos están cargados actualmente
    int n = 0;

    int opcion = 0;
    int seguir = 1;

    do {
        printf("\n===== MENU INVENTARIO =====\n");
        printf("1) Ingresar/actualizar productos\n");
        printf("2) Calcular precio total del inventario\n");
        printf("3) Mostrar producto mas caro y mas barato\n");
        printf("4) Calcular precio promedio\n");
        printf("5) Buscar producto por nombre\n");
        printf("6) Ver tabla de inventario\n");
        printf("7) Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {

        case 1:
            // Carga de datos; guardamos la cantidad en n
            n = ingresarProductos(nombres, precios, 10);
            break;

        case 2: {
            // Total del inventario
            if (n == 0) {
                printf("Primero cargue productos (opcion 1).\n");
                break;
            }
            float total = calcularTotal(precios, n);
            printf("Total del inventario: %.2f\n", total);
            break;
        }

        case 3: {
            // Más caro y más barato (mostramos nombre + precio)
            if (n == 0) {
                printf("No hay datos.\n");
                break;
            }
            int idxMax = indiceMasCaro(precios, n);
            int idxMin = indiceMasBarato(precios, n);
            printf("Mas caro:   %s (%.2f)\n", nombres[idxMax], precios[idxMax]);
            printf("Mas barato: %s (%.2f)\n", nombres[idxMin], precios[idxMin]);
            break;
        }

        case 4: {
            // Promedio de precios
            if (n == 0) {
                printf("No hay datos.\n");
                break;
            }
            float prom = calcularPromedio(precios, n);
            printf("Precio promedio: %.2f\n", prom);
            break;
        }

        case 5: {
            // Búsqueda por nombre
            if (n == 0) {
                printf("No hay datos.\n");
                break;
            }
            char buscado[30];
            printf("Nombre a buscar (sin espacios): ");
            scanf(" %29s", buscado);

            int pos = buscarProducto(nombres, precios, n, buscado);
            if (pos == -1) {
                printf("No existe el producto.\n");
            } else {
                printf("%s cuesta %.2f\n", nombres[pos], precios[pos]);
            }
            break;
        }

        case 6:
            // Mostrar tabla del inventario (función void)
            mostrarTabla(nombres, precios, n);
            break;

        case 7:
            // Salir del programa
            printf("Saliendo...\n");
            seguir = 0;
            break;

        default:
            printf("Opcion invalida.\n");
        }

    } while (seguir == 1);

    return 0;
}
