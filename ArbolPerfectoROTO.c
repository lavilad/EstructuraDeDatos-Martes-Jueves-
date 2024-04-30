#include <stdio.h>
#include <stdlib.h>

// Función para ver si es un árbol perfecto
int perfect(Node* root) {
  //regresa si el árbol está vacío
  if (root == NULL){
    return 1;
  }
  // crear una queue vacía y poner en queue el nodo raíz
  list<Node*> queue;
  queue.push_back(root);

  // puntero para almacenar el nodo actual
  Node* root = NULL;

  // bandera para marcar el final de los nodos completos
  int flag = 0;

  // bucle hasta que la queue esté vacía
  while (queue.size())
  {
      // quitar la queue del nodo frontal
      root = queue.front();
      queue.pop_front();

      // si hemos encontrado un nodo no lleno antes y el nodo actual
      // no es una hoja, un árbol no puede estar completo
      if (flag && (root->left || root->right)) {
          return 0;
      }

      // si el hijo izquierdo está vacío y el hijo derecho existe,
      // un árbol no puede estar completo
      if (root->left == NULL && root->right) {
          return 0;
      }
     // si existe el hijo izquierdo, ponerlo en queue
      if (root->left) {
          queue.push_back(root->left);
      }
      // si el nodo actual no es un nodo completo, establezca el indicador en verdadero
      else {
          flag = 1;
      }


      // si existe el hijo correcto, ponerlo en queue
      if (root->right) {
          queue.push_back(root->right);
      }
      // si el nodo actual no es un nodo completo, establezca el indicador en verdadero
      else {
          flag = 1;
      }
    }

    return 1;
    }
}