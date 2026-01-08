/*
Graph Input:
    4 4
    0 1 1
    1 2 -1
    2 3 -1
    3 0 -1

Graph Output:
    -2 -1 -2 -3
    -3 -2 -3 -4
    -2 -1 -2 -3
    -3 -2 -3 -4
*/

/*
Initialize

          0  1  2  3
         -----------
        0|0  1  ∞  ∞
D(0) =  1|∞  0 -1  ∞
        2|∞  ∞  0 -1
        3|-1 ∞  ∞  0


intermediate (k = 0)
    3 → 1 = 3 → 0 → 1 = −1 + 1 = 0

          0  1  2  3
         -----------
        0|0  1  ∞  ∞
D(1) =  1|∞  0 -1  ∞
        2|∞  ∞  0 -1
        3|-1 0  ∞  0


intermediate (k = 1)
    0 → 2 = 0 → 1 → 2 = 1 + (−1) = 0
    3 → 2 = 3 → 1 → 2 = 0 + (−1) = −1

          0  1  2  3
         -----------
        0|0  1  0  ∞
D(2) =  1|∞  0 -1  ∞
        2|∞  ∞  0 -1
        3|-1 0 -1  0


intermediate (k = 2)
    0 → 3 = 0 → 2 → 3 = 0 + (−1) = −1
    1 → 3 = 1 → 2 → 3 = −1 + (−1) = −2
    3 → 3 = 3 → 2 → 3 = −1 + (−1) = −2

          0  1  2  3
         -----------
        0|0  1  0 -1
D(3) =  1|∞  0 -1 -2
        2|∞  ∞  0 -1
        3|-1 0 -1 -2


intermediate (k = 3)
    0 → 0 = 0 → 3 → 0 = −1 + (−1) = −2
    1 → 1 = 1 → 3 → 1 = −2 + 0 = −2
    2 → 2 = 2 → 3 → 2 = −1 + (−1) = −2

           0  1  2  3
         ------------
        0|-2 -1 -2 -3
D(4) =  1|-3 -2 -3 -4
        2|-2 -1 -2 -3
        3|-3 -2 -3 -4

After simulation the values of   d[0][0] = -2,  d[1][1] = -2, d[2][2] = -2,  d[3][3] = -4

They are negative because,
    The graph contains a negative-weight cycle: 0 → 1 → 2 → 3 → 0 = −2

In Floyd Warshall Algorithm:
    # d[i][i] is the shortest path from node i back to itself
    # If a negative cycle is reachable from i, you can loop indefinitely to reduce cost
    # Hence, d[i][i]<0

Rule: If after Floyd Warshall any  d[i][i]<0, the graph has a negative cycle.

*/