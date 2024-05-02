



// FUNCIÓN PARA SUMAR LOS VALORES DE UN NIVEL ESPECÍFICO
int sumarNivel(Node *raiz, int nivel) {
    if (raiz == NULL)
        return 0;
    if (nivel == 0)
        return raiz->key;
    else
        return sumarNivel(raiz->left, nivel-1) + sumarNivel(raiz->right, nivel-1);
}

