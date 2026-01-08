/* Pseudocode of Floyd Warshall

- Input: A weighted graph as an adjacency matrix
- Output: All pair shortest distance

- Create a distance matrix 'd' where d[i][j] = x where there is direct
    edge from node 'i' to node 'j' and the cost is 'x' --> O(v^2)
- for all node 'i' d[i][i] = 0
- for all nodes 'i' & 'j' where there isn't any direct edge from 'i' to 'j'
    d[i][j] = INF
- for all node 'k' - O(n)
    - for all node 'u' - O(n)
        - for all node 'v' - O(n)
            - d[u][v] = min(d[u][v], d[u][k] + d[k][v]) - O(1)

- output all pair shortest distance 'd'

*** Time Complexity: O(v^3) -> O(n^3)
** Space Complexity: O(v^2) -> O(n^2)

*/