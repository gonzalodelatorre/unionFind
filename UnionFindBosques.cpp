#include <stdio.h>
#include <stdlib.h>

/*

Imprementaci�n Union-Find para Bosques.

*/

// Estructura
struct elem_data {
    void *data;
    struct elem_data *leader;
    int rank;
};
typedef struct elem_data element;

// Cabeceras (Al pedo)
element* makeSet (void *);
element* find (element *);
void setUnion (element *, element *);


// makeSet()
// Recibe algo, devuelve un puntero a element
element* makeSet (void *data)
{
    // Creo un puntero a element, inicializo a NULL
    element *retVal = NULL;
    // Pido espaciom devuelvo un puntero, se lo asigno. No es m�s NULL
    retVal = (element *)malloc(sizeof(element));
    // Le asigno el dato.
    retVal->data = data;
    // Le asigno un rango igual a cero.
    retVal->rank = 0;
    // Apunta a si mismo, REPRESENTANTE.
    retVal->leader = retVal;
    // Devuelvo el puntero.
    return retVal;
}

// find()
// Recibe un puntero a element, devuelve un puntero a element
element* find (element *e)
{
    // Busco el representante, si no est� al inicio...
    if (e != e->leader)
        e->leader = find(e->leader);
    // Devuelvo el representante.
    return e->leader;
}

// setUnion()
// Recibe dos elements. No devuelve nada.
void setUnion (element *x, element *y)
{
     // Busco representante de x
    element *leaderX = find(x);
     // Busco representante de y
    element *leaderY = find(y);
    // Si el representante de x tiene mayor rango
    if (leaderX->rank > leaderY->rank)
        // Hago esta asignaci�n
        leaderY->leader = leaderX;
    else {
        // Si no hago esta asignaci�n
        leaderX->leader = leaderY;
        // Si tienen el mismo rango, hago esto.
        // El rango se incrementa en uno.
        if (leaderX->rank == leaderY->rank)
            ++(leaderY->rank);
    }

    return;
}

int main (void)
{
    return 0;
}
