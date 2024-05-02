#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int valor;
    struct Nodo* izquierda;
    struct Nodo* derecha;
};

struct Nodo* crear_nodo(int valor) {
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodo->valor = valor;
    nodo->izquierda = NULL;
    nodo->derecha = NULL;
    return nodo;
}

struct Nodo* insertar(struct Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return crear_nodo(valor);
    } else {
        if (valor < raiz->valor) {
            raiz->izquierda = insertar(raiz->izquierda, valor);
        } else {
            raiz->derecha = insertar(raiz->derecha, valor);
        }
    }
    return raiz;
}

int contar_nodos_internos(struct Nodo* raiz) {
    if (raiz == NULL || (raiz->izquierda == NULL && raiz->derecha == NULL)) {
        return 0;
    }
    return 1 + contar_nodos_internos(raiz->izquierda) + contar_nodos_internos(raiz->derecha);
}

int main() {
    struct Nodo* raiz = NULL;
    int valores[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(valores) / sizeof(valores[0]);
    
    for (int i = 0; i < n; i++) {
        raiz = insertar(raiz, valores[i]);
    }

    printf("El número de nodos internos es: %d\n", contar_nodos_internos(raiz));

    return 0;
}

