/* pseudocode for negative cycle
- Input: A weighted graph and src node(with no negative cycle)
- Output: Shortest distance from src node to all others nodes
- Create distance array 'd' with all values to infinity
- negative_cycle = false
- for i = 1 to n:
    - for all edge e(u, v, w):
        - if d[u] + w < d[v]:
            - d[v] = d[u] + w
            - if i == n:
                - negative_cycle = true
- print whether negative cycle exists
- print the distance array 'd'
*/
