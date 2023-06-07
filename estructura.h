int buscaModelo(char modelo[]){
	setlocale(LC_CTYPE, "Spanish");
	bool bandera=false;
	almacenamiento dato={};
	int numero=0;
	if(!(arch=fopen("almacen.txt", "r"))){
		printf("Error al intentar leer archivo");
		exit(1);
	}
		
	while(!feof(arch)){
		fscanf(arch, "%[^\t]\t", dato.modelo);
		fscanf(arch, "%d\t", &dato.existencia);
		fscanf(arch, "%f\t", &dato.unitario);
		fscanf(arch, "%[^\n]\n", dato.ubicacion);
		
		if(strcmp(dato.modelo, modelo)==0){
			printf("\nDatos actuales del electronico: \n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("Modelo\tExistencia\tUnitario\tUbicacion\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			printf("%s\t", dato.modelo);
			printf("%d\t\t", dato.existencia);
			printf("%.2f\t\t", dato.unitario);
			printf("%s\n", dato.ubicacion);
			fclose(arch);
			printf("valor repetido");
			bandera=true;
			numero=1;
			return numero;
		}
	}
	if(bandera==false){
		printf("\nContinue\n");
		return numero;
	}
}

void imprimirEstructura(int estructura){
	setlocale(LC_CTYPE, "Spanish");
	
	printf("\n\n----------Registros en la Estructura----------\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("Modelo\tExistencia\tUnitario\tUbicacion\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	if(estructura==1){
		for(int i=0; i<10; i++){
			printf("%s\t", info[i].modelo);
			printf("%d\t\t", info[i].existencia);
			printf("%.2f\t\t", info[i].unitario);
			printf("%s\n", info[i].ubicacion);
		}
	}else{
		if(estructura==2){
			for(int i=0; i<5; i++){
				printf("%s\t", info[i].modelo);
				printf("%d\t\t", info[i].existencia);
				printf("%.2f\t\t", info[i].unitario);
				printf("%s\n", info[i].ubicacion);
			}
		}else{
			if(estructura==3){
				for(int i=5; i<10; i++){
					printf("%s\t", info[i].modelo);
					printf("%d\t\t", info[i].existencia);
					printf("%.2f\t\t", info[i].unitario);
					printf("%s\n", info[i].ubicacion);
				}
			}
		}
	}
}
/*
void crear_archivo(){
	if(!(arch=fopen("informacion.txt", "w"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	for(int i=0; i<3; i++){
		fprintf(arch, "%d\t", data[i].matricula);
		fprintf(arch, "%s\t", data[i].nombre);
		fprintf(arch, "%s\t", data[i].carrera);
		fprintf(arch, "%f\t", data[i].calif[0]);
		fprintf(arch, "%f\t", data[i].calif[1]);
		fprintf(arch, "%f\n", data[i].calif[2]);
		
	}
	
	fclose(arch);
}
*/

void crear_archivo(){
	if(!(arch=fopen("almacen.txt", "w"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	for(int i=0; i<10; i++){
		fprintf(arch, "%s\t", info[i].modelo);
		fprintf(arch, "%d\t", info[i].existencia);
		fprintf(arch, "%f\t", info[i].unitario);
		fprintf(arch, "%s\n", info[i].ubicacion);
	}
	
	fclose(arch);
}

void leer_archivo(int caso){
	setlocale(LC_CTYPE, "Spanish");
	almacenamiento dato;
	
	if(!(arch=fopen("almacen.txt", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1);
	}
	
	printf("\n\n----------Registros en el Archivo----------\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("Modelo\tExistencia\tUnitario\tUbicacion\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	
	while(!feof(arch)){
		
		fscanf(arch, "%[^\t]\t", dato.modelo);
		fscanf(arch, "%d\t", &dato.existencia);
		fscanf(arch, "%f\t", &dato.unitario);
		fscanf(arch, "%[^\n]\n", dato.ubicacion);
		if(caso==1){
			printf("%s\t", dato.modelo);
			printf("%d\t\t", dato.existencia);
			printf("%.2f\t\t", dato.unitario);
			printf("%s\n", dato.ubicacion);
		}else{
			if(caso==2){
				if(dato.modelo[0]=='E' && dato.modelo[1]=='S' && dato.modelo[2]=='T'){
					printf("%s\t", dato.modelo);
					printf("%d\t\t", dato.existencia);
					printf("%.2f\t\t", dato.unitario);
					printf("%s\n", dato.ubicacion);
				}
			}else{
				if(caso==3){
					if(dato.modelo[0]=='H' && dato.modelo[1]=='O' && dato.modelo[2]=='R'){
						printf("%s\t", dato.modelo);
						printf("%d\t\t", dato.existencia);
						printf("%.2f\t\t", dato.unitario);
						printf("%s\n", dato.ubicacion);
					}
				}
			}
		}
	}
	fclose(arch);
}


void modificar_archivo(int num){
	setlocale(LC_CTYPE, "Spanish");
	almacenamiento dato;
	FILE *arch2;
	char model[7];
	bool bandera=false;
	int eleccion;
	int numero=1;
	
	numero=validaEntero("Quieres continuar?  Si--1, No--2: ");
	
	while(numero==1){
		if(!(arch=fopen("almacen.txt", "r"))){
			printf("Error al intentar leer el archivo");
			exit(1);
		}
		if(!(arch2=fopen("copia.txt", "a+"))){
			printf("Error al intentar leer archivo");
			exit(1);
		}
		
		printf("Escribe el modelo a modificar: ");
		scanf("%s", model);
		if(num==1){
			if(model[0]!='E'){
				model[0]=0;
				
			}
		}
		if(num==2){
			if(model[0]!='H'){
				model[0]=0;
				
			}
		}
		
		while(!feof(arch)){
			fscanf(arch, "%[^\t]\t", &dato.modelo);
			fscanf(arch, "%d\t", &dato.existencia);
			fscanf(arch, "%f\t", &dato.unitario);
			fscanf(arch, "%[^\n]\n", &dato.ubicacion);
			
			if(strcmp(dato.modelo, model)==0){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("Modelo\tExistencia\tUnitario\tUbicacion\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				if(num==1){
					if(dato.modelo[0]=='E' && dato.modelo[1]=='S' && dato.modelo[2]=='T'){
						printf("%s\t", dato.modelo);
						printf("%d\t\t", dato.existencia);
						printf("%.2f\t\t", dato.unitario);
						printf("%s\n", dato.ubicacion);
					}
				}else{
					if(num==2){
						
						if(dato.modelo[0]=='H' && dato.modelo[1]=='O' && dato.modelo[2]=='R'){
							printf("%s\t", dato.modelo);
							printf("%d\t\t", dato.existencia);
							printf("%.2f\t\t", dato.unitario);
							printf("%s\n", dato.ubicacion);
						}
					}
				}
				eleccion=validaEntero("\nQue quieres modificar?\n1-->Existencia\n2-->Precio unitario\n3-->Ubicacion\n");
				if(eleccion==1){
					dato.existencia=validaEntero("\nNueva Existencia:");
				}else{
					if(eleccion==2){
						dato.unitario=validaFlotante("\nNuevo precio unitario: ");
					}else{
						if(eleccion==3){
							validaCadena("\nNueva ubicacion: ", dato.ubicacion);
						}
					}
				}
				bandera=true;
			}
			fprintf(arch2, "%s\t", dato.modelo);
			fprintf(arch2, "%d\t", dato.existencia);
			fprintf(arch2, "%f\t", dato.unitario);
			fprintf(arch2, "%s\n", dato.ubicacion);
		}
		
		if(bandera==false){
			printf("No se encuentra el registro");
		}else{
			printf("\nRegistro Actualizado");
		}
		fclose(arch2);
		fclose(arch);
		remove("almacen.txt");
		rename("copia.txt", "almacen.txt");
		numero=validaEntero("Quieres seguir haciendo cambios en el archivo? Si--1, No--2: ");
		system("cls");
		if(num==1){
			leer_archivo(2);
		}else{
			if(num==2){
				leer_archivo(3);
			}
		}
	}
}

void modificar_existencia(int num, char modo[], int cantidad, int id){
	setlocale(LC_CTYPE, "Spanish");
	almacenamiento dato;
	Referencia data;
	FILE *arch2;
	FILE *arch3;
	FILE *arch4;
	char model[7];
	bool bandera=false;
	int eleccion;
	int numero=1;
	int cont=0;
	if(!(arch=fopen("almacen.txt", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1);
	}
	if(!(arch2=fopen("copia.txt", "a+"))){
		printf("Error al intentar leer archivo");
		exit(1);
	}
	if(!(arch3=fopen("encabezado.txt", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1);
	}
	if(!(arch4=fopen("copy.txt", "a+"))){
		printf("Error al intentar leer archivo");
		exit(1);
	}
	
	strcpy(model, modo);
	while(!feof(arch)){
		fscanf(arch, "%[^\t]\t", &dato.modelo);
		fscanf(arch, "%d\t", &dato.existencia);
		fscanf(arch, "%f\t", &dato.unitario);
		fscanf(arch, "%[^\n]\n", &dato.ubicacion);
		
		if(strcmp(dato.modelo, model)==0){
			if(dato.existencia<cantidad){
				printf("\nNo se pudo enviar el producto: %s porque la cantidad de producto excedia la existencia de este\n", dato.modelo);
				cont++;
				while(!feof(arch3)){
					fscanf(arch3, "%d\t", &data.pedido.idPedido);
					fscanf(arch3, "%[^\t]\t", data.pedido.estado);
					fscanf(arch3, "%[^\t]\t", data.cliente.nomCompleto);
					fscanf(arch3, "%[^\t]\t", data.cliente.correo);
					fscanf(arch3, "%[^\n]\n", data.cliente.telefono);
					if(data.pedido.idPedido==id){
						strcpy(data.pedido.estado, "Activo");
					}
					fprintf(arch4, "%d\t", data.pedido.idPedido);
					fprintf(arch4, "%s\t", data.pedido.estado);
					fprintf(arch4, "%s\t", data.cliente.nomCompleto);
					fprintf(arch4, "%s\t", data.cliente.correo);
					fprintf(arch4, "%s\n", data.cliente.telefono);
				}
				bandera=true;
			}else{
				dato.existencia=dato.existencia-cantidad;
				printf("\nSe envio con exito el producto: %s\n", dato.modelo);
				bandera=true;
			}
		}
		fprintf(arch2, "%s\t", dato.modelo);
		fprintf(arch2, "%d\t", dato.existencia);
		fprintf(arch2, "%f\t", dato.unitario);
		fprintf(arch2, "%s\n", dato.ubicacion);
	}
	
	if(bandera==false){
		printf("\nNo se pudo enviar\n");
		while(!feof(arch3)){
			fscanf(arch3, "%d\t", &data.pedido.idPedido);
			fscanf(arch3, "%[^\t]\t", data.pedido.estado);
			fscanf(arch3, "%[^\t]\t", data.cliente.nomCompleto);
			fscanf(arch3, "%[^\t]\t", data.cliente.correo);
			fscanf(arch3, "%[^\n]\n", data.cliente.telefono);
			if(data.pedido.idPedido==id){
				strcpy(data.pedido.estado, "Activo");
			}
			fprintf(arch4, "%d\t", data.pedido.idPedido);
			fprintf(arch4, "%s\t", data.pedido.estado);
			fprintf(arch4, "%s\t", data.cliente.nomCompleto);
			fprintf(arch4, "%s\t", data.cliente.correo);
			fprintf(arch4, "%s\n", data.cliente.telefono);
		}
	}
	fclose(arch4);
	fclose(arch3);
	fclose(arch2);
	fclose(arch);
	if(bandera==false || cont>0){
		if(remove("encabezado.txt")!=0){
			printf("\nNo se movio");
		}
		if(rename("copy.txt", "encabezado.txt")!=0){
			printf("\nNo se cambio nombre");
		}
	}
	remove("almacen.txt");
	rename("copia.txt", "almacen.txt");
}

void agregarRegistro(){
	setlocale(LC_CTYPE, "Spanish");
	almacenamiento dato;
	bool bandera=false;
	int numero;
	int electrodomestico;
	int x;
	int y;
	int z;
	char xx;
	char yy;
	char zz;
	char tipo[7];
	numero=validaEntero("Quieres continuar?  Si--1, No--2: ");
	
	while(numero==1){
		printf("\nAgregar registro\n");
		electrodomestico=validaEntero("Estufa --> 1, Horno -->otro numero: ");
		etiqueta:
		if(electrodomestico==1){
			strcpy(tipo, "EST");
			srand(time(NULL));
			x=1+rand()%(9-1+1);
			y=1+rand()%(9-1+1);
			z=1+rand()%(9-1+1);
			xx=x+'0';
			yy=y+'0';
			zz=z+'0';
			char idmodelo[4]={xx,yy,zz};
			strcat(tipo, idmodelo);
			printf("%s", tipo);
			strcpy(dato.modelo, tipo);
			
		}else{
			if(electrodomestico!=1){
				strcpy(tipo, "HOR");
				srand(time(NULL));
				x=1+rand()%(9-1+1);
				y=1+rand()%(9-1+1);
				z=1+rand()%(9-1+1);
				xx=x+'0';
				yy=y+'0';
				zz=z+'0';
				char idmodelo[4]={xx,yy,zz};
				strcat(tipo, idmodelo);
				printf("%s", tipo);
				strcpy(dato.modelo, tipo);
			}
		}
		numero=buscaModelo(dato.modelo);
		if(numero==1){
			goto etiqueta;
		}else{
			if(numero==0){
				dato.existencia=validaEntero("\nExistencia: ");
				dato.unitario=validaFlotante("\nPrecio Unitario: ");
				validaCadena("\nUbicacion: ", dato.ubicacion);
				printf("\nRegistro agregado\n\n");		
			}
		}
		if(!(arch=fopen("almacen.txt", "a+"))){
			printf("Error al intentar leer archivo");
			exit(1);
		}
		fprintf(arch, "%s\t", dato.modelo);
		fprintf(arch, "%d\t", dato.existencia);
		fprintf(arch, "%.2f\t", dato.unitario);
		fprintf(arch, "%s\n", dato.ubicacion);
		fclose(arch);
		numero=validaEntero("Quieres seguir haciendo cambios en el archivo? Si--1, No--2: ");
		system("cls");
		leer_archivo(1);
	}
}
