#include <iostream>
#include "Set.h"
//#include "LinkedList.h"

using namespace std;

struct NodoS{
    int elem; //valor del nodo
    NodoS* siguiente; // puntero al siguiente nodo
};
struct SetSt{
    int cantidad; // cantidad de elementos diferentes.
    NodoS* primero; // puntero al primer nodo
};

//INVARIANTES:
// -cantidad va a el numero total de nodos que se puede recorrer desde el primer nodo a traves del primero->siguiente hasta llegar al ultimo nodo en una queue.
// -si primero es NULL, el ultimo tambien es NULL.
// -si el ultimo es NULL, el primero tambien es NULL.
// -no hay elementos repetidos en la estructura de set. 

Set emptyS(){
    //Crea un conjunto vacío.
    SetSt* set = new SetSt;
    set -> cantidad = 0;
    set -> primero =nullptr;
    return set;
}
bool isEmptyS(Set s){
    //Indica si el conjunto está vacío.
    return s->cantidad==0;
}
bool belongsS(int x, Set s){
    //Indica si el elemento pertenece al conjunto.
    NodoS* tmp = s->primero;
    bool noSeEncontro =tmp->siguiente != nullptr;
    while(noSeEncontro && tmp->elem !=x){
        tmp= s->primero->siguiente;
    }
    return !noSeEncontro; 
}
void AddS(int x, Set s){
    //Agrega un elemento al conjunto.
    //probar con booleanos tipo aparece y unir casos.
    NodoS* current =s->primero;
    bool aparecio =false;
    while(current != nullptr && !aparecio ){
        aparecio = (current->elem==x);
        current = current->siguiente;
    }
    if(!aparecio){
        NodoS* nuevo = new NodoS;
        nuevo->elem = x;
        nuevo->siguiente =s->primero;
        s->primero= nuevo;
        s->cantidad++;
    }
}

//data Set a = S [] int -- elems cantidad

//addS :: Ord a => a -> Set a -> Set a
//addS x (S xs n) = if elems x xs
//                      then S xs n
//                      else S (x:xs) (n + 1) CUCHAAU

void RemoveS(int x, Set s){
    //Quita un elemento dado.
    //probar con un bool que sea aparece y nombres de punteros mas apropiados.
    if(s->cantidad>0){ //hay al menos un elemento, si no hay ninguno pasa de largo.
        NodoS* current = s->primero; // lo uso como iterador para recorrer el set.
        bool aparecio = false;
        NodoS* previo =nullptr;

        while(current != nullptr && !aparecio){
            aparecio = current->elem==x;
            
            if(!aparecio){
                previo = current;
                current = current->siguiente;
            }
        }
        if(aparecio){
            
            if(previo ==nullptr){ // cuando el elemento es el primero y previo habia quedado en null
                s->primero=current->siguiente;
            
            }else{ //cuando el elemento no es el primero, entonces puedo hacer siguiente de algo que no es nulo.
                previo->siguiente = current->siguiente;}
            
            delete current;
            s->cantidad--;
        }
        //{1,2} c=1 p=null
    }
}

int sizeS(Set s){
    //Devuelve la cantidad de elementos.
    return s->cantidad;
}
LinkedList setToList(Set s){
    //Devuelve una lista con los elementos del conjunto.
    LinkedList xs = nil();
    NodoS* tmp = s->primero;
    while(tmp !=nullptr){
        int elemActual = tmp->elem;
        Cons (elemActual, xs);
        tmp= tmp->siguiente;
    }
    return xs;
}
void DestroyS(Set s){
    //Libera la memoria ocupada por el conjunto.
    NodoS* tmp = s->primero;
    while(tmp != nullptr){
        s->primero = s->primero->siguiente;
        s->cantidad--;
        delete tmp;
        tmp = s->primero;
    }
    delete s;
}


void DestroyST(Set s)
{
    NodoS *current = s->primero;

    while (current != nullptr)
    {
        NodoS *next = current->siguiente;
        delete current;
        current = next;
    }

    delete s;
}
