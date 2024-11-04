#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

/* declaration of function in library */

void DFS (Graph *g, int s);



/* fill in this function with the specified processing on the graph
   after the search has been performed */

void GraphProcessing (Graph *g, int s)
{
	for (int i = 0; i < g->num_vertices; i++){
		printf("%d: d = %d f = %d pred = %d\n", i, g->v[i].d, g->v[i].f, g->v[i].pred);
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
   int s;
  
   if (argc != 3)
   {
      printf ("usage: %s <graph_file> <source_vertex>\n", argv[0]);
      return 1;
   }

   g = ReadGraphFile (argv[1]);

   if (g != NULL)
   {
      s = atoi (argv[2]);
      if (s < 0 || s > g->num_vertices - 1)
      {
         printf ("source vertex ID must be between 0 and %d\n",
		 g->num_vertices - 1);
	 return 1;
      }

      DFS (g, s);

      GraphProcessing (g, s);
   }

   return 0;
}

