/*Enrique Rodríguez Vázquez 
  Funcion imprimir el arbol   */
#include <stdio.h>

// Función para imprimir el árbol 
void printTree(Node* root, int nivel) {
    if (root == NULL) return;

    // Incrementa el nivel para el siguiente nodo
    nivel += 5;

    // Imprime el subárbol derecho primero
    printTree(root->right, nivel);

    // Imprime el nodo actual
    printf("\n");
    for (int i = 5; i < nivel; i++) printf(" ");
    printf("%d\n", root->key);

    // Imprime el subárbol izquierdo
    printTree(root->left, nivel);
}

