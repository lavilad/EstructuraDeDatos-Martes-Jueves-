#include <stdio.h>

typedef struct Node{
  int key;
  struct Node *left;
  struct Node *right;  
}Node;

Node *verificarNodoVacio(Node *nodo){
  if(nodo == NULL){
    printf("El nodo esta vacio\n");
    return NULL;
  }
  return NULL;
}
