//Emiliano Galaviz y Tenoch Moreno
include <stdio.h>
include <stdlib.h>

//Funcion para saber el padre de un nodo del arbol
void searchFather(Node* root, int key){
    //verifica si el arbol tiene datos
    if(root == NULL || root->key == key){
      printf("No se encontró el nodo o es la raíz del árbol.\n");
        return;
    }
    //verifica si tiene mas de un nodo
    if(root->left && root->left->key == key){
      printf("El padre de %d es %d.\n", key, root->key);
      return;
    }
    //verifica si tiene mas de un nodo
    if(root->right && root->right->key == key){
      printf("El padre de %d es %d.\n", key, root->key);
      return;
    }
    //usa recursividad para encontrar el nodo, si esta a la izquierda
    if(key < root->key){
      searchFather(root->left, key);
      return;
    }
    //usa recursividad para encontrar el nodo, si esta a la derecha
    if(key > root->key){
      searchFather(root->right, key);
      return;
    } 
  }
