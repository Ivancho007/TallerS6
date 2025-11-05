#include <stdio.h>
#include "funciones.h"

int main() {
    /* Capacidad fija: 10 productos */
    char  nombres[10][30];
    float precios[10];
    int   n = 0;                 /* cuántos productos están cargados */

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
            n = ingresarProductos(nombres, precios, 10);
            break;

        case 2: {
            if (n == 0) { printf("Primero cargue productos (opcion 1).\n"); break; }
            float total = calcularTotal(precios, n);
            printf("Total del inventario: %.2f\n", total);
            break;
        }

        case 3: {
            if (n == 0) { printf("No hay datos.\n"); break; }
            int idxMax = indiceMasCaro(precios, n);
            int idxMin = indiceMasBarato(precios, n);
            printf("Mas caro:   %s (%.2f)\n", nombres[idxMax], precios[idxMax]);
            printf("Mas barato: %s (%.2f)\n", nombres[idxMin], precios[idxMin]);
            break;
        }

        case 4: {
            if (n == 0) { printf("No hay datos.\n"); break; }
            float prom = calcularPromedio(precios, n);
            printf("Precio promedio: %.2f\n", prom);
            break;
        }

        case 5: {
            if (n == 0) { printf("No hay datos.\n"); break; }
            char buscado[30];
            printf("Nombre a buscar (sin espacios): ");
            scanf(" %29s", buscado);
            int pos = buscarProducto(nombres, precios, n, buscado);
            if (pos == -1) printf("No existe el producto.\n");
            else           printf("%s cuesta %.2f\n", nombres[pos], precios[pos]);
            break;
        }

        case 6:
            mostrarTabla(nombres, precios, n);
            break;

        case 7:
            printf("Saliendo...\n");
            seguir = 0;
            break;

        default:
            printf("Opcion invalida.\n");
        }

    } while (seguir == 1);

    return 0;
}
