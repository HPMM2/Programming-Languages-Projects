/*
Proyecto Integrador de Aprendizaje - PIA

1950648	MARTINEZ BRONDO ALAN ALEXIS
1952947	MARTINEZ MARTINEZ HEIDI PAMELA
2077620	REQUENES SALAZAR ALDO JOSUE

*/


//Biblioteca estándar de C (Archivos incluidos)

#include <stdio.h>
#include <windows.h>
#include <conio.h> 
#include <string.h> 



//Define función gotoxy() para compiladores ANSI C 

void gotoxy(short x, short y) 
{
   COORD pos = {x, y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}




//-------------------------- Identificadores constantes con alcance de archivo (Directivas de preprocesador) --------------------------
#define CIERTO 1
#define FALSO 0
#define LONGITUD_NUMERO_CLIENTE 100
#define LONGITUD_NOMBRE 100
#define LONGITUD_IMPORTE 30

#define NUMERO_MAX 35





//-------------------------- Identificadores variables con alcance de archivo (variables globales) --------------------------

//Estructura del archivo de entrada

typedef struct
{
	char NumeroCliente[LONGITUD_NUMERO_CLIENTE];
	char NombreCliente[LONGITUD_NOMBRE];
} regCliente; //Nombre del registro de entrada

regCliente vtrCliente;

typedef struct
{
	char NumeroCliente[LONGITUD_NUMERO_CLIENTE];
	float Importe;
} regImporte; //Nombre del registro de entrada

regImporte vtrImporte;

//Estructura del archivo de salida
typedef struct
{
	char NumeroCliente[LONGITUD_NUMERO_CLIENTE];
	char NombreCliente[LONGITUD_NOMBRE];
	float ImporteTotal;
} regSalida; //Nombre del registro de salida

regSalida vtrSalida;

//Punteros al archivo de entrada y de salida
FILE *ptfCliente, *ptfImporte;
FILE *ptfSalida;




//-------------------------- Identificadores para funciones definidas por el programador con alcance de archivo (prototipos) -------------------------- 

void vCICLO_MENU();

void vINICIAR();

int iSELECCIONA_OPCION( int OpcionMenor , int OpcionMayor );

void vALTAS_CLIENTE( regCliente vtrCliente );

void vALTAS_IMPORTE( regImporte vtrImporte );

int iBUSCAR_NUMERO( char NumeroBuscado[LONGITUD_NUMERO_CLIENTE] );

char cCAPTURAR_NOMBRE(char NombreReceptor[], char NombreLocal[]);

char ccCAPTURAR_NUMERO_CLIENTE( char NumeroReceptor[], char NumeroLocal[] );

float fCAPTURAR_IMPORTE();

void vREPORTE_CORTE_DE_CONTROL( regCliente vtrCliente, regImporte vtrImporte, regSalida vtrSalida);

void ORDENAR_REGISTROS( regCliente vtrCliente );

void ORDENAR_REGISTROS_IMPORTE( regImporte vtrImporte );

void vIMPRIME(regSalida vtrSalida);

void vARCHIVO_HACIA_ARREGLOS();

void vORDENAMIENTO( char auNumero[][LONGITUD_NUMERO_CLIENTE], char auNombre[][LONGITUD_NOMBRE], float auImporte[], int Registros );

void vARREGLO_HACIA_ARCHIVO( char auNumero[][LONGITUD_NUMERO_CLIENTE], char auNombre[][LONGITUD_NOMBRE], float auImporte[], int Registros, regCliente vtrCliente, regImporte vtrImporte );

int iABRIR_PARA_LEER();




//-------------------------- Definición de la función principal -------------------------- 

main()
{
	//Declaración de identificadores con alcance de bloque
	//Instrucciones que forman el cuerpo o bloque de la función principal
   	
	vCICLO_MENU();
   
}//Fin de la funcion main





//-------------------------- Definición de las funciones creadas por el programador -------------------------- 

void vCICLO_MENU()
{
	//Declaración de identificadores con alcance de bloque
   
	int OpcionMenu;
	int OpcionMenor = 1, OpcionMayor = 5;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador
   
	do
	{
		system("cls"); //Borra consola		
		
		printf("\n");
		printf("\n		------ M E N U   P R I N C I P A L ------ \n\n");
		printf("\n		1 - I N I C I A R \n");
		printf("\n		2 - A L T A S   C L I E N T E S \n");
		printf("\n		3 - A L T A S   I M P O R T E S \n");		
		printf("\n		4 - R E P O R T E   D E   C O N T R O L \n");
		printf("\n		5 - S A L I D A \n");
		printf("\n		          Cual opcion deseas? : ");
		
		OpcionMenu = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor );   
		
		switch( OpcionMenu )
		{
			case 1:
					
				//Borra el archivo de entrada anterior, si se desea
				
				vINICIAR();
				
			break;
			
			case 2:
					
				//Altas de Clientes
				
				vALTAS_CLIENTE( vtrCliente );
				
			break;
			
			case 3:
				
				//Altas de Importes
				
				vALTAS_IMPORTE( vtrImporte );
			
			break;
			
			case 4:
				
				//Da el resultado del proceso
				
				vREPORTE_CORTE_DE_CONTROL( vtrCliente, vtrImporte, vtrSalida);

			break;
			
			case 5:
				
				//Salida
				
				printf("\nHA ELEGIDO SALIR DEL PROGRAMA. ADIOS \n");                      		  
				system("pause");
				
			break;			
			
			default:
				
				printf("\nEL NUMERO ELEGIDO ESTA FUERA DEL RANGO. \n");
				printf("\nEL PROGRAMA SE CERRARA EN ESTE MOMENTO. INTENTE NUEVAMENTE. \n");             
				system("pause");
				
			break;   
			           
		}//Fin  switch
		
	}while( OpcionMenu >= OpcionMenor && OpcionMenu < OpcionMayor );
	
}//Fin fin funcion vCICLO_MENU





//------------------------------------------------- iSELECCIONA_OPCION -------------------------------------------------

int iSELECCIONA_OPCION( int LimiteMenor , int LimiteMayor )
{
	//Declaración de identificadores con alcance de bloque
	
	int OpcionSeleccionada;
	char Opcion[2];        
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador	   
	
	do
	{
		scanf( "%s", Opcion );  
		OpcionSeleccionada = atoi( Opcion );
		
		if( OpcionSeleccionada == FALSO )
		{
			
			printf("\nLa opcion seleccionada NO es correcta. Intente nuevamente. \n");
			printf("\nEl rango de opciones es de %d a %d \n", LimiteMenor, LimiteMayor );     
			     
		} 
		   
		else
		{
			if( OpcionSeleccionada < LimiteMenor || OpcionSeleccionada > LimiteMayor )
			{
				
				printf("\nLa opcion seleccionada NO es correcta. Intente nuevamente. \n");
				printf("\nEl rango de opciones es de %d a %d \n", LimiteMenor, LimiteMayor );
				
			}//Fin if
			
		}//Fin if
		
	}while( OpcionSeleccionada < LimiteMenor || OpcionSeleccionada > LimiteMayor );
	
	return(OpcionSeleccionada);
	
}//Fin funcion iSELECCIONA_OPCION()





//------------------------------------------------- vINICIAR -------------------------------------------------

void vINICIAR()
{
	//Declaración de identificadores con alcance de bloque 
	
	system("cls"); //Borra consola		
	
	int OpcionMenor = 1, OpcionMayor = 2;     
	int Opcion;    
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador  

	printf( "\n			---- I N I C I A R ---- \n" );
	printf( "\nEsta ruta DESTRUYE los archivos de entrada anteriores. \n" );
	printf( "\nDesea DESTRUIRLOS?\n 1.- SI\n 2.- NO \n" );
	Opcion = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor );
	
	if( Opcion == CIERTO )
	{
		ptfCliente = fopen("c:CLIENTES.dat","r");  //Abrir archivo de entrada Clientes
		ptfImporte = fopen("c:IMPORTES.dat","r");  //Abrir archivo de entrada Importes
				
		if( ptfCliente == NULL || ptfImporte == NULL )
		{
			printf( "\nNo puedes DESTRUIR los archivos porque NO existen. \n" );
			system( "pause" );
		}
		else
		{
			fclose( ptfCliente );
			fclose( ptfImporte );			
			
			//Borra archivo
			
			remove("c:CLIENTES.dat");
			remove("c:IMPORTES.dat");			
			
		}//Fin  if( ptfCliente == NULL || ptfImporte == NULL )
		
	}//Fin if(Opcion == CIERTO)
	
}//Fin funcion vINICIAR()





// ---------------------------------------------------------------- iBUSCAR_NUMERO ----------------------------------------------------------------

//Módulo que busca el numero del cliente 
//Si el numero de cliente no existe se regresa un cero, si existe se regresa un uno 

int iBUSCAR_NUMERO( char NumeroBuscado[LONGITUD_NUMERO_CLIENTE] )
{
	//Declaración de identificadores con alcance de bloque 
	int Busqueda;
    
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 		    
	//Busqueda secuencial de un registro    
	
	ptfCliente = fopen("c:CLIENTES.dat","r");	
		
	Busqueda = FALSO;
	
	rewind( ptfCliente ); //Poner puntero al principio del archivo 
	
	do
	{
		fread(&vtrCliente, sizeof( regCliente ), 1, ptfCliente ); //Leer archivo 
		
		if( ! strcmp( vtrCliente.NumeroCliente, NumeroBuscado ) )
		{
			Busqueda = CIERTO;     //Si lo encontró se asigna 1 a buscado 
			
			break;
			
		}//Fin if 
		
	}while( ! feof( ptfCliente ) );  //Se repite hasta fin de archivo 
	
	if( ptfCliente == NULL)
	{
	
		printf( "\nEl archivo de entrada NO existe. Revise su proceso nuevamente. \n" );
		system("pause");
	} 
	else 
	{
		//Cierra archivo
		
		fclose( ptfCliente );
	
	}
	
	return( Busqueda );
	
}//Fin funcion iBUSCAR_NUMERO




//------------------------------------------------- vALTAS_CLIENTE -------------------------------------------------

void vALTAS_CLIENTE( regCliente vtrCliente )
{
	//Declaración de identificadores con alcance de bloque 
	
	system("cls"); //Borra consola
	
	int Continuar = 1, OpcionMenor = 1, OpcionMayor = 2, Longitud;
	int NoValido, Encontrado; //Encontrado= 1 verdadero ; Encontrado= 0 falso
	char NumeroCapturado[LONGITUD_NUMERO_CLIENTE], NombreCapturado[LONGITUD_NOMBRE];
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador    
	//Abrir archivo de entrada 
	
	ptfCliente = fopen("c:CLIENTES.dat","a+");
	
	while( ptfCliente != NULL && Continuar == CIERTO )
	{
		do
		{
			printf( "\n			---- A L T A S   C L I E N T E S ---- \n" );
			
			ccCAPTURAR_NUMERO_CLIENTE( NumeroCapturado, NumeroCapturado );
			
			//NoValido = iVALIDAR_NUMERO( NumeroCapturado );
	       
		}while( NoValido == CIERTO );
       
		//Busqueda secuencial de un registro 	
		
		Encontrado = iBUSCAR_NUMERO( NumeroCapturado );  //Llamada a la funcion buscar 				
		
		if( Encontrado )
		{
			printf( "\n		-- N O M B R E   E X I S T E N T E -- \n" );
			
			printf( "\nNo se puede asignar el numero de cliente porque ya existe en el archivo de datos. \n");
			
			system( "pause" );
		}
		else
		{
			//Numero de cliente no existe, entonces se puede dar de alta 
	      
			strcpy( vtrCliente.NumeroCliente, NumeroCapturado );
			ccCAPTURAR_NUMERO_CLIENTE( NumeroCapturado, NumeroCapturado );	
			strcpy( vtrCliente.NombreCliente, NombreCapturado );				  		  		  		            
		  
		  

 
			fseek( ptfCliente, 1L, 2 );  //Poner el puntero al final del archivo
			fwrite( &vtrCliente, sizeof( regCliente ), 1, ptfCliente ); //Escribir en el archivo
	      
		}//Fin if Encontrado 
        			 			    
		printf( "\nDeseas continuar?\n 1 - SI\n 2 - NO \n" );
			
		Continuar = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor );	    
			
		strset( NumeroCapturado, ' ' );   //Borrar basura
		strset( NombreCapturado, ' ' );   //Borrar basura		
		 		
	}//Fin while( ptfCliente != NULL && Continuar == CIERTO )
	
	if( ptfCliente == NULL)
	{
	
		printf( "\nEl archivo de entrada NO existe. Revise su proceso nuevamente. \n" );
		system("pause");
	} 
	else 
	{
		//Cierra archivo
		
		fclose( ptfCliente );
		
	}//Fin ptfCliente
	

	}//Fin de la funcion Altas_CLIENTE()





//------------------------------------------------- vALTAS_IMPORTE -------------------------------------------------

void vALTAS_IMPORTE( regImporte vtrImporte )
{
	//Declaración de identificadores con alcance de bloque 
	
	system("cls"); //Borra consola
	
	int Continuar = 1, OpcionMenor = 1, OpcionMayor = 2, Longitud;
	int PonerImporte, ArchivoAbierto = 1, NoValido;	

	int Encontrado; //Encontrado= 1 verdadero ; Encontrado= 0 falso
	char NumeroCapturado[LONGITUD_NUMERO_CLIENTE];
	float ImporteCapturado;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador    
	//Abrir archivo de entrada 
	
	ptfCliente = fopen("c:CLIENTES.dat","r");	
	ptfImporte = fopen("c:IMPORTES.dat","a+");

	ArchivoAbierto = 1;   
	while( ArchivoAbierto )
	{
		do
		{  
			printf( "\n			---- A L T A S   I M P O R T E S ---- \n" );
			
			ccCAPTURAR_NUMERO_CLIENTE( NumeroCapturado, NumeroCapturado );
			
			//NoValido = iVALIDAR_NUMERO( NumeroCapturado );
	       
		}while( NoValido == CIERTO );
       
		//Busqueda secuencial de un registro 	
		
		Encontrado = iBUSCAR_NUMERO( NumeroCapturado );  //Llamada a la funcion buscar 	
		 
		if( Encontrado )
		{
			fCAPTURAR_IMPORTE();
			
		}//Fin Encontrado
		else
		{
			//Cierra archivo
			
			fclose( ptfImporte );
			
		}//Fin ptfCliente
	
	
	
	}//Fin de la funcion Altas_IMPORTE()

}


/*
// ---------------------------------------------------------------- iABRIR_PARA_LEER ----------------------------------------------------------------
 
//Módulo que abre el archivo para lectura 
//Si el archivo no pudo abrirse se regresa un cero, si pudo abrirse se regresa un uno 

int iABRIR_PARA_LEER()
{
	//Declaración de identificadores con alcance de bloque 
   
	int Abrir = CIERTO; 
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 		   
	//Abrir archivo en modo lectura
   
	ptfCliente = fopen("c:CLIENTES.dat","r");	
	ptfImporte = fopen("c:IMPORTES.dat","r");
	   
	if( ptfCliente == NULL || ptfImporte == NULL )
	{
		printf( "\n\n NO SE PUEDE ABRIR EL ARCHIVO PORQUE NO EXISTE \n\n\n" );
		Abrir = FALSO;
		
	}//Fin if	   
	   
	//Parámetro de salida vale CERO si no se pudo abrir archivo, vale UNO si se pudo abrir archivo 
   
	return( Abrir );
   
}//Fin funcion iABRIR_PARA_LEER 
*/


// ---------------------------------------------------------------- ccCAPTURAR_NUMERO_CLIENTE ----------------------------------------------------------------

char ccCAPTURAR_NUMERO_CLIENTE( char NumeroReceptor[], char NumeroLocal[] )
{
	//Declaración de identificadores con alcance de bloque
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador		
	
	printf( "\nCapture el numero de cliente : " );
	scanf( "%s", NumeroLocal ); 
	
	return( NumeroLocal[LONGITUD_NUMERO_CLIENTE] );
}





//------------------------------------------------- cCAPTURAR_NOMBRE -------------------------------------------------

char cCAPTURAR_NOMBRE(char NombreReceptor[], char NombreLocal[])
{
	//Declaración de identificadores con alcance de bloque
	
	int Longitud, NoCumple, i;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador	   
	
	do
	{
		NoCumple = FALSO; 
		printf("\nCaptura el nombre del cliente: \n");     
		scanf(" %[^\n]",NombreLocal);
		Longitud = strlen( NombreLocal );
		
		for( i = 0; i < Longitud; i++ )
		{
			if( ! ( isalpha(NombreLocal[i]) || isspace(NombreLocal[i]) ) )
			{
				
				NoCumple = CIERTO;
				
			}//Fin if 
			
		}//Fin for 
		
		if( Longitud < 1 || Longitud > LONGITUD_NOMBRE || NoCumple == CIERTO )
		{
			
			printf( "\nEl dato capturado para el directorio no cumple con los requisitos. Intente nuevamente. \n");
			printf( "\nCaptura un dato no mayor a %d letras y espacios en blanco. \n", LONGITUD_NOMBRE );
			strset( NombreLocal, ' ' );
			
		}//Fin if 
	
	} while( Longitud < 1 || Longitud > LONGITUD_NOMBRE || NoCumple == CIERTO );
	
	return(NombreLocal[LONGITUD_NOMBRE]);	 
	  
}//Fin funcion cCAPTURAR_NOMBRE 




//------------------------------------------------- fCAPTURAR_IMPORTE() -------------------------------------------------

float fCAPTURAR_IMPORTE()
{	
	//Declaración de identificadores con alcance de bloque
	
	float ImporteLocal;
	char ImporteCadena[LONGITUD_IMPORTE];	   
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador  
	do
	{
		printf("Captura el importe econ%cmico: \n", 162);     
		scanf(" %[^\n]",ImporteCadena);
		ImporteLocal = atof(ImporteCadena);	//Atol convierte el parámetro de cadena a largo entero 
		
		if( ImporteLocal == 0 )
		{
        	printf( "El dato capturado para el importe econ%cmico no cumple con los requisitos \n", 162);
        	printf( "favor de capturar otro dato \n"); 			       	
        	strset( ImporteCadena, ' ' ); //Borrar basura de MatriculaCadena 
        	
		}//Fin if
		
   }while( ImporteLocal == 0 );
   
return( ImporteLocal );

}//Fin funcion fCAPTURAR_IMPORTE 




//------------------------------------------------- vREPORTE_CORTE_DE_CONTROL -------------------------------------------------

void vREPORTE_CORTE_DE_CONTROL( regCliente vtrCliente, regImporte vtrImporte, regSalida vtrSalida)
{
	//Declaración de identificadores con alcance de bloque
	
	char Nombre_control[LONGITUD_NOMBRE];
	char Numero_control[LONGITUD_NUMERO_CLIENTE];
	float ImporteTotal_control = 0;
	int arranque=1;
	int flagX;
	
	
	void ORDENAR_REGISTROS( regCliente vtrCliente );
	void ORDENAR_REGISTROS_IMPORTE( regImporte vtrImporte );

	
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador    
	//Abrir archivo de entrada 
	
	ptfCliente = fopen("c:CLIENTES.dat","r");	
	ptfImporte = fopen("c:IMPORTES.dat","r");	
	
	
	ptfSalida = fopen("c:SALIDAS.sal","w");
	
	
	if( ptfCliente == NULL || ptfImporte == NULL )
	{
		printf( "\nLOS ARCHIVOS DE ENTRADA NO EXISTEN. \n" );
		system( "pause" );
	}
	else
	{
		fread(&vtrCliente, sizeof( regCliente ), 1, ptfCliente);
		do
		{
			flagX=0;
			ImporteTotal_control = 0;

			strcpy(Numero_control, vtrCliente.NumeroCliente);			
			strcpy(Nombre_control, vtrCliente.NombreCliente);
			
			if( arranque==1 )
			{
				fread(&vtrImporte, sizeof( regImporte ), 1, ptfImporte);
				arranque=0;
	        }		
			
			do
			{
				if(strcmp(vtrImporte.NumeroCliente, Numero_control)==0)
				{
					ImporteTotal_control = ImporteTotal_control + vtrImporte.Importe;
				}
				else
				{
					flagX=1;
				}
			
	
		}while(flagX == 0);
		
			//Se guarda en el puntero de salida
			strcpy(vtrSalida.NumeroCliente, Numero_control);			
			strcpy(vtrSalida.NombreCliente, Nombre_control);	
			vtrSalida.ImporteTotal=ImporteTotal_control;	
		
		}while(flagX == 1);	
		//Cerrar archivos 
		
		fclose( ptfCliente );
		fclose( ptfImporte );
		fclose( ptfSalida );
		
		vIMPRIME(vtrSalida);
	}

	
	system("pause");		
}




//------------------------------------------------- vIMPRIME -------------------------------------------------

void vIMPRIME(regSalida vtrSalida)
{
	//Declaración de identificadores con alcance de bloque 
   
	int Linea;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador    
	//Abrir archivo de salida 
	
	ptfCliente = fopen("c:CLIENTES.dat","r");	
	ptfImporte = fopen("c:IMPORTES.dat","r");		
	ptfSalida = fopen("c:SALIDAS.sal","r");
	
	system("cls");
	
	if( ptfSalida == NULL )
	{
		printf( "\nEl archivo de entrada NO existe. \n" );
		printf( "\nRevise su proceso nuevamente. \n" );
			
	}//Fin if(ptfSalida==NULL) 
 
	//Poner encabezados 
	
	printf("NUM				NOMBRE				IMPORTE		\n");
	Linea=2;
	
	//Leer archivo de salida 
	
	fread(&vtrSalida, sizeof(regSalida), 1, ptfSalida);
	do
	{
		gotoxy( 1, Linea ); 
		printf( "%s", vtrSalida.NumeroCliente );
		
		gotoxy( 15, Linea ); 
		printf( "%s",vtrSalida.NombreCliente);      
		  
		gotoxy( 45, Linea ); 
		printf( "%f", vtrSalida.ImporteTotal);
		

		Linea++;
		
		//Leer archivo de salida 
		
		fread(&vtrSalida, sizeof(regSalida), 1, ptfSalida);
	
	}while(!feof(ptfSalida));
	
	fclose(ptfSalida);
	
} //Fin funcion vIMPRIME() 




//------------------------------------------------- ORDENAR_REGISTROS -------------------------------------------------

void ORDENAR_REGISTROS( regCliente vtrCliente )
{  
	//Declaración de identificadores con alcance de bloque 
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 
   
	vARCHIVO_HACIA_ARREGLOS();   
	
}//Fin funcion ORDENAR_REGISTROS




//------------------------------------------------- vARCHIVO_HACIA_ARREGLOS -------------------------------------------------

void vARCHIVO_HACIA_ARREGLOS()
{
	//Declaración de identificadores con alcance de bloque 
	
	char auNombre[1000][LONGITUD_NOMBRE];
	char auNumero[1000][LONGITUD_NUMERO_CLIENTE];
	float auImporte[1000];
	int i = 0, Registros;
	
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 	
	   
	ptfCliente = fopen("c:CLIENTES.dat","r");	
	ptfImporte = fopen("c:IMPORTES.dat","r");		
	

	fread(&vtrCliente, sizeof(regCliente), 1, ptfCliente);
	fread(&vtrImporte, sizeof(regImporte), 1, ptfImporte);
	do
	{
		//Pasar de datos de archivo hacia arreglos 
		
		strcpy( auNumero[i], vtrCliente.NumeroCliente );		
		strcpy( auNombre[i], vtrCliente.NombreCliente );		
		auImporte[i] = vtrImporte.Importe;
		

		i = i + 1;
		fread(&vtrCliente, sizeof(regCliente), 1, ptfCliente);
		fread(&vtrImporte, sizeof(regImporte), 1, ptfImporte);
	
	}while( !feof( ptfCliente ) );
	
	Registros = i;
	
	//Cerrar el archivo 
	
	fclose( ptfCliente );
	fclose( ptfImporte );
	
	vORDENAMIENTO (auNumero, auNombre, auImporte, Registros );

		
} //Fin funcion vARCHIVO_HACIA_ARREGLOS 




//------------------------------------------------- vORDENAMIENTO -------------------------------------------------

void vORDENAMIENTO( char auNumero[][LONGITUD_NUMERO_CLIENTE], char auNombre[][LONGITUD_NOMBRE], float auImporte[], int Registros )
{
	//Declaración de identificadores con alcance de bloque 
	
	int i, j;
	char AuxiliarNumero[LONGITUD_NUMERO_CLIENTE];	
	char AuxiliarNombre[LONGITUD_NOMBRE];
	float AuxiliarImporte;


	ptfCliente = fopen("c:CLIENTES.dat","r");	
	ptfImporte = fopen("c:IMPORTES.dat","r");
	
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 	   
	
	for ( i = 1; i < Registros; i++)
	{
		for ( j = 0; j < Registros - i; j++)
		{
			
			if (auNumero[j] >= auNumero[j+1] )
			{
	            strcpy(AuxiliarNumero, auNumero[j]);
	            strcpy(auNumero[j], auNumero[j+1]);
	            strcpy(auNumero[j+1], AuxiliarNumero);
	            
	            strcpy(AuxiliarNombre, auNombre[j]);
	            strcpy(auNombre[j], auNombre[j+1]);
	            strcpy(auNombre[j+1], AuxiliarNombre);           
				
				AuxiliarImporte = auImporte[j];
				auImporte[j] = auImporte[j+1];
				auImporte[j+1] = AuxiliarImporte;
				
                       
			}//Fin if 
			
		}//Fin for j 
		
	}//Fin for i 
	
		//Cerrar el archivo 
	
	fclose( ptfCliente );
	fclose( ptfImporte );
	
	vARREGLO_HACIA_ARCHIVO( auNumero, auNombre, auImporte, Registros, vtrCliente, vtrImporte );
	
}//Fin funcion vORDENAMIENTO 	




//------------------------------------------------- vARREGLO_HACIA_ARCHIVO -------------------------------------------------

void vARREGLO_HACIA_ARCHIVO( char auNumero[][LONGITUD_NUMERO_CLIENTE], char auNombre[][LONGITUD_NOMBRE], float auImporte[], int Registros, regCliente vtrCliente, regImporte vtrImporte )
{
	//Declaración de identificadores con alcance de bloque 
	
	FILE *ptfNuevoArchivo;
	int i;

	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador    
	//Abrir archivo en modo escritura 
	
	ptfCliente = fopen("c:CLIENTES.dat","r");	
	ptfImporte = fopen("c:IMPORTES.dat","w");   
   
	for( i = 0; i < Registros; i++ )
	{
		//Pasar datos de arreglos al archivo 

		strcpy( vtrCliente.NumeroCliente, auNumero[i] ); 
		strcpy( vtrCliente.NombreCliente, auNombre[i] ); 
		vtrImporte.Importe = auImporte[i]; 

   
		fwrite(&vtrImporte, sizeof(regImporte), 1, ptfImporte);
		
	}//Fin del for 
	
		//Cerrar el archivo 
	
	fclose( ptfCliente );
	fclose( ptfImporte );
	
	return;	
}





