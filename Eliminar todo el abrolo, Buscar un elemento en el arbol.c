//funcion para eliminar todos los elemntos 
  
void borrar(Node* node){
    if(node == NULL)
      return;
    borrar(node->left);
    borrar(node->right);
  
    free(node);
}
//Funcion para buscar un elemento en especifico en el arbol 
int search(Node* node, int key){
  if(node == NULL){
    return 0;}
  if(node->key == key){
    return 1;
  }
  if(key < node->key){
    return search(node->left, key);
  }
    
  else{
    return search(node->right, key);
  }
}
