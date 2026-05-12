
#include<iostream>
#include <windows.h>
#include<stdio.h>


using namespace std;

int main() 
{

   int num, aux;
   int comparaciones = 0;
   int intercambios = 0;
   int* arreglo;
   cout << "Ingrese el limite de numeros del ordenamiento : \n ";
   cin >> num;
   arreglo = new int[num];


   for(int x = 0; x < num; x++) {
      cout << "Ingresa el numero " << x << " de la serie : \n ";
      cin >> arreglo[x];
      cout << endl;
   }
	system("cls");
	cout << "\nNUMEROS INGRESADOS \n" << endl;

   for(int y = 0; y < num; y++) {
      cout <<  " " << arreglo[y] << endl;
   }

   for(int z = 1; z < num; ++z) {
      for(int v = 0; v < (num - z); v++) {
         comparaciones++;
         if(arreglo[v] > arreglo[v+1]){
            aux = arreglo[v];
            arreglo[v] = arreglo[v + 1];
            arreglo[v + 1] = aux;
            intercambios++;
         }
      }
    }

   cout << "\nORDENAMIENTO BURBUJA \n" << endl;

   for(int w = 0; w < num; w++) {
      cout << " "  << arreglo[w] << endl;
   }


  
   delete[] arreglo;
   return 0;
}

