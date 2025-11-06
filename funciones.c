#include <stdio.h>
#include <string.h>
#include "funciones.h"

//  ingresarProductos - Pide cantidad (1..capacidad) - Carga nombres (sin espacios) y precios (>=0) - Devuelve n (cuántos productos ingresados)
int ingresarProductos(char nombres[][30], float precios[], int capacidad) {
    int n = 0;

    // Pedimos la cantidad asegurando el rango 
    do {
        printf("Cantidad de productos (1..%d): ", capacidad);
        scanf("%d", &n);
        if (n < 1 || n > capacidad) {
            printf("Valor invalido. Intente nuevamente.\n");
        }
    } while (n < 1 || n > capacidad);

    // Cargar cada producto 
    for (int i = 0; i < n; i++) {
        printf("\nProducto %d\n", i + 1);

        // Para mantenerlo basico: nombre sin espacios
        printf("Nombre (sin espacios): ");
        scanf(" %29s", nombres[i]);

        // Validar precio no negativo
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

// calcularTotal - Suma todos los precios

float calcularTotal(float precios[], int n) {
    float total = 0.0f;
    for (int i = 0; i < n; i++) {
        total += precios[i];
    }
    return total;
}

//  indiceMasCaro - Recorre el arreglo y devuelve el índice del precio mayor
int indiceMasCaro(float precios[], int n) {
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (precios[i] > precios[idx]) {
            idx = i;
        }
    }
    return idx;
}

//  indiceMasBarato - Devuelve el índice del precio menor
int indiceMasBarato(float precios[], int n) {
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (precios[i] < precios[idx]) {
            idx = i;
        }
    }
    return idx;
}

// calcularPromedio - Promedio = total / n - Si n == 0, devuelve 0.0
float calcularPromedio(float precios[], int n) {
    if (n == 0) return 0.0f;
    return calcularTotal(precios, n) / (float)n;
}

//  buscarProducto - Compara cadenas (strcmp) - Retorna índice del nombre encontrado o -1 si no existe
int buscarProducto(char nombres[][30], float precios[], int n, char nombreBuscado[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            return i;
        }
    }
    return -1;
}

// mostrarTabla (void) - Solo imprime la tabla con los datos actuales
void mostrarTabla(char nombres[][30], float precios[], int n) {
    if (n == 0) {
        printf("No hay productos cargados.\n");
        return;
    }

    printf("\n--- Inventario ---\n");
    printf("#\tNombre\t\tPrecio\n");
    for (int i = 0; i < n; i++) {
        // %.2f -> dos decimales para moneda 
        printf("%d\t%s\t\t%.2f\n", i, nombres[i], precios[i]);
    }
}
