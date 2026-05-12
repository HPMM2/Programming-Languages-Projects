

/*
Una maestra conoce los nombres y las estaturas de sus alumnos al principio y al final del año escolar
 
Haga el diagrama de flujo y el código que permita conocer el porcentaje de crecimiento de cada uno de ellos

Utilice programación por módulos con paso de parámetros y arreglos de memoria unidimensionales.
 
Capture los datos conocidos con el teclado y validelos

Use variables estructuradas en el código

*/

/* 1. Biblioteca estándar de C (Archivos incluidos) */

#include <stdio.h>

#include <windows.h>   
 
#include <string.h> 

#include <stdlib.h>

#include<locale.h>

#include<math.h>

/* 2. Identificadores constantes con alcance de archivo (Directivas de preprocesador) */

/* 3. Identificadores variables con alcance de archivo (variables globales) */

typedef struct{
	
	int iEstAlumFinal;
	
	int iEstAlumInicial;
	
	char Nombre[45];
	
	float Porc;
	
		
}estAlumno;

estAlumno vtrAlumno;

/* 4. Identificadores para funciones definidas por el programador con alcance de archivo (prototipos) */

int iCAPTURA_ESTATURA_FINAL();

int iCAPTURA_ESTATURA_INICIAL();

void ccCAPTURAR_NOMBRE(char NombreReceptor[45]);

float fCAPTURAR_VENTA(regNegocio vtrNegocio, int i); 


/* 5. Definición de la función principal */

main()
{
	float alum;
	
	printf("De cuantos alumnos desea conocer el porcentaje?\n ");
	
	scanf("%f", &alum);//declaracion tipo local
	
	if(alum<=0)
	
	{
		printf("Error cantidad no valida, intente de nuevo con un numero positivo\n");

				
	system("pause");
	
	system("cls");//limpieza cada ciclo	
	}while(alum>0);
	
   /* 5.1 Declaración de identificadores con alcance de bloque */    
   
   int i = 1;	
   
   /* 5.2 Instrucciones que forman el cuerpo o bloque de la función principal */   
   
   for( i = 0; i>=alum ; i++ )
   {
    	vtrAlumno.iEstAlumFinal[i] = iCAPTURA_ESTATURA_FINAL(vtrAlumno, i); 
    	vtrAlumno.iEstAlumInicial[i] = iCAPTURA_ESTATURA_INICIAL(vtrAlumno, i);
    	ccCAPTURAR_NOMBRE(vtrAlumno.Nombre);
    	
      vtrNegocio.VentaAnual = vtrNegocio.VentaAnual + vtrNegocio.Ventas[i];
   } /* fin for */
   
	printf( "La estatura final del alumno es %d\n", vtrAlumno.iEstAlumFinal);
	printf( "La estatura inicial del alumno es %d\n", vtrAlumno.iEstAlumInicial);
	printf( "El nombre del estudiante es %s\n", vtrAlumno.Nombre);
		
		 	        
   system("pause");
   
   
   		

	


	


   
   
   
} /* fin funcion main */
for(i=0;i>=alum;i++)
{//inicio del for
	
	i=1;
	char nom[20];
	printf("Dame el nombre del alumno %d ", i);
	scanf("%s", &nom);
	
	do
	{
		printf("Dame la primera calificacion ");
		scanf("%f", &C1);
		if(C1<0 || C1>100)
		{
			printf("Error calificacion no valida\n");
			
				
	system("pause");
		}
	}while(C1<0 || C1>100);	

		do
	{
		printf("Dame la segunda calificacion ");
		scanf("%f", &C2);
		if(C2<0 || C2>100)
		{
			printf("Error calificacion no valida\n");
			
				
	system("pause");
		}
	}while(C2<0 || C2>100);	
	
		do
	{
		printf("Dame la tercera calificacion ");
		scanf("%f", &C3);
		if(C3<0 || C3>100)
		{
			printf("Error calificacion no valida\n");
			
				
	system("pause");
		}
	}while(C3<0 || C3>100);	
	
	
	
	prom=(C1+C2+C3)/3;
	if(prom>=70)
	{//inicio del if
		printf("Tu promedio es de %d por lo tanto aprobaste\n", prom);
		numapro = numapro+1;
	}
	else
	{
		printf("Tu promedio es de %d por lo tanto reprobaste\n", prom);
		numrepro = numrepro+1;
		
		int op;//declaracion tipo local
	


main() 
{
	

	
	
   /* 5.1 Declaración de identificadores con alcance de bloque */
   
   /* 5.2 Instrucciones que forman el cuerpo o bloque de la función principal */
   

			
} /* fin función main */






/* -------------------------------------------------------------------------------------------------------------------- */





/* 6. Definición de las funciones creadas por el programador */

int iCAPTURA_ESTATURA_FINAL()
{
   /* 6.1 Declaración de identificadores con alcance de bloque */
   
   
    int FestLocal;
    
    char FestCadena[3];
    
   /* 6.2 Instrucciones que forman el cuerpo o bloque de la función definida por el programador */ 
      
   do{
       printf("Captura la estatura final \n");  
       
       scanf(" %[^\n]", FestCadena);
       
       FestLocal = atoi( FestCadena );	/* atoi convierte el parámetro de cadena a entero */
       
       if( FestLocal <= 0 )
       {
       	   printf("ERROR...!!!     El dato capturado no cumple con los requisitos \n");
       	   
           printf("Favor de capturar un dato num%crico positivo y en centimetros. Ej. 170 en lugar de 1.70 \n", 130);        	
		}
	}while( FestLocal <= 0 );
	
	return(FestLocal);	
	
} /* fin iCAPTURA_ESTATURA_FINAL() */






/* -------------------------------------------------------------------------------------------------------------------- */




int iCAPTURA_ESTATURA_INICIAL()
{
	
   /* 6.1 Declaración de identificadores con alcance de bloque */
   
   
    int IestLocal;
    
    char IestCadena[3];
    
   /* 6.2 Instrucciones que forman el cuerpo o bloque de la función definida por el programador */ 
      
   do{
       printf("Captura la estatura inicial \n");  
       
       scanf(" %[^\n]", IestCadena);
       
       IestLocal = atoi( IestCadena );	/* atoi convierte el parámetro de cadena a entero */
       
       if( IestLocal <= 0 )
       {
       	   printf("ERROR...!!!     El dato capturado no cumple con los requisitos \n");
       	   
           printf("Favor de capturar un dato num%crico positivo y en centimetros. Ej. 170 en lugar de 1.70 \n", 130);        	
		}
	}while( IestLocal <= 0 );
	return(IestLocal);	
	
} /* fin iCAPTURA_ESTATURA_INICIAL() */






/* -------------------------------------------------------------------------------------------------------------------- */





void ccCAPTURAR_NOMBRE(char NombreReceptor[45])
{
	
	
   /* 6.1 Declaración de identificadores con alcance de bloque */
   
	char NombreLocal[45];   
	
	
	int i, EsLetra, Longitud;
	
	
   /* 6.2 Instrucciones que forman el cuerpo o bloque de la función definida por el programador */		
   
   /* fflush(stdin) permite limpiar el buffer de entrada */
   
	fflush(stdin); 

   do{
   	
      EsLetra = 1;  
	   	
      /* gets permite capturar un dato cadena de caracteres con el teclado */
      
	  printf("Captura el NOMBRE DEL ESTUDIANTE \n");
	  
	  gets(NombreLocal);

      Longitud = strlen( NombreLocal ); /* permite saber cuántos caracteres tiene la variable MatriculaLocal */

      /* ciclo for permite detectar sin algún carácter de la variable MatriculaLocal no es un número arábigo */
      for( i = 0; i < Longitud; i++ )
      {
         if( ! isalpha( NombreLocal[i]) && ! isspace( NombreLocal[i] ) ) /* si no es alfabetico y no es espacio en blanco */
         {
	       EsLetra = 0;
         }  /* fin if */      
      } /* fin for */

      if( EsLetra == 0)
      {
         printf( "ERROR...!!!     El dato capturado no cumple con los requisitos \n" );
         
         printf("favor de capturar un dato alfab%ctico \n", 130);  
         
		 strset(NombreLocal,' ');      	
      } /* fin if */      
   }while( EsLetra == 0 );

	strcpy(NombreReceptor,NombreLocal);



	return;
	


	
} /* fin ccCAPTURAR_NOMBRE */



