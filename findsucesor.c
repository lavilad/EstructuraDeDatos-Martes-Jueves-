#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo del árbol
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Función para crear un nuevo nodo del árbol
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Función para encontrar el sucesor de un nodo en un árbol binario de búsqueda
struct TreeNode* findSuccessor(struct TreeNode* root, struct TreeNode* node) {
    // Si el nodo tiene un hijo derecho, entonces el sucesor será el nodo más a la izquierda en el subárbol derecho
    if (node->right != NULL) {
        node = node->right;
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    // Si no tiene hijo derecho, entonces el sucesor será el primer ancestro mayor que él.
    struct TreeNode* successor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else {
            break;
        }
    }
    return successor;
}

// Función de prueba para imprimir el sucesor de un nodo
void testSuccessor(struct TreeNode* root, struct TreeNode* node) {
    struct TreeNode* successor = findSuccessor(root, node);
    if (successor != NULL)
        printf("El sucesor de %d es %d.\n", node->data, successor->data);
    else
        printf("No hay sucesor para el nodo %d.\n", node->data);
}

// Función principal
int main() {
    // Construcción del árbol de prueba
    struct TreeNode* root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->right->left = newNode(25);
    root->right->right = newNode(35);

    // Prueba de la función para encontrar el sucesor de un nodo
    testSuccessor(root, root->left);  // Sucesor de 10
    testSuccessor(root, root->left->right);  // Sucesor de 15
    testSuccessor(root, root->right->right);  // Sucesor de 30

    return 0;
}
