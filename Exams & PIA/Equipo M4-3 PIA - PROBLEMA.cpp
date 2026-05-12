/*
Proyecto Integrador de Aprendizaje - PIA

1950648	MARTINEZ BRONDO ALAN ALEXIS
1952947	MARTINEZ MARTINEZ HEIDI PAMELA
2077620	REQUENES SALAZAR ALDO JOSUE



Problema: Promediar estudiantes con sus 3 calificaciones
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
#define LONGITUD_CA 3
#define CA_MINIMA 1
#define CA_MAXIMA 100





//-------------------------- Identificadores variables con alcance de archivo (variables globales) --------------------------

//Estructura del archivo de entrada

typedef struct
{
	char Nombre_e[LONGITUD_NOMBRE+1];
	long int CA1_e;
	long int CA2_e;
	long int CA3_e;	
		
} regDatos; //Nombre del registro de entrada


//Estructura del archivo de salida

typedef struct
{
	char Nombre_s[LONGITUD_NOMBRE+1];
	long int CA1_s;
	long int CA2_s;
	long int CA3_s;
	float Promedio_s;
	
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

long int liCAPTURAR_CA1();

long int liCAPTURAR_CA2();

long int liCAPTURAR_CA3();

void vREPORTE_CORTE_DE_CONTROL( regDatos vtrEntrada, regSalida vtrSalida );

void vIMPRIME( regSalida vtrSalida );

int iSELECCIONA_OPCION( int OpcionMenor , int OpcionMayor );

void ORDENAR_REGISTROS( regDatos vtrEntrada );

void vARCHIVO_HACIA_ARREGLOS();

void vORDENAMIENTO( char auNombre_t[][LONGITUD_NOMBRE],  long int auCA1_t[],  long int auCA2_t[], long int auCA3_t[], int Registros );
	
void vARREGLO_HACIA_ARCHIVO( char auN_t[][LONGITUD_NOMBRE], long int auC1_t[],  long int auC2_t[], long int auC3_t[], int R, regDatos vtrEntrada );





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
		printf("\nM E N U   P R I N C I P A L \n");
		printf("\n1.- I N I C I A R \n");
		printf("\n2.- A L T A S \n");
		printf("\n3.- R E P O R T E \n");
		printf("\n4.- S A L I D A \n");
		printf("\nCual opcion deseas? : ");
		
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
   
	int OpcionMenor = 1, OpcionMayor = 2;     
	int Opcion;    
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador  

	printf( "\nI N I C I A R \n" );
	printf( "\nEsta ruta DESTRUYE el archivo de entrada anterior. \n" );
	printf( "\nDesea DESTRUIRLO?\n 1.- SI\n 2.- NO \n" );
	Opcion = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor );
	
	if( Opcion == CIERTO )
	{
		ptfEntrada = fopen("c:PROBLEMA.dat","r");  //Abrir archivo de entrada
		
		if( ptfEntrada == NULL )
		{
			printf( "\nNo puedes DESTRUIR el archivo porque NO existe. \n" );
			system( "pause" );
		}
		
		else
		{
			fclose( ptfEntrada );
			
			//Borra archivo
			
			remove("c:PROBLEMA.dat");
			
		}//Fin  if(ptfEntrada == NULL)
		
	}//Fin if(Opcion == CIERTO)
	
}//Fin funcion vINICIAR()





//------------------------------------------------- vALTAS -------------------------------------------------

void vALTAS( regDatos vtrEntrada )
{
	//Declaración de identificadores con alcance de bloque 
	
	int Continuar, OpcionMenor = 1, OpcionMayor = 2;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador    
	//Abrir archivo de entrada 
	
	ptfEntrada = fopen("c:PROBLEMA.dat","a+");
	
	if( ptfEntrada == NULL)
	{
	
		printf( "\nEl archivo de entrada NO existe. \n" );
		printf( "\nRevise su proceso nuevamente. \n" );
				
	}//Fin if

	if( ptfEntrada != NULL)
	{
		do
		{
			printf( "\nA L T A S \n" );
			
			cCAPTURAR_NOMBRE(vtrEntrada.Nombre_e, vtrEntrada.Nombre_e);			
						
			vtrEntrada.CA1_e = liCAPTURAR_CA1();
									
			vtrEntrada.CA2_e = liCAPTURAR_CA2();
			
			vtrEntrada.CA3_e = liCAPTURAR_CA3();			
	  	      
			fwrite(&vtrEntrada, sizeof(regDatos), 1, ptfEntrada);
			
			printf( "\nDeseas continuar?\n 1.- SI\n 2.-NO \n" );
			
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
		printf("\nCaptura el nombre del alumno: \n");     
		scanf(" %[^\n]", NombreLocal);
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
			
			printf( "\nEl dato capturado no cumple con los requisitos. Intente nuevamente. \n");
			printf( "\nCaptura un dato no mayor a %d letras y espacios en blanco. \n", LONGITUD_NOMBRE );
			strset( NombreLocal, ' ' );
			
		}//Fin if 
	
	} while( Longitud < 1 || Longitud > LONGITUD_NOMBRE || NoCumple == CIERTO );
	
	return(NombreLocal[LONGITUD_NOMBRE]);	 
	  
}//Fin funcion cCAPTURAR_NOMBRE 





//------------------------------------------------- liCAPTURAR_CA1 -------------------------------------------------

long int liCAPTURAR_CA1()
{	
	//Declaración de identificadores con alcance de bloque 
   
	long int CA1Local;
	char CA1Cadena[LONGITUD_CA];	   
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador

	do
	{
		printf("\nCaptura la primera calificacion: \n");     
		scanf(" %[^\n]",CA1Cadena);
		CA1Local = atol(CA1Cadena);	//Atol convierte el parámetro de cadena a largo entero
		
		if(  CA1Local == 0 || CA1Local < CA_MINIMA || CA1Local > CA_MAXIMA )
		{
			printf( "\nEl dato capturado para el n%cmero de telefono del directorio no cumple con los requisitos. Intente nuevamente \n", 163);
			printf( "\Capture un dato con %d digitos \n", LONGITUD_CA ); 			       	
			strset( CA1Cadena, ' ' );   //Borrar basura de  CA1Cadena
		
		}//Fin if
	
	}while(  CA1Local == 0 ||  CA1Local < CA_MINIMA ||  CA1Local > CA_MAXIMA );

return(  CA1Local );

}//Fin funcion liCAPTURAR_CA1





//------------------------------------------------- liCAPTURAR_CA2 -------------------------------------------------

long int liCAPTURAR_CA2()
{	
	//Declaración de identificadores con alcance de bloque 
   
	long int CA2Local;
	char CA2Cadena[LONGITUD_CA];	   
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador

	do
	{
		printf("\nCaptura la segunda calificacion: \n");     
		scanf(" %[^\n]",CA2Cadena);
		CA2Local = atol(CA2Cadena);	//Atol convierte el parámetro de cadena a largo entero
		
		if(  CA2Local == 0 || CA2Local < CA_MINIMA || CA2Local > CA_MAXIMA )
		{
			printf( "\nEl dato capturado para el n%cmero de telefono del directorio no cumple con los requisitos. Intente nuevamente \n", 163);
			printf( "\Capture un dato con %d digitos \n", LONGITUD_CA ); 			       	
			strset( CA2Cadena, ' ' );   //Borrar basura de  CA2Cadena
		
		}//Fin if
	
	}while(  CA2Local == 0 ||  CA2Local < CA_MINIMA ||  CA2Local > CA_MAXIMA );

return(  CA2Local );

}//Fin funcion liCAPTURAR_CA2





//------------------------------------------------- liCAPTURAR_CA3 -------------------------------------------------

long int liCAPTURAR_CA3()
{	
	//Declaración de identificadores con alcance de bloque 
   
	long int CA3Local;
	char CA3Cadena[LONGITUD_CA];	   
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador

	do
	{
		printf("\nCaptura la tercera calificacion: \n");     
		scanf(" %[^\n]",CA3Cadena);
		CA3Local = atol(CA3Cadena);	//Atol convierte el parámetro de cadena a largo entero
		
		if(  CA3Local == 0 || CA3Local < CA_MINIMA || CA3Local > CA_MAXIMA )
		{
			printf( "\nEl dato capturado para el n%cmero de telefono del directorio no cumple con los requisitos. Intente nuevamente \n", 163);
			printf( "\Capture un dato con %d digitos \n", LONGITUD_CA ); 			       	
			strset( CA3Cadena, ' ' );   //Borrar basura de  CA3Cadena
		
		}//Fin if
	
	}while(  CA3Local == 0 ||  CA3Local < CA_MINIMA ||  CA3Local > CA_MAXIMA );

return(  CA3Local );

}//Fin funcion liCAPTURAR_CA3





//------------------------------------------------- vREPORTE_CORTE_DE_CONTROL -------------------------------------------------

void vREPORTE_CORTE_DE_CONTROL( regDatos vtrEntrada, regSalida vtrSalida )
{
	//Declaración de identificadores con alcance de bloque
	
	char Nombre_t[LONGITUD_NOMBRE];
	long int CA1_t, CA2_t, CA3_t;
	float Promedio_t = 0;
    
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 

	ORDENAR_REGISTROS( vtrEntrada );    
	ptfEntrada = fopen("c:PROBLEMA.dat","r");  //Abrir archivo de entrada
    ptfSalida = fopen("c:M4_3_PIA.sal","w");  //Abrir archivo de salida
    
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
		CA1_t = vtrEntrada.CA1_e;
		CA2_t = vtrEntrada.CA2_e;
		CA3_t = vtrEntrada.CA3_e;						

		do
		{
			if( Nombre_t == vtrEntrada.Nombre_e )
			{				
				Promedio_t = (Promedio_t + vtrEntrada.CA1_e + vtrEntrada.CA2_e + vtrEntrada.CA3_e)/3;
				
				//Leer archivo de entrada 
				
				fread(&vtrEntrada, sizeof(regDatos), 1, ptfEntrada);
			}
			
			else
			{
				//Se realiza el corte de control 
				//Pasar los valores de la variables de trabajo a las variables de salida 
				
				strcpy(vtrSalida.Nombre_s,Nombre_t);							
				vtrSalida.CA1_s = CA1_t;
				vtrSalida.CA2_s = CA2_t;
				vtrSalida.CA3_s = CA3_t;
				vtrSalida.Promedio_s = Promedio_t;												
	       
				//Escribir en el archivo de salida 
				
				fwrite(&vtrSalida, sizeof(regSalida), 1, ptfSalida);

				//Re-inicializar las variables de trabajo 
				
				strcpy(Nombre_t,vtrEntrada.Nombre_e);								
				CA1_t = vtrEntrada.CA1_e;
				CA2_t = vtrEntrada.CA2_e;	
				CA3_t = vtrEntrada.CA3_e;	
				Promedio_t = 0;										
	       	
			}//Fin if 
			
		}while(!feof(ptfEntrada));
		
		//Se realiza el ultimo corte de control 
		//Pasar los valores de la variables de trabajo a las variable de salida 
		
		strcpy(vtrSalida.Nombre_s,Nombre_t);							
		vtrSalida.CA1_s = CA1_t;
		vtrSalida.CA2_s = CA2_t;
		vtrSalida.CA3_s = CA3_t;
		vtrSalida.Promedio_s = Promedio_t;											
	       

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
	
	ptfSalida = fopen("c:M4_3_PIA.sal","r");
	system("cls");
	
	if( ptfSalida == NULL )
	{
		printf( "\nEl archivo de entrada NO existe. \n" );
		printf( "\nRevise su proceso nuevamente. \n" );
			
	}//Fin if(ptfSalida==NULL) 
 
	//Poner encabezados 
	
	printf("Nombre				CA1		CA2		CA3		PROM \n");
	Linea=2;
	
	//Leer archivo de salida 
	
	fread(&vtrSalida, sizeof(regSalida), 1, ptfSalida);
	do
	{
		gotoxy( 1, Linea ); 
		printf( "%s", vtrSalida.Nombre_s );
		
		gotoxy( 15, Linea ); 
		printf( "ld",vtrSalida.CA1_s );      
		  
		gotoxy( 25, Linea ); 
		printf( "ld", vtrSalida.CA2_s );
		
		gotoxy( 30, Linea ); 
		printf( "ld", vtrSalida.CA3_s );		
		
		gotoxy( 35, Linea ); 
		printf( "ld", vtrSalida.Promedio_s );			
		
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
	long int auCA1_t[1000];
	long int auCA2_t[1000];	
	long int auCA3_t[1000];	

	int i = 0, Registros;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 	
	   
	ptfEntrada = fopen("c:PROBLEMA.dat","r");

	fread(&vtrEntrada, sizeof(regDatos), 1, ptfEntrada);
	do
	{
		//Pasar de datos de archivo hacia arreglos 
		
		strcpy( auNombre_t[i], vtrEntrada.Nombre_e );				
		auCA1_t[i] = vtrEntrada.CA1_e;
		auCA2_t[i] = vtrEntrada.CA2_e;
		auCA3_t[i] = vtrEntrada.CA3_e;				

		i = i + 1;
		fread(&vtrEntrada, sizeof(regDatos), 1, ptfEntrada);
	
	}while( !feof( ptfEntrada ) );
	
	Registros = i;
	
	//Cerrar el archivo 
	
	fclose( ptfEntrada );
	vORDENAMIENTO (auNombre_t, auCA1_t, auCA2_t, auCA3_t, Registros );
;
		
} //Fin funcion vARCHIVO_HACIA_ARREGLOS 





//------------------------------------------------- vORDENAMIENTO -------------------------------------------------

void vORDENAMIENTO( char auN_t[][LONGITUD_NOMBRE], long int auC1_t[],  long int auC2_t[], long int auC3_t[], int R)
{
	//Declaración de identificadores con alcance de bloque 
	
	int i, j, AuxiliarCA1, AuxiliarCA2, AuxiliarCA3;
	char AuxiliarNombre[LONGITUD_NOMBRE];


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
				
				AuxiliarCA1 = auC1_t[j];
				auC1_t[j] = auC1_t[j+1];
				auC1_t[j+1] = AuxiliarCA1;
				
				AuxiliarCA2 = auC2_t[j];
				auC2_t[j] = auC2_t[j+1];
				auC2_t[j+1] = AuxiliarCA2;
				
				AuxiliarCA3 = auC3_t[j];
				auC3_t[j] = auC3_t[j+1];
				auC3_t[j+1] = AuxiliarCA3;											
                       
			}//Fin if 
			
		}//Fin for j 
		
	}//Fin for i 
	
	vARREGLO_HACIA_ARCHIVO( auN_t, auC1_t, auC2_t, auC3_t, R, vtrEntrada );
	
}//Fin funcion vORDENAMIENTO 





//------------------------------------------------- vARREGLO_HACIA_ARCHIVO -------------------------------------------------

void vARREGLO_HACIA_ARCHIVO( char auN_t[][LONGITUD_NOMBRE], long int auC1_t[],  long int auC2_t[], long int auC3_t[], int R, regDatos vtrEntrada )
{
	//Declaración de identificadores con alcance de bloque 
	FILE *ptfNuevoArchivo;
	int i;

	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador    
	//Abrir archivo en modo escritura 
	
	ptfEntrada = fopen("c:PROBLEMA.dat","w");   
   
	for( i = 0; i < R; i++ )
	{
		//Pasar datos de arreglos al archivo 

		strcpy( vtrEntrada.Nombre_e, auN_t[i] ); 
		vtrEntrada.CA1_e = auC1_t[i];     
		vtrEntrada.CA2_e = auC2_t[i];  
		vtrEntrada.CA3_e = auC3_t[i];  				
   
		fwrite(&vtrEntrada, sizeof(regDatos), 1, ptfEntrada);
		
	}//Fin del for 
	
	fclose( ptfEntrada );
	return;
	
}//Fin funcion vARREGLO_HACIA_ARCHIVO




