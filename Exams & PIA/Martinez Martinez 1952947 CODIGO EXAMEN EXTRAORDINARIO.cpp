

//1952947 - Heidi Pamela Martinez Martinez

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





//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Identificadores constantes con alcance de archivo (Directivas de preprocesador)
#define CIERTO 1
#define FALSO 0

#define LONGITUD_NUMERO 3
#define LONGITUD_MATRICULA 9
#define LONGITUD_PERIODO 4
#define LONGITUD_VENTAS 2
#define LONGITUD_DISPONIBLES 2
#define SEMANAS 52
#define LETRASA 3
#define NUMEROSB 99999
#define LETRASC 2
#define DIAS 7






//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Identificadores variables con alcance de archivo (variables globales)
//Estructura del archivo de entrada
typedef struct
{
	int NBus;
	char Matricula[LONGITUD_MATRICULA + 1];
	char Periodo[LONGITUD_PERIODO + 1];
	int Ventas; 
	int Disponibles;

} regRegistro;	//Nombre del registro de entrada


regRegistro vtrEntrada;	//Variable tipo registro del archivo de entrada
FILE *ptfEntrada;	   //Punteros al archivo de entrada


//Estructura del archivo de salida
typedef struct
{
	int NBus;
	char Matricula[LONGITUD_MATRICULA + 1];
	char Periodo[LONGITUD_PERIODO + 1];
	int Disponibles;
	int Ventas;
	float Porcentaje;
	int Total;
	
} regSalida;		//Nombre del registro de salida

regSalida vtrSalida;	 	 //Variable tipo registro del archivo de salida
FILE *ptfSalida;			//Punteros al archivo de salida


//Arreglo
typedef struct 
{	
	int auBus[1000];
	char auMatricula[1000][LONGITUD_MATRICULA + 1];
	char auPeriodo[1000][LONGITUD_PERIODO + 1];
	int auVentas[1000];
	int auDisponibles[1000];
	int Registros;
	
}regArreglos;




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Identificadores para funciones definidas por el programador con alcance de archivo (prototipos)

void vCICLO_MENU();
void vINICIAR();
void vALTAS( regRegistro vtrEntrada );
void vREPORTE_CORTE_DE_CONTROL( regRegistro vtrEntrada , regSalida vtrSalida );
void vIMPRIMIR_REPORTE();
int iSELECCIONA_OPCION( int OpcionMenor , int OpcionMayor );
int iCAPTURAR_BUS();
int iCAPTURAR_DISPONIBLES();
int iCAPTURAR_VENTAS();
char ccCAPTURAR_MATRICULA( char MatriculaReceptor[] , char MatriculaLocal[] );
char ccCAPTURAR_LETRASA( char LetrasAReceptor[] , char LetrasALocal[]);
char ccCAPTURAR_NUMEROSB( char NumerosBReceptor[] , char NumerosBLocal[]);
char ccCAPTURAR_LETRASC( char LetrasCReceptor[] , char LetrasCLocal[]);
char ccCAPTURAR_PERIODO( char PeriodoReceptor[] , char PeriodoLocal[] );
char ccCAPTURAR_SEMANAP( char SemanaReceptor[] , char SemanaLocal[]);
char ccCAPTURAR_DIAP( char DiaReceptor[] , char DiaLocal[] );
char ccMAYUSCULAS( char Destino[] , char Fuente[] );

regArreglos rORDENAR_REGISTROS( regArreglos vtrArreglos );
regArreglos rREGISTROS_HACIA_ARREGLO( regArreglos vtrLocal );
void vREGISTROS_HACIA_ARCHIVO( regArreglos vtrLocal );




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Definición de la función principal
main()
{
	//Declaración de identificadores con alcance de bloque
	//Instrucciones que forman el cuerpo o bloque de la función principal		
	
	vCICLO_MENU();
	
}//Fin de la funcion main




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Definición de las funciones creadas por el programador
void vCICLO_MENU()
{
	int OpcionMenu;
	int OpcionMenor = 1, OpcionMayor = 4;
	
	do
	{
		system("cls");
		
		printf("	MENU PRINCIPAL	\n\n");
		
		printf("\n	1. INICIAR \n");
		printf("\n	2. ALTAS \n");
		printf("\n	3. REPORTE \n");
		printf("\n	4. SALIR \n");
		printf("\n Seleccione una opcion: ");
		
		OpcionMenu = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor );  

		system("cls");
		
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
        	
              printf("\nUsted ha elegido la opcion para salir del Programa... Gracias.. \n");     
			                   		  
              system("pause");
              
              break;
              
        default:
        	
              printf("\n La opcion elegida esta fuera de rango \n");
              
              printf("\n El programa concluira su funcion \n");    
			           
              system("pause");
              
              break;              
              
	 }//Fin  switch
	 
   }while( OpcionMenu >= OpcionMenor && OpcionMenu < OpcionMayor );
   
}//Fin fin funcion vCICLO_MENU




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
int iSELECCIONA_OPCION( int LimiteMenor , int LimiteMayor )
{
   /* 6.1 Declaración de identificadores con alcance de bloque */
   int OpcionSeleccionada;
   char Opcion[2];        
   
   /* 6.2 Instrucciones que forman el cuerpo o bloque de la función definida por el programador */	   
   do{
      scanf( "%s", Opcion );  
      OpcionSeleccionada = atoi( Opcion );
      if( OpcionSeleccionada == FALSO )
      {
          printf("La opcion seleccionada NO ES CORRECTA !!!\n");
          printf("El rango de opciones es de %d a %d, favor de intentar de nuevo \n", LimiteMenor, LimiteMayor );          
      }    
      else
      {
         if( OpcionSeleccionada < LimiteMenor || OpcionSeleccionada > LimiteMayor )
         {
            printf("La opcion seleccionada NO ES CORRECTA !!!\n");
            printf("El rango de opciones es de %d a %d, favor de intentar de nuevo \n", LimiteMenor, LimiteMayor );
         } /* fin if */
      } /* fin if */   
   }while( OpcionSeleccionada < LimiteMenor || OpcionSeleccionada > LimiteMayor );
   return(OpcionSeleccionada);
} /* fin funcion iSELECCIONA_OPCION() */




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
void vINICIAR()	
{
  /* 6.1 Declaración de identificadores con alcance de bloque */
   int OpcionMenor = 1, OpcionMayor = 2;     
   int Opcion;    
   
   /* 6.2 Instrucciones que forman el cuerpo o bloque de la función definida por el programador */	   
   printf( "\n I N I C I A R\n" );
   printf( "\nEsta rutina DESTRUYE el archivo de entrada anterior !!!!\n" );
   printf( "\nDeseas DESTRUIRLO? 1.-SI; 2.-NO : " );
   Opcion = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor );
   if( Opcion == CIERTO )
   {
      ptfEntrada = fopen("c:ExtraOrdinario1952947.dat","r");  /* abrir archivo de entrada */
      if( ptfEntrada == NULL )
      {
	      printf( "No puedo DESTRUIR el archivo porque NO existe \n" );
	      system( "pause" );
       }
       else
       {
	      fclose( ptfEntrada );
          /* borra archivo */
	      remove("c:ExtraOrdinario1952947.dat");
       } /* fin  if(ptfentrada == NULL) */
    } /* fin if(Opcion == CIERTO) */
} /* fin funcion vINICIAR() */




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
void vALTAS( regRegistro vtrEntrada )
{
	int Opcion = 1 , NumeroLocal;
	int OpcionMenor = 1, OpcionMayor = 2, Continuar;
	
	ptfEntrada = fopen( "C:ExtraOrdinario1952947.dat" , "a+");
	
	while(ptfEntrada != NULL)
	{													
		do
		{
		printf("\n	ALTAS	\n\n");
		vtrEntrada.NBus = iCAPTURAR_BUS();
		ccCAPTURAR_MATRICULA( vtrEntrada.Matricula , vtrEntrada.Matricula );
		ccCAPTURAR_PERIODO( vtrEntrada.Periodo , vtrEntrada.Periodo );
		vtrEntrada.Ventas= iCAPTURAR_VENTAS();
		vtrEntrada.Disponibles = iCAPTURAR_DISPONIBLES();
		
		fwrite( &vtrEntrada , sizeof(regRegistro) , 1 , ptfEntrada );
		
		printf("\nSe ha agregado exitosamente!");
		printf("\n\nDesea continuar en ALTAS? (1. SI / 2. NO) ");
        Continuar = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor );	      
      	}while( Continuar == 1 );
}

	fclose(ptfEntrada);
}




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
void vREPORTE_CORTE_DE_CONTROL( regRegistro vtrEntrada , regSalida vtrSalida )
{
	int i = 0;
	
	printf("\n	CORTE DE CONTROL	\n\n\n");
	ptfEntrada = fopen("C:ExtraOrdinario1952947.dat" , "r");
	ptfSalida = fopen("C:ExtraOrdinario1952947.sal" , "w");
	if(ptfEntrada != NULL)
	{
		regArreglos vtrArreglos = rORDENAR_REGISTROS(vtrArreglos);
		
		vtrSalida.NBus = vtrArreglos.auBus[0];
		
		strcpy( vtrSalida.Matricula , vtrArreglos.auMatricula[0] );
		
		strcpy( vtrSalida.Periodo , vtrArreglos.auPeriodo[0] );		
		
		vtrSalida.Ventas = 0;
		
		vtrSalida.Disponibles = 0;
		
		vtrSalida.Porcentaje = 0;
		
		vtrSalida.Total = 0;
		
		printf("Registros: %d" , vtrArreglos.Registros);
		
		while(i < vtrArreglos.Registros)
		{
			if(vtrSalida.NBus == vtrArreglos.auBus[i])
			{
				float Ocupacion = 0;
				if(vtrArreglos.auVentas[i] > 1 || vtrArreglos.auDisponibles[i] > 1)
				{
					Ocupacion = vtrArreglos.auVentas[i] / vtrArreglos.auDisponibles[i] * 100;
				}
			
				vtrSalida.Porcentaje = vtrSalida.Porcentaje + Ocupacion;
				vtrSalida.Porcentaje++;
				i++;
			}
			else
			{
				vtrSalida.Ventas = vtrSalida.Ventas + vtrSalida.Ventas;
				vtrSalida.Disponibles = vtrSalida.Disponibles + vtrSalida.Disponibles;	
				vtrSalida.Total = vtrSalida.Total + vtrSalida.Total;			
				fwrite(&vtrSalida , sizeof(regSalida) , 1 , ptfSalida);
				
				//Datos siguientes
				
				vtrSalida.NBus = vtrArreglos.auBus[i];
				strcpy( vtrSalida.Matricula , vtrArreglos.auMatricula[i] );
				vtrSalida.Porcentaje = 0;
				vtrSalida.Total = 0;
				vtrSalida.Ventas = 0;
				vtrSalida.Disponibles = 0;
			}
		}
		
		vtrSalida.Ventas = vtrSalida.Ventas + vtrSalida.Ventas;				
		vtrSalida.Disponibles = vtrSalida.Disponibles + vtrSalida.Disponibles;	
		vtrSalida.Total = vtrSalida.Total + vtrSalida.Total;		
		fwrite(&vtrSalida , sizeof(regSalida) , 1 , ptfSalida);
		fclose(ptfSalida);
		vIMPRIMIR_REPORTE();
	}
	else
	{
		printf("\n NO se pudo abrir el archivo. Intente nuevamente y revise los datos.");
	}
	fclose(ptfEntrada);
	fclose(ptfSalida);
	printf("\n\n");
	system("pause");
}




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
void vIMPRIMIR_REPORTE()
{
	
	gotoxy(0 , 2);		printf("NUMERO ECONOMICO");
	gotoxy(20 , 2);		printf("MATRICULA");
	gotoxy(55 , 2);		printf("PERIODO");
	gotoxy(70 , 2);		printf("PASAJES VENDIDOS");
	gotoxy(85 , 2);		printf("ASIENTOS DISPONIBLES");
	gotoxy(100 , 2);	printf("PORCENTAJE");
	gotoxy(110 , 2);	printf("TOTAL VIAJES");
	
	ptfSalida = fopen("C:ExtraOrdinario1952947.sal" , "r");
	rewind(ptfSalida);
	fread(&vtrSalida , sizeof(regSalida) , 1 , ptfSalida);
	for(int i = 4 ; !feof(ptfSalida) ; i++)
	{
		gotoxy(0 , i);		printf("%d" , vtrSalida.NBus);
		gotoxy(20 , i);		printf("%s" , vtrSalida.Matricula);
		gotoxy(55 , i);		printf("$%.2f" , vtrSalida.Periodo);
		gotoxy(70 , i);		printf("$%.2f" , vtrSalida.Ventas);
		gotoxy(85 , i);		printf("$%.2f" , vtrSalida.Disponibles);
		gotoxy(100 , i);	printf("%d" , vtrSalida.Porcentaje);
		gotoxy(110 , i);	printf("%d" , vtrSalida.Total);		
		
		fread(&vtrSalida , sizeof(regSalida) , 1 , ptfSalida);
	}
	fclose(ptfSalida);
}




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
int iCAPTURAR_BUS()
{
	int NumEntero;
	char NumCadena[LONGITUD_NUMERO + 1];
	
	printf("\n Capture el numero economico del autobus: \n ");
	do
	{
		strset(NumCadena , ' ' );
		
		scanf("%s" , NumCadena);
		
		NumEntero = atoi(NumCadena);
		
		if(NumEntero == 0 || strlen(NumCadena) != LONGITUD_NUMERO)
		{
			printf( "\n Intente nuevamente con un numero entero de %d digitos: " , LONGITUD_NUMERO);
	    }
	}
	while(NumEntero == 0 || strlen(NumCadena) != LONGITUD_NUMERO);
	return(NumEntero);	
}




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
char ccCAPTURAR_MATRICULA( char MatriculaReceptor[] , char MatriculaLocal[] )
{
	char LetrasA[3] , NumerosB[4], LetrasC[2];
	ccCAPTURAR_LETRASA(LetrasA , LetrasA);
	ccCAPTURAR_NUMEROSB( NumerosB , NumerosB);
	ccCAPTURAR_LETRASC( LetrasC , LetrasC);
	strcpy(MatriculaLocal , LetrasA);
	strcat(MatriculaLocal , "-");
	strcat(MatriculaLocal , NumerosB);
	strcat(MatriculaLocal , "-");
	strcpy(MatriculaLocal , LetrasC);	
	return( MatriculaLocal[LONGITUD_MATRICULA + 1] );
}




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
char ccCAPTURAR_LETRASA( char LetrasAReceptor[] , char LetrasALocal[])
{
	bool Valido;
	
	printf("Capture las primeras 3 letras de la matricula: ");
	do
	{
		Valido = true;
		strset(LetrasALocal , ' ');
		scanf(" %[^\n]" , LetrasALocal);
		if( strlen(LetrasALocal) > (LETRASA + 1) )
		{
			Valido = false;
		}
		else
		{
			for(int i = 0 ; i < strlen(LetrasALocal) ; i++)
			{
				if( !isalpha(LetrasALocal[i]) && !isspace(LetrasALocal[i]) )
				{
					Valido = false;
					break;
				}
			}
		}
		if(Valido == false)
		{
			printf("ERROR. Favor de capturar solo letras y espacios (maximo 4 caracteres): " );
		}
	}
	while(Valido == false);
	
	ccMAYUSCULAS( LetrasALocal , LetrasALocal );
	return( LetrasALocal[LETRASA + 1]  );
}




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
char ccCAPTURAR_NUMEROSB( char NumerosBReceptor[] , char NumerosBLocal[])
{
	int BEntero;
	char BCadena[4];
	
	printf("\n Capture los 4 numeros de la matricula: \n ");
	do
	{
		strset(BCadena , ' ' );
		scanf("%s" , BCadena);
		BEntero = atoi(BCadena);
		if(BEntero < 1 || BEntero > NUMEROSB)
		{
			printf( "\n Intente nuevamente con numeros enteros." );
	    }
	}
	while(BEntero < 1 || BEntero > NUMEROSB);
	return(BCadena[4]);
}




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
char ccCAPTURAR_LETRASC( char LetrasCReceptor[] , char LetrasCLocal[])
{
	bool Valido;
	
	printf("Capture las 2 ultimas letras de la matricula: ");
	do
	{
		Valido = true;
		strset(LetrasCLocal , ' ');
		scanf(" %[^\n]" , LetrasCLocal);
		if( strlen(LetrasCLocal) > (LETRASC + 1) )
		{
			Valido = false;
		}
		else
		{
			for(int i = 0 ; i < strlen(LetrasCLocal) ; i++)
			{
				if( !isalpha(LetrasCLocal[i]) && !isspace(LetrasCLocal[i]) )
				{
					Valido = false;
					break;
				}
			}
		}
		if(Valido == false)
		{
			printf("ERROR. Favor de capturar solo letras y espacios (maximo 4 caracteres): ");
		}
	}
	while(Valido == false);
	
	ccMAYUSCULAS( LetrasCLocal , LetrasCLocal );
	return( LetrasCLocal[LETRASC + 1]  );
}




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
char ccCAPTURAR_PERIODO( char PeriodoReceptor[] , char PeriodoLocal[] )
{
	char Semana[3] , Dia[2];
	ccCAPTURAR_SEMANAP(Semana , Semana);
	ccCAPTURAR_DIAP(Dia , Dia);
	strcpy(PeriodoLocal , Semana);
	strcat(PeriodoLocal , "/");
	strcat(PeriodoLocal , Dia);
	return( PeriodoLocal[LONGITUD_PERIODO + 1] );
}




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
char ccCAPTURAR_SEMANAP( char SemanaReceptor[] , char SemanaLocal[] )
{
	int SemanaEntero;
	char SemanaCadena[3];
	
	printf("\n Capture la semana del periodo: \n ");
	do
	{
		strset(SemanaCadena , ' ' );
		scanf("%s" , SemanaCadena);
		SemanaEntero = atoi(SemanaCadena);
		if(SemanaEntero < 1 || SemanaEntero > SEMANAS)
		{
			printf( "\n Intente nuevamente con numeros enteros entre 1 y 52" );
	    }
	}
	while(SemanaEntero < 1 || SemanaEntero > SEMANAS);
	return(SemanaCadena[3]);
}




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
char ccCAPTURAR_DIAP( char DiaReceptor[] , char DiaLocal[] )
{
	int DiaEntero;
	char DiaCadena[2];
	
	printf("\n Capture el dia del periodo: \n ");
	do
	{
		strset(DiaCadena , ' ' );
		scanf("%s" , DiaCadena);
		DiaEntero = atoi(DiaCadena);
		if(DiaEntero < 1 || DiaEntero > DIAS)
		{
			printf( "\n Intente nuevamente con numeros enteros entre 1 y 7");
	    }
	}
	while(DiaEntero < 1 || DiaEntero > DIAS);
	return(DiaCadena[2]);
}




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
int iCAPTURAR_VENTAS()
{
	int VentaEntero;
	char VentaCadena[LONGITUD_VENTAS + 1];
	
	printf("\n Capture la cantidad de pasajes vendidos: \n ");
	do
	{
		strset(VentaCadena , ' ' );
		
		scanf("%s" , VentaCadena);
		
		VentaEntero = atoi(VentaCadena);
		
		if(VentaEntero == 0 || strlen(VentaCadena) != LONGITUD_VENTAS)
		{
			printf( "\n Intente nuevamente con un numero entero de %d digitos: " , LONGITUD_VENTAS);
	    }
	}
	while(VentaEntero == 0 || strlen(VentaCadena) != LONGITUD_VENTAS);
	return(VentaEntero);	
}




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
int iCAPTURAR_DISPONIBLES()
{
	int DispoEntero;
	char DispoCadena[LONGITUD_DISPONIBLES + 1];
	
	printf("\n Capture la cantidad de asientos disponibles: \n ");
	do
	{
		strset(DispoCadena , ' ' );
		
		scanf("%s" , DispoCadena);
		
		DispoEntero = atoi(DispoCadena);
		
		if(DispoEntero == 0 || strlen(DispoCadena) != LONGITUD_DISPONIBLES)
		{
			printf( "\n Intente nuevamente con un numero entero de %d digitos: " , LONGITUD_DISPONIBLES);
	    }
	}
	while(DispoEntero == 0 || strlen(DispoCadena) != LONGITUD_DISPONIBLES);
	return(DispoEntero);	
}




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
char ccMAYUSCULAS( char Destino[] , char Fuente[] )
{
	int i;
	for(i = 0 ; i < strlen(Fuente) ; i++)
	{
		Destino[i] = toupper( Fuente[i] );
	}
	Destino[i] = '\0';
	return( Destino[ strlen(Fuente) ] );
}




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
regArreglos rORDENAR_REGISTROS( regArreglos vtrArreglos )
{
	int BusAuxiliar , VentasAuxiliar,  DisponiblesAuxiliar;
	char MatriculaAuxiliar[LONGITUD_MATRICULA + 1] , PeriodoAuxiliar[LONGITUD_PERIODO + 1];
	
	vtrArreglos = rREGISTROS_HACIA_ARREGLO( vtrArreglos );
	for(int i = 1 ; i < vtrArreglos.Registros ; i++)
	{
		for(int j = 0 ; j < (vtrArreglos.Registros - i) ; j++)
		{
			if( vtrArreglos.auBus[j] > vtrArreglos.auBus[j + 1] )
			{
				BusAuxiliar = vtrArreglos.auBus[j + 1];
				strcpy( MatriculaAuxiliar , vtrArreglos.auMatricula[j + 1] );
				strcpy( PeriodoAuxiliar , vtrArreglos.auPeriodo[j + 1] );
				VentasAuxiliar = vtrArreglos.auVentas[j + 1];
				DisponiblesAuxiliar = vtrArreglos.auDisponibles[j + 1];
				
				vtrArreglos.auBus[j + 1] = vtrArreglos.auBus[j];
				strcpy( vtrArreglos.auMatricula[j + 1] , vtrArreglos.auMatricula[j] );
				strcpy( vtrArreglos.auPeriodo[j + 1] , vtrArreglos.auPeriodo[j] );
				vtrArreglos.auVentas[j + 1] = vtrArreglos.auVentas[j];
				vtrArreglos.auDisponibles[j + 1] = vtrArreglos.auDisponibles[j];				
				
				vtrArreglos.auBus[j] = BusAuxiliar;
				strcpy( vtrArreglos.auMatricula[j] , MatriculaAuxiliar );
				strcpy( vtrArreglos.auPeriodo[j] , PeriodoAuxiliar );
				vtrArreglos.auVentas[j] = VentasAuxiliar;
				vtrArreglos.auDisponibles[j] = DisponiblesAuxiliar;				
			}
		}
	}

	return(vtrArreglos);
}




//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
regArreglos rREGISTROS_HACIA_ARREGLO( regArreglos vtrLocal )	
{
	vtrLocal.Registros= 0;
	rewind(ptfEntrada);
	fread( &vtrEntrada , sizeof(regRegistro) , 1 , ptfEntrada );
	for(int i = 0 ; !feof(ptfEntrada) ; i++)
	{
		vtrLocal.auBus[i] = vtrEntrada.NBus;
		strcpy( vtrLocal.auMatricula[i] , vtrEntrada.Matricula );
		strcpy( vtrLocal.auPeriodo[i] , vtrEntrada.Periodo );
		vtrLocal.auVentas[i] = vtrEntrada.Ventas;
		vtrLocal.auDisponibles[i] = vtrEntrada.Disponibles;		
		vtrLocal.Registros++;
		
		fread( &vtrEntrada , sizeof(regRegistro) , 1 , ptfEntrada );
	}
	fclose(ptfEntrada);
	return(vtrLocal);
}
