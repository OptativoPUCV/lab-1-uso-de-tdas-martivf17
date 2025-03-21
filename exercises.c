#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();

   int i = 1;
   while(i<= 10){
      int *num = (int*) malloc(sizeof(int));
      if(num == NULL){
         exit(EXIT_FAILURE);
      }
      pushBack(L,num);
      *num = i;
      i++;
   }

   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int suma = 0;
   int *dato = first(L);

   while(dato != NULL){
      suma += *(int*)dato;
      dato = next(L);
   }

   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem)
{
   void *dato = first(L);

   while(dato != NULL)
   {
      if(*(int*)dato == elem)
      {
         popCurrent(L);
         dato = first(L);
      }
      else
      {
         dato = next(L);
      }
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack *auxiliar = create_stack();

   while(top(P1) != NULL){
      void *dato = top(P1);
      push(auxiliar, dato);
      pop(P1);
   }
   while(top(auxiliar) != NULL){
      void *dato = top(auxiliar);
      push(P1,dato);
      push(P2,dato);
      pop(auxiliar);
   }
   free(auxiliar);
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   Stack *P1 = create_stack();

   for (int i=0 ; cadena[i] != '\0' ; i++){
         if(cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{'){
            push(P1, &cadena[i]);
         }
         else if(cadena[i] == ')' || cadena[i] == ']' || cadena[i] == '}'){
            if(top(P1) == NULL) return 0;
            char *open = top(P1);
            char close = cadena[i];

            if(*open == '('){
               if(close != ')') return 0;
            }
            else if(*open == '['){
               if(close != ']') return 0;
            }
            else{
               if(close != '}') return 0;
            }
            pop(P1);
         }
   }
   if(top(P1) != NULL) return 0;
   free(P1);
   return 1;
}

/* FIN DEL CODIGO*/