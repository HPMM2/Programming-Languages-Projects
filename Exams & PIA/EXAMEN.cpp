

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
#define CUENTA_MINIMA 100
#define CUENTA_MAXIMA 999
#define LONGITUD_CUENTA 3
#define LONGITUD_NOMBRE 40
#define LONGITUD_IMPORTE 15

#define LONGITUD_NUMERO 4
#define LONGITUD_FOLIO 3
#define LONGITUD_EMPLEADO 30
#define LONGITUD_PERIODO 4
#define LONGITUD_SUBTOTAL 8
#define SUBTOTAL_MAXIMO 10000 
#define SEMANAS 52
#define DIAS 7





//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Identificadores variables con alcance de archivo (variables globales)
//Estructura del archivo de entrada
typedef struct
{
	int NEmpleado;
	int Folio;
	char Empleado[LONGITUD_EMPLEADO + 1];
	char Periodo[LONGITUD_PERIODO + 1];
	float Subtotal;

} regEmpleado;	//Nombre del registro de entrada


regEmpleado vtrEntrada;	//Variable tipo registro del archivo de entrada
FILE *ptfEntrada;	   //Punteros al archivo de entrada


//Estructura del archivo de salida
typedef struct
{
	int NEmpleado;
	char Empleado[LONGITUD_EMPLEADO + 1];	 
	float PBruto;
	float IMSS;
	float PTotal;
	int Ventas;
	
} regTotal;		//Nombre del registro de salida

regTotal vtrSalida;	 	 //Variable tipo registro del archivo de salida
FILE *ptfTotal;			//Punteros al archivo de salida





//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Identificadores para funciones definidas por el programador con alcance de archivo (prototipos)

void vCICLO_MENU();
void vINICIAR();
void vALTAS( regEmpleado vtrEntrada );
void vREPORTE( regEmpleado vtrEntrada , regTotal vtrSalida );
void vIMPRIMIR_REPORTE();
int iSELECCIONA_OPCION( int OpcionMenor , int OpcionMayor );
int iCAPTURAR_NUMERO();
int iCAPTURAR_FOLIO();
char ccCAPTURAR_EMPLEADO( char EmpleadoReceptor[] , char EmpleadoLocal[] );
char ccCAPTURAR_PERIODO( char PeriodoReceptor[] , char PeriodoLocal[] );
char ccCAPTURAR_SEMANA( char SemanaReceptor[] , char SemanaLocal[]);
char ccCAPTURAR_DIA( char DiaReceptor[] , char DiaLocal[] );
float fCAPTURAR_SUBTOTAL();
char ccMAYUSCULAS( char Destino[] , char Fuente[] );

regArreglo rORDENAR_REGISTROS( regArreglo vtrArreglo );
regArreglo rREGISTROS_HACIA_ARREGLO( regArreglo vtrLocal );
void vREGISTROS_HACIA_ARCHIVO( regArreglo vtrLocal );





//void vCICLO_MENU();
//void vINICIAR();
//void vALTAS( regCuenta vtrEntrada );
long int liCAPTURAR_CUENTA();
char cCAPTURAR_NOMBRE(char NombreReceptor[], char NombreLocal[]);
float fCAPTURAR_IMPORTE();
void vREPORTE_CORTE_DE_CONTROL( regCuenta vtrEntrada, regTotal vtrSalida);
void vIMPRIME( regTotal vtrSalida);
int iSELECCIONA_OPCION( int OpcionMenor , int OpcionMayor );
void ORDENAR_REGISTROS( regCuenta vtrEntrada );
void vARCHIVO_HACIA_ARREGLOS();
void vORDENAMIENTO( long int auCuenta_t[], char auNombre_t[][LONGITUD_NOMBRE], float auImporte_t[], int Registros );	
void vARREGLO_HACIA_ARCHIVO( long int auC_t[], char auN_t[][LONGITUD_NOMBRE], float auI_t[], int R, regCuenta vtrEntrada );





//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Definición de la función principal
main()
{
	//Declaración de identificadores con alcance de bloque
	//Instrucciones que forman el cuerpo o bloque de la función principal		
	
	vCICLO_MENU();
	
}//Fin de la funcion main




