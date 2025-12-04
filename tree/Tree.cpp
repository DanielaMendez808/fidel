#include <iostream>
#include "Tree.h"

using namespace std;

// data Tree a = EmptyT | NodeT int (Tree a) (Tree a)

struct NodeT {
    int elem; //valor del nodo
    NodeT* left; //rama izquierda
    NodeT* right; //rama derecha
};
//INVARIANTES:
//- Los elem del arbol izquierdo son menores a la raiz.
//- Los elem del arbol derecho son mayores a la raiz.
//- Los sub arboles cumplen ser BST
//           7 
//     4<-        ->11
//   <- ->9     8<- ->14
//
// 
Tree emptyT(){ //es porque todo arbol parte de un nodo entonces, un puntero a nada es un arbol vacio?
    return nullptr;
}

// PRECOND: left y right son BST
Tree nodeT(int elem, Tree left, Tree right){
    NodeT* nodo = new NodeT;
    nodo->elem = elem;
    nodo->left = left; // verificar q todos los elems son menores que elem
    nodo->right = right; // verificar q todos los elems son mayores que elem
    return nodo; 
}

bool isEmptyT(Tree t){
    return t==nullptr;
}

int rootT(Tree t){
    if(t==nullptr){
        throw runtime_error("El arbol es NULL");
    }else {
        return t->elem;
    }
}
Tree left(Tree t){
    if(t==nullptr){
        return nullptr; // ta bien, se puede hacer mejor dando vuelta la condicion o tirar error
    } else {
        return t->left;
    }
}
Tree right(Tree t){
    if(t==nullptr){
        return nullptr;
    } else {
        return (t->right);
    }
}
/////////////////////////////////////////////////////////////////////
// EJERCICIO 7
int sumarT(Tree t){
    //Dado un árbol binario de enteros devuelve la suma entre sus elementos.
    if (isEmptyT (t)){
        return 0;
    } else {
        return rootT(t) + sumarT(left(t)) + sumarT(right(t));
    }
}

int sizeT(Tree t){
    //Dado un árbol binario devuelve su cantidad de elementos, es decir, el tamaño del árbol (size en inglés).
    if(isEmptyT(t)){ // empty verifica q el arbol es null, --> esta bien q sea cero uwu
        return 0;
    } else {
        return 1 + sizeT(left(t)) + sizeT(right(t));
    }
}

bool perteneceT (int e, Tree t){
    if (isEmptyT (t)){
        return false;
    } else {
        return rootT(t)==e || perteneceT(e,left(t)) || perteneceT(e,right(t));
    }
}

int aparicionesT(int e, Tree t){
    if(isEmptyT(t)){
        return 0;
    } else{
        if(rootT(t)==e){
            return 1 + aparicionesT(e,left(t)) + aparicionesT (e,right(t));
        }else{
            return aparicionesT(e,left(t)) + aparicionesT (e,right(t));
        }
    }
}

int heightT(Tree t){
    if(isEmptyT(t)){
        return 0;
    } else {
        return 1 + max(heightT(left(t)),heightT(right(t)));
    }
}