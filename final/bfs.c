void BFS(graph *g, int s) {
    for (int u = 0; u < g->num_vertices; u++) {
        g->v[u].color = WHITE;
        g->v[u].dist = INF;
        g->v[u].pred = NULL; 
    }
    g->v[s].color = GRAY;
    g->v[s].dist = 0;
    g->v[s].pred = NULL;

    enqueue(Q, s);

    while (Q !empty) {
        int u = dequeue(Q);
        edge *curr = >v[u].adj;
        while (curr != NULL) {
            int v = curr->vertex; 
            if (g->v[v].color == WHITE) {
                g->v[v].dist = g->v[u].dist + 1;
                g->v[v].pred = u;
                enqueue(Q, v);
            }
            curr = curr->next;
        }
        g->v[u].color = BLACK;
    }
}