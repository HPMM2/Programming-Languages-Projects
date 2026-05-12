

//Biblioteca estándar de C (Archivos incluidos) 

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Define función gotoxy() para compiladores ANSI C 

void gotoxy(short x, short y) 
{
   COORD pos = {x, y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


// ---------------------------------------------------------------- VARIABLES DEFINIDAS ----------------------------------------------------------------

//Identificadores constantes con alcance de archivo (Directivas de preprocesador)

#define NOMBRE_CLIENTE 25
#define LONG_EMPLEADO_MAX 2
#define LONG_PROVEEDOR_MAX 2
#define LONG_PEDIDO_MAX 2
#define LONG_COMPRA_MAX 2
#define LONG_PRODUCTOS_MAX 3
#define LONG_PRECIO_MAX 10
#define NOMBRE_MINIMO 1
#define NOMBRE_MAXIMO 25
#define MINIMO 0
#define CIERTO 1
#define FALSO 0







// ---------------------------------------------------------------- ESTRUCTURAS ----------------------------------------------------------------

//Identificadores variables con alcance de archivo (variables globales) 

typedef struct {
		char FolioCliente[NOMBRE_CLIENTE];
		long int FolioProveedor;
		long int FolioEmpleado;
		long int FolioPedido;
		long int NumeroCompra;
		long int NumeroProductos;
		long int PrecioProductos;	
		        
	} regNegocio;  // nombre del registro 

regNegocio vtrNegocio;    // variable tipo registro

FILE *ptfProductos2021;   // apuntador al archivo 

typedef struct {
		char auCliente[25][NOMBRE_CLIENTE];
		long int auProveedor[2];
	    long int auEmpleado[2];
	    long int auPedido[2];
		long int auCompra[2];
	    long int auProductos[2];
	    long int auPrecio[10];
        int Registros;
          
	} regArreglo;  // nombre del registro 

regArreglo vtrArreglo;    // variable tipo registro 




//Identificadores para funciones definidas por el programador con alcance de archivo (prototipos)

void vCICLO_MENU();
void vINICIAR();
char ccCAPTURAR_FOLIO_CLIENTE( char FolioReceptor[], char FolioLocal[] );
long int liCAPTURAR_FOLIO_PROVEEDOR( char FolioCliente[] );
long int liCAPTURAR_FOLIO_EMPLEADO( char FolioCliente[] );
long int liCAPTURAR_FOLIO_PEDIDO( char FolioCliente[] );
long int liCAPTURAR_NUMERO_COMPRA( char FolioCliente[] );
long int liCAPTURAR_NUMERO_PRODUCTOS( char FolioCliente[] );
long int liCAPTURAR_PRECIO_PRODUCTOS( char FolioCliente[] );

regNegocio rALTAS( regNegocio vtrNegocio );
regNegocio rBAJAS( regNegocio vtrNegocio );
regNegocio rCAMBIOS( regNegocio vtrNegocio );
void vREPORTE_MONITOR( regNegocio vtrNegocio );
void vREPORTE_ARCHIVO( regNegocio vtrNegocio );


int iABRIR_PARA_LEER();
int iSELECCIONA_OPCION( int OpcionMenor , int OpcionMayor );
//char iVALIDAR_FOLIO( char FolioSinValidar[NOMBRE_CLIENTE] );
int iBUSCAR_FOLIO( char FolioBuscado[NOMBRE_CLIENTE] );
int iBUSCAR_REGISTRO( char FolioBuscado[NOMBRE_CLIENTE] );
void vBORRAR_REGISTRO( char FolioCancelado[NOMBRE_CLIENTE] );
void vCAMBIAR_REGISTRO( regNegocio vtrNegocio, char FolioCambio[NOMBRE_CLIENTE] );
char ccLETRAS_MAYUSCULAS( char Destino[], char Fuente[] );

regArreglo rDATOS_HACIA_ARREGLOS( regArreglo vtrArreglo );
void vORDENAMIENTO_BURBUJA();	
void vARREGLO_HACIA_ARCHIVO( regArreglo vtrEmisor, regNegocio vtrReceptor );












// ---------------------------------------------------------------- MAIN ----------------------------------------------------------------

//Definición de la función principal 

main()
{
   //Declaración de identificadores con alcance de bloque    
   //Instrucciones que forman el cuerpo o bloque de la función principal 
   
	vCICLO_MENU();
    
}//Fin funcion main() 






// ---------------------------------------------------------------- SWITCH ----------------------------------------------------------------

//Definición de las funciones creadas por el programador 

void vCICLO_MENU()
{
	// Declaración de identificadores con alcance de bloque 
	
	int OpcionMenu;
   
	int OpcionMenor = 1, OpcionMayor = 7;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador
	 	   
	do
	{
		system("cls");
        
		printf( "M E N U   P R I N C I P A L \n" );
        
		printf( "\n1.- I N I C I A R \n" );
        
        printf( "\n2.- A L T A S \n" );
        
        printf( "\n3.- B A J A S \n" );
        
        printf( "\n4.- C A M B I O S \n" );
        
        printf( "\n5.- R E P O R T E   E N   M O N I T O R \n" );
        
        printf( "\n6.- R E P O R T E   E N   A R C H I V O \n" );      
		  
        printf( "\n7.- S A L I R \n" );
        
        printf( "\nCual opcion deseas ? : \n" );
        
        OpcionMenu = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor );
        
        switch( OpcionMenu )
        {
	       case 1:
                //Borra el archivo anterior, si se desea
                 
		        vINICIAR();
		         
		        break;
		         
	       case 2:
                //Aagregar registros al archivo 
                 
		        rALTAS( vtrNegocio );
		         
		        break;
		         
	       case 3:
                //Borrar registros del archivo
                 
		        rBAJAS( vtrNegocio );
		         
		        break;
		         
           case 4:
                //Cambiar datos en campos del resgistro
                 
		        rCAMBIOS( vtrNegocio );
		         
		        break;
		         
           case 5:
                //Imprimir reporte 
                 
		        vREPORTE_MONITOR( vtrNegocio ); 
		         
		        break;
		         
           case 6:
                //Imprimir reporte 
                 
		        vREPORTE_ARCHIVO( vtrNegocio );
		         
				printf("Se ha enviado el reporte al archivo: REPORTE_ACTIVIDAD_3.1.DAT \n");
		         
		        printf("Para visualizarlo favor de buscarlo en la carpeta y abrirlo con un editor de textos \n");
				 	
				system("pause");	  
				        
		        break;
		         
           case 7:
           	
                printf("Usted ha elegido la opci%cn para salir del Programa, gracias por usarlo \n",162);    
				                  		  
                system("pause");
                 
                break;
                 
           default:
           	
            	printf("La opcion elegida est%c fuera de rango \n", 160);
				          
                system("pause");
                  
                break;
                  
		}//Fin switch
        
	}while(  OpcionMenu >= OpcionMenor && OpcionMenu < OpcionMayor );
     
 }//Fin funcion vCICLO_MENU() 










// ---------------------------------------------------- iSELECCIONA_OPCION ---------------------------------------------------- 

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
			printf("ERROR. No fue posible completar la accion solicitada, intente nuevamente \n");
          
			printf("El rango de opciones es de %d a %d \n", LimiteMenor, LimiteMayor );          
		}    
		else
		{
		if( OpcionSeleccionada < LimiteMenor || OpcionSeleccionada > LimiteMayor )
		{
			printf("ERROR. No fue posible completar la accion solicitada, intente nuevamente \n");
            
			printf("El rango de opciones es de %d a %d \n", LimiteMenor, LimiteMayor );
            
		}//Fin if 
         
		}//Fin if  
      
	}while( OpcionSeleccionada < LimiteMenor || OpcionSeleccionada > LimiteMayor );
   
   return(OpcionSeleccionada);
   
}//Fin funcion iSELECCIONA_OPCION() 











// ---------------------------------------------------- INICIAR ---------------------------------------------------- 

void vINICIAR()
{
	//Declaración de identificadores con alcance de bloque 
   
	int Opcion;
	int OpcionMenor = 1, OpcionMayor = 2;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 
   	   
	printf( "\nI  N  I  C  I  A  R \n" );
   
	printf( "\nEsta ruta DESTRUYE el archivo de datos: REPORTE_ACTIVIDAD_3.1 \n" );
   
	printf( "\nDeseas DESTRUIRLO?\n1.- SI\n2.- NO\n " );
   
	Opcion = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor );
   
	if( Opcion == CIERTO )
	{
		//Abrir archivo en modo escritura, si ya existe se pierde el anterior
		
		ptfProductos2021 = fopen( "C:ACTIVIDAD_3.1.DAT", "w" );  
		fclose( ptfProductos2021 );     //Cerrar archivo
		
	}//Fin if
    
}//Fin funcion vINICIAR()











// ---------------------------------------------------- ALTAS ---------------------------------------------------- 

//Módulo que permite agregar registros al archivo de datos 

regNegocio rALTAS( regNegocio vtrNegocio )
{
	//Declaración de identificadores con alcance de bloque 
   
	int NoValido, Encontrado; //Encontrado=1 verdadero ; Encontrado=0 falso
	int OpcionMenor = 1, OpcionMayor = 2;   
	int Continuar = 1, Longitud;
	char FolioCapturado[NOMBRE_CLIENTE];
	long int ProveedorCapturado, EmpleadoCapturado, PedidoCapturado, CompraCapturado, ProductosCapturado, PrecioCapturado;


	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 		    
	//Apertura de archivo de datos para actualización en modo agregar y extraer datos 
	//Con modo de apertura a+ si el archivo no existe se crea. El apuntador se coloca al inicio del archivo 
   
	ptfProductos2021 = fopen( "c:ACTIVIDAD_3.1.DAT", "a+" ); 
   
	//Ciclo si el archivo existe
   
	while( ptfProductos2021 != NULL && Continuar == CIERTO )
	{
		do
		{
			printf( "\nA  L  T  A  S \n\n" );
	       
			ccCAPTURAR_FOLIO_CLIENTE( FolioCapturado, FolioCapturado );
	       
			//NoValido = iVALIDAR_FOLIO( FolioCapturado );
	       
		}while( NoValido == CIERTO );
       
		//Busqueda secuencial de un registro 
       
		Encontrado = iBUSCAR_FOLIO( FolioCapturado );  //Llamada a la funcion buscar 
       
		if( Encontrado )
		{
			printf( "\nN O M B R E   E X I S T E N T E \n" );
			
			printf( "\nNo se puede asignar el folio #%s porque ya existe en el archivo de datos \n", FolioCapturado );
			
			system( "pause" );
       }
       
		else
		{
			//Matricula no existe, entonces se puede dar de alta 
	      
			strcpy( vtrNegocio.FolioCliente, FolioCapturado );
          
			vtrNegocio.FolioProveedor = liCAPTURAR_FOLIO_PROVEEDOR(vtrNegocio.FolioCliente); 
		  
			vtrNegocio.FolioEmpleado = liCAPTURAR_FOLIO_EMPLEADO(vtrNegocio.FolioCliente); 	
          
	        vtrNegocio.FolioPedido = liCAPTURAR_FOLIO_PEDIDO(vtrNegocio.FolioCliente);  
			  
	        vtrNegocio.NumeroCompra = liCAPTURAR_NUMERO_COMPRA(vtrNegocio.FolioCliente); 
			  
	    	vtrNegocio.NumeroProductos = liCAPTURAR_NUMERO_PRODUCTOS(vtrNegocio.FolioCliente); 
	
	        vtrNegocio.PrecioProductos = liCAPTURAR_PRECIO_PRODUCTOS(vtrNegocio.FolioCliente); 		  		  		  		            
		  
		  
			//Cambiar letras a mayusculas
		   
			ccLETRAS_MAYUSCULAS( vtrNegocio.FolioCliente, FolioCapturado );
 			 			    
   
			fseek( ptfProductos2021, 1L, 2 );  //Poner el puntero al final del archivo
			fwrite( &vtrNegocio, sizeof( regNegocio ), 1, ptfProductos2021 ); //Escribir en el archivo
	      
		}//Fin if Encontrado 
       
		printf( "\n%cDeseas continuar en ALTAS?\n1.- SI\n2.- NO\n ",168 );
		Continuar = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor );       
		strset( FolioCapturado, ' ' );   //Borrar basura 

	}//Fin while ptfProductos2021 != NULL && Continuar == CIERTO 
    
	if( ptfProductos2021 == NULL )
	{
		printf(" ERROR ");
		
 		printf(" el archivo de datos no se pudo abrir\n");
 		
		printf(" favor de revisar si existe la carpeta en la memoria externa \n");   
			
		system("pause");
	} 
	else 
	{
		//Cerrar archivo 
       
		fclose( ptfProductos2021 );   
	    	   	
	}//Fin if ptfAlumno == NULL
   
	return( vtrNegocio );
   
}//Fin de la funcion rALTAS() 











// ---------------------------------------------------- BAJAS ---------------------------------------------------- 

//Módulo que permite borrar registros del archivo de datos  

regNegocio rBAJAS( regNegocio vtrNegocio )
{
	//Declaración de identificadores con alcance de bloque 

	int Continuar, BorrarRegistro, ArchivoAbierto = 1, NoValido; 
	int Encontrado; //Encontrado=1 verdadero ; Encontrado = 0 falso
	int OpcionMenor = 1, OpcionMayor = 2;
	char FolioCapturado[NOMBRE_CLIENTE]; 

	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 
   	
	ArchivoAbierto = iABRIR_PARA_LEER();
   
	while( ArchivoAbierto )
	{
		do
		{ 
			printf( "\nB A J A S \n\n" );
			ccCAPTURAR_FOLIO_CLIENTE( FolioCapturado, FolioCapturado );
			//NoValido = iVALIDAR_FOLIO( FolioCapturado );
			
		}while( NoValido == CIERTO );
       
		//Llamada a la funcion iBUSCAR_REGISTRO 
       
		Encontrado = iBUSCAR_REGISTRO( FolioCapturado );  
		
		if( Encontrado )
		{
			//El folio buscado si existe    
          
			printf( "\nDeseas dar de BAJA este registro?\n1.- SI\n2.- NO\n " );
			BorrarRegistro = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor );
				      
			if( BorrarRegistro == CIERTO )
			{
				vBORRAR_REGISTRO( FolioCapturado );
				
			}//Fin BorrarRegistro == CIERTO 
		}
		else
		{
			//El folio buscado no existe 
			
			printf( "N O M B R E   I N E X I S T E N T E \n" );
			
			system( "pause" );
			
		}//Fin if Encontrado 
		
		printf( "\nDeseas continuar en BAJAS?\n1.- SI\n2.- NO\n " );
		Continuar = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor );  
		          
		if( Continuar != CIERTO )
		{
			//Cerrar archivo 
			
			fclose( ptfProductos2021 );  
			return( vtrNegocio );
			
		}//Fin if  
		
	}//Fin while 
	
}//Fin funcion rBAJAS 











// ---------------------------------------------------- CAMBIOS ---------------------------------------------------- 

//Módulo que permite modificar datos en campos de los registros del archivo  

regNegocio rCAMBIOS( regNegocio vtrNegocio )
{
	//Declaración de identificadores con alcance de bloque 
   
	int CambiarRegistro, ArchivoAbierto = 1, NoValido;
	int Continuar, Encontrado;
	int OpcionMenor = 1, OpcionMayor = 2;
	char FolioCapturado[NOMBRE_CLIENTE];
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 
   		   
	ArchivoAbierto = iABRIR_PARA_LEER();   
   
	while( ArchivoAbierto )
	{
 		do
		{  
			printf( "\nC A M B I O S \n\n" );
			ccCAPTURAR_FOLIO_CLIENTE( FolioCapturado, FolioCapturado );
			//NoValido = iVALIDAR_FOLIO( FolioCapturado );
			
		}while( NoValido == CIERTO );
		
		//Llamada a la funcion iBUSCAR_REGISTRO       
       
		Encontrado = iBUSCAR_REGISTRO( FolioCapturado ); 
	    
		//Busqueda secuencial de un registro 
       
		if( Encontrado )
		{
			//El folio buscado si existe  
			
			printf( "\nDeseas CAMBIAR este registro?\n1.- SI\n2.- NO\n " );
			CambiarRegistro = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor ); 
			
			if( CambiarRegistro == CIERTO )
			{
				vCAMBIAR_REGISTRO( vtrNegocio, FolioCapturado );
	          
			}//Fin if op==1 
		}
		else
		{
			//El folio buscado no existe 
	      
			printf( "N O M B R E   I N E X I S T E N T E \n" );
			
			system( "pause" );
	      
		}//Fin if Encontrado 
        
		printf( "\nDeseas continuar en CAMBIOS?\n1.- SI\n2.- NO\n " );
		Continuar = iSELECCIONA_OPCION( OpcionMenor, OpcionMayor );
		
		if( Continuar != CIERTO )
		{
        	
			//Cerrar archivo 
			
			fclose( ptfProductos2021 );  
			return( vtrNegocio );
			
		}//Fin if   
		
	}//Fin while 
	
}//Fin función CAMBIOS() 












// ---------------------------------------------------------------- ccCAPTURAR_FOLIO_CLIENTE ----------------------------------------------------------------


// Módulo que permite capturar el nombre del cliente y validar si el dato cumple con ciertos requisitos  

char ccCAPTURAR_FOLIO_CLIENTE( char FolioReceptor[], char FolioLocal[] )
{
	//Declaración de identificadores con alcance de bloque 
   
	int Longitud, i, NoCumple;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 
			   
	do
	{
		NoCumple = FALSO;      
		printf( "Captura el nombre del cliente : "  );
		scanf( " %[^\n]", FolioLocal );
		Longitud = strlen( FolioLocal );   
   
		for( i = 0; i < Longitud; i++ )
		{
			if( !isalpha(FolioLocal[i]) && !isspace(FolioLocal[i]) || Longitud > NOMBRE_CLIENTE-1 )
			{
				NoCumple = CIERTO;
				
			}//Fin if 
			
		}//Fin for 
       
			if( NoCumple == CIERTO)
			{
 				printf( "ERROR...!!!     El dato capturado no cumple con los requisitos \n", NOMBRE_CLIENTE-1 ); 
				      	
				printf( "Favor de capturar %cnicamente entre 1 y 25 letras y espacios en blanco, m%cximo %d   !!! \n",163, 160, NOMBRE_CLIENTE-1 );
				
				printf( "Favor de intentar de nuevo\n" );
				
				strset(FolioLocal, ' ');
				
				system( "pause" );
				
			}//Fin if    
			
	}while(NoCumple == CIERTO);
	
return( FolioLocal[NOMBRE_CLIENTE] );

}//Fin funcion ccCAPTURAR_FOLIO_CLIENTE









/*


// ---------------------------------------------------------------- VALIDACION ----------------------------------------------------------------

//Validar 

char iVALIDAR_FOLIO( char FolioSinValidar[NOMBRE_CLIENTE] )
{
	//Declaración de identificadores con alcance de bloque
	
	int Longitud, i, NoCumple;
	char FolioLetrasSinValidar;
   
   //Instrucciones que forman el cuerpo o bloque de la función definida por el programador
   		   
	NoCumple = FALSO;
	Longitud = strlen( FolioSinValidar ); //Permite saber cuántos caracteres tiene la variable FolioSinValidar

	
   
	if( Longitud != NOMBRE_CLIENTE-1 || FolioLetrasSinValidar < NOMBRE_MINIMO || FolioLetrasSinValidar > NOMBRE_MAXIMO || NoCumple == CIERTO)
	{
		printf( "El dato capturado no cumple con los requisitos solicitados. Intente de nuevo \n" );
        
		printf( "El folio debe ser con caracteres con menos de 50 d%cgitos \n", 161 );
		
		NoCumple = CIERTO;
		
		system( "pause" );
		
	}//Fin if
	
	return( NoCumple );
	
}//Fin función iVALIDAR_FOLIO



*/








// ---------------------------------------------------------------- liCAPTURAR_FOLIO_PROVEEDOR ----------------------------------------------------------------

// Módulo que permite capturar el Numero del Proveedor y validar si el dato cumple con ciertos requisitos   

long int liCAPTURAR_FOLIO_PROVEEDOR( char FolioProveedor[] )
{
	//Declaración de identificadores con alcance de bloque 
    
	int Longitud, i, NoCumple;
	long int ProveedorNumerico;
	char ProveedorNoNumerico[2];
   
   //Instrucciones que forman el cuerpo o bloque de la función definida por el programador 
    
   do
   {
		NoCumple = FALSO;      
		printf( "Captura el folio del proveedor (2 digitos) : ", FolioProveedor );
		scanf( " %[^\n]", ProveedorNoNumerico );
		Longitud = strlen( ProveedorNoNumerico );   
		ProveedorNumerico = atoi(ProveedorNoNumerico);
		
		for( i = 0; i < Longitud; i++ )
		{
			if( !isdigit(ProveedorNoNumerico[i]) || ProveedorNoNumerico <= 0 || Longitud < LONG_PROVEEDOR_MAX || Longitud > LONG_PROVEEDOR_MAX  )
			{
				NoCumple = CIERTO;
			}//Fin if 
         
		}//Fin for 
		
		if( NoCumple == CIERTO)
		{
			printf( "El dato capturado no cumple con los requisitos solicitados. Intente de nuevo \n" );
			
			printf( "Favor de capturar un valor entero y positivo sin puntos ni comas, m%cximo 2 digitos \n",160 );
			
			strset(ProveedorNoNumerico, ' ');
			
			system( "pause" );
         
		}//Fin if    
		 
	}while(NoCumple == CIERTO);
	
return( ProveedorNumerico );

}//Fin funcion liCAPTURAR_FOLIO_PROVEEDOR












// ---------------------------------------------------------------- liCAPTURAR_FOLIO_EMPLEADO ----------------------------------------------------------------


// Módulo que permite capturar el ID del empleado que atendio al cliente y validar si el dato cumple con ciertos requisitos 

long int liCAPTURAR_FOLIO_EMPLEADO( char FolioEmpleado[] )
{
	//Declaración de identificadores con alcance de bloque 
    
   int Longitud, i, NoCumple;
   long int EmpleadoNumerico;
   char EmpleadoNoNumerico[5];
   
   //Instrucciones que forman el cuerpo o bloque de la función definida por el programador 
    
   do
   {
		NoCumple = FALSO;
			       
		printf( "Captura el numero ID del empleado que le atendio (2 digitos) : ",  FolioEmpleado );
	      
		scanf( " %[^\n]", EmpleadoNoNumerico );

		Longitud = strlen( EmpleadoNoNumerico );   
		
		EmpleadoNumerico = atoi(EmpleadoNoNumerico);
		
		
		for( i = 0; i < Longitud; i++ )
		{
			if( !isdigit(EmpleadoNoNumerico[i]) || EmpleadoNoNumerico <= 0 || Longitud < LONG_EMPLEADO_MAX || Longitud > LONG_EMPLEADO_MAX )
			{
				NoCumple = CIERTO;
			}//Fin if  
			
		}//Fin for 
            
		if( NoCumple == CIERTO)
		{
			printf( "El dato capturado no cumple con los requisitos solicitados. Intente de nuevo \n" );
         
			printf( "Favor de capturar un valor entero y positivo sin puntos ni comas, m%cximo 2 digitos \n",160 );
         
			strset(EmpleadoNoNumerico, ' ');
         
			system( "pause" );  
			   
		}//Fin if     
		
	}while(NoCumple == CIERTO);
	
return( EmpleadoNumerico );

}//Fin funcion liCAPTURAR_FOLIO_EMPLEADO












// ---------------------------------------------------------------- liCAPTURAR_FOLIO_PEDIDO ----------------------------------------------------------------


// Módulo que permite capturar el numero del pedido y validar si el dato cumple con ciertos requisitos 

long int liCAPTURAR_FOLIO_PEDIDO( char FolioPedido[] )
{
	//Declaración de identificadores con alcance de bloque 
    
	int Longitud, i, NoCumple, Encontrado;
	long int PedidoNumerico;
	char PedidoNoNumerico[2];
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 
    
	do
	{
		NoCumple = FALSO;      
		printf( "Captura el numero del pedido (2 digitos) : ", FolioPedido );
		scanf( " %[^\n]", PedidoNoNumerico );
		Longitud = strlen( PedidoNoNumerico );   
		PedidoNumerico = atoi(PedidoNoNumerico);
		

		for( i = 0; i < Longitud; i++ )
		{
			if( !isdigit(PedidoNoNumerico[i]) || PedidoNoNumerico <= 0 || Longitud < LONG_PEDIDO_MAX || Longitud > LONG_PEDIDO_MAX )
			{
				NoCumple = CIERTO;
			}//Fin if 
			
		}//Fin for 

		if( NoCumple == CIERTO)
		{
			printf( "El dato capturado no cumple con los requisitos solicitados. Intente de nuevo \n" );
			
			printf( "Favor de capturar un valor entero y positivo sin puntos ni comas, m%cximo 2 digitos \n",160 );
			
			strset(PedidoNoNumerico, ' ');
			
			system( "pause" );
			
		}//Fin if

	}while(NoCumple == CIERTO);
	
return( PedidoNumerico );

}//Fin funcion liCAPTURAR_FOLIO_PEDIDO












// ---------------------------------------------------------------- liCAPTURAR_NUMERO_COMPRA ----------------------------------------------------------------


// Módulo que permite capturar el numero de compra y validar si el dato cumple con ciertos requisitos 

long int liCAPTURAR_NUMERO_COMPRA( char NumeroCompra[] )
{
	//Declaración de identificadores con alcance de bloque 
    
	int Longitud, i, NoCumple, Encontrado;
	long int CompraNumerico;
	char CompraNoNumerico[2];
   
   	do
	{
		NoCumple = FALSO;      
		printf( "Captura el numero de la compra (2 digitos) : ", NumeroCompra );
		scanf( " %[^\n]", CompraNoNumerico );
		Longitud = strlen( CompraNoNumerico );   
		CompraNumerico = atoi(CompraNoNumerico);
		


		for( i = 0; i < Longitud; i++ )
		{
			if( !isdigit(CompraNoNumerico[i]) || CompraNoNumerico <= 0 || Longitud < LONG_COMPRA_MAX || Longitud > LONG_COMPRA_MAX  )
			{
				NoCumple = CIERTO;
			}//Fin if  
			
		}//Fin for 
       
		if( NoCumple == CIERTO)
		{
			printf( "El dato capturado no cumple con los requisitos solicitados. Intente de nuevo \n" );
			
			printf( "Favor de capturar un valor entero y positivo sin puntos ni comas, m%cximo 2 digitos \n",160 );
			
			strset(CompraNoNumerico, ' ');
			
			system( "pause" );  
			
		}//Fin if     	
	}while(NoCumple == CIERTO);
   
return( CompraNumerico );

}//Fin funcion liCAPTURAR_NUMERO_COMPRA












// ---------------------------------------------------------------- liCAPTURAR_NUMERO_PRODUCTOS ----------------------------------------------------------------


// Módulo que permite capturar el numero total de los productos pedidos de la compra total y validar si el dato cumple con ciertos requisitos 

long int liCAPTURAR_NUMERO_PRODUCTOS( char NumeroProductos[] )
{
	//Declaración de identificadores con alcance de bloque 
    
	int Longitud, i, NoCumple;
	long int ProductosNumerico;
	char ProductosNoNumerico[3];
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 
    
	do
	{
		NoCumple = FALSO;      
		printf( "Captura el numero total de productos pedidos en la compra realizada (maximo 3 digitos) : ", NumeroProductos );
		scanf( " %[^\n]", ProductosNoNumerico );
		Longitud = strlen( ProductosNoNumerico );   
		ProductosNumerico = atoi(ProductosNoNumerico);
		
		for( i = 0; i < Longitud; i++ )
		{
			if( !isdigit(ProductosNoNumerico[i]) || ProductosNoNumerico <= 0 || Longitud > LONG_PRODUCTOS_MAX  )
			{
				NoCumple = CIERTO;
			}//Fin if  
			
		}//Fin for 
       
		if( NoCumple == CIERTO)
		{
			printf( "El dato capturado no cumple con los requisitos solicitados. Intente de nuevo \n" );
			
			printf( "Favor de capturar un valor entero y positivo sin puntos ni comas, m%cximo 3 digitos \n",160 );
			
			strset(ProductosNoNumerico, ' ');
			
			system( "pause" );
         
 		}//Fin if
		  
	}while(NoCumple == CIERTO);
   
return( ProductosNumerico );

}//Fin funcion liCAPTURAR_NUMERO_PRODUCTOS











// ---------------------------------------------------------------- liCAPTURAR_PRECIO_PRODUCTOS ----------------------------------------------------------------


// Módulo que permite capturar el precio total de los productos de la factura y validar si el dato cumple con ciertos requisitos 

long int liCAPTURAR_PRECIO_PRODUCTOS( char PrecioProductos[] )
{
	//Declaración de identificadores con alcance de bloque 
    
	int Longitud, i, NoCumple;
	long int PrecioNumerico;
	char PrecioNoNumerico[10];
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 
    
	do
	{
		NoCumple = FALSO;      
		printf( "Captura el precio total por los productos (maximo 10 digitos) : ", PrecioProductos );
		scanf( " %[^\n]", PrecioNoNumerico );
		Longitud = strlen( PrecioNoNumerico );   
		PrecioNumerico = atoi(PrecioNoNumerico);
		
		for( i = 0; i < Longitud; i++ )
		{
			if( !isdigit(PrecioNoNumerico[i]) || PrecioNoNumerico <= 0  || Longitud > LONG_PRECIO_MAX  )
			{
			NoCumple = CIERTO;
			}//Fin if 
         
		}//Fin for 
       
		if( NoCumple == CIERTO)
		{
			printf( "El dato capturado no cumple con los requisitos solicitados. Intente de nuevo \n" );
			
			printf( "Favor de capturar un valor entero y positivo sin puntos ni comas, m%cximo 10 digitos \n",160 );
			
			strset(PrecioNoNumerico, ' ');
			
			system( "pause" );
         
		}//Fin if     
		
	}while(NoCumple == CIERTO);
   
return( PrecioNumerico );

}//Fin funcion liCAPTURAR_PRECIO_PRODUCTOS











// ---------------------------------------------------------------- iBUSCAR_FOLIO ----------------------------------------------------------------

//Módulo que busca el folio en el archivo 
//Si el folio no existe se regresa un cero, si existe se regresa un uno 

int iBUSCAR_FOLIO( char FolioBuscado[NOMBRE_CLIENTE] )
{
	//Declaración de identificadores con alcance de bloque 
	int Busqueda;
    
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 		    
	//Busqueda secuencial de un registro    
	
	Busqueda = FALSO;
	rewind( ptfProductos2021 ); //Poner puntero al principio del archivo 
	
	do
	{
		fread(&vtrNegocio, sizeof( regNegocio ), 1, ptfProductos2021 ); //Leer archivo 
		
		if( ! strcmp( vtrNegocio.FolioCliente, FolioBuscado ) )
		{
			Busqueda = CIERTO;     //Si lo encontró se asigna 1 a buscado 
			
			break;
			
		}//Fin if 
		
	}while( ! feof( ptfProductos2021 ) );  //Se repite hasta fin de archivo 
	
	return( Busqueda );
	
}//Fin funcion iBUSCAR_FOLIO 






// ---------------------------------------------------------------- iBUSCAR_REGISTRO ----------------------------------------------------------------

//Módulo que busca el folio en los registros en el archivo, si lo encuentra lo imprime en el monitor 
//Si el folio no existe se regresa un cero, si existe se regresa un uno 

int iBUSCAR_REGISTRO( char FolioBuscado[NOMBRE_CLIENTE] )
{
	//Declaración de identificadores con alcance de bloque 
   
	int Busqueda;
    
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 	
	//Busqueda secuencial de un registro 
   
	Busqueda = FALSO;
	rewind( ptfProductos2021 ); //Poner puntero al principio del archivo 
	
	do
	{
		fread(&vtrNegocio, sizeof( regNegocio ), 1, ptfProductos2021 ); //Leer archivo 
		
		if( ! strcmp( vtrNegocio.FolioCliente, FolioBuscado ) )
		{
			Busqueda = CIERTO;  //Si lo encontró se asigna 1 a Busqueda 
			printf("EL REGISTRO FUE ENCONTRADO EN EL ARCHIVO. \n");    	
			printf( "Nombre del Cliente            : %s\n", vtrNegocio.FolioCliente );
			printf( "Folio del proveedor           : %ld\n", vtrNegocio.FolioProveedor );
			printf( "ID del empleado               : %ld\n", vtrNegocio.FolioEmpleado );	 
			printf( "Numero del pedido             : %ld\n", vtrNegocio.FolioPedido );
			printf( "Orden de la compra            : %ld\n", vtrNegocio.NumeroCompra );
			printf( "Numeros de productos pedidos  : %ld\n", vtrNegocio.NumeroProductos );
			printf( "Precio total de los productos : %ld\n", vtrNegocio.PrecioProductos );
		  		  		  		  		  		       
			break; //Se suspende la búsqueda porque ya lo encontró 
			
		}//Fin if 
       
	}while( !feof( ptfProductos2021 ) );  //Se repite hasta fin de archivo 
   
	return( Busqueda );
   
}//Fin iBUSCAR_REGISTRO 











// ---------------------------------------------------------------- vBORRAR_REGISTRO ----------------------------------------------------------------

// Módulo que borra físicamente un registro del archivo 

void vBORRAR_REGISTRO( char FolioCancelado[NOMBRE_CLIENTE] )
{
	//Declaración de identificadores con alcance de bloque 
	
	FILE *ptfNuevo;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 	
	//Copiado secuencial de registros un archivo a otro 
	//Baja fisica de un registro   
   
	ptfNuevo = fopen( "c:REPORTE_ACTIVIDAD_3.1.NEW", "w" ); //Abrir archivo nuevo 
   
	rewind( ptfProductos2021 );  //Poner apuntador al principio del archivo viejo    
	fread(&vtrNegocio, sizeof( regNegocio ), 1, ptfProductos2021 ); //Leer registro
    
	do
	{
		if( strcmp( vtrNegocio.FolioCliente, FolioCancelado ) )
		{
			fwrite(&vtrNegocio, sizeof( regNegocio ), 1, ptfNuevo );	 
			     
		}//Fin if 
		
		fread(&vtrNegocio, sizeof( regNegocio ), 1, ptfProductos2021 ); //Leer archivo 
		
	}while( ! feof( ptfProductos2021 ) );  //Se repite hasta fin de archivo 
	
	fclose( ptfNuevo );
	fclose( ptfProductos2021 );
	
	//Borrar archivo anterior 
   
	remove( "c:ACTIVIDAD_3.1.DAT" );
   
	// cambiar nombre a archivo actualizado 
   
	rename( "c:ACTIVIDAD_3.1.NEW", "c:ACTIVIDAD_3.1.DAT");
   
	// abrir archivo en modo lectura 
   
	ptfProductos2021 = fopen( "c:ACTIVIDAD_3.1.DAT", "r" );  
   
}//Fin funcion vBORRAR_REGISTRO 











// ---------------------------------------------------------------- vCAMBIAR_REGISTRO ----------------------------------------------------------------
 
void vCAMBIAR_REGISTRO( regNegocio vtrNegocio, char FolioCambio[NOMBRE_CLIENTE] )
{
	//Declaración de identificadores con alcance de bloque 
   
	long int FolioProveedor;
	long int FolioEmpleado;
	long int FolioPedido;
	long int NumeroCompra;
	long int NumeroProductos;
	long int PrecioProductos;
 
	int Op, Longitud, i;
	char Opc;
	FILE *ptfNuevo;
      
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 	   
	//Copiado secuencial de registros de un archivo a otro 
	//Baja fisica de un registro 
	//Se inicia el proceso de pasar todos los registros a otro archivo 
   
	rewind( ptfProductos2021 );  //Poner puntero al principio del archivo 
   
	ptfNuevo = fopen( "c:REPORTE_ACTIVIDAD_3.1.NEW", "w" );  //Abrir archivo nuevo 
	fread(&vtrNegocio, sizeof( regNegocio ), 1, ptfProductos2021 ); //Leer registro 
	do
	{
		if( strcmp( vtrNegocio.FolioCliente, FolioCambio ) )
		{
			fwrite( &vtrNegocio, sizeof(regNegocio), 1, ptfNuevo );
		}
		else
		{
			vtrNegocio.FolioProveedor = liCAPTURAR_FOLIO_PROVEEDOR(vtrNegocio.FolioCliente); 
		  
			vtrNegocio.FolioEmpleado = liCAPTURAR_FOLIO_EMPLEADO(vtrNegocio.FolioCliente); 	
          
			vtrNegocio.FolioPedido = liCAPTURAR_FOLIO_PEDIDO(vtrNegocio.FolioCliente); 
		  
			vtrNegocio.NumeroCompra = liCAPTURAR_NUMERO_COMPRA(vtrNegocio.FolioCliente); 
		  
			vtrNegocio.NumeroProductos = liCAPTURAR_NUMERO_PRODUCTOS(vtrNegocio.FolioCliente); 

			vtrNegocio.PrecioProductos = liCAPTURAR_PRECIO_PRODUCTOS(vtrNegocio.FolioCliente); 		  		  		  		            
		  
	   
			//Escribir cambio 
		
			fwrite( &vtrNegocio, sizeof(regNegocio), 1, ptfNuevo );
			
		}//Fin if 
		
		fread(&vtrNegocio, sizeof( regNegocio ), 1, ptfProductos2021); //Leer archivo 
		
	}while( ! feof ( ptfProductos2021 ) );  //Se repite hasta fin de archivo 
	
	//Cerrar archivos 
	
	fclose( ptfNuevo );
	fclose( ptfProductos2021 );
	
	//Borrar archivo anterior
	 
	remove( "c:ACTIVIDAD_3.1.DAT" );
	
	//Cambiar nombre a archivo actualizado 
	
	rename( "ACTIVIDAD_3.1.NEW", "c:ACTIVIDAD_3.1.DAT");
	
	//Abrir archivo en modo lectura 
	
	ptfProductos2021 = fopen( "c:ACTIVIDAD_3.1.DAT", "r" );  
	
} //Fin funcion vCAMBIAR_REGISTRO 











// ---------------------------------------------------------------- iABRIR_PARA_LEER ----------------------------------------------------------------
 
//Módulo que abre el archivo para lectura 
//Si el archivo no pudo abrirse se regresa un cero, si pudo abrirse se regresa un uno 

int iABRIR_PARA_LEER()
{
	//Declaración de identificadores con alcance de bloque 
   
	int Abrir = CIERTO; 
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 		   
	//Abrir archivo en modo lectura
   
	ptfProductos2021 = fopen( "c:ACTIVIDAD_3.1.DAT", "r" );  
	if( ptfProductos2021 == NULL)
	{
		printf( "\n\n NO SE PUEDE ABRIR EL ARCHIVO PORQUE NO EXISTE \n\n\n" );
		Abrir = FALSO;
		
	}//Fin if	   
	   
	//Parámetro de salida vale CERO si no se pudo abrir archivo, vale UNO si se pudo abrir archivo 
   
	return( Abrir );
   
}//Fin funcion iABRIR_PARA_LEER 










// ---------------------------------------------------------------- vREPORTE_MONITOR ----------------------------------------------------------------
 
//Módulo que imprime en el monitor un reporte del contenido del archivo 

void vREPORTE_MONITOR( regNegocio vtrLocal )
{
	//Declaración de identificadores con alcance de bloque 
   
	int Linea, ArchivoAbierto = 1;
	int Registros;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 
   	   
	vORDENAMIENTO_BURBUJA();    
   
	ArchivoAbierto = iABRIR_PARA_LEER();
	system("cls");
   
	if( ArchivoAbierto == 1 )
	{   
		Linea = 1;
		   
		//Imprime encabezado 
	    
		gotoxy( 1, Linea ); printf("Cliente");
		gotoxy( 15, Linea ); printf("Proveedor");
		gotoxy( 26, Linea ); printf("ID Empleado");	
		gotoxy( 40, Linea ); printf("Pedido");
		gotoxy( 48, Linea ); printf("Orden");
		gotoxy( 55, Linea ); printf("Productos");
		gotoxy( 67, Linea ); printf("TOTAL");									       
		Linea = Linea + 1;    
	    printf("\n");    
		fread(&vtrLocal, sizeof( regNegocio ), 1, ptfProductos2021 ); //Leer archivo      
		Registros = 0;
		
		do
		{			     	
			//Imprime detalle de registros              
			
			gotoxy( 1, Linea ); printf( "%s", vtrLocal.FolioCliente );
			gotoxy( 18, Linea ); printf( "%ld", vtrLocal.FolioProveedor );
			gotoxy( 29, Linea ); printf( "%ld", vtrLocal.FolioEmpleado );
			gotoxy( 42, Linea ); printf( "%ld", vtrLocal.FolioPedido );
			gotoxy( 50, Linea ); printf( "%ld", vtrLocal.NumeroCompra );
			gotoxy( 57, Linea ); printf( "%ld", vtrLocal.NumeroProductos );
			gotoxy( 68, Linea ); printf( "%ld", vtrLocal.PrecioProductos );
			Linea = Linea + 1;
			fread(&vtrLocal, sizeof( regNegocio ), 1, ptfProductos2021 ); //Leer archivo       
			Registros = Registros + 1;
			
		}while( !feof( ptfProductos2021 ) );
        

		
		system( "pause" );
		fclose( ptfProductos2021 );
		
	}//Fin if 
	
}//Fin funcion vREPORTE_MONITOR 










// ---------------------------------------------------------------- vREPORTE_ARCHIVO ----------------------------------------------------------------
 
// Módulo que imprime el reporte en un archivo 

void vREPORTE_ARCHIVO( regNegocio vtrLocal )
{
	//Declaración de identificadores con alcance de bloque
    
	int Linea, ArchivoAbierto = 1;
	FILE *ptfReporte2021;

	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 
   		
	ptfReporte2021 = fopen( "c:ACTIVIDAD_3.1.DAT", "w" );     

	ArchivoAbierto = iABRIR_PARA_LEER();   
	if( ArchivoAbierto == 1 )
	{   
		//Imprime encabezado 
      
		fprintf(ptfReporte2021,"Folio \tACTIVIDAD 3.1 \tFACTURACION \n");
	        
		fread(&vtrLocal, sizeof( regNegocio ), 1, ptfProductos2021 ); //Leer archivo       
		do
		{			  	
			//Imprime detalle de registros   
           
			fprintf(ptfReporte2021, "%s \t%ld \t%ld \t%ld \t%ld \t%ld \t%ld \t%ld \n", vtrLocal.FolioCliente, vtrLocal.FolioProveedor, vtrLocal.FolioEmpleado, vtrLocal.FolioPedido, vtrLocal.NumeroCompra, vtrLocal.NumeroProductos, vtrLocal.PrecioProductos );		                        
			fread(&vtrLocal, sizeof( regNegocio ), 1, ptfProductos2021 ); //Leer archivo 
			    
		}while( !feof( ptfProductos2021 ) );
		       
		fclose( ptfProductos2021 );
		fclose( ptfReporte2021 );    
		    
	}//Fin if 
   
}//Fin funcion vREPORTE_ARCHIVO 










// ---------------------------------------------------------------- ccLETRAS_MAYUSCULAS ----------------------------------------------------------------
 
//Módulo que convierte a letras mayúsculas

char ccLETRAS_MAYUSCULAS( char Destino[], char Fuente[] )
{
	//Declaración de identificadores con alcance de bloque 
   
	int Longitud, i;   
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador
    		   
	Longitud = strlen( Fuente );
	
	for( i=0; i < Longitud; i++ )
	{
		Destino[i] = toupper( Fuente[i] );
		
	}//Fin for 
	
	Destino[i]='\0';
	return(Destino[Longitud]);
	
}//Fin funcion ccLETRAS_MAYUSCULAS 











// ---------------------------------------------------------------- vORDENAMIENTO_BURBUJA ----------------------------------------------------------------

void vORDENAMIENTO_BURBUJA()
{
	//Declaración de identificadores con alcance de bloque 
   
	char AuxiliarCliente[NOMBRE_CLIENTE];
	long int AuxiliarProveedor;
	long int AuxiliarEmpleado;
	long int AuxiliarPedido;
	long int AuxiliarCompra;
	long int AuxiliarProductos;
	long int AuxiliarPrecio;

	int i, j;   

	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 
   	   
	vtrArreglo = rDATOS_HACIA_ARREGLOS(vtrArreglo);  
   
	//ORDENAMIENTO, método burbuja
	
	for ( i = 1; i < vtrArreglo.Registros; i++)
	{
		for ( j = 0; j < vtrArreglo.Registros - i; j++)
		{
			if ( atoi( vtrArreglo.auCliente[j]) >= atoi( vtrArreglo.auCliente[j+1]) )
			{            
	            strcpy(AuxiliarCliente, vtrArreglo.auCliente[j]);
	            strcpy(vtrArreglo.auCliente[j], vtrArreglo.auCliente[j+1]);
	            strcpy(vtrArreglo.auCliente[j+1], AuxiliarCliente);

	            AuxiliarProveedor = vtrArreglo.auProveedor[j];
	            vtrArreglo.auProveedor[j] = vtrArreglo.auProveedor[j+1];
	            vtrArreglo.auProveedor[j+1] = AuxiliarProveedor;  
	            
	            AuxiliarEmpleado = vtrArreglo.auEmpleado[j];
	            vtrArreglo.auEmpleado[j] = vtrArreglo.auEmpleado[j+1];
	            vtrArreglo.auEmpleado[j+1] = AuxiliarEmpleado;  
				
	            AuxiliarPedido = vtrArreglo.auPedido[j];
	            vtrArreglo.auPedido[j] = vtrArreglo.auPedido[j+1];
	            vtrArreglo.auPedido[j+1] = AuxiliarPedido;
	            
	            AuxiliarCompra = vtrArreglo.auCompra[j];
	            vtrArreglo.auCompra[j] = vtrArreglo.auCompra[j+1];
	            vtrArreglo.auCompra[j+1] = AuxiliarCompra;
				
	            AuxiliarProductos = vtrArreglo.auProductos[j];
	            vtrArreglo.auProductos[j] = vtrArreglo.auProductos[j+1];
	            vtrArreglo.auProductos[j+1] = AuxiliarProductos;
				
	            AuxiliarPrecio = vtrArreglo.auPrecio[j];
	            vtrArreglo.auPrecio[j] = vtrArreglo.auPrecio[j+1];
	            vtrArreglo.auPrecio[j+1] = AuxiliarPrecio;															          

			}//Fin if 
			
		}//Fin for j 
		
	}//Fin for i 
	
	vARREGLO_HACIA_ARCHIVO(vtrArreglo, vtrNegocio);
	   
}//Fin funcion vORDENAMIENTO 











// ---------------------------------------------------------------- rDATOS_HACIA_ARREGLOS ----------------------------------------------------------------

regArreglo rDATOS_HACIA_ARREGLOS( regArreglo vtrLocal )
{
	//Declaración de identificadores con alcance de bloque 
	
	int i = 0;

	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 
		
	ptfProductos2021 = fopen( "c:ACTIVIDAD_3.1.DAT", "r" );  

	fread(&vtrNegocio, sizeof( regNegocio ), 1, ptfProductos2021 ); //Leer archivo 
	      
	do
	{
		//Pasar de datos de archivo hacia arreglos 
		
		strcpy( vtrLocal.auCliente[i], vtrNegocio.FolioCliente );
        vtrLocal.auProveedor[i] = vtrNegocio.FolioProveedor;
		vtrLocal.auEmpleado[i] = vtrNegocio.FolioEmpleado;
		vtrLocal.auPedido[i] = vtrNegocio.FolioPedido;
		vtrLocal.auCompra[i] = vtrNegocio.NumeroCompra;
		vtrLocal.auProductos[i] = vtrNegocio.NumeroProductos;		
		vtrLocal.auPrecio[i] = vtrNegocio.PrecioProductos;

		i = i + 1;
		fread(&vtrNegocio, sizeof( regNegocio ), 1, ptfProductos2021 ); //Leer archivo
		
	}while( !feof( ptfProductos2021 ) );
	
	vtrLocal.Registros = i;
	
	//Cerrar el archivo 
	
	fclose( ptfProductos2021 );
	return(vtrLocal);	
	
}//Fin funcion iDATOS_HACIA_ARREGLOS 











// ---------------------------------------------------------------- vARREGLO_HACIA_ARCHIVO ----------------------------------------------------------------

void vARREGLO_HACIA_ARCHIVO( regArreglo vtrEmisor, regNegocio vtrReceptor )
{
	//Declaración de identificadores con alcance de bloque 
	
	FILE *ptfNuevoArchivo;
	int i;
   
	//Instrucciones que forman el cuerpo o bloque de la función definida por el programador 		   
	//Abrir archivo en modo escritura 
	
	ptfNuevoArchivo = fopen("c:ACTIVIDAD_3.1.DAT","w");   
   
	for( i = 0; i < vtrEmisor.Registros; i++ )
	{
		//Pasar datos de arreglos al archivo 
		
		strcpy( vtrReceptor.FolioCliente, vtrEmisor.auCliente[i] );              
	    vtrReceptor.FolioProveedor = vtrEmisor.auProveedor[i];
		vtrReceptor.FolioEmpleado = vtrEmisor.auEmpleado[i];
		vtrReceptor.FolioPedido = vtrEmisor.auPedido[i];
		vtrReceptor.NumeroCompra = vtrEmisor.auCompra[i];
		vtrReceptor.NumeroProductos = vtrEmisor.auProductos[i];
		vtrReceptor.PrecioProductos = vtrEmisor.auPrecio[i]; 	   	   	   	   	   	         

       
		fwrite(&vtrReceptor, sizeof(regNegocio), 1, ptfNuevoArchivo);
		
	}//Fin del for 
	
	fclose( ptfNuevoArchivo );
 	return;
 	
}//Fin funcion vARREGLO_HACIA_ARCHIVO 

