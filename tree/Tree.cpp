#include <iostream>
#include "Tree.h"

using namespace std;

struct NodeT {
    int elem; //valor del nodo
    NodeT* left; //rama izquierda
    NodeT* right; //rama derecha
};
//INVARIANTES:
//-

Tree emptyT(){ //es porque todo arbol parte de un nodo entonces, un puntero a nada es un arbol vacio?
    return nullptr;
}
Tree nodeT(int elem, Tree left, Tree right){
    NodeT* nodo = new NodeT;
    nodo->elem = elem;
    nodo->left= left;
    nodo->right=right;
    return nodo; 
}
bool isEmptyT(Tree t){
    return (t==nullptr)
}
int rootT(Tree t){
    if(t==nullptr){
        throw runtime_error("No apunta a un arbol");
    }else {
        return t->elem;
    }
}
Tree left(Tree t){
    if(t==nullptr){
        return nullptr;
    } else {
        return t->left;
    }
}
Tree right(Tree t){
    if(t==nullptr){
        return nullptr;
    } else {
        return t->right;
    }
}