void DFS(graph * g) {
    for (int u = 0; u < g->num_vertices; u++) {
        g->v[u].color = WHITE;
        g->v[u].pred = NULL;
    }
    time = 0;
    for (int u = 0; u < g->num_vertices; u++) {
        if (g->v[u].color == WHITE) {
            DFSvisit(g, u); 
        }
    }
}

void DFSvisit(graph g, int u) {
    time = time + 1;
    g->v[u].dist = time;
    g->v[u].color = GRAY;

    for(edge *curr = g->[u].adj; curr != NULL; curr = curr->next) {
        int v = curr->vertex; 
        if (g->v[v].color == WHITE) {
            g->v[v].pred = u;
            DFSvisit(g, v);
        }
    }
    time++;
    g->v[u].f = time;
    g->v[u].color = BLACK;
}