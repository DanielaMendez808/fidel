#include "LinkedList.h"
#include <iostream>

using namespace std;

struct NodoL {
    int elem; // valor del nodo
    NodoL* siguiente; // puntero al siguiente nodo
};

struct LinkedListSt {
    // INV.REP.: cantidad indica la cantidad de nodos que se pueden recorrer
    // desde primero por siguiente hasta alcanzar a NULL
    int cantidad; // cantidad de elementos
    NodoL* primero; // puntero al primer nodo
    NodoL* ultimo; // puntero al ultimo nodo
};

struct IteratorSt {
    NodoL* current;
};

LinkedList nil() 
{
    LinkedListSt* xs = new LinkedListSt;
    xs->cantidad = 0;
    xs->primero = nullptr;
    
    return xs;
}

bool isEmpty(LinkedList xs)
{
    return xs->cantidad == 0;
    // return xs->primero == nullptr;
}

int head(LinkedList xs) // parcial
{   
    if (xs->cantidad == 0)
    {
        cout << "ERROR: La LinkedList no tiene elementos" << endl;
    }

    return xs->primero->elem;
}

//void Cons(int x, LinkedList xs)
//{
    // 1) creo el nuevo nodo que va a ser el nuevo primer nodo.
//    NodoL* n = new NodoL;
//    n->elem = x;

    // 2) pongo que su siguiente nodo sea el primero de la lista original
//    n->siguiente = xs->primero;
    
    // 3) ahora en la lista original conecto el puntero primero y actualizo la cantidad.
//    xs->primero = n;
//    xs->cantidad++;
//}
void Cons(int x,LinkedList xs){
    NodoL* n = new NodoL;
    n->elem = x;
    n->siguiente=nullptr;
    if(xs->ultimo==nullptr){
        xs->ultimo = n;
    } else{
        n->siguiente=xs->primero;
    }
    xs->primero=n;
    xs->cantidad++;
}

// void Cons(int x, LinkedList xs)
// {
//     NodoL *node = createNode(x);
//     node->siguiente = xs->primero;

//     if (xs->cantidad == 0)
//         xs->ultimo = node;

//     xs->primero = node;
//     xs->cantidad++;
// }


void Tail(LinkedList xs) // parcial
//Quita el primero elemento.
{ 
    if (xs->cantidad == 0)
    {
        cout << "ERROR: La LinkedList no tiene elementos" << endl;
    }else if(xs->cantidad == 1){
        delete xs->primero;
        xs->primero=nullptr;
        xs->ultimo=nullptr;
        xs->cantidad--;
        // n    = 1
        // fst -> [null]      NO EXISTE MAS [x] -> NULL
        // lst -> [null]
    } else{
    //1) hago que el puntero al primero, apunte el segundo para no perder la referencia.
    NodoL* tmp = xs->primero;
    xs->primero = xs->primero->siguiente;
    //2) libero la memoria reservada al primero nodo de la lista original, 
    delete tmp;
    //3) cambio la cantidad
    
    // n    = 1       BORRAR tmp -> [x]
    // fst -> [y]     [y] -> NULL
    // lst -> [y]
    }
    xs->cantidad--;
}
//NodeL* tmp = xs->primero
//xs->primero = xs->primero->siguiente
//delete tmp
//if (xs->primero == NULL) {
//  xs->ultimo = NULL
//}
//xs->cantidad --
int length(LinkedList xs)
{
    return xs->cantidad;
}


// void Tail(LinkedList xs)
// {
//     if (xs->cantidad == 0)
//         throw runtime_error("La lista esta vacia");

//     if (xs->cantidad > 0)
//     {
//         NodoL *tmp = xs->primero; // este lo quiero deletear
//         xs->primero = xs->primero->siguiente;
//         xs->cantidad--;
//         delete tmp;
//     }
//     // n    = 0       BORRAR tmp -> [y]
//     // fst -> [null]     [y] -> NULL
//     // lst -> [null]
//     if (xs->primero == nullptr)
//         xs->ultimo = nullptr;
// }

void Snoc(int x, LinkedList xs)
//agrega un elemento al final de la lista
{
    NodoL* n = new NodoL;
    n->elem = x;
    n->siguiente = nullptr;
    if(xs->ultimo==nullptr){
        xs->primero= n;
    }else{
        xs->ultimo->siguiente=n;
    }
    xs->ultimo=n;
    xs->cantidad++;

        // n    = 3       n -> [z] -> NULL
        // fst -> [x]     [x] -> [y] -> [z] -> NULL
        // lst -> [z]
}

// void Snoc(int x, LinkedList xs)
// {
//     // 1) creo el nuevo nodo que va a ser el nuevo ultimo nodo.
//     NodoL* n = new NodoL;
//     n->elem = x;
//     n->siguiente = nullptr;
//     // 2) si la lista es vacia, lo agrego al principio
//     if(xs->cantidad == 0)
//     {
//         xs->primero = n;
//     } else
//     {
//         // 3) hago que el nodo temporal y que recorra la lista mientras que el siguiente sea nulo
//         NodoL* tmp = xs->primero;
//         while (tmp->siguiente != nullptr)
//         {
//             tmp = tmp->siguiente;
//         }
//         tmp->siguiente = n;
//     }
//     xs->cantidad++;
// }
ListIterator getIterator(LinkedList xs){
    //apunta el recorrido al primer elemento.
    IteratorSt* i = new IteratorSt;
    i->current = xs->primero;
    return i; 
}
int current(ListIterator ixs){
    //Devuelve el elemento actual en el recorrido.
    return ixs->current->elem;
}
void SetCurrent(int x, ListIterator ixs){
    //Reemplaza el elemento actual por otro elemento.
    ixs->current->elem = x;
}
void Next(ListIterator ixs){
    //Pasa al siguiente elemento.
    ixs->current=ixs->current->siguiente;
}
bool atEnd(ListIterator ixs){
    //Indica si el recorrido ha terminado.
    return ixs->current->siguiente=nullptr;
}
void DisposeIterator(ListIterator ixs){
    //Libera la memoria ocupada por el iterador.
    delete ixs;
    //Borro solo el iterador, no el current que es parte de su estructura, ni el nodo al que apunta.
}

void DestroyL(LinkedList xs)
{                                     
    NodoL* tmp = xs->primero; 
    while(xs->primero != nullptr) {
        xs->primero = xs->primero->siguiente;
        xs->cantidad--;
        delete tmp;
        tmp = xs->primero;
    }
    delete xs;
    }

void DestroyLT(LinkedList xs)
{
    NodoL *actual = xs->primero;

    while (actual != nullptr)
    {
        NodoL *tmp = actual;
        actual = actual->siguiente;
        delete tmp;
    }

    delete xs;
}


