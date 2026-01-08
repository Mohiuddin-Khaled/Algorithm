/*
# Bellman–Ford simulation with five iterations, Assume A is the source vertex.

# Graph Edges:
    A → D (4)
    A → C (2)
    C → D (1)
    C → E (1)
    D → B (2)
    D → E (−1)
    E → B (3)

# Number of vertices n = 5 → 4 relaxations + 1 check iteration

# Bellman–Ford Iteration Table

|     Iteration       | A | B | C | D | E |
| ------------------- | - | - | - | - | - |
|   0  (Initialize)   | 0 | ∞ | ∞ | ∞ | ∞ |
|   1                 | 0 | ∞ | 2 | 4 | ∞ |
|   2                 | 0 | ∞ | 2 | 3 | 3 |
|   3                 | 0 | 5 | 2 | 3 | 2 |
|   4                 | 0 | 5 | 2 | 3 | 2 |
|   5 (Cycle Check)   | 0 | 5 | 2 | 3 | 2 |


#Final Answer
    Shortest distances from A:
    A = 0
    B = 5
    C = 2
    D = 3
    E = 2

# Negative cycle detection: No negative cycle present

Although the graph contains a negative edge (D → E = −1), it does not form a cycle.

Bellman–Ford successfully computes shortest paths, and no negative cycle exists in the given graph.

*/