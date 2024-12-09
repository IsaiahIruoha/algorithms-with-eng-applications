int BellmanFord(Graph *G, int s) {
    InitializeSingleSource(G, s);
    int u;
    for (int i = 0; i < G->num_vertices; i++) {
        for (Edge *e = G->v[i].adj; e != NULL; e = e->next) {
            u = e->vertex; 
            Relax(G,u,i, e->weight); 
        }
    }
    for (int i = 0; i < G->num_vertices; i++) {
        for(Edge *e = G->v[i].adj; e != NULL; e = e->next){
            u = e->vertex; 
            if (G->v[i].d > G ->v[u].d + e->weight) {
                return 0;
            }
        }
    }
    return 1;
}
void InitializeSingleSource(Graph *G, int s) {
    for (int i = 0; i < G->num_vertices; i++) {
        G->v[i].d = __INIT_MAX__;
        G->v[i].pred == NULL;
    }
    G->v[s].d = 0;
}
void Relax(Graph *G, int u, int v, int w) {
    if (G->v[v].d > G->v[u].d + w) {
        G->v[v].d = G->v[u].d + w;
        G->v[v].pred = u; 
    }
}