
/*  INV.REP:
     * NO existen dos nodos con un mismo value
     * La Ronda de puede recorrer desde el nodo actual a traves de prev o next, hasta llegar al nodo actual
    OBS:
     * Si hay un solo elemento,su next y prev apuntan a si mismo
     * No existe el caso donde next y prev son nulos
*/
struct RondaNode
{
    int value;
    RondaNode *next;
    RondaNode *prev;
};

// obs: si current = NULL la ronda esta vacia
struct RondaStr
{
    RondaNode *current;
};

struct RondaStr;
typedef RondaStr *Ronda; // El puntero Ronda no es NULL

Ronda mkRonda()
{
    RondaStr *ronda = new RondaStr;
    ronda->current = nullptr;
    return ronda;
}

int current(Ronda ronda)
{
    return ronda->current->value;
}

void move(int pos, Ronda ronda)
{
    if (ronda->current == nullptr)
    {
        return;
    }
    if (pos > 0)
    {
        for (int i = 0; i < pos; i++)
        {
            ronda->current = ronda->current->next;
        }
    }
    else
    {
        for (int i = 0; i > pos; i--)
        {
            ronda->current = ronda->current->prev;
        }
    }
}

// que inserta un elemento como el nuevo elemento actual de la ronda dada. Si la ronda ya tiene elementos, el anterior valor actual se mueve a la posición previa.
void insert(int value, Ronda ronda)
{
    if (ronda->current == nullptr)
    {
        RondaNode *node = new RondaNode;
        node->value = value;
        node->next = node;
        node->prev = node;
        ronda->current = node;
    }
    else
    {

        if (ronda->current->value != value)
        {
            RondaNode *actual = ronda->current;
            ronda->current = ronda->current->next;
            bool found = false;

            while (ronda->current != actual && !found)
            {
                found = ronda->current->value == value;
                ronda->current = ronda->current->next;
            }

            if (found)
            {
                ronda->current = actual;
            }
            else
            {
                RondaNode *node = new RondaNode;
                node->value = value;
                node->next = ronda->current->next;
                node->prev = ronda->current;

                ronda->current->next = node;
                //ronda->current->next->prev = node;
                node->next->prev=node;
                ronda->current = node;
            }
        }else{
            error "No puedo agregar un valor que ya existe"
        }
    }
    /*
    ANALIZAR COSTOS:
     * OPERACIONAL:
        N(cantidad de elementos en la ronda recorriendo desde el current hasta el prev del current)
        dos accesos (1)
        una comparaion (1)
        creo nodo (1)
        3 accesos (1)
        creacion de variable (1)
        N*(dos accesos
        una comparacion
        3 acessos) N*(1)
        creo un puntero
        muchos accesos (1)
        = O(N)
     * EN MEMORIA DINAMICA(HEAP):
        tengo memoria guardada para la ronda y el value
        guardo espacio para un nodo (1) tamaño fijo, constante
        =O(1)
     * EN MEMORIA ESTATICA(STACK FRAME):
        tengo memoria guardada para un puntero a la ronda y al   value
        reservo memoria para un puntero(actual)  
        reservo memoria para un puntero al nodo (node).  
        4*(1)  
        =O(1)
     */
}

int length(Ronda ronda)
{
    int count = 0;

    if (ronda->current != nullptr)
    {
        RondaNode *actual = ronda->current;
        ronda->current = ronda->current->next; // preguntar si tenemos que usar el mismo current para recorrer la ronda o hay que crearse otro puntero y usarlo como iterador para recorrer?
        // nota: el current termina donde estaba parado inicialmente, no rompe el inv

        while (ronda->current != actual)
        {
            count++;
            ronda->current = ronda->current->next;
        }
        count++;
    }

    return count;
}

// que, suponiendo de que la lista no está vacía, remueve el elemento actual, moviendo el valor anterior a la posición actual. Si la lista está vacía, no hace nada
void remove(Ronda ronda)
{
    if (ronda->current == nullptr)
        return;

    RondaNode *previo = ronda->current->prev;
    RondaNode *posterior = ronda->current->next;
    RondaNode *tmp = ronda->current; // quiero deletearlo

    // hay un solo nodo
    if (tmp == previo) // o posterior, es lo mismo
        ronda->current = nullptr;
    else
    {
        previo->next = posterior;
        posterior->prev = previo;
        ronda->current = previo;
    }

    delete tmp;
}

// USUARIO DE RONDA REDONDA:

// que construye una array con todos los valores de la ronda dada
int *toArray(Ronda ronda)
{
    int len = length(ronda);
    int *array = new int[len];

    for (int i = 0; i < len; i++)
    {
        array[i] = current(ronda);
        move(1, ronda);
    }

    return array;
}

// que construye una ronda con todos los valores del array dado. El elemento actual del resultado debe ser el primer elemento del array dado
Ronda fromArray(int len, int *toArray)
{
    Ronda ronda = mkRonda();

    for (int i = 0; i < len; i++)
    {
        insert(toArray[i], ronda);
    }
    move(1, ronda);

    return ronda;
}

/*
ANALIZAR COSTOS:
 * OPERACIONAL
 * EN MEMORIA DINAMICA(HEAP)
 * EN MEMORIA ESTATICA(STACK FRAME)
*/
