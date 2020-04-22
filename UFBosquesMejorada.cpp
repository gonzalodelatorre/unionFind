#include <stdio.h>
#include <stdlib.h>

/*

Imprementación Union-Find para Bosques.

*/

// Estructura
struct elem_data {
    char data;
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
element* makeSet (char data)
{
    // Creo un puntero a element, inicializo a NULL
    element *retVal = NULL;
    // Pido espaciom devuelvo un puntero, se lo asigno. No es más NULL
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
    // Busco el representante, si no está al inicio...
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
    if (leaderX->rank > leaderY->rank){
        // Hago esta asignación
        leaderY->leader = leaderX;
        }
    else {
        // Si no hago esta asignación
        leaderX->leader = leaderY;
        // Si tienen el mismo rango, hago esto.
        // El rango se incrementa en uno.
        if (leaderX->rank == leaderY->rank) {
            ++(leaderY->rank);
      }
    }

   
}

int main (void)
{
    // Primer árbol
    element * elemC = makeSet('C');   
    //elemC -> rank = 10;
    element * elemH = makeSet('H');
    elemH -> leader = elemC;
    element * elemE = makeSet('E');
    elemE -> leader = elemC;
    element * elemB = makeSet('B');   
    elemB -> leader = elemH;
    // Segundo árbol
    element * elemF = makeSet('F');
    //elemF -> rank = 9;
    element * elemD = makeSet('D'); 
    elemD -> leader = elemF;
    element * elemG = makeSet('G');
    elemG -> leader = elemD;
  /*  
    // Primer prueba. Uno mayor que el otro.
    elemC -> rank = 8;
    elemF -> rank = 9;
    setUnion (elemC,elemF);
    
    // Me duelve el representante. Si cambio elemX por cualquiera
    // Siempre devuelve F
    char result = find(elemD) -> data;
    printf("%c \n",result);
  */  
   /* 
    // Segunda prueba. Uno mayor que el otro.
    elemC -> rank = 10;
    elemF -> rank = 9;
    setUnion (elemC,elemF);
    
    // Me duelve el representante. Si cambio elemX por cualquiera
    // Siempre devuelve C
    char result = find(elemB) -> data;
    printf("%c \n",result);
    */
    
    
    // Tercera prueba. Mismo rango.
    // Hace lo mismo que el 2° caso, pero incrementa el rango
    elemC -> rank = 3;
    elemF -> rank = 3;
    setUnion (elemC,elemF);
    
    // Me duelve el representante. Si cambio elemX por cualquiera
    // Siempre devuelve F
    // Aumenta el rango en uno.
    char result = find(elemD) -> data;
    int rank = find(elemD) -> rank;
    printf("%c \n",result);
    printf("%d \n",rank);
    
    system("pause");
    return 0;
}
