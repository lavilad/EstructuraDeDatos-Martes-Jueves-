//Emiliano Galaviz
include <stdio.h>
include <stdlib.h>

//Funcion para saber el padre de un nodo del arbol
Node* searchFather(Node* root, int key){
  //verifica si el arbol tiene datos
  if(root == NULL || root->key == key){
    return NULL;
  }
  //verifica si tiene mas de un nodo
  if(root->left && root->left->key == key){
    return root;
  }
  //verifica si tiene mas de un nodo
  if(root->right && root->right->key == key){
    return root;
  }
  //usa recursividad para encontrar el nodo, si esta a la izquierda
  if(key < root->key){
    return searchFather(root->left, key);
  }
  //usa recursividad para encontrar el nodo, si esta a la derecha
  if(key > root->key){
    return searchFather(root->right, key);
  }
}
