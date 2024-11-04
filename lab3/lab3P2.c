#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

/* declaration of function in library */
#define Create(HOW_MANY, TYPE) (TYPE *) calloc (HOW_MANY, sizeof (TYPE))


void DFS (Graph *g, int s);
void PrintGraph (Graph *g, int show_duplicate_edges);


/* fill in this function with the specified processing on the graph
   after the search has been performed */

void GraphProcessing (Graph *g, int s)
{
	for (int i = 0; i < g->num_vertices; i++){
		printf("%d:\n d = %d\n f = %d\n pred = %d\n", i, g->v[i].d, g->v[i].f, g->v[i].pred);
		if (i == s){
			printf("SOURCE VERTEX\n");
		}
	}
	
}


/* main routine that reads in text file describing a graph
   then performs search and subsequent processing */

int main (int argc, char *argv[])
{
   Graph *g;
   Vertex *v_array;
   
   g = Create (1, Graph);
   g->type = UNDIRECTED;
   g->num_vertices = 3;
   g->num_edges = 0;
   
   v_array = Create (g->num_vertices, Vertex);
 
   g->v = v_array;
  
   for (int i = 0; i < g->num_vertices; i++){
	   g->v[i].weight = 0;
        g->v[i].color = 0;
        g->v[i].d = 0;
        g->v[i].f = 0;
        g->v[i].pred = -1; 
        g->v[i].adj = NULL; 
        g->v[i].x = 0; 
        g->v[i].y = i;
   }
   
    for (int i = 0; i < g->num_vertices; i++)
    {
        for (int j = i + 1; j < g->num_vertices; j++)
        {
            Edge *new_edge = Create(1, Edge);
            new_edge->vertex = i;
            new_edge->other_vertex = j;
			new_edge->weight = i + j;
            new_edge->next = g->v[i].adj;
            g->v[i].adj = new_edge;

            new_edge = Create(1, Edge) ;
            new_edge->vertex = j;
            new_edge->other_vertex = i;
			new_edge->weight = j + i;
            new_edge->next = g->v[j].adj;
            g->v[j].adj = new_edge;

            g->num_edges += 2; 
        }
    }

    PrintGraph(g, 1);

   return 0;
}

void PrintGraph (Graph *g, int show_duplicate_edges)
{
   int i;
   Edge *p;

   printf ("graph has %d vertices and %d edges\n", g->num_vertices, g->num_edges);
   printf ("list of edges:\n");
   for (i = 0; i < g->num_vertices; i++){
      for (p = g->v[i].adj; p!= NULL; p = p->next){
         if ((g->type == UNDIRECTED) && (show_duplicate_edges == 0) && (p->other_vertex < p->vertex))
            continue;
         else
            printf ("(%d, %d) %d\n", p->vertex, p->other_vertex, p->weight);
      }
   }
}