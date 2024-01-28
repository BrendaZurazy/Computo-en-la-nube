// Tarea1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <omp.h>

#define N 2000 /* cantidad de elementos a manejar en los arreglos*/
#define chunk 100 /*tamaño que tendrán los pedazos de los arreglos para que cada hilo*/
#define mostrar 10

void imprimeArreglo(float* d);

int main()
{
	std::cout << "Sumando Arreglos en paralelo!\n";
	float a[N], b[N], c[N];
	int i;

	for (i = 0; i < N; i++)
	{
		a[i] = rand()%100;
		b[i] = rand() % 100;/* Asigna valores aleatorios entre 0 y 99*/
	}
	int pedazos = chunk;

	/*Procedimiento para crear hilos y ejecutar las operaciones de manera paralela.*/
	#pragma omp parallel for \
	shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)

	/*El siguiente for se realizará en paralelo por medio de las instrucciones de la librería OpenMP.*/
	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];

	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: ";
	imprimeArreglo(a);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: ";
	imprimeArreglo(b);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: ";
	imprimeArreglo(c);
}

void imprimeArreglo(float* d)
{
	for (int x = 0; x < mostrar;x++)
		std::cout << d[x] << " - ";
	std::cout <<std::endl;
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

