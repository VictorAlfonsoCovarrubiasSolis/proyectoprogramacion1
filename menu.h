void menuProyecto();
void menu1();
void menu2();
void menu4();
void menu(int,int,int &);
void menu_1(int x,int y,int &opc);
void menu_2(int x,int y,int &opc);
void menu_4(int x,int y,int &opc);


void menu(int x, int y, int &opc){
	char tecla='\0';
	opc=1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()){
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),17);
			gotoxy(x,y);
			printf("%c", 16);
			if(opc>1&&tecla==72){//Flecha arriba
				y--;
				opc--;
			}
			if(opc<7&&tecla==80){//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
			gotoxy(x,y);
			printf("%c",16);
		}
	}while(tecla!=13);//13--> enter
}

void menu_1(int x, int y, int &opc){
	char tecla='\0';
	opc=1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()){
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),17);
			gotoxy(x,y);
			printf("%c", 16);
			if(opc>1&&tecla==72){//Flecha arriba
				y--;
				opc--;
			}
			if(opc<4&&tecla==80){//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
			gotoxy(x,y);
			printf("%c",16);
		}
	}while(tecla!=13);//13--> enter
}

void menu_2(int x, int y, int &opc){
	char tecla='\0';
	opc=1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()){
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),17);
			gotoxy(x,y);
			printf("%c", 16);
			if(opc>1&&tecla==72){//Flecha arriba
				y--;
				opc--;
			}
			if(opc<4&&tecla==80){//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
			gotoxy(x,y);
			printf("%c",16);
		}
	}while(tecla!=13);//13--> enter
}

void menu_4(int x, int y, int &opc){
	char tecla='\0';
	opc=1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()){
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),17);
			gotoxy(x,y);
			printf("%c", 16);
			if(opc>1&&tecla==72){//Flecha arriba
				y--;
				opc--;
			}
			if(opc<5&&tecla==80){//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
			gotoxy(x,y);
			printf("%c",16);
		}
	}while(tecla!=13);//13--> enter
}


void menuProyecto(){
	setlocale(LC_CTYPE, "Spanish");
	int opc =0;
	int x=0;
	int y=0;
	
	while(opc != 7){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(x,y);
		printf("1. Consulta de almacén.\n");
		gotoxy(x,++y);
		printf("2. Actualizar almacén.\n");
		gotoxy(x,++y);
		printf("3. Registrar Pedido.\n");
		gotoxy(x,++y);
		printf("4. Consultar Pedido.\n");
		gotoxy(x,++y);
		printf("5. Registrar entrega.\n");
		gotoxy(x,++y);
		printf("6. Modificar estado de pedido.\n");
		gotoxy(x,++y);
		printf("7. Salir del sistema.\n");
		gotoxy(x,++y);
		//printf("\nDame la opcion: ");
		//scanf("%d", &opc);
		menu(22,5,opc);
		//system("color 10");
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				menu1();
				getch();
				break;
			case OPC2:
				menu2();
				getch();
				break;
			case OPC3:
				agregarDinamico();
				getch();
				break;
			case OPC4:
				menu4();
				getch();
				break;
			case OPC5:
				modificar_dinamico(1);
				getch();
				break;
			case OPC6:
				modificar_dinamico(2);
				getch();
				break;
			case OPC7:
				system("color 60");
				printf("Adios :(");
				exit(0);
		}
	}
	getch();
}

void menu1(){
	setlocale(LC_CTYPE, "Spanish");
	int opc =0;
	int x=0;
	int y=0;
	
	while(opc != 4){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(x,y);
		printf("1. Consulta General.\n");
		gotoxy(x,++y);
		printf("2. Estufas.\n");
		gotoxy(x,++y);
		printf("3. Hornos de Microondas.\n");
		gotoxy(x,++y);
		printf("4. Regresar.\n");
		gotoxy(x,++y);
		//printf("\nDame la opcion: ");
		//scanf("%d", &opc);
		menu_1(22,5,opc);
		//system("color 10");
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				imprimirEstructura(1);
				leer_archivo(1);
				getch();
				break;
			case OPC2:
				imprimirEstructura(2);
				leer_archivo(2);
				getch();
				break;
			case OPC3:
				imprimirEstructura(3);
				leer_archivo(3);
				getch();
				break;
			case OPC4:
				menuProyecto();
				break;
		}
	}
	getch();
}

void menu2(){
	setlocale(LC_CTYPE, "Spanish");
	int opc =0;
	int x=0;
	int y=0;
	
	while(opc != 4){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(x,y);
		printf("1. Modificar Estufas.\n");
		gotoxy(x,++y);
		printf("2. Modificar Hornos de Microondas.\n");
		gotoxy(x,++y);
		printf("3. Agregar al archivo (Estufa o Horno).\n");
		gotoxy(x,++y);
		printf("4. Regresar.\n");
		gotoxy(x,++y);
		//printf("\nDame la opcion: ");
		//scanf("%d", &opc);
		menu_2(22,5,opc);
		//system("color 10");
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				leer_archivo(2);
				modificar_archivo(1);
				leer_archivo(2);
				getch();
				break;
			case OPC2:
				leer_archivo(3);
				modificar_archivo(2);
				leer_archivo(3);
				getch();
				break;
			case OPC3:
				agregarRegistro();
				leer_archivo(1);
				getch();
				break;
			case OPC4:
				menuProyecto();
				break;
		}
	}
	getch();
}

void menu4(){
	setlocale(LC_CTYPE, "Spanish");
	int opc =0;
	int x=0;
	int y=0;
	
	while(opc != 5){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(x,y);
		printf("1. Pedidos Activos.\n");
		gotoxy(x,++y);
		printf("2. Pedidos Entregados.\n");
		gotoxy(x,++y);
		printf("3. Pedidos Cancelados.\n");
		gotoxy(x,++y);
		printf("4. Número de pedido.\n");
		gotoxy(x,++y);
		printf("5. Regresar.\n");
		gotoxy(x,++y);
		//printf("\nDame la opcion: ");
		//scanf("%d", &opc);
		menu_4(22,5,opc);
		//system("color 10");
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				leer_dinamico(1);
				getch();
				break;
			case OPC2:
				leer_dinamico(2);
				getch();
				break;
			case OPC3:
				leer_dinamico(3);
				getch();
				break;
			case OPC4:
				leer_dinamico(0);
				getch();
				break;
			case OPC5:
				menuProyecto();
				break;
		}
	}
	getch();
}
