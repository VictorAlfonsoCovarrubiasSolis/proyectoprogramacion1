void portada(){
	int aux=0;
	FILE *archivo = fopen("portada.txt", "r");
	
	for(int i=0; i<58; i++){
		for(int j=0; j<53; j++){
			fscanf(archivo, "%d\t", &aux);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), aux);
			printf("%c", 177);
		}
		printf("\n");
	}
	
	fclose(archivo);
}

void datos(){
	setlocale(LC_CTYPE, "Spanish");
	gotoxy(65, 35);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("Universidad Politecnica de San Luis Potosi");
	gotoxy(65, 37);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("Programacion I Lenguaje C");
	gotoxy(65, 39);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("Victor Alfonso Covarrubias Solis");
	gotoxy(65, 41);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("Cervantes Candia Saul");
	gotoxy(65, 43);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("Cualquier tecla para inciar...");
	getch();
}
