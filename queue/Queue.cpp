#include <iostream>
#include "Queue.h"

using namespace std;

struct NodoQ {
    int elem; // valor del nodo
    NodoQ* siguiente; // puntero al siguiente nodo
};
struct QueueSt {
    int cantidad; // cantidad de elementos
    NodoQ* primero; // puntero al primer nodo
    NodoQ* ultimo; // puntero al ultimo nodo
};
//INVARIANTES:
// -cantidad va a el numero total de nodos que se puede recorrer desde el primer nodo a traves del primero->siguiente hasta llegar al ultimo nodo en una queue.
// -si primero es NULL, el ultimo tambien es NULL.
// -si el ultimo es NULL, el primero tambien es NULL.
// -el elemento que se agrega primero es el primero en salir. 
Queue emptyQ(){
    //Crea una cola vacía.
    //Costo: O(1).
    /*
    ANALIZAR COSTOS:
     * OPERACIONAL(costo temporal, como el haskell):
     crear un struct(1), 3*asignaciones(1) =1+3.1=4*1=O(1) 
     * EN MEMORIA DINAMICA(HEAP)=Creo un solo struct y eso incluye la memoria para el int y los dos punteros. O(1)
     * EN MEMORIA ESTATICA(STACK FRAME)=Creo solamente un punterio a la heap, O(1)
    */
    QueueSt* q = new QueueSt;
    q->cantidad = 0;
    q->primero=nullptr;
    q->ultimo=nullptr;
    return q;
}
bool isEmptyQ(Queue q){
    //Indica si la cola está vacía.
    //Costo: O(1).
    return q->cantidad==0;
    /*ANALIZAR COSTOS:
     * OPERACIONAL = accedo a un puntero y hago una comparacion O(1)
     * EN MEMORIA DINAMICA(HEAP)= el espacio ya esta reservado por parametro, entonces es fijo O(1)
     * EN MEMORIA ESTATICA(STACK FRAME)= espacio para (Queue q) reservado O(1). */
}
int firstQ(Queue q){
    //Devuelve el primer elemento.
    //Costo: O(1).
    if(q->cantidad==0){
        throw runtime_error("La queue esta vacia");
    }else{return q->primero->elem;
    }
    /*ANALIZAR COSTOS:
     * OPERACIONAL = 2 accesos a punteros en el peor caso, 2*(1)=O(1)
     * EN MEMORIA DINAMICA(HEAP)= el espacio ya esta reservado por parametro, entonces es fijo O(1)
     * EN MEMORIA ESTATICA(STACK FRAME)= espacio para (Queue q) reservado O(1). */
}
void Enqueue(int x, Queue q){
    //Agrega un elemento al final de la cola.
    //Costo: O(1).
    NodoQ* nuevo = new NodoQ;
    nuevo->elem=x;
    nuevo->siguiente= nullptr;
    if(q->cantidad==0){
        q->primero=nuevo;
    }else{
        q->ultimo->siguiente=nuevo;
    }
    q->ultimo =nuevo;
    q->cantidad++;
    /*ANALIZAR COSTOS:
     * OPERACIONAL =
     creo un nodo en la heap (1)
     dos asignaciones 2*(1)
     dos accesos a punteros y una asignacion 2*(1) + (1)
     dos asignaciones 2*(1)
     8*(1)
     =0(1)
     * EN MEMORIA DINAMICA(HEAP)= 
     el espacio ya esta reservado por parametro para q(Queue)
     reservo espacio para un nuedo NodoQ O(1)
     * EN MEMORIA ESTATICA(STACK FRAME)= 
     espacio para (Queue q) reservado O(1). 
     espacio para (int x) reservado O(1).
     creo espacio para el puntero (Nodoq nuevo) O(1).
     3*(1)
     =(1)
     */
}
void Dequeue(Queue q){
    //Quita el primer elemento de la cola.
    //Costo: O(1).
    if(q->cantidad==0){
        throw runtime_error("La queue esta vacia");
    }else{
        NodoQ * tmp = q->primero; // este lo quiero deletear
        q->primero = q->primero->siguiente;
        q->cantidad--;
        delete tmp;
    }
    
    if (q->primero == nullptr){
        q->ultimo = nullptr;
    }
     /*ANALIZAR COSTOS:
     * OPERACIONAL =
        comparaciones (1)
        creacion de puntero (1)
        accesos y asignaciones (1)
        =O(1)
     * EN MEMORIA DINAMICA(HEAP)= 
     el espacio ya esta reservado por parametro para q(Queue)
     * EN MEMORIA ESTATICA(STACK FRAME)= 
     espacio para (Queue q) reservado O(1). 
     creo un puntero(Nodoq tmp) O(1).
     borro un puntero(Nodoq tmp) O(1)
     3*(1)
     =(1)
     */

}
int lengthQ(Queue q){
    //Devuelve la cantidad de elementos de la cola.
    //Costo: O(1).
    return q->cantidad;
}
void MergeQ(Queue q1, Queue q2){
    //Anexa q2 al final de q1, liberando la memoria inservible de q2 en el proceso.
    //Nota: Si bien se libera memoria de q2, no necesariamente la de sus nodos.
    //Costo: O(1).
    if(q1->cantidad==0){
        q1->primero=q2->primero;
        q1->ultimo =q2->ultimo;
    }else{
        q1->ultimo->siguiente = q2->primero;
        if(q2->ultimo!=nullptr){
            q1->ultimo=q2->ultimo;
        }
    }
    q1->cantidad= (q1->cantidad) + (q2->cantidad);
    delete q2;
}
void DestroyQ(Queue q){
    //Libera la memoria ocupada por la cola.
    //Costo: O(n).
    NodoQ* tmp = q->primero;
    while(tmp !=nullptr){
        q->primero=q->primero->siguiente;
        q->cantidad--;
        delete tmp;
        tmp= q->primero;
    }
    delete q;
    /*ANALIZAR COSTOS:
     * OPERACIONAL = 
        N=cantidad de elementos de la queue
        creacion de puntero (1)
        N*(comparaciones (1) + accesos y asignaciones (1))
        un delete (1)
        =2*(1) + N*(2*(1))
        =(1) +N(1)
        =O(N)
     * EN MEMORIA DINAMICA(HEAP)= 
     el espacio ya esta reservado por parametro para q(Queue) O(1)
     el delete de q(Queue) O(1)
     el espacio reservado, lo estoy liberando.
     * EN MEMORIA ESTATICA(STACK FRAME)= 
     espacio para (Queue q) reservado O(1). 
     reservo espacio para un puntero(Nodoq tmp) O(1).
     borro un puntero(Nodoq tmp) O(1)
     cuando asigno o borro el espacio reservado no ocupo mas espacio.
     3*(1)
     =(1)
     */
}