// 1952947 - Heidi Pamela Martinez Martinez 

/*Se conoce la cantidad de carros vendidos en una cantidad de meses predeterminado de año 

en curso. Realice el diagrama de flujo en Raptor que genere la siguiente información (Vea el

ejemplo que se anexa) y escriba el código fuente en Lenguaje C. Utilice módulos con paso de

parámetros y arreglos de memoria, y en la codificación utilice variables estructuradas.

a) Haga un módulo que permita capturar y validar la cantidad de meses de los que se conocen

los datos. Capture el dato con el teclado.

b) Haga el módulo que permita capturar y validar la cantidad de vehículos vendidos en cada mes;

almacene los datos en un arreglo de memoria. Capture los datos con el teclado.

c) Haga un módulo que permita calcular el porcentaje mensual y el porcentaje acumulado de

ventas*/

// 1. Biblioteca estándar de C (Archivos incluidos) 


#include <stdio.h> 

#include <windows.h>

// 2. Identificadores constantes con alcance de archivo (Directivas de preprocesador) 

// 3. Identificadores variables con alcance de archivo (variables globales) 

typedef struct{
           float Ventas[20];
		   float VentaAnual;
        } regAuto;

regAuto vtrAuto;        



// 4. Identificadores para funciones definidas por el programador con alcance de archivo (prototipos)

float fCAPTURAR_VENTA(regAuto vtrAuto, int i); 

// 5. Definición de la función principal

main()
{
   //5.1 Declaración de identificadores con alcance de bloque
   	float PorcentajeAcu;
	float PorcentajeMensual;
  	 int i = 1;	
   
   
	int meses;
	do{
		
	
	printf("De cuantos meses desea saber el porcentaje?\n ");
	
	scanf("%d", &meses);//declaracion tipo local
	
	if(meses>=13 || meses <0)
	
	{
		printf("Error cantidad no valida, intente de nuevo con un numero positivo y menor o igual a 12\n");

				
	system("pause");
	
	system("cls");//limpieza cada ciclo	
	}
	}while(meses>=13 || meses <0);

	
	
   // 5.2 Instrucciones que forman el cuerpo o bloque de la función principal   
    
   for( i = 1; i <= meses; i++ )
   {
      vtrAuto.Ventas[i] = fCAPTURAR_VENTA(vtrAuto, i); 
	       	
      vtrAuto.VentaAnual = vtrAuto.VentaAnual + vtrAuto.Ventas[i];
      
      PorcentajeMensual = vtrAuto.Ventas[i]/vtrAuto.VentaAnual * 1000;
      
	PorcentajeAcu = PorcentajeMensual + vtrAuto.Ventas[i] ;
      
   } // fin for 
   
      
	printf("La venta anual es de = %8.2f \n", vtrAuto.VentaAnual);   	   
	printf("El porcentaje de cada mes es de = %8.2f \n", PorcentajeMensual);       
	printf("El porcentaje acumulado por las ventas es de = %8.2f \n", PorcentajeAcu);       
	system("pause");
   
   
} // fin funcion main 






//-------------------------------------------------------------------------------------------



// 6. Definición de las funciones creadas por el programador 



float fCAPTURAR_VENTA(regAuto vtrAuto, int I) 
{
   // 6.1 Declaración de identificadores con alcance de bloque 
   
   	auto float VentaLocal;
   	
	auto char VentaCadena[10];	
	
   //6.2 Instrucciones que forman el cuerpo o bloque de la función definida por el programador
   
    do{
    	
        printf("Ingresa la venta del mes %d \n", I);    	
        
        scanf(" %[^\n]",VentaCadena);
        
		VentaLocal = atof(VentaCadena); // atof convierte el parámetro de cadena a flotante 
		
        if( VentaLocal <= 0 )
        
        {
        	printf("Error. El dato capturado no cumple con los requisitos \n", 160);
        	
        	printf("Favor de capturar un dato num%crico y positivo \n",137);        
				
		} // fin if 
		
	}while( VentaLocal <= 0 );
	
	return( VentaLocal );	
	
	
} // fin funcion fCAPTURAR_VENTA 
