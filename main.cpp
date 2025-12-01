#include <iostream>
#include "LinkedList.h"

using namespace std;

int sumatoria(LinkedList xs){
    //Devuelve la suma de todos los elementos.
    ListIterator ixs = getIterator(xs);
    int contador = 0;
    while(!atEnd(ixs)){
        contador +=current(ixs);
        Next(ixs);
    }
    DisposeIterator(ixs); // lo borro porque en getIterator creo el puntero en heap
    return contador;
}

void Sucesores(LinkedList xs){
    //Incrementa en uno todos los elementos.
    ListIterator ixs = getIterator(xs);
    while(!atEnd(ixs)){
        int elemActual =current(ixs)+1;
        SetCurrent(elemActual,ixs);
        Next(ixs);
    }
    DisposeIterator(ixs);
}
bool pertenece(int x, LinkedList xs){
    //Indica si el elemento pertenece a la lista.
    ListIterator ixs = getIterator(xs);
    while(!atEnd(ixs) && (current(ixs) != x) ){
        Next(ixs);
    }
    bool aparece = !atEnd(ixs);
    DisposeIterator(ixs);
    return aparece;
}

// bool pertenece(int x, LinkedList xs)
// {
//     ListIterator i = getIterator(xs);
//     bool found = false;

//     while (!found && !atEnd(i))
//     {
//         found |= x == current(i); // found = found || condition
//         Next(i);
//     }
//     DisposeIterator(i);

//     return found;
// }
int apariciones(int x, LinkedList xs){
    ListIterator ixs = getIterator(xs);
    int contador = 0;
    while (!atEnd(ixs)){
        if(current(ixs) == x){ //podria hacer un auxiliar de unoSiCeroSino pero es la misma idea
            contador++;
        }
        Next(ixs);
    }
    delete ixs; // puedo borrar el iterador sin problemas porque lo que devuelvo no esta directamente relacionado si ya no tengo acceso a el.
    return contador;
}
int minimo(LinkedList xs){
    ListIterator ixs = getIterator(xs);
    int minimoPorAhora =current(ixs);
    while(!atEnd(ixs)){
        Next(ixs);
        if(minimoPorAhora<current(ixs)){
            minimoPorAhora ==current(ixs);
        }
    }
    delete ixs;
    return minimoPorAhora;
}

LinkedList copy(LinkedList xs){
    //Dada una lista genera otra con los mismos elementos, en el mismo orden.
    LinkedList copia = nil();
    ListIterator ixs = getIterator(xs);
    while(!isEmpty(xs)){
        int actual =current(ixs);
        Snoc(actual, copia);
        Next(ixs);
    }
    delete ixs;
    return copia;
}

void Append(LinkedList xs, LinkedList ys){
    // agrega todos los elementos de la segunda lista al final de la primera.
    // La segunda lista se destruye.
    ListIterator ixs = getIterator(ys);
    while(!isEmpty(ys)){
        int actual =current(ixs);
        Snoc(actual,xs);
        Next(ixs);
    }
    delete ixs;
    delete ys;
}

int main(){
    cout << "hola"; 
    return 0;
}