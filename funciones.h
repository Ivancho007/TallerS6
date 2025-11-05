#ifndef FUNCIONES_H
#define FUNCIONES_H

/* Lee productos y devuelve cuántos quedaron cargados (1..capacidad). */
int  ingresarProductos(char nombres[][30], float precios[], int capacidad);

/* Cálculos sobre precios */
float calcularTotal(float precios[], int n);
int   indiceMasCaro(float precios[], int n);
int   indiceMasBarato(float precios[], int n);
float calcularPromedio(float precios[], int n);

/* Búsqueda por nombre: retorna índice (0..n-1) o -1 si no existe */
int   buscarProducto(char nombres[][30], float precios[], int n, char nombreBuscado[]);

/* Muestra una tablita; retorna 0 solo como estado */
int   mostrarTabla(char nombres[][30], float precios[], int n);

#endif
