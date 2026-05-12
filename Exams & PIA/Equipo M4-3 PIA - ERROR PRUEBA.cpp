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
#define LONGITUD_NOMBRE 20
#define CORREO_EMAIL 20
#define TELEFONO_MINIMA 1
#define TELEFONO_MAXIMA 999
#define LONGITUD_TELEFONO 15







//-------------------------- Identificadores variables con alcance de archivo (variables globales) --------------------------

//Estructura del archivo de entrada

typedef struct
{
	//DIRECTORIO
	//Nombre, correo electronico, telefono 10 dig, codigo postal 5 dig
	
	char Nombre_e[LONGITUD_NOMBRE+1];
	char Correo_e[CORREO_EMAIL+1];
	long int Telefono_e;

	
} regDatos; //Nombre del registro de entrada


//Estructura del archivo de salida

typedef struct
{
	char Nombre_s[LONGITUD_NOMBRE+1];
	char Correo_s[CORREO_EMAIL+1];
	long int Telefono_s;

} regSalida; //Nombre del registro de salida




        
//-------------------------- Punteros al archivo de entrada y de salida --------------------------

FILE *ptfEntrada, *ptfSalida;

regDatos vtrEntrada; //Variable tipo registro del archivo de entrada
regSalida vtrSalida;  //Variable tipo registro del archivo de salida





//-------------------------- Identificadores para funciones definidas por el programador con alcance de archivo (prototipos) -------------------------- 

void vCICLO_MENU();

void vINICIAR();

void vALTAS( regDatos vtrEntrada );

char cCAPTURAR_NOMBRE(char NombreReceptor[], char NombreLocal[]);

char cCAPTURAR_CORREO(char CorreoReceptor[], char CorreoLocal[]);

long int liCAPTURAR_TELEFONO();

void vREPORTE_CORTE_DE_CONTROL( regDatos vtrEntrada, regSalida vtrSalida );

void vIMPRIME( regSalida vtrSalida );

int iSELECCIONA_OPCION( int OpcionMenor , int OpcionMayor );

void ORDENAR_REGISTROS( regDatos vtrEntrada );

void vARCHIVO_HACIA_ARREGLOS();

void vORDENAMIENTO( char auNombre_t[][LONGITUD_NOMBRE], char auCorreo_t[][CORREO_EMAIL], long int auTelefono_t[], int Registros );
	
void vARREGLO_HACIA_ARCHIVO( char auN_t[][LONGITUD_NOMBRE], char auC_t[][CORREO_EMAIL], long int auT_t[], int R, regDatos vtrEntrada );





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
	int OpcionMenor = 1, OpcionMayor = 4;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador
   
	do
	{
			system("cls");
		printf("\n");
		printf("\n		------ M E N U   P R I N C I P A L ------ \n\n");
		printf("\n		1 - I N I C I A R \n");
		printf("\n		2 - A L T A S   C L I E N T E S \n");
		printf("\n		2 - A L T A S   I M P O R T E S \n");		
		printf("\n		3 - R E P O R T E   D E   C O N T R O L \n");
		printf("\n		4 - S A L I D A \n");
		printf("\n		          Cual opcion deseas? : ");

		OpcionMenu = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor );   

		switch( OpcionMenu )
		{

			case 1:
					
				//Borra el archivo de entrada anterior, si se desea
				
				vINICIAR();
				
			break;
			
			case 2:
					
				//Altas de registros
				
				vALTAS(vtrEntrada);
				
			break;
			
			case 3:
				
				//Da el resultado del proceso
				
				vREPORTE_CORTE_DE_CONTROL(vtrEntrada, vtrSalida);
			
			break;
			
			case 4:
				
				printf("\nUsted ha elegido salir del programa. \n");                      		  
				system("pause");
				
			break;
			
			default:
				
				printf("\nLa opcion elegida esta fuera de rango. \n");
				printf("\nEl programa concluira su funcion en estos momentos. \n");             
				system("pause");
				
			break;   
			           
		} //Fin  switch
	
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
			printf("\nEl rango de opciones es de %d a %d \n", LimiteMenor, LimiteMayor );  
			printf("\nLa opcion seleccionada NO es correcta. Intente nuevamente. ");


			     
		} 
		   
		else
		{
			if( OpcionSeleccionada < LimiteMenor || OpcionSeleccionada > LimiteMayor )
			{
				printf("\nEl rango de opciones es de %d a %d \n", LimiteMenor, LimiteMayor );
				printf("\nLa opcion seleccionada NO es correcta. Intente nuevamente. ");

			
				
			}//Fin if
			
		}//Fin if
		
	}while( OpcionSeleccionada < LimiteMenor || OpcionSeleccionada > LimiteMayor );
	
	return(OpcionSeleccionada);
	
}//Fin funcion iSELECCIONA_OPCION()





//------------------------------------------------- vINICIAR -------------------------------------------------

void vINICIAR()
{
	//Declaración de identificadores con alcance de bloque 
   system("cls");
	int OpcionMenor = 1, OpcionMayor = 2;     
	int Opcion;    
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador  

	printf( "\n			---- I N I C I A R ---- \n" );
	printf( "\nEsta ruta DESTRUYE el archivo de entrada anterior. \n" );
	printf( "\nDesea DESTRUIRLO?\n 1.- SI\n 2.- NO \n" );
	Opcion = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor );
	
	if( Opcion == CIERTO )
	{
		ptfEntrada = fopen("c:DIRECTORIO.dat","r");  //Abrir archivo de entrada
		
		if( ptfEntrada == NULL )
		{
			printf( "\nNo puedes DESTRUIR el archivo porque NO existe. \n" );
			system( "pause" );
		}
		
		else
		{
			fclose( ptfEntrada );
			
			//Borra archivo
			
			remove("c:DIRECTORIO.dat");
			
		}//Fin  if(ptfEntrada == NULL)
		
	}//Fin if(Opcion == CIERTO)
	
}//Fin funcion vINICIAR()





//------------------------------------------------- vALTAS -------------------------------------------------

void vALTAS( regDatos vtrEntrada )
{
	//Declaración de identificadores con alcance de bloque 
system("cls");
	int Continuar, OpcionMenor = 1, OpcionMayor = 2;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador    
	//Abrir archivo de entrada 
	
	ptfEntrada = fopen("c:DIRECTORIO.dat","a+");
	
	if( ptfEntrada == NULL)
	{
	
		printf( "\nEl archivo de entrada NO existe. \n" );
		printf( "\nRevise su proceso nuevamente. \n" );
				
	}//Fin if

	if( ptfEntrada != NULL)
	{
		do
		{
			printf( "\n			---- A L T A S ---- \n" );
			
			cCAPTURAR_NOMBRE(vtrEntrada.Nombre_e, vtrEntrada.Nombre_e);	
			
			cCAPTURAR_CORREO(vtrEntrada.Correo_e, vtrEntrada.Correo_e);				
						
			vtrEntrada.Telefono_e = liCAPTURAR_TELEFONO();
									
	  	      
			fwrite(&vtrEntrada, sizeof(regDatos), 1, ptfEntrada);
			
			printf( "\nDeseas continuar?\n 1 - SI\n 2 - NO \n" );
			
			Continuar = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor );	      
		
		}while( Continuar == 1 );
		
	}//Fin if(ptfEntrada!=NULL)
	
	fclose(ptfEntrada);
	
}//Fin de la funcion Altas()





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





//------------------------------------------------- cCAPTURAR_CORREO -------------------------------------------------

char cCAPTURAR_CORREO(char CorreoReceptor[], char CorreoLocal[])
{
	//Declaración de identificadores con alcance de bloque
	
	int Longitud, NoCumple, i;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador	   
	
	do
	{
		NoCumple = FALSO; 
		printf("\nSOLO dominio @gmail.com y NO añada '@gmail.com' : \n"); 		
		printf("\nCaptura el correo electronico : \n");     
		scanf(" %[^\n]",CorreoLocal);
		Longitud = strlen( CorreoLocal );
		
		for( i = 0; i < Longitud; i++ )
		{
			if( ! ( isalpha(CorreoLocal[i]) || isspace(CorreoLocal[i]) ) )
			{
				
				NoCumple = CIERTO;
				
			}//Fin if 
			
		}//Fin for 
		
		if( Longitud < 1 || Longitud > CORREO_EMAIL || NoCumple == CIERTO )
		{
			
			printf( "El dato capturado para el directorio no cumple con los requisitos. Intente nuevamente. \n");
			printf( "Captura un dato no mayor a %d letras y espacios en blanco. (NO añada '@gmail.com') \n", CORREO_EMAIL );
			strset( CorreoLocal, ' ' );
			
		}//Fin if 
	
	}while( Longitud < 1 || Longitud > CORREO_EMAIL || NoCumple == CIERTO );
	
	return(CorreoLocal[CORREO_EMAIL]);	 
	  
}//Fin funcion cCAPTURAR_CORREO 





//------------------------------------------------- liCAPTURAR_TELEFONO -------------------------------------------------

long int liCAPTURAR_TELEFONO()
{	
	//Declaración de identificadores con alcance de bloque 
   
	long int TelefonoLocal;
	char TelefonoCadena[LONGITUD_TELEFONO];	   
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador

	do
	{
		printf("\nCaptura el n%cmero de telefono celular: \n", 163);     
		scanf(" %[^\n]",TelefonoCadena);
		TelefonoLocal = atol(TelefonoCadena);	//Atol convierte el parámetro de cadena a largo entero
		
		if( TelefonoLocal == 0 )
		{
			printf( "\nEl dato capturado para el n%cmero de telefono del directorio no cumple con los requisitos. Intente nuevamente \n", 163);
			printf( "\nCapture un dato numerico con %d digitos \n", LONGITUD_TELEFONO ); 			       	
			strset( TelefonoCadena, ' ' );   //Borrar basura de  TelefonoCadena
		
		}//Fin if
	
	}while( TelefonoLocal == 0 );

return( TelefonoLocal );

}//Fin funcion liCAPTURAR_TELEFONO







//------------------------------------------------- vREPORTE_CORTE_DE_CONTROL -------------------------------------------------

void vREPORTE_CORTE_DE_CONTROL( regDatos vtrEntrada, regSalida vtrSalida )
{
	//Declaración de identificadores con alcance de bloque
	
	char Nombre_t[LONGITUD_NOMBRE];
	char Correo_t[CORREO_EMAIL];
	long int Telefono_t, Codigo_t;
    
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 

	ORDENAR_REGISTROS( vtrEntrada );    
	ptfEntrada = fopen("c:DIRECTORIO.dat","r");  //Abrir archivo de entrada
    ptfSalida = fopen("c:PIA.sal","w");  //Abrir archivo de salida
    
	if( ptfEntrada == NULL )
	{
		printf( "\nEl archivo de entrada NO existe. \n" );
		printf( "\nRevise su proceso nuevamente. \n" );
	
	}//Fin if 
    
	if( ptfEntrada != NULL )
	{
		//Leer archivo de entrada 
		
		fread(&vtrEntrada, sizeof(regDatos), 1, ptfEntrada);
		strcpy(Nombre_t, vtrEntrada.Nombre_e);
		strcpy(Correo_t, vtrEntrada.Correo_e);				
		Telefono_t = vtrEntrada.Telefono_e;
	

		do
		{
			if( Nombre_t == vtrEntrada.Nombre_e )
			{				
			
			
				//Se realiza el corte de control 
				//Pasar los valores de la variables de trabajo a las variables de salida 
				
				strcpy(vtrSalida.Nombre_s,Nombre_t);
				strcpy(vtrSalida.Correo_s,Correo_t);								
				vtrSalida.Telefono_s = Telefono_t;
				
	       
				//Escribir en el archivo de salida 
				
				fwrite(&vtrSalida, sizeof(regSalida), 1, ptfSalida);

				//Re-inicializar las variables de trabajo 
				
				strcpy(Nombre_t,vtrEntrada.Nombre_e);
				strcpy(Correo_t,vtrEntrada.Correo_e);								
				Telefono_t = vtrEntrada.Telefono_e;
				
	       	
			}//Fin if 
			
		}while(!feof(ptfEntrada));
		
		//Se realiza el ultimo corte de control 
		//Pasar los valores de la variables de trabajo a las variable de salida 
		
			strcpy(vtrSalida.Nombre_s,Nombre_t);
			strcpy(vtrSalida.Correo_s,Correo_t);								
			vtrSalida.Telefono_s = Telefono_t;


		//Escribir en el archivo de salida 
		
		fwrite(&vtrSalida, sizeof(regSalida), 1, ptfSalida);
		
		//Cerrar archivos 
		
		fclose(ptfEntrada);
		fclose(ptfSalida);
		
		vIMPRIME(vtrSalida);
		
	}//Fin del if 
	
	system("pause");
	
}//Fin funcion vREPORTE_CORTE_DE_CONTROL 





//------------------------------------------------- vIMPRIME -------------------------------------------------

void vIMPRIME(regSalida vtrSalida)
{
	//Declaración de identificadores con alcance de bloque 
   
	int Linea;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador    
	//Abrir archivo de salida 
	
	ptfSalida = fopen("c:PIA.sal","r");
	system("cls");
	
	if( ptfSalida == NULL )
	{
		printf( "\nEl archivo de entrada NO existe. \n" );
		printf( "\nRevise su proceso nuevamente. \n" );
			
	}//Fin if(ptfSalida==NULL) 
 
	//Poner encabezados 
	
	printf("Nombre				Correo				Cel.		\n");
	Linea=2;
	
	//Leer archivo de salida 
	
	fread(&vtrSalida, sizeof(regSalida), 1, ptfSalida);
	do
	{
		gotoxy( 1, Linea ); 
		printf( "%s", vtrSalida.Nombre_s );
		
		gotoxy( 15, Linea ); 
		printf( "%s@gmail.com",vtrSalida.Correo_s );      
		  
		gotoxy( 45, Linea ); 
		printf( "ld", vtrSalida.Telefono_s );
		

		Linea++;
		
		//Leer archivo de salida 
		
		fread(&vtrSalida, sizeof(regSalida), 1, ptfSalida);
	
	}while(!feof(ptfSalida));
	
	fclose(ptfSalida);
	
} //Fin funcion vIMPRIME() 





//------------------------------------------------- ORDENAR_REGISTROS -------------------------------------------------

void ORDENAR_REGISTROS( regDatos vtrEntrada )
{  
	//Declaración de identificadores con alcance de bloque 
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 
   
	vARCHIVO_HACIA_ARREGLOS();   
	
}//Fin funcion ORDENAR_REGISTROS





//------------------------------------------------- vARCHIVO_HACIA_ARREGLOS -------------------------------------------------

void vARCHIVO_HACIA_ARREGLOS()
{
	//Declaración de identificadores con alcance de bloque 
	
	char auNombre_t[1000][LONGITUD_NOMBRE];
	char auCorreo_t[1000][CORREO_EMAIL];		
	long int auTelefono_t[1000];
	

	int i = 0, Registros;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 	
	   
	ptfEntrada = fopen("c:DIRECTORIO.dat","r");

	fread(&vtrEntrada, sizeof(regDatos), 1, ptfEntrada);
	do
	{
		//Pasar de datos de archivo hacia arreglos 
		
		strcpy( auNombre_t[i], vtrEntrada.Nombre_e );		
		strcpy( auCorreo_t[i], vtrEntrada.Correo_e );		
		auTelefono_t[i] = vtrEntrada.Telefono_e;
		

		i = i + 1;
		fread(&vtrEntrada, sizeof(regDatos), 1, ptfEntrada);
	
	}while( !feof( ptfEntrada ) );
	
	Registros = i;
	
	//Cerrar el archivo 
	
	fclose( ptfEntrada );
	vORDENAMIENTO (auNombre_t, auCorreo_t, auTelefono_t, Registros );
;
		
} //Fin funcion vARCHIVO_HACIA_ARREGLOS 





//------------------------------------------------- vORDENAMIENTO -------------------------------------------------

void vORDENAMIENTO( char auN_t[][LONGITUD_NOMBRE], char auC_t[][CORREO_EMAIL], long int auT_t[],  int R)
{
	//Declaración de identificadores con alcance de bloque 
	
	int i, j, AuxiliarTelefono;
	char AuxiliarNombre[LONGITUD_NOMBRE];
	char AuxiliarCorreo[CORREO_EMAIL];

	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 	   
	
	for ( i = 1; i < R; i++)
	{
		for ( j = 0; j < R-i; j++)
		{
			
			if (auN_t[j] >= auN_t[j+1] )
			{
	            strcpy(AuxiliarNombre, auN_t[j]);
	            strcpy(auN_t[j], auN_t[j+1]);
	            strcpy(auN_t[j+1], AuxiliarNombre);
	            
	            strcpy(AuxiliarCorreo, auC_t[j]);
	            strcpy(auC_t[j], auC_t[j+1]);
	            strcpy(auC_t[j+1], AuxiliarCorreo);	            
				
				AuxiliarTelefono = auT_t[j];
				auT_t[j] = auT_t[j+1];
				auT_t[j+1] = AuxiliarTelefono;
				
                       
			}//Fin if 
			
		}//Fin for j 
		
	}//Fin for i 
	
	vARREGLO_HACIA_ARCHIVO( auN_t, auC_t, auT_t, R, vtrEntrada );
	
}//Fin funcion vORDENAMIENTO 





//------------------------------------------------- vARREGLO_HACIA_ARCHIVO -------------------------------------------------

void vARREGLO_HACIA_ARCHIVO( char auN_t[][LONGITUD_NOMBRE], char auC_t[][CORREO_EMAIL], long int auT_t[], int R, regDatos vtrEntrada )
{
	//Declaración de identificadores con alcance de bloque 
	FILE *ptfNuevoArchivo;
	int i;

	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador    
	//Abrir archivo en modo escritura 
	
	ptfEntrada = fopen("c:DIRECTORIO.dat","w");   
   
	for( i = 0; i < R; i++ )
	{
		//Pasar datos de arreglos al archivo 

		strcpy( vtrEntrada.Nombre_e, auN_t[i] ); 
		strcpy( vtrEntrada.Correo_e, auC_t[i] ); 
		vtrEntrada.Telefono_e = auT_t[i];     

   
		fwrite(&vtrEntrada, sizeof(regDatos), 1, ptfEntrada);
		
	}//Fin del for 
	
	fclose( ptfEntrada );
	return;
	
}//Fin funcion vARREGLO_HACIA_ARCHIVO




