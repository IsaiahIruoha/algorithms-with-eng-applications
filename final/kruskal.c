// Sort the edges in non-decreasing order of weight
Edge *sortedEdges = SORT_EDGES(g->edges, g->num_edges); // Assume SORT_EDGES sorts and returns a pointer

for (int i = 0; i < g->num_edges; i++) {
    int u = sortedEdges[i].vertex;        // First vertex of the edge
    int v = sortedEdges[i].other_vertex;  // Second vertex of the edge

    // Check if u and v are in different sets to avoid cycles
    if (FIND_SET(u) != FIND_SET(v)) {
        // Add edge (u, v) to the MST
        ADDTOMST(u, v);

        // Merge the sets of u and v
        UNION(u, v);
    }
}