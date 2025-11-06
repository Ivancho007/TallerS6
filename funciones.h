#ifndef FUNCIONES_H
#define FUNCIONES_H

// Prototipos de funciones del inventario.

// Lee productos: pide cantidad 
int  ingresarProductos(char nombres[][30], float precios[], int capacidad);

// Cálculos sobre el arreglo de precios 
float calcularTotal(float precios[], int n);
int   indiceMasCaro(float precios[], int n);
int   indiceMasBarato(float precios[], int n);
float calcularPromedio(float precios[], int n);

// Búsqueda por nombre: retorna la posición (0..n-1) o -1 si no existe 
int   buscarProducto(char nombres[][30], float precios[], int n, char nombreBuscado[]);

// Muestra una tabla simple con índice, nombre y precio pero no retorna valor
void  mostrarTabla(char nombres[][30], float precios[], int n);

#endif
