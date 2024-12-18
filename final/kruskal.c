// Assume edges are already sorted in non-decreasing order of weight
Edge *sortedEdges = g->edges; // Pointer to the graph's edge list

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