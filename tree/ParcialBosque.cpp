#include <iostream>
#include "ParcialBosque.h"
#include "Tree.h"
#include "ListOfTrees.h"

using namespace std;

//InvariantesDeRepresentacion, escrito a mano

//implementador

void insertLeft(int id,Bosque b){
    //inserta un nuevo nodo como hijo izquierdo del nodo actual.Si ya existe hijo izquierdo, no hacer nada.
    if(b->current->left == NULL){ // inserto solo si el hijo izquierdo no existe
        Nodo* nuevo = new Nodo;
        nuevo -> value = id;
        nuevo -> left = NULL;
        nuevo -> right = NULL;
        if(b->current == b->root){
            nuevo -> parent = NULL;
        }else{
            nuevo ->parent = b-> current;
            b->current->left=nuevo;
        }
    }
}

void removeCurrent(Bosque b){
    //elimina el nodo actual
    //  si es hoja -> se elimina
    //  si tiene un solo hijo -> ese hijo sube al lugar del nodo
    //  si tiene dos hijos ->reemplazar por el minimo del subarbol derecho
    //      cuando termino current debe apuntar al padre del nodo eliminado
    Nodo* actual= b->current;
    Nodo* raiz = b-> root;
    if(actual !=NULL){
        if(cantDeHijos(actual) == 0){ // caso donde el nodo es hoja
            if (actual == raiz){ //caso donde el nodo a eliminar es la raiz
                Nodo* nodoABorrar = raiz;
                raiz = NULL;
                actual = NULL;
                delete nodoABorrar;
            }else{  // caso donde el nodo a eliminar no es la raiz, entonces tiene padre
                Nodo *nodoABorrar = actual;
                actual = actual->parent;
                delete nodoABorrar;
            }
        if(cantDeHijos(actual)==1){ //caso donde el nodo tiene un hijo
            if(actual == raiz){  //caso donde el nodo a eliminar es la raiz
                if(raiz->left ==NULL){ //caso donde tiene un hijo derecho
                    
                }
                if (actual->parent->left==NULL){ //caso donde el unico hijo sea el derecho
                actual->parent->right = actual ->right;
                actual ->right ->parent = actual ->parent;
            } else{ 
                actual->parent->left =actual->left; //caso donde el unico hijo sea el izquierdo
                actual ->left ->parent = actual ->parent;
            }
            delete nodoABorrar;
                

            }
        }
        } else if (actual->left != NULL && actual->right!= NULL){ // caso donde el actual/raiz tiene ambos hijos

        }else{  //caso donde el actual tiene un solo hijo

        }
        


        if(actual->right == NULL && actual->left == NULL){ //caso donde el actual es hoja
            Nodo *nodoABorrar = actual;
            if (actual != raiz){ // caso donde el current no este apuntando a la raiz
            actual = actual->parent;
            }else{ // caso donde el current este apuntando a la raiz
            actual == NULL
            
            }
            delete nodoABorrar;
        }else if(actual->left != NULL && actual->right!= NULL ){ // caso donde el actual tiene ambos hijos
            Nodo* nodoMinimo = new Nodo;
            nodoMinimo -> value = minimo(b);
            nodoMinimo->parent= actual->parent;// asignando como padre del nodo minimo, el padre del nodo actual.
            nodoMinimo-> right = actual ->right;
            nodoMinimo-> left = actual -> left;
            if(actual ->parent ->left == NULL){ //caso donde el current sea hijo derecho
                actual->parent->right = nodoMinimo; //asingo al padre del actual, que tenga de hijo al nodo minimo
                if(nodoMinimo->right == NULL && nodoMinimo->left == NULL){ // caso donde el nodo minimo no tiene hijos
                }
                else{ // caso donde el nodo minimo tiene un hijo y siempre es hijo derecho, dicho por el parcial.
                    nodoMinimo -> right -> parent =  nodoMinimo ->parent; 
                }             
            }else{ //caso donde el current sea hijo izquierdo
                actual->parent->left = nodoMinimo; //asingo al padre del actual, que tenga de hijo al nodo minimo
                if(nodoMinimo->right == NULL && nodoMinimo->left == NULL){ // caso donde el nodo minimo no tiene hijos
                }
                else{ 
                nodoMinimo -> right -> parent =  nodoMinimo ->parent; // caso donde el nodo minimo tiene un hijo y siempre es hijo derecho, dicho por el parcial.
                }
            }
            Nodo* nodoABorrar = actual;
            actual = actual->parent;
            delete nodoABorrar;                
        }else{ //caso donde el actual tiene un solo hijo
            Nodo* nodoABorrar= actual;
            if (actual->parent->left==NULL){ //caso donde el unico hijo sea el derecho
                actual->parent->right = actual ->right;
                actual ->right ->parent = actual ->parent;
            } else{ 
                actual->parent->left =actual->left; //caso donde el unico hijo sea el izquierdo
                actual ->left ->parent = actual ->parent;
            }
            delete nodoABorrar;
        }
}

int cantDeHijos(Nodo* x){
    if(x->left== NULL && x->right==NULL){
        return 0;
    } else if(x->left!= NULL && x->right !=NULL){
        return 2;
    } else{ 
        return 1;
    }
}
int minimo(Bosque b){
    //busco el id del nodo con id menor en el arbol dado desde abajo del current
    TList faltanProcesar = emptyTL();
    Tree actual;
    int minimoHastaAhora = b -> current ->value;

    if(b->current->left != NULL || b->current->right != NULL){
        ConsTL(current,faltanProcesar);
    }
    while(!isEmptyTList(faltanProcesar)){
        actual = headTL(faltanProcesar);
        TailTL(faltanProcesar);
        if(actual->value < minimoHastaAhora){
            minimoHastaAhora = actual ->value
        }
        if(!isEmptyT(right(actual))){
            ConsTL(right(actual),faltanProcesar);
        }
        
        if(!isEmptyT(left(actual))){
            ConsTL(left(actual),faltanProcesar);
        }
    }
    LiberarTL(faltanProcesar);
    return minimoHastaAhora;
}

int size(Bosque b){
    //size del arbol dado, segun el parcial hacerlo por recursion.
    if(b == NULL){
        //error
    }
    if(b != NULL){
        return auxiliarParaNoRomperInvariante(b->root);
    }
}

int auxiliarParaNoRomperInvariante(Nodo* x){
    if(x == NULL){
        return 0;
    }else{
       return  1+ auxiliarParaNoRomperInvariante(x->right) + auxiliarParaNoRomperInvariante (x->left);
    }
}

