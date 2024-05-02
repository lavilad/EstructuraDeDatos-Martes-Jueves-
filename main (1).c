//funcion para hayar el ancestro común más cercano (LCA)

Node* findLCA(Node* root, int n1, int n2)
{
   if (root == NULL) return NULL; 
    // Si el árbol está vacío, retorna NULL. Si ambos n1 y n2 son menores que la raiz, entonces LCA reside en el subárbol izquierdo.
   if (root->key > n1 && root->key > n2)
       return findLCA(root->left, n1, n2);
   // Si 1 y 2 son mayores que la raiz, entonces LCA reside en el subárbol derecho.
   if (root->key < n1 && root->key < n2)
       return findLCA(root->right, n1, n2);
   // Si 1 o 2 es igual a razi->key, o uno está en el subárbol izquierdo y el otro en el derecho, entonces el nodo actual es el LCA.
   return root;
}