
/* 004 A2021 CLASE ORDINARIA LENGUAJES DE PROGRAMACION Y LAB */

/* Nombre: Martinez Martinez Heidi Pamela */

/* Matricula: 1952947 */

/* Semestre Agosto 2021 - Diciembre 2021 */ 

/* Actividad 1.3 - Diagrama y Código Básico */

//librerias
#include<stdio.h>
#include<windows.h>
#include<math.h>

int menu();
int suma();
int resta();
int producto();
int division();
int potencia();
int raiz();
int volver();

float a,b,c; //declaracion de variables tipo global

main()
{//inicio del main

system("cls");//limpieza cada ciclo

menu();
volver();
return 0;
}//fin del main



//----------funcion menu-------------
menu()
{
	int op;//declaracion tipo local

	do{	
	printf("Programa que mediante un Men%c indique que operacion fundamental desea hacer\n\n",163);
	printf("Men%c principal\n\n 1 Suma\n 2 Resta\n 3 Producto\n 4 Divisi%cn\n 5 Potencia\n 6 Ra%cz\n ",163, 162, 161);
	scanf("%d", &op);
	if(op<1|| op>6)
	{
		printf("Error rango fuera de 1-6, intente de nuevo");

				
	system("pause");
	system("cls");//limpieza cada ciclo
	
	}
	}while(op<1|| op>6);



switch(op)//inicio del switch
{
	case 1:
		suma();
	break;
	
	case 2:
		resta();
	break;
	
	case 3:
		producto();
	break;
	
	case 4:
		division();
	break;
	
	case 5:
		potencia();
	break;
	
	case 6:
		raiz();
	break;
}//fin del switch

}



//-----------funcion suma---------
suma()
{
	printf("Dame el primer valor a sumar ");
	scanf("%f", &a);
	printf("Dame el segundo valor a sumar ");
	scanf("%f", &b);
	
	c=a+b;

	printf("La suma de %.1f y %.1f es: %.1f\n", a, b, c);
}



//-----------funcion resta---------
resta()
{
	printf("Dame el primer valor a restar ");
	scanf("%f", &a);
	printf("Dame el segundo valor a restar ");
	scanf("%f", &b);
	
	c=a-b;

	
	printf("La resta de %.1f y %.1f es: %.1f\n", a, b, c);
}



//-----------funcion producto---------
producto()
{
	printf("Dame el primer valor a multiplicar ");
	scanf("%f", &a);
	printf("Dame el segundo valor a multiplicar ");
	scanf("%f", &b);
	
	c=a*b;

	
	printf("La multiplicaci%cn de %.1f y %.1f es: %.1f\n", 162, a, b, c);
}



//-----------funcion division---------
division()
{
	printf("Dame el primer valor a dividir ");
	scanf("%f", &a);
	printf("Dame el segundo valor a dividir ");
	scanf("%f", &b);
	
	c=a/b;

	{
	if(b==0)
		do{
		printf("No se puede dividir entre cero, ingrese otro n%cmero ", 163);
		printf("Dame el segundo valor a dividir ");	
		scanf("%f", &b);
		
		c=a/b;
		}
		while (b<=1);
	
		else(b<=1);	
	printf("La divisi%cn de %.1f entre %.1f es: %.1f\n", 162, a, b, c);
	}
}

	

//-----------funcion potencia----------
potencia()
{
	printf("Dame el valor que desea ");
	scanf("%f", &a);
	printf("Dame el valor que sera la potencia ");
	scanf("%f", &b);
	
	c=pow(a,b);

	
	printf("La potencia de %.1f a la %.1f potencia es: %.1f\n", a, b, c);
}

	

//-----------funcion raiz----------
raiz()
{
	printf("Dame el valor que desea ");
	scanf("%f", &a);
	
	c=sqrt(a);

	
	{
	if(a<=0)
		do{
		printf("No se puede sacar ra%cz cuadrada de un n%cmero negativo, ingrese otro numero ", 161, 163);
		scanf("%f", &a);
		c=sqrt(a);
		}
		while (a<=0);
		
	else(a<=0);	
		printf("La ra%cz cuadrada de %.1f es: %.1f\n", 161, a, c);
	}
}

volver()
{
	system("pause");
	system("cls");//limpieza cada ciclo
	
	int res;//declaracion tipo local
	
	do{
		printf("\n¿Quieres volver a empezar?\n 1 - SI\n 2 - NO\n");
		scanf("%d",&res);	
	
	if (res<1|| res>2)
	{
		printf("Error rango fuera de 1-2, intente de nuevo");

				
	system("pause");
	system("cls");//limpieza cada ciclo
	}
	}while(res<1|| res>2);	
	
	if (res==1)
	{
		return main();
	}
	else 
	{
		return 0;
	}
}
	
	
	



