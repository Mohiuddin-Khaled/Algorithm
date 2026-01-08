/* Pseudocode of path printing negative cycle
****
    u ----> v
    d[u] + c(u, v) < d[v]
        - d[v] = d[u] + c(u, v)
****
- Input: A weighted graph and src node(with no negative cycle) & a destination node
- Output: Shortest distance from src node to all other nodes
- create a parent array --> O(n)
- create a distance array 'd' with all values to infinity --> O(n)
- d[src] = 0
- negative_cycle = false
- last_updated_node = - 1
- for i = 1 to n: --> O(n)
    - for all edge(u, v, w): --> O(m)
        - // relaxation: O(n * m)
        - if d[u] + c(u, v) < d[v]: --> O(1)
            - d[v] = d[u] + c(u, w) --> O(1)
            - parent[v] = u --> O(1)
            - if i == n:
                - negative_cycle = true
                - last_updated_node = v

- if negative_cycle == false: -> O(n)
    - print the distance array 'd'
    - selected_node = destination_node
    - declare a vector path
    - while true: --> O(n)
        - path.push_back(selected_node)
        - if selected_node == src
            - break
        - selected_node = parent[selected_node]
    - reverse the vector path
    - print the path
- else: --> O(n) + O(n) = O(n)
    - print negative cycle exists
    - selected_node = last_updated_node
    - for i = 1 to n - 1: --> O(n)
        - selected_node = parent[selected_node]
    - first_node = selected_node
    - declare a vector cycle
    - cycle.push_back(selected_node)
    - while true: --> O(n)
        - selected_node = parent[selected_node]
        - cycle.push_back(selected_node)
        - if selected_node == last_updated_node:
            - break
    - reverse the cycle vector
    - print the cycle
****
- n -> number of nodes in graph
- m -> number of edges in graph
- O(n) + O(n) + O(n * m) + O(1) + O(1) + O(1) + O(n) + O(n) + O(n)
- Time Complexity: O(n * m)
- Space Complexity: O(n)
****
*/