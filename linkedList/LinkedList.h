struct LinkedListSt;
typedef LinkedListSt* LinkedList; // INV.REP.: el puntero NO es NULL

struct IteratorSt;
typedef IteratorSt* ListIterator; // INV.REP.: el puntero NO es NULL

LinkedList nil();
bool isEmpty(LinkedList xs);
int head(LinkedList xs); // parcial
void Cons(int x, LinkedList xs);
void Tail(LinkedList xs); // parcial
int length(LinkedList xs);
void Snoc(int x, LinkedList xs);
void DestroyL(LinkedList xs);

ListIterator getIterator(LinkedList xs);
int current(ListIterator ixs);
void SetCurrent(int x, ListIterator ixs);
void Next(ListIterator ixs);
bool atEnd(ListIterator ixs);
void DisposeIterator(ListIterator ixs);