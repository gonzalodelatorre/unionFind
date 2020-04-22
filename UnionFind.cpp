#include <stdlib.h>
#include <errno.h>

#include <time.h>
#include <stdio.h>

// http://decsai.ugr.es/~jfv/ed1/tedi/cdrom/docs/Ejer_AG.htm

struct nodeStruct {
	int element;
	int rank;
	struct nodeStruct *parent;
};

typedef struct nodeStruct node;

// link()
// Lo mismo que setUnion()
void link(node *rx, node *ry) {
	if(rx->rank > ry->rank) {
		ry->parent = rx;
	}
	else {
		rx->parent = ry;
		if(rx->rank == ry->rank) {
			ry->rank++;
		}
	}
}
// Variable
int visitedNodes = 0;
// Cabecera
node *findAux(node *, node *);

  node * find(node *x) {
	return findAux(x,x);
}

// orig es el nodo del que hicimos el find original
// (ver llamada a findAux arriba)
node *findAux(node *x, node *orig) {
	visitedNodes++;
	if(x != x->parent) {
		node *newParent = findAux(x->parent,orig);
		x->parent = newParent;
	}
	return x->parent;
}

void setUnion(node *x, node *y) {
	node *rx = find(x);
	node *ry = find(y);
	if(rx != ry) {
		link(rx,ry);
	}
}

int main() {
	
	srand(time(NULL));


	
	// Elementos
	int n = 20;
	// Operaciones Union
    int u = 4;
    // Operaciones Find
	int finds = 10;
	
	// Nodo tamaño n, en mi caso 20
	node *nodes = (node *) malloc(n * sizeof(node));
    // Creo n nodos.
	for(int i = 0; i < n; i++) {
		nodes[i].element = i;
		nodes[i].parent = &(nodes[i]);
		nodes[i].rank = 0;
	}
     // Hago u uniones
	for(int i = 0; i < u; i++) {
	   printf("ITERACION NUMERO: %d\n",i);	
       int n1 = rand()%n;
       printf("NRO RANDOM: %d\n", n1);
       int n2 = rand()%n;
       printf("NRO RANDOM: %d\n", n2);		
       setUnion(&(nodes[n1]),&(nodes[n2]));
       // Hay que hacer un find de algunos de los nodos.
       //printf("RANGO: ");	
       // una funcion que calcule desde el find la altura del arbol
       // la cantidad de nodos
 
 }
     // Hago finds find.
	for(int i = 0; i < finds; i++) {
		int n1 = rand()%n;
		find(&(nodes[n1]));
	}
	// Imprime el núumero de nodos visitados en operaciones find.
	printf("Nodos visitados: %d\n", visitedNodes);
	system("pause");
    return 0;
}

