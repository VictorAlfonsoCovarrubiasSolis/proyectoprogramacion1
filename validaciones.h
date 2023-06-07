int validaEntero(const char mensaje[]){
	int continuar=0;
	int entero=0;
	do{
		printf("\n%s", mensaje);
		continuar = scanf("%d", &entero);
		fflush(stdin);
	}while(continuar != 1);
	
	return entero;
}

float validaFlotante(const char mensaje[]){
	int continuar=0;
	float flotante=0;
	do{
		printf("\n%s", mensaje);
		continuar = scanf("%f", &flotante);
		fflush(stdin);
	}while(continuar != 1);
	
	return flotante;
}

void validaCadena(const char mensaje[], char cadena[]){//cadena pasa por referencia
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	bool bandera=true;
	int i;
	
	while(bandera){
		printf("%s", mensaje);
		scanf("%[^\n]", cadena);
		fflush(stdin);
		if(strlen(cadena)>15){
			continue;
		}else{
			for(i=0; i<strlen(cadena); i++){
				//if(isalpha(cadena[i]) || cadena[i]==' '){
				if(i==(strlen(cadena))-1){
					bandera=false;
				}
				//}else{
					//break;
				//}
			}
		}
	}
}

void validaNombre(const char mensaje[], char cadena[]){
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	bool bandera=true;
	int i;
	
	while(bandera){
		printf("%s", mensaje);
		scanf("%[^\n]", cadena);
		fflush(stdin);
		if(strlen(cadena)>15){
			continue;
		}else{
			for(i=0; i<strlen(cadena); i++){
				if(isalpha(cadena[i])){
					if(i==(strlen(cadena))-1){
						bandera=false;
					}
				}else{
					break;
				}
			}
		}
	}
}
void validaCorreo(const char mensaje[], char cadena[]){
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	bool bandera=true;
	int i;
	int cont;
	int cont2;
	
	while(bandera){
		cont=0;
		cont2=0;
		printf("%s", mensaje);
		scanf("%[^\n]", cadena);
		fflush(stdin);
		if(strlen(cadena)>30){
			continue;
		}else{
			for(i=0; i<strlen(cadena); i++){
				if(cadena[i]=='@'){
					cont++;
				}
				if(cadena[i]=='.'){
					cont2++;
				}
			}
			if(cont==1 && cont2==1){
				bandera=false;
			}
		}
	}
}
void validaModelo(const char mensaje[], char cadena[]){
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	bool bandera=true;
	
	while(bandera){
		printf("%s", mensaje);
		scanf("%[^\n]", cadena);
		fflush(stdin);
		if(strlen(cadena)>15){
			continue;
		}else{
			if(cadena[0]=='E' && cadena[1]=='S' && cadena[2]=='T' || cadena[0]=='H' && cadena[1]=='O' && cadena[2]=='R'){
				bandera=false;
			}else{
				printf("\nModelo invalido");
			}
		}
	}
}
void validaNum(const char mensaje[], char cadena[]){
	//setlocale(LC_CTYPE, "Spanish");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	bool bandera = true;
	int num = 0;
	
	while(bandera){
		num = 0;
		//system("cls");
		printf("\n%s", mensaje);
		scanf("%[^\n]", cadena);
		//scanf("%s", cadena);
		//gets(cadena);
		fflush(stdin);
		if(strlen(cadena)>10){
			//printf("Tamaño cadena -> %d \n", strlen(cadena));
			continue;
			//break
		}else{
			for(int i = 0; i<strlen(cadena); i++){
				if(isdigit(cadena[i])){
					num++;
				}else{
					if(isalpha(cadena[i]) || cadena[i]==' '){
						break;
					}
				}
				if (i== (strlen(cadena)-1) && num == 10){
					bandera=false;
				}
			}
		}	
	}
}
int validaCantidad(const char mensaje[], int existencia){
	//setlocale(LC_CTYPE, "Spanish");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	int continuar=0;
	int entero=0;
	bool bandera = true;
	
	do{
		int cont=0;
		do{
			printf("\n%s", mensaje);
			continuar = scanf("%d", &entero);
			fflush(stdin);
			}while(continuar != 1);
		if(entero<1){
			printf("Tiene que ser mas de 0");
		}else{
			cont++;
		}
		if(entero>existencia){
			printf("El número excede la existencia del producto");
		}else{
			cont++;
		}
		if(cont==2){
			bandera=false;
		}
	}while(bandera==true);
	return entero;
}

int comparar_id(int identificacion){
	setlocale(LC_CTYPE, "Spanish");
	bool bandera=false;
	Referencia dato={};
	int numero=0;
	if(!(arch=fopen("encabezado.txt", "r"))){
		printf("Error al intentar leer archivo");
		exit(1);
	}
		
	while(!feof(arch)){
		fscanf(arch, "%d\t", &dato.pedido.idPedido);
		fscanf(arch, "%[^\t]\t", dato.pedido.estado);
		fscanf(arch, "%[^\t]\t", dato.cliente.nomCompleto);
		fscanf(arch, "%[^\t]\t", dato.cliente.correo);
		fscanf(arch, "%[^\n]\n", dato.cliente.telefono);
		if(dato.pedido.idPedido==identificacion){
			fclose(arch);
			bandera=true;
			numero=1;
			return numero;
		}
	}
	if(bandera==false){
		fclose(arch);
		return numero;
	}
}
//validacion para correo
/*
if(cadena[i]==){
	if(i==(strlen(cadena))-1){
		bandera=false;
	}
}else{
	break;
}
*/
