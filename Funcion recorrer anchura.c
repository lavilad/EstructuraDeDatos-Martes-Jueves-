//FUNCION PARA RECORRER EL ARBOL POR ANCHURA
//POR CHRISTIAN OJEDA

/*ESTA FUNCION UTILIZA UNA COLA  EN LA CUAL SE LE ASIGNARAN LOS NODOS DEL ARBOL,
Y ESTA IRA RECORRIENDOLOS POR NIVELES DE IZQUIERDA A DERECHA*/


// Estructura para la cola
typedef struct QueueNode {
    Node* data;
    struct QueueNode* next;
} QueueNode;

// Función para insertar un nuevo nodo en la cola
void enqueue(QueueNode** front, QueueNode** rear, Node* data) {
    // Se crea un nuevo nodo de la cola
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    // Si la cola está vacía, el nuevo nodo será tanto el frente como el final de la cola
    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }

    // Se añade el nuevo nodo al final de la cola y se actualiza el puntero al final de la cola
    (*rear)->next = newNode;
    *rear = newNode;
}

// Función para eliminar un nodo de la cola
Node* dequeue(QueueNode** front, QueueNode** rear) {
    // Si la cola está vacía, se retorna NULL
    if (*front == NULL)
        return NULL;

    // Se almacena el nodo del frente y se elimina de la cola
    QueueNode* temp = *front;
    Node* data = temp->data;
    *front = (*front)->next;

    // Si el nodo del frente se convierte en NULL, el final de la cola también se actualiza a NULL
    if (*front == NULL)
        *rear = NULL;

    // Se libera la memoria del nodo eliminado
    free(temp);
    return data;
}

// Función para recorrer el árbol en anchura, pasando de izquierda a derecha
void recorrer_anchura(Node* root) {
    if (root == NULL)
        return;

    // Se inicializa la cola para el recorrido en anchura
    QueueNode *front = NULL, *rear = NULL;

    // Se encola el nodo raíz
    enqueue(&front, &rear, root);

    while (front != NULL) {
        // Se elimina el nodo del frente de la cola y se imprime su valor
        Node* current = dequeue(&front, &rear);
        printf("%d ", current->key);

        // Se encolan los hijos izquierdo y derecho del nodo actual si existen, asegurando que primero se encole el hijo izquierdo
        if (current->left)
            enqueue(&front, &rear, current->left);
        if (current->right)
            enqueue(&front, &rear, current->right);
    }
}

