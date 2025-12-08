#include <iostream>
#include "Tree.h"
#include "arrayList.h"
#include "ListOfTrees.h"

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

ArrayList toList(Tree t){
    ArrayList xs = newArrayListWith(sizeT(t));
    tree2Array(t, xs);
    return xs;
}

void tree2Array(Tree t, ArrayList xs){
    if(!isEmptyT(t)){
        add(rootT(t), xs);
        tree2Array(left(t), xs);
        tree2Array(right(t), xs);
    }
}

ArrayList leaves (Tree t){
    ArrayList xs = newArrayListWith(sizeT(t));
    tree2Leaves(t,xs);
    return xs
}

void tree2Leaves (Tree t, ArrayList xs){
    if(!isEmptyT(t)){
        if(esHoja(t)){
            add(rootT(t),xs);
        } else{
            tree2Leaves(left(t),xs);
            tree2Leaves(right(t),xs);
        }
    }
}

bool esHoja(Tree t){
    return isEmptyT(left(t)) && isEmptyT(right(t));
}

ArrayList levelN(int n, Tree t){
    ArrayList xs= newArrayListWith(sizeT(t));
    tree2LevelN(t, n, xs);
    return xs;
}

void tree2LevelN(Tree t, int n, ArrayList xs){
    if(!isEmptyT(t)){
        if(n==0){
        add(rootT(t),xs);
    }else{
        tree2LevelN(left(t),n-1,xs);
        tree2LevelN(right(t),n-1,xs);
    }
    }
}


//Usando BFS con ListOfTrees
int iSumT(Tree t){
    //Dado un arbol binario de enteros devuelve la suma de sus elementos.
    TList faltanProcesar = emptyTL();
    Tree actual;
    int totalVisto=0;
    if(!isEmptyT(t)){
        ConsTL(t,faltanProcesar); // aca habria que reasignar a faltanProcesar??
    }

    while(!isEmptyTList(faltanProcesar)){
        actual = headTL(faltanProcesar);
        TailTL(faltanProcesar);
        totalVisto += rootT(actual);
        
        if(!isEmptyT(right(actual))){
            ConsTL(right(actual),faltanProcesar);
        }
        
        if(!isEmptyT(left(actual))){
            ConsTL(left(actual),faltanProcesar);
        }
    }
    LiberarTL(faltanProcesar);
    return totalVisto;
}

int sizeT(Tree t){
    //Dado un arbol binario devuelve su cantidad de elementos, el tamaño del arbol
    TList faltanProcesar = emptyTL();
    Tree actual;
    int tamaño = 0;
    if(!isEmptyT(t)){
        ConsTL(t,faltanProcesar);
    }
    while(!isEmptyTList(faltanProcesar)){
        actual = headTL(faltanProcesar);
        TailTL(faltanProcesar);
        tamaño++;

        if(!isEmptyT(right(actual))){
            ConsTL(right(actual),faltanProcesar);
        }
        
        if(!isEmptyT(left(actual))){
            ConsTL(left(actual),faltanProcesar);
        }
    }
    LiberarTL(faltanProcesar);
    return tamaño;
}

bool perteneceT(int e, Tree t){
    //Dados un elemento e y un arbol binario devuelve True si existe un elementos igual al dado en el arbol.
    TList faltanProcesar = emptyTL();
    Tree actual;
    bool aparecio = false;

    if(!isEmptyT(t)){
        ConsTL(t,faltanProcesar);
    }
    while(!isEmptyTList(faltanProcesar) && !aparecio){
        actual = headTL(faltanProcesar);
        TailTL(faltanProcesar);
        aparecio = (rootT(actual) == e);

        if(!isEmptyT(right(actual))){
            ConsTL(right(actual),faltanProcesar);
        }
        
        if(!isEmptyT(left(actual))){
            ConsTL(left(actual),faltanProcesar);
        }
    }
    LiberarTL(faltanProcesar);
    return aparecio;
}

int aparicionesT(int e,Tree t){
    //Dados un elemento e y un arbol binario devuelve la cantidad de elementos del arbol que son iguales a e.
    TList faltanProcesar = emptyTL();
    Tree actual;
    int vecesQueAparecio = 0;

    if(!isEmptyT(t)){
        ConsTL(t,faltanProcesar);
    }
    while(!isEmptyTList(faltanProcesar)){
        actual = headTL(faltanProcesar);
        TailTL(faltanProcesar);
        if((rootT(actual) == e)){
            vecesQueAparecio++;
        }

        if(!isEmptyT(right(actual))){
            ConsTL(right(actual),faltanProcesar);
        }
        
        if(!isEmptyT(left(actual))){
            ConsTL(left(actual),faltanProcesar);
        }
    }
    LiberarTL(faltanProcesar);
    return vecesQueAparecio;
}

int heightT(Tree t){
    //Dado un arbol devuelve su altura.
    TList faltanProcesar = emptyTL();
    Tree actual;
    int altura = 0;
    int nodosEnNivel;
    if(!isEmptyT(t)){
        SnocTL(faltanProcesar,t); // lo agrego atras de la fila
    }
    while(!isEmptyTList(faltanProcesar)){
        nodosEnNivel = lengthTL(faltanProcesar);
        altura++;
        while(nodosEnNivel!= 0){
            actual = headTL(faltanProcesar);
            TailTL(faltanProcesar);
            nodosEnNivel--;
            if(!isEmptyT(right(actual))){
                SnocTL(faltanProcesar,right(actual));
            }
            
            if(!isEmptyT(left(actual))){
                SnocTL(faltanProcesar,left(actual));
            }
        }
    }
    LiberarTL(faltanProcesar);
    return altura;

}
