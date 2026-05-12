/* 004 A2021 CLASE ORDINARIA LENGUAJES DE PROGRAMACION Y LAB */

/* Nombre: Martinez Martinez Heidi Pamela */

/* Matricula: 1952947 */

/* Semestre Agosto 2021 - Diciembre 2021 */ 

/* Actividad 2.1 - Codificación de Programas Funcionalizados. */

//librerias

#include<stdio.h>

#include<windows.h>

#include<math.h>


int salario1, salario2, Mensualidad;



main()

{//inicio del main

system("cls");//limpieza cada ciclo








//------------------ MODULO ASIGNAR_VARIABLE_INDEPENDIENTE1 -------------


	salario1=5000;
/*Cuando un modulo tiene un parametro de salida,

debo asegurarme que esa variable obtenga

un valor dentro del modulo.

El valor almacenado en Dato regresa a main y se almacenara en la variable salario1 */







//------------------ MODULO ASIGNAR_VARIABLE_INDEPENDIENTE2 ---------


	do{
		
		printf("Ingrese el segundo salario del trabajador\n");
		
		scanf("%d", &salario2);
		
	if(salario2<=0)
	
	{
		
		printf("ERROR. Ingrese un valor nuumerico superior a 1\n");

				
	system("pause");
	
	system("cls");//limpieza cada ciclo
	
	}
	
	}while(salario2<=0);

/*Cuando un modulo tiene un parametro de salida,

debo asegurarme que esa variable obtenga

un valor dentro del modulo.

El valor almacenado en Dato regresa a main y se almacenara en la variable salario1*/




//------------------ MODULO CALCULAR_VARIABLE_DEPENDIENTE ---------


/* La variable Valor1 recibira el dato almacenado en la variable salario1

La variable Valor2 recibira el dato almacenado en la variable salario2*/



	Mensualidad = salario1 + salario2;




/*Cuando un modulo tiene un parametro de salida,

debo asegurarme que esa varaible obtenga

un valor dentro del modulo.

El valor almacenado en Valor3  regresa a main y se almacenara en la variable Mensualidad */




//------------------ MODULO IMPRIMIR_RESULTADOS ---------


/* Dato1 recibira el valor de la variable salario1

Dato2 recibira el valor de la variable salario2

Dato3 recibira el valor de la variable Mensualidad */


	printf("El valor del salario 1 fijo es de %d ", salario1, " pesos mexicanos.\n");
	
	printf("\nEl valor del salario 2 es de %d ", salario2, " pesos mexicanos.\n");
	
	printf("\nEntonces la mensualidad del trabajador es de %d ", Mensualidad, " pesos mexicanos este mes.\n");

	
}













	
