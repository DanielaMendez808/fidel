struct BosqueStr;
typedef BosqueStr* Bosque;

Bosque mkBosque();  
bool isEmpty(Bosque b);
int current(Bosque b);         // PRE: no vacío
void moveLeft(Bosque b);       // PRE: hijo izq no vacío
void moveRight(Bosque b);      // PRE: hijo der no vacío
void moveUp(Bosque b);         // PRE: no está en raíz
void insertLeft(int id, Bosque b);
void insertRight(int id, Bosque b);
void removeCurrent(Bosque b);  // Borra el nodo actual y sube el cursor al padre
int size(Bosque b);


struct Nodo {
    int value;
    Nodo* left;
    Nodo* right;
    Nodo* parent;
};
struct BosqueStr {
    Nodo* root;
    Nodo* current;
};

