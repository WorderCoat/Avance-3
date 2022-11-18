#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h> //punteros
using namespace std;

//\n
//[]
string* nom, * clasificacion, * caracteristicas, * descripcion, * generos, encontrar;
int opcion, registros, opcion2, eliminar, modificar;
int* idarticulo, * item, * fecha;
float* precio, * iva, * total;

void Crear() {
	printf("Cuantos articulos va a crear?\n");
	scanf_s("%d", &registros);
	idarticulo = new int[registros];
	item = new int[registros];
	precio = new float[registros];
	iva = new float[registros];
	total = new float[registros];
	nom = new string[registros];
	fecha = new int[registros];
	clasificacion = new string[registros];
	caracteristicas = new string[registros];
	descripcion = new string[registros];
	generos = new string[registros];


	//crear articulo
	for (int i = 0;i < registros;i++) {
		printf("Ingrese id del articulo\n");
		scanf_s("%d", &idarticulo[i]);
		printf("Ingrese el numero del articulo \n");
		scanf_s("%d", &item[i]);
		printf("Ingrese el nombre del videojuego\n");
		cin.ignore();
		getline(cin, nom[i]);
		printf("Ingrese el year de salida del videojuego\n");
		scanf_s("%d", &fecha[i]);
		printf("Ingrese las clasificaciones del videojuegos\n");
		cin.ignore();
		getline(cin, clasificacion[i]);
		printf("Ingrese las caracteristicas del videojuego\n");
		cin.ignore();
		getline(cin, caracteristicas[i]);
		printf("Describa el juego basado a su opinion\n");
		cin.ignore();
		getline(cin, descripcion[i]);
		printf("Ingrese los generos que abarca el videojuego\n");
		cin.ignore();
		getline(cin, generos[i]);
		printf("Ingrese el precio unitario del videojuego\n");
		scanf_s("%f", &precio[i]);
		iva[i] = precio[i] * .16;
		total[i] = precio[i] + iva[i];
		printf("Articulo creado correctamente\n");
	}
}
void Lista() {
	printf("Bienvenido a la lista de los articulos\nSeleccione una opcion para encontrar su articulo\n");
	printf("1.-Clasificacion\n2.-Genero\n");
	scanf_s("%d", &opcion2);
	switch (opcion2) {
	case 1: {
		printf("Ingrese la clasificacion del videojuego a buscar\n");
		cin.ignore();
		getline(cin, encontrar);
		int i = 0;
		if (clasificacion[i] == encontrar) {
			if (item[i] != 0) {
				printf("Numero del articulo:%d\n", item[i]);
				printf("Nombre del videojuego:%s\n", nom[i].c_str());
				printf("Year de salida del videojuego:%d\n", fecha[i]);
				printf("Clasificaciones del videojuego:%s\n", clasificacion[i].c_str());
				printf("Caracteristicas del videojuego:%s\n", caracteristicas[i].c_str());
				printf("Descrpcion del videojuego:%s\n", descripcion[i].c_str());
				printf("Generos que abarca el videojuego:%s\n", generos[i].c_str());
				printf("Precio unitario del videojuego:%f\n", precio[i]);
				printf("Iva incluido es igual a:%f\n", iva[i]);
				printf("Total:%f\n", total[i]);
				break;
			}
		}

	}
	case 2: {
		printf("Ingrese el genero del videojuego a buscar\n ");
		cin.ignore();
		getline(cin, encontrar);
		int i = 0;
		if (generos[i] == encontrar) {
			if (item[i] != 0) {
				printf("Numero de compra:%d\n", item[i]);
				printf("Nombre del videojuego:%s\n", nom[i].c_str());
				printf("Year de salida del videojuego:%d\n", fecha[i]);
				printf("Clasificaciones del videojuego:%s\n", clasificacion[i].c_str());
				printf("Caracteristicas del videojuego:%s\n", caracteristicas[i].c_str());
				printf("Descrpcion del videojuego:%s\n", descripcion[i].c_str());
				printf("Generos que abarca el videojuego:%s\n", generos[i].c_str());
				printf("Precio unitario del videojuego:%f\n", precio[i]);
				printf("Iva incluido es igual a:%f\n", iva[i]);
				printf("Total:%f\n", total[i]);
				break;
			}
		}
	}
	default: {
		printf("Seleccione una opcion valida");
		return Lista();
		break;
	}
	}
}
void Eliminar() {
	printf("Ingrese el numero del articulo que desea eliminar\n");
	scanf_s("%d", &eliminar);
	for (int i = 0;i < registros;i++) {
		if (eliminar == item[i]) {
			item[i] = 0;
			printf("Se borro exitosamente\n");
		}
	}
}
void Modificar() {
	do {
		printf("Ingrese el id del articulo a modificar");
		scanf_s("%d", &modificar);
	} while (modificar <= 0);
	
	for (int i = 0;i < registros;i++) {
		if (modificar == idarticulo[i]) {
			printf("Ingrese nuevo  id del articulo\n");
			scanf_s("%d", &idarticulo[i]);
			printf("Ingrese el numero de compra\n");
			scanf_s("%d", &item[i]);
			printf("Ingrese el nombre del videojuego\n");
			cin.ignore();
			getline(cin, nom[i]);
			printf("Ingrese el year de salida del videojuego\n");
			scanf_s("%d", &fecha[i]);
			printf("Ingrese las clasificaciones del videojuegos\n");
			cin.ignore();
			getline(cin, clasificacion[i]);
			printf("Ingrese las caracteristicas del videojuego\n");
			cin.ignore();
			getline(cin, caracteristicas[i]);
			printf("Describa el juego basado a su opinion\n");
			cin.ignore();
			getline(cin, descripcion[i]);
			printf("Ingrese los generos que abarca el videojuego\n");
			cin.ignore();
			getline(cin, generos[i]);
			printf("Ingrese el precio unitario del videojuego\n");
			scanf_s("%f", &precio[i]);
			iva[i] = precio[i] * .16;
			total[i] = precio[i] + iva[i];
			printf("Articulo cambiado correctamente\n");
		}
	}
}
void Archivo() {
	ofstream archivo;
	archivo.open("Articulos.txt", ios::out);
	if (archivo.fail()) {
		printf("No se pudo crear el archivo\n");
	}
	else {
		for (int i = 0;i < registros;i++) {
			if (clasificacion[i] == encontrar) {
				printf("Numero de compra:%d\n", item[i]);
				printf("Nombre del videojuego:%s\n", nom[i].c_str());
				printf("Year de salida del videojuego:%d\n", fecha[i]);
				printf("Clasificaciones del videojuego:%s\n", clasificacion[i].c_str());
				printf("Caracteristicas del videojuego:%s\n", caracteristicas[i].c_str());
				printf("Descrpcion del videojuego:%s\n", descripcion[i].c_str());
				printf("Generos que abarca el videojuego:%s\n", generos[i].c_str());
				printf("Precio unitario del videojuego:%f\n", precio[i]);
				printf("Iva incluido es igual a:%f\n", iva[i]);
				printf("Total:%f\n", total[i]);

			}
		}
	}
	archivo.close();
}


int main() {
	while (opcion!=6) {
		void Archivo();
		printf("Bienvenido a esta tienda de videojuegos,\n Seleccione una opcion\n");
		printf("1.-Crear articulo\n2.-Lista de articulos\n3.-Modificar articulo\n4.-Eliminar articulo\n5.-Limpiar pantalla\n6.-Salir del programa\n");
		scanf_s("%d", &opcion);
		switch (opcion) {
		case 1: {
			Crear();
			system("pause");
			
			break;
		}
		case 2: {
			Lista();
			system("pause");

			break;
		}
		case 3: {
			Modificar();
			break;
		}
		case 4: {
			Eliminar();
			break;
		}
		case 5: {
			system("cls");
			
			break;
		}
		case 6: {
			printf("Bonito dia,vuelva pronto <3\n");
			break;
		}
		default: {
			printf("Ingrese una opcion validan\n");
			break;
		}
		}
	}
	
}
