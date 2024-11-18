#include "stdio.h"
#include "graph.h"

#define MAX 99999999

void Relax(Graph *g, Edge *e, int *flag_ptr){
	
	if ((g->v[e->vertex].d != MAX) && (g->v[e->other_vertex].d > g->v[e->vertex].d + e->weight)){
		printf("\tvertex %d estimate changed frm %d to %d\n", e->other_vertex, g->v[e->other_vertex].d, g->v[e->vertex].d + e->weight);
		g->v[e->other_vertex].d = g->v[e->vertex].d + e->weight;
		g->v[e->other_vertex].pred = e->vertex;
		*flag_ptr = 1;
		
	}
}

