#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "queue.h"

#define Create(HOW_MANY, TYPE) (TYPE *) calloc (HOW_MANY, sizeof (TYPE))

#define WHITE 0 //undiscovered
#define GRAY 1 //discovered
#define BLACK 2 //visited

/* declaration of function in library */

void BFS (Graph *g, int s);
void PrintGraph (Graph *g, int show_duplicate_edges);

/* fill in this function with the specified processing on the graph
   after the search has been performed */

void GraphProcessing (Graph *g, int s)
{
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

      BFS (g, s);

      GraphProcessing (g, s);
   }

   return 0;
}

void BFS (Graph *g, int s)
{
   int i;
   Vertex *u;
   Edge *p;
   Queue *q;

   for (i = 0; i < g->num_vertices; i++)
   {
      u = &g->v[i];
      u->color = WHITE;
      u->d = -1;
      u->pred = -1;
   }

   u = &g->v[s];
   u->color = GRAY;
   u->d = 0;
   u->pred = -1;

   q = CreateQueue (g->num_vertices);
   Enqueue (q, s);

   while (!IsEmpty (q))
   {
      i = Dequeue (q);
      u = &g->v[i];
      for (p = u->adj; p != NULL; p = p->next)
      {
         if (g->v[p->other_vertex].color == WHITE)
         {
            g->v[p->other_vertex].color = GRAY;
            g->v[p->other_vertex].d = u->d + 1;
            g->v[p->other_vertex].pred = i;
            Enqueue (q, p->other_vertex);
         }
      }
      u->color = BLACK;
   }

   DisposeQueue (q);
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
            printf ("(%d, %d) ", p->vertex, p->other_vertex);
      }
   }
}
