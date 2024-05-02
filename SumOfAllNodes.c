void SumOfAllNodes(Node* root, int result){//Función para mostrar la suma de los nodos del árbol
    int temp = 0;
    if(root != NULL){
        SumOfAllNodes(root -> left, result);
        temp = root -> key;
        //printf("%d, acumulado: %d. ", root -> key, result);
        result += temp;
        printf("{Valor del nodo: %d, acumulado: %d} | ", root -> key, result);
        SumOfAllNodes(root -> right, result);
    }
}
