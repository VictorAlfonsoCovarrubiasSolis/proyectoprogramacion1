#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

void gotoxy(int x, int y){
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dWPos;
	dWPos.X=x;
	dWPos.Y=y;
	SetConsoleCursorPosition(hcon, dWPos);
}

typedef struct{
	char modelo[20];
	int existencia;
	float unitario;
	char ubicacion[20];
}almacenamiento;

almacenamiento info[]={
	{"EST001", 1000, 4500, "Estante A"},
	{"EST002", 1000, 4500, "Estante B"},
	{"EST003", 1000, 4500, "Estante C"},
	{"EST004", 1000, 4500, "Estante D"},
	{"EST005", 1000, 4500, "Estante E"},
	{"HOR011", 1500, 4500, "Estante F"},
	{"HOR022", 1500, 4500, "Estante G"},
	{"HOR033", 1500, 4500, "Estante H"},
	{"HOR044", 1500, 4500, "Estante I"},
	{"HOR055", 1500, 4500, "Estante J"}
};

typedef struct{
	char idModelo[20];
	almacenamiento info;
}Modelo;

typedef struct{
	int idPedido;
	char estado[10];
}Pedido;

typedef struct{
	int idCliente;
	char nomCompleto[20];
	char correo[40];
	char telefono[11];
}Cliente;

typedef struct{
	int idDetalle;
	float unitario;
	int cantidad;
	float subtotal;
}Detalle;

typedef struct{
	Modelo modelo;
	Pedido pedido;
	Cliente cliente;
	Detalle detalle;
}Referencia;

enum MENU { OPC1=1, OPC2, OPC3, OPC4, OPC5, OPC6, OPC7};

FILE *arch = NULL;
Referencia *regis = (Referencia *)malloc(sizeof(Referencia));
#include "decorar.h"
#include "validaciones.h"
#include "estructura.h"
#include "estrucApuntador.h"
#include "menu.h"
