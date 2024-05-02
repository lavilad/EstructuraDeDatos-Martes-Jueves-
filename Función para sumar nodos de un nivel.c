



// FUNCIÓN PARA SUMAR LOS VALORES DE UN NIVEL ESPECÍFICO
int sumarNivel(Nodo *raiz, int nivel) {
    if (raiz == NULL)
        return 0;
    if (nivel == 0)
        return raiz->clave;
    else
        return sumarNivel(raiz->izquierda, nivel-1) + sumarNivel(raiz->derecha, nivel-1);
}

