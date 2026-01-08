/* Pseudocode of Bellman-Ford
- Input: A weighted graph & a src node(with no negative cycles)
- Output: Shortest distance from src node to all other nodes
- Create a distance array 'd' with all values to infinity --> O(n) -> O(n)
- d[src] = 0 --> O(1)
- for i = 1 to n-1: --> O(n)
    - for all edge e(u, v, w): --> O(m)
        - // relaxation --> O(n * m)
        - if d[u] + c(u, v, w) < d[w]: --> O(1)
            - d[v] = d[u] + c(u, v, w) --> O(1)
- Print the distance array 'd' --> O(n)

- n : number of nodes in graph
- m : number of edges in graph
- O(n) + O(1) + O(n * m) + O(n)
- O(n * m)
- O(|E| + |V|)
- Time Complexity: O(n * m)
- Space Complexity: O(n)

- Worst Case: O(n^3) --> m = n^2
- Average Case: O(n^2) --> n = n, m = n
*/

/* Pseudocode of Bellman Ford Algorithm
- BellmanFord(G,V, E, S)
    - for each vertex v ∈ G do: --> O(V) (step 1)
        - dist[v] = INF
        - dist[S] = 0

    - for i = 1 to |v| - 1: --> O(V * E) (step 2)
        - for each edge (u, v) ∈ G:
            - Relax(u, v, w)

    - for each edge (u, v) ∈ G: --> (step 3)
        - if (dist[u] + w(u, v) < dist[v])
            - return "Graph contain negative weight cycle"

    - return distance
*/

// Pseudocode & Complexity
/* Pseudocode of Bellman Ford
- input: A weighted graph and a src node(with no negative cycles)
- output: shortest distance from src node to all other nodes

- create a distance array 'd' with all values to infinity --> O(n)
- d[src] = 0
- for i = 1 to n - 1:
    - for all edge e(u, v, w):
        - // relaxation
        - if d(u) + w < d(v):
            - d(v) = d(u) + w
- print the distance array 'd'

--> Time Complexity: O(n * m) // best case
--> Space Complexity: O(n)
-- Average Case: Time Complexity: O(n^2) => m = n
- Worse Case: Time Complexity: O(n^3) => m = n^2
*/