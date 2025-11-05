#include <stdio.h>
#include <string.h>
#include "funciones.h"

int ingresarProductos(char nombres[][30], float precios[], int capacidad) {
    int n = 0;

    do {
        printf("Cantidad de productos (1..%d): ", capacidad);
        scanf("%d", &n);
        if (n < 1 || n > capacidad) {
            printf("Valor invalido. Intente nuevamente.\n");
        }
    } while (n < 1 || n > capacidad);

    for (int i = 0; i < n; i++) {
        printf("\nProducto %d\n", i + 1);

        /* Para mantenerlo basico: sin espacios */
        printf("Nombre (sin espacios): ");
        scanf(" %29s", nombres[i]);

        do {
            printf("Precio (>= 0): ");
            scanf("%f", &precios[i]);
            if (precios[i] < 0) {
                printf("El precio no puede ser negativo.\n");
            }
        } while (precios[i] < 0);
    }

    return n;
}

float calcularTotal(float precios[], int n) {
    float total = 0.0f;
    for (int i = 0; i < n; i++) total += precios[i];
    return total;
}

int indiceMasCaro(float precios[], int n) {
    int idx = 0;
    for (int i = 1; i < n; i++)
        if (precios[i] > precios[idx]) idx = i;
    return idx;
}

int indiceMasBarato(float precios[], int n) {
    int idx = 0;
    for (int i = 1; i < n; i++)
        if (precios[i] < precios[idx]) idx = i;
    return idx;
}

float calcularPromedio(float precios[], int n) {
    if (n == 0) return 0.0f;
    return calcularTotal(precios, n) / (float)n;
}

int buscarProducto(char nombres[][30], float precios[], int n, char nombreBuscado[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) return i;
    }
    return -1;
}

int mostrarTabla(char nombres[][30], float precios[], int n) {
    if (n == 0) {
        printf("No hay productos cargados.\n");
        return 0;
    }
    printf("\n--- Inventario ---\n");
    printf("#\tNombre\t\tPrecio\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%.2f\n", i, nombres[i], precios[i]);
    }
    return 0;
}
