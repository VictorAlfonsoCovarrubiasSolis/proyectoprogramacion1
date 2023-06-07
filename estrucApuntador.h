
void resta_existencia(int id){
	setlocale(LC_CTYPE, "Spanish");
	bool bandera=false;
	Referencia dato={};
	almacenamiento dete={};
	FILE *arch3;
	if(!(arch3=fopen("detalle.txt", "r"))){
		printf("Error al intentar crear archivo");
		exit(1);
	}
	while(!feof(arch3)){
		fscanf(arch3, "%d\t", &dato.pedido.idPedido);
		fscanf(arch3, "%[^\t]\t", dato.modelo.idModelo);
		fscanf(arch3, "%d\t", &dato.detalle.cantidad);
		fscanf(arch3, "%f\t", &dato.detalle.unitario);
		fscanf(arch3, "%f\n", &dato.detalle.subtotal);
		if(dato.pedido.idPedido==id){
			modificar_existencia(0, dato.modelo.idModelo, dato.detalle.cantidad, id);
		}
	}
	fclose(arch3);
}

almacenamiento buscaMatricula(char modelo[]){
	setlocale(LC_CTYPE, "Spanish");
	bool bandera=false;
	almacenamiento dato={};
	
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
			return dato;
		}
	}
	fclose(arch);
	if(bandera==false){
		printf("No se encuentra el registro");
	}
	return dato;
}
int retornoMatricula(char modelo[]){
	setlocale(LC_CTYPE, "Spanish");
	almacenamiento dato={};
	
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
			fclose(arch);
			return 1;
		}
	}
	fclose(arch);
	return 2;
}

void imprimirDinamico(int id){
	setlocale(LC_CTYPE, "Spanish");
	Referencia dato={};
	FILE *arch3;
	float total=0;
	system("cls");
	printf("\n\n");
	if(!(arch=fopen("encabezado.txt", "r"))){
		printf("Error al intentar crear archivo");
		exit(1);
	}
	while(!feof(arch)){
		fscanf(arch, "%d\t", &dato.pedido.idPedido);
		fscanf(arch, "%[^\t]\t", dato.pedido.estado);
		fscanf(arch, "%[^\t]\t", dato.cliente.nomCompleto);
		fscanf(arch, "%[^\t]\t", dato.cliente.correo);
		fscanf(arch, "%[^\n]\n", dato.cliente.telefono);
		if(dato.pedido.idPedido==id){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			printf("Número de Pedido: %d\n", dato.pedido.idPedido);
			printf("Estado: %s\n", dato.pedido.estado);
			printf("Nombre del Cliente: %s\n", dato.cliente.nomCompleto);
			printf("Correo Electronico: %s\n", dato.cliente.correo);
			printf("Telefono: %s\n", dato.cliente.telefono);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("Pedido\tModelo\tCantidad\tPrecio\tSubtotal\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	if(!(arch3=fopen("detalle.txt", "r"))){
		printf("Error al intentar crear archivo");
		exit(1);
	}
	while(!feof(arch3)){
		fscanf(arch3, "%d\t", &dato.pedido.idPedido);
		fscanf(arch3, "%[^\t]\t", dato.modelo.idModelo);
		fscanf(arch3, "%d\t", &dato.detalle.cantidad);
		fscanf(arch3, "%f\t", &dato.detalle.unitario);
		fscanf(arch3, "%f\n", &dato.detalle.subtotal);
		if(dato.pedido.idPedido==id){
			printf("%d\t", dato.pedido.idPedido);
			printf("%s\t", dato.modelo.idModelo);
			printf("%d\t\t", dato.detalle.cantidad);
			printf("%.2f\t", dato.detalle.unitario);
			printf("%.2f\n", dato.detalle.subtotal);
			total=total+dato.detalle.subtotal;
		}
	}
	printf("Total: %.2f\n", total);
	fclose(arch3);
	fclose(arch);
}

void agregarDinamico(){
	setlocale(LC_CTYPE, "Spanish");
	almacenamiento dato={};
	float subtotal;
	int numero;
	int retorno;
	int num;
	int opc;
	numero=validaEntero("Quieres continuar?  Si--1, No--2: ");
	
	while(numero==1){
		system("cls");
		printf("\nRegistro Dinamico: \n");
		
		do{
			srand(time(NULL));
			regis->pedido.idPedido=10000+rand()%(99999-10000+1);
			num=comparar_id(regis->pedido.idPedido);
		}while(num==1);
		
		strcpy(regis->pedido.estado, "Activo");
		validaNombre("Nombre Del cliente: ", regis->cliente.nomCompleto);
		validaNum("Telefono: ", regis->cliente.telefono);
		validaCorreo("Correo Electronico (debe contener minimo un @ y un .): ", regis->cliente.correo);
		if(!(arch=fopen("encabezado.txt", "a+"))){
			printf("Error al intentar crear archivo");
			exit(1);
		}
		fprintf(arch, "%d\t", regis->pedido.idPedido);
		fprintf(arch, "%s\t", regis->pedido.estado);
		fprintf(arch, "%s\t", regis->cliente.nomCompleto);
		fprintf(arch, "%s\t", regis->cliente.correo);
		fprintf(arch, "%s\n", regis->cliente.telefono);
		
		fclose(arch);
		//leer_archivo(1);
		do{
			system("cls");
			printf("%d\t", regis->pedido.idPedido);
			printf("%s\t", regis->pedido.estado);
			printf("%s\t", regis->cliente.nomCompleto);
			printf("%s\t", regis->cliente.correo);
			printf("%s\n", regis->cliente.telefono);
			
			leer_archivo(1);
			do{
				validaCadena("\nModelo: ", regis->modelo.idModelo);
				dato = buscaMatricula(regis->modelo.idModelo);
				retorno= retornoMatricula(regis->modelo.idModelo);
			}while(retorno==2);
			regis->detalle.cantidad=validaCantidad("Cantidad del producto: ", dato.existencia);
			regis->detalle.unitario=dato.unitario;
			regis->detalle.subtotal=regis->detalle.cantidad*regis->detalle.unitario;
			strcpy(regis->modelo.info.modelo, dato.modelo);

			if(!(arch=fopen("detalle.txt", "a+"))){
				printf("Error al intentar crear archivo");
				exit(1);
			}
			fprintf(arch, "%d\t", regis->pedido.idPedido);
			fprintf(arch, "%s\t", regis->modelo.idModelo);
			fprintf(arch, "%d\t", regis->detalle.cantidad);
			fprintf(arch, "%.2f\t", regis->detalle.unitario);
			fprintf(arch, "%.2f\n", regis->detalle.subtotal);
			fclose(arch);
			printf("\nRegistro agregado\n\n");
			imprimirDinamico(regis->pedido.idPedido);
			opc=validaEntero("Quieres agregar otro registro? 1--Si, otro numero--No: ");
			//imprimirDinamico(regis->pedido.idPedido);
		}while(opc==1);
		//imprimirDinamico(regis->pedido.idPedido);
		numero=validaEntero("Quieres seguir haciendo otros pedidos? Si--1, No--2: ");
	}
}

void leer_dinamico(int opcion){
	setlocale(LC_CTYPE, "Spanish");
	Referencia data={};
	int id;
	int desicion=1;
	if(opcion==0){
		desicion=validaEntero("Quieres continuar?  1--Si, otro numero--NO: ");	
	}
	while(desicion==1){
		system("cls");
		if(!(arch=fopen("encabezado.txt", "r"))){
			printf("Error al intentar leer el archivo");
			exit(1);
		}
		if(opcion==0){
			printf("\n\n------------------Pedidos-------------------\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("Pedido\tEstado\t\tNombre\tCorreo\tTelefono\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		}
		if(opcion==1){
			printf("\n\n--------------Pedidos Activos-----------\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("Pedido\tEstado\tNombre\tCorreo\tTelefono\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		}
		if(opcion==2){
			printf("\n\n--------------Pedidos Entregados-----------\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("Pedido\tEstado\t\tNombre\tCorreo\tTelefono\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		}
		if(opcion==3){
			printf("\n\n--------------Pedidos Cancelados-----------\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("Pedido\tEstado\t\tNombre\tCorreo\tTelefono\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		}
		if(opcion==4){
			printf("\n\n----------Pedidos Activos y Cancelados-------\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("Pedido\tEstado\t\tNombre\tCorreo\tTelefono\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		}
		while(!feof(arch)){
			if(opcion==0){
				fscanf(arch, "%d\t", &data.pedido.idPedido);
				fscanf(arch, "%[^\t]\t", data.pedido.estado);
				fscanf(arch, "%[^\t]\t", data.cliente.nomCompleto);
				fscanf(arch, "%[^\t]\t", data.cliente.correo);
				fscanf(arch, "%[^\n]\n", data.cliente.telefono);
				printf("%d\t", data.pedido.idPedido);
				if(strcmp(data.pedido.estado, "Activo")==0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					printf("%s\t", data.pedido.estado);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				}else{
					if(strcmp(data.pedido.estado, "Entregado")==0){
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						printf("%s\t", data.pedido.estado);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
					}else{
						if(strcmp(data.pedido.estado, "Cancelado")==0){
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
							printf("%s\t", data.pedido.estado);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
						}
					}
				}
				printf("%s\t", data.cliente.nomCompleto);
				printf("%s\t", data.cliente.correo);
				printf("%s\n", data.cliente.telefono);
				
			}else{
				if(opcion==1){
					fscanf(arch, "%d\t", &data.pedido.idPedido);
					fscanf(arch, "%[^\t]\t", data.pedido.estado);
					fscanf(arch, "%[^\t]\t", data.cliente.nomCompleto);
					fscanf(arch, "%[^\t]\t", data.cliente.correo);
					fscanf(arch, "%[^\n]\n", data.cliente.telefono);
					if(strcmp(data.pedido.estado, "Activo")==0){	
						printf("%d\t", data.pedido.idPedido);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						printf("%s\t", data.pedido.estado);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
						printf("%s\t", data.cliente.nomCompleto);
						printf("%s\t", data.cliente.correo);
						printf("%s\n", data.cliente.telefono);
					}
				}else{
					if(opcion==2){
						fscanf(arch, "%d\t", &data.pedido.idPedido);
						fscanf(arch, "%[^\t]\t", data.pedido.estado);
						fscanf(arch, "%[^\t]\t", data.cliente.nomCompleto);
						fscanf(arch, "%[^\t]\t", data.cliente.correo);
						fscanf(arch, "%[^\n]\n", data.cliente.telefono);
						if(strcmp(data.pedido.estado, "Entregado")==0){	
							printf("%d\t", data.pedido.idPedido);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							printf("%s\t", data.pedido.estado);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
							printf("%s\t", data.cliente.nomCompleto);
							printf("%s\t", data.cliente.correo);
							printf("%s\n", data.cliente.telefono);
						}
					}else{
						if(opcion==3){
							fscanf(arch, "%d\t", &data.pedido.idPedido);
							fscanf(arch, "%[^\t]\t", data.pedido.estado);
							fscanf(arch, "%[^\t]\t", data.cliente.nomCompleto);
							fscanf(arch, "%[^\t]\t", data.cliente.correo);
							fscanf(arch, "%[^\n]\n", data.cliente.telefono);
							if(strcmp(data.pedido.estado, "Cancelado")==0){	
								printf("%d\t", data.pedido.idPedido);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
								printf("%s\t", data.pedido.estado);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
								printf("%s\t", data.cliente.nomCompleto);
								printf("%s\t", data.cliente.correo);
								printf("%s\n", data.cliente.telefono);
							}
						}else{
							if(opcion==4){
								fscanf(arch, "%d\t", &data.pedido.idPedido);
								fscanf(arch, "%[^\t]\t", data.pedido.estado);
								fscanf(arch, "%[^\t]\t", data.cliente.nomCompleto);
								fscanf(arch, "%[^\t]\t", data.cliente.correo);
								fscanf(arch, "%[^\n]\n", data.cliente.telefono);
								if(strcmp(data.pedido.estado, "Activo")==0){	
									printf("%d\t", data.pedido.idPedido);
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
									printf("%s\t", data.pedido.estado);
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
									printf("%s\t", data.cliente.nomCompleto);
									printf("%s\t", data.cliente.correo);
									printf("%s\n", data.cliente.telefono);
								}
								if(strcmp(data.pedido.estado, "Cancelado")==0){
									printf("%d\t", data.pedido.idPedido);
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
									printf("%s\t", data.pedido.estado);
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
									printf("%s\t", data.cliente.nomCompleto);
									printf("%s\t", data.cliente.correo);
									printf("%s\n", data.cliente.telefono);
								}
							}
						}	
					}
				}
			}
		}
		fclose(arch);
		if(opcion==0){
			id=validaEntero("Escribe la id de el pedido por mostrar: ");
			imprimirDinamico(id);
			desicion=validaEntero("Quieres hacer otra consulta?  1--Si, otro numero--NO: ");
		}else{
			desicion=2;
		}
	}
}


void modificar_dinamico(int num){
	setlocale(LC_CTYPE, "Spanish");
	Referencia dato;
	FILE *arch3;
	int id;
	bool bandera=false;
	int numero;
	int identificacion;
	numero=validaEntero("Quieres continuar?  Si--1, No--2: ");
	while(numero==1){
		system("cls");
		if(num==1){
			leer_dinamico(1);
			id=validaEntero("\nEscribe la id del pedido a entregar: ");	
		}
		if(num==2){
			leer_dinamico(4);
			id=validaEntero("\nEscribe la id del pedido a modificar: ");
		}
		if(!(arch=fopen("encabezado.txt", "r"))){
			printf("Error al intentar leer el archivo");
			exit(1);
		}
		if(!(arch3=fopen("copy.txt", "a+"))){
			printf("Error al intentar leer el archivo");
			exit(1);
		}
		if(num==1){
			while(!feof(arch)){
				fscanf(arch, "%d\t", &dato.pedido.idPedido);
				fscanf(arch, "%[^\t]\t", dato.pedido.estado);
				fscanf(arch, "%[^\t]\t", dato.cliente.nomCompleto);
				fscanf(arch, "%[^\t]\t", dato.cliente.correo);
				fscanf(arch, "%[^\n]\n", dato.cliente.telefono);
				
				if(dato.pedido.idPedido==id){
					printf("\nDatos del pedido\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					printf("Pedido\tEstado\tNombre\tCorreo\tTelefono\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
					printf("%d\t", dato.pedido.idPedido);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					printf("%s\t", dato.pedido.estado);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
					printf("%s\t", dato.cliente.nomCompleto);
					printf("%s\t", dato.cliente.correo);
					printf("%s\n", dato.cliente.telefono);
					if(strcmp(dato.pedido.estado, "Entregado")==0){
						printf("Este pedido ya ha sido entregado");
					}else{
						if(strcmp(dato.pedido.estado, "Cancelado")==0){
							printf("Este pedido se encuentra cancelado");
						}else{
							strcpy(dato.pedido.estado, "Entregado");
							identificacion=dato.pedido.idPedido;
						}
					}
					bandera=true;
				}
				fprintf(arch3, "%d\t", dato.pedido.idPedido);
				fprintf(arch3, "%s\t", dato.pedido.estado);
				fprintf(arch3, "%s\t", dato.cliente.nomCompleto);
				fprintf(arch3, "%s\t", dato.cliente.correo);
				fprintf(arch3, "%s\n", dato.cliente.telefono);
			}
			if(bandera==false){
				printf("No se encuentra la id");
			}
			if(fclose(arch3)!=0){
				printf("\nNo se cerro arch3");
			}
			if(fclose(arch)!=0){
				printf("\nNo se cerro arch");
			}
			if(remove("encabezado.txt")!=0){
				printf("\nNo se movio");
			}
			if(rename("copy.txt", "encabezado.txt")!=0){
				printf("\nNo secambio nombre");
			}
			resta_existencia(identificacion);
		}else{
			if(num==2){
				while(!feof(arch)){
					fscanf(arch, "%d\t", &dato.pedido.idPedido);
					fscanf(arch, "%[^\t]\t", dato.pedido.estado);
					fscanf(arch, "%[^\t]\t", dato.cliente.nomCompleto);
					fscanf(arch, "%[^\t]\t", dato.cliente.correo);
					fscanf(arch, "%[^\n]\n", dato.cliente.telefono);
					
					if(dato.pedido.idPedido==id){
						printf("\nDatos del pedido\n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						printf("Pedido\tEstado\tNombre\tCorreo\tTelefono\n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
						printf("%d\t", dato.pedido.idPedido);
						if(strcmp(dato.pedido.estado, "Activo")==0){
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
							printf("%s\t", dato.pedido.estado);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
						}else{
							if(strcmp(dato.pedido.estado, "Entregado")==0){
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
								printf("%s\t", dato.pedido.estado);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
							}else{
								if(strcmp(dato.pedido.estado, "Cancelado")==0){
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
									printf("%s\t", dato.pedido.estado);
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
								}
							}
						}
						printf("%s\t", dato.cliente.nomCompleto);
						printf("%s\t", dato.cliente.correo);
						printf("%s\n", dato.cliente.telefono);
						if(strcmp(dato.pedido.estado, "Entregado")==0){
							printf("El pedido ya ha sido entregado, no puede modificarse");
						}
						if(strcmp(dato.pedido.estado, "Activo")==0){
							strcpy(dato.pedido.estado, "Cancelado");
							printf("\nCambio Realizado");
						}else{
							if(strcmp(dato.pedido.estado, "Cancelado")==0){
								strcpy(dato.pedido.estado, "Activo");
								printf("\nCambio Realizado");
							}
						}
						bandera=true;
					}
					fprintf(arch3, "%d\t", dato.pedido.idPedido);
					fprintf(arch3, "%s\t", dato.pedido.estado);
					fprintf(arch3, "%s\t", dato.cliente.nomCompleto);
					fprintf(arch3, "%s\t", dato.cliente.correo);
					fprintf(arch3, "%s\n", dato.cliente.telefono);
				}
				if(bandera==false){
					printf("No se encuentra la id");
				}
				if(fclose(arch3)!=0){
					printf("\nNo se cerro arch3");
				}
				if(fclose(arch)!=0){
					printf("\nNo se cerro arch");
				}
				if(remove("encabezado.txt")!=0){
					printf("\nNo se movio");
				}
				if(rename("copy.txt", "encabezado.txt")!=0){
					printf("\nNo se cambio nombre");
				}
			}
		}
		numero=validaEntero("Quieres seguir haciendo cambios en el archivo? Si--1, No--2: ");
		/*if(num==1){
			leer_dinamico(2);
		}else{
			if(num==2){
				leer_dinamico(4);
			}
		}*/
	}
	
	
}
