#include <stdio.h>
#include <stdlib.h>


//Función para contar el numero de nodos en el árbol. Esta funcion te devuelve un entero con el número de nodos de un arbol
int NumNodes(Node* root, int count) {
  //Count vale 0 por lo que si esta vacio, te devolvera 0. Si no lo esta, sumara 1 a la cuenta y llamara a la funcion con el nodo izquierdo y derecho para que haga la misma evluacion de manera similar a la funcion que te imprime el arbol.
  if (root != NULL) {
    count++;
    count=NumNodes(root->left, count);
    count=NumNodes(root->right, count); 
  }
  return count;
}  

