/*
Yes, Bellman–Ford works on unweighted graphs.

An unweighted graph can be treated as a weighted graph where every edge has weight 1 (or any equal constant).
Bellman–Ford does not require varying weights;
it only requires numeric edge weights and supports negative weights as well.

Therefore, Bellman–Ford will correctly compute shortest paths in an unweighted graph
once all edges are assigned weight 1.

Although Bellman–Ford works, it is not efficient for unweighted graphs:

Bellman–Ford time complexity: O(V * E)

Breadth-First Search (BFS) time complexity: O(V + E)

For unweighted graphs, BFS is preferred because it is faster and simpler.

Bellman–Ford does work on unweighted graphs.
It is correct but inefficient compared to BFS, which is the optimal choice for unweighted graphs.

*/