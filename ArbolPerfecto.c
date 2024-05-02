#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Función para calcular la altura de un árbol
int alturaArbol(struct Node* nodo) {
    if (nodo == NULL) return 0;
    else {
        int alturaIzquierda = alturaArbol(nodo->left);
        int alturaDerecha = alturaArbol(nodo->right);

        if (alturaIzquierda > alturaDerecha) return alturaIzquierda + 1;
        else return alturaDerecha + 1;
    }
}

//Árbol perfecto//
// Función para verificar si un árbol es perfecto
bool esArbolPerfecto(struct Node* nodo) {
    // Si el árbol está vacío, es perfecto
    if (nodo == NULL){
  printf("\n\nEl árbol es perfecto\n\n");
      return false;
    }
    // Se calcula la altura de ambos subárboles
    int alturaIzquierda = alturaArbol(nodo->left);
    int alturaDerecha = alturaArbol(nodo->right);

    // Si la altura de ambos subárboles es la misma, y ambos subárboles son perfectos, entonces el árbol es perfecto
    if (alturaIzquierda == alturaDerecha && esArbolPerfecto(nodo->right) && esArbolPerfecto(nodo->right)){
      printf("\n\nEl árbol es perfecto\n\n");
      return true;
    }

    // Si no cumple las condiciones anteriores, no es perfecto
  else{
  printf("\n\nEl árbol no es perfecto\n\n");
    return false;
}
}