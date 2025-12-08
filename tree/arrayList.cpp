#include "Array.h"
#include <iostream>
using namespace std;
struct ArrayListSt{
    int cantidad; // cantidad de elementos
    int* elementos; // array de elementos
    int capacidad; // tamaño del array
};
typedef ArrayListSt* ArrayList;
//Definir la siguiente interfaz de este tip o de listas:
ArrayList newArrayList(){
//Crea una lista con 0 elementos.
//Nota: empezar el array list con capacidad 16.
    ArrayListSt* xs = new ArrayListSt;
    int* elem = new int[16];
    xs -> cantidad = 0;
    xs -> elementos = elem; // primero el tipo de elemento de la lista y entre corchetes la longitud.
    xs -> capacidad = 16;
    return xs;
}
ArrayList newArrayListWith(int capacidad1){
    //Crea una lista con 0 elementos y una capacidad dada por parámetro.
    ArrayList a = new ArrayListSt;
    a -> capacidad = capacidad1;
    a -> cantidad = 0;
    int* elem = new int[capacidad1];
    a-> elementos = elem;
    return a;
}
int lengthAL(ArrayList xs1){
    //Devuelve la cantidad de elementos existentes.
    return xs1 -> cantidad;
}
int get(int i, ArrayList xs){
    //Devuelve el iésimo elemento de la lista.
    return xs -> elementos[i];
}
void set(int i, int x, ArrayList xs){
    //Reemplaza el iésimo elemento p or otro dado.
    xs ->elementos[i] = x;
}
void resize(int capacidad1, ArrayList xs){
    //Decrementa o aumenta la capacidad del array.
    //Nota: en caso de decrementarla, se pierden los elementos del final de la lista.
    if (xs->capacidad < capacidad1){
        // aumentar capacidad
        int* nuevoArray = new int[capacidad1]; 
        for (int i = 0; i < xs->cantidad; i++) {
            nuevoArray[i] = xs->elementos[i];
        }
        // 2. Liberar memoria vieja
        delete[] xs->elementos; 
        // 3. Actualizar campos
        xs->elementos = nuevoArray;
        xs->capacidad = capacidad1;
        // xs->cantidad NO cambia
    } else {
        int* nuevoArray = new int[capacidad1];
        int* arrayViejo = xs->elementos;
        int elementosACopiar = min(xs->cantidad, capacidad1);
        for (int i = 0; i < elementosACopiar; i++) {
        nuevoArray[i] = arrayViejo[i];
        }
        delete[] arrayViejo;
        xs-> elementos = nuevoArray;
        xs -> cantidad = elementosACopiar;
        xs -> capacidad = capacidad1;
    }
}
void add(int x, ArrayList xs)
    //Agrega un elemento al final de la lista.
void remove(ArrayList xs)
    //Borra el último elemento de la lista.