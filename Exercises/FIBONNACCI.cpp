#include <stdio.h>
#include <stdlib.h>



int serie[100];
int x=0,y=0,i=0,j=0,k=0,elements=0;
float prom=0;

int main(){
do{
printf("programa que calucula una serie de numero (factorial o fibonacci)\n\n");
printf("calcula el promedio de n numeros de la serie\n\n");
printf("elija la serie a calcular y digite el numero de elementos menor que 100\n\n");
printf("1. factorial\n\n");
printf("2. fibonacci\n\n");
printf("3. salir\n\n");
scanf("%d",&x);
//calcula factorial
if (x==1){
printf("ahora el total de elementos del array\n\n");
scanf("%d",&y);
j=1;
for(i=1; i<=y; ++i){
printf("\n");
j=j*i;
serie[i-1]=j;
printf("[%d]",serie[i-1]);
}
printf("cuantos elementos del array quiere calcular, su array tiene %d elementos\n\n",y);
scanf("%d",&elements);
for(i=0; i<=elements; ++i){
k=(serie[i]+k);
}
prom=k/elements;
printf("Promedio de los primeros %d numeros = %f ",elements,prom);
printf("\n\n\n");
}
//calcula fibonacci

if(x==2){
printf("ahora el total de elementos del array\n\n");
scanf("%d",&y);
j=1;
serie[0]=1;
serie[1]=1;
for(i=2; i<y; ++i){
serie[i]=serie[i-1]+serie[i-2];
}
for(i=0; i<y; ++i){
printf("\n");
printf("[%d]",serie[i]);
}
printf("cuantos elementos del array quiere calcular, su array tiene %d elementos\n\n",y);
scanf("%d",&elements);
for(i=0; i<elements; ++i){
k=(serie[i]+k);
}
prom=k/elements;
printf("Promedio de los primeros %d numeros = %f ",elements,prom);
printf("\n\n\n");
}
}
while(x!=3);
}

