#include <iostream>
#include <iomanip>
using namespace std;
#include "ParcialBSTconJerarquia.h"


void insertar(string nuevo,string superior, JerarquíaBST bst){
    if(!find (superior,bst->root) || find (nuevo,bst->root)){
        //error "No existe padre jerarquico en bst o el nodo a insertar ya existe"
    }else{
        JBSTNodeStr* nodo = new JBSTNodeStr;
        nodo-> name = nuevo;
        nodo->right = NULL;
        nodo->left= NULL;
        JBSTNodeStr* padre= find(superior,bst->root);
        nodo->parent=padre;
        JBSTNodeStr* temp = bst->root;
        JBSTNodeStr* padreFisico =NULL;
        while(temp != NULL){
            padreFisico = temp;
            if(temp->name >nuevo){
                temp = temp->left;
            }else{
                temp=temp ->right;
            }
        }
        if(padreFisico->name>nuevo){
            padreFisico->left = nodo;
        }else{
            padreFisico->right = nodo;
        }
    }
}

JBSTNodeStr* find(string nombre,JBSTNodeStr* t){
    //describe el nodo donde esta la persona con el nombre dado en la jerarquia que comienza con el nombre dado.
        JBSTNodeStr* actual = t;
        while(actual != NULL && actual->name != nombre){

            if(actual->name > nombre ){
            actual=actual->left;
            }else{
            actual = actual ->right;
            }
            
    }
    return actual;
}

bool esSubordinadoDe(string empleado, string superior, JerarquíaBST bst){
    bool esEmpleado = false;
    JBSTNodeStr* empleadoNodo = find(empleado, bst->root);
    while (empleadoNodo != NULL && empleadoNodo->parent !=NULL){
        if(empleadoNodo->parent->name==superior){
            esEmpleado = true;
        }
        empleadoNodo=empleadoNodo->parent;
    }
    return esEmpleado;
}

ArrayList toArrayInOrder(Bosque b){

}