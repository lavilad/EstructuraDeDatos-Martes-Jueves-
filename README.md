// FUNCIÓN PARA CALCULAR LA ALTURA DEL ÁRBOL
int alturaArbol(Nodo *raiz) {
    if (raiz == NULL) {
        return 0; // Altura de un árbol vacío es 0
    } else {
        // Calcula la altura de los subárboles izquierdo y derecho
        int alturaIzquierda = alturaArbol(raiz->izquierda);
        int alturaDerecha = alturaArbol(raiz->derecha);

        // La altura del árbol es la máxima altura entre los subárboles izquierdo y derecho
        return 1 + (alturaIzquierda > alturaDerecha ? alturaIzquierda : alturaDerecha);
    }
}
