/*
Procedure PRIMS(s): -> O(V + E log E) -> edge-based heap
     - create an empty priority_queue pq      // min-heap ordered by edge weight
     - create an empty list edgeList
     - pq.push(Edge(s, s, 0))
     - while pq is not empty:
         - parent ← pq.top()
         - pq.pop()
         - a ← parent.a
         - b ← parent.b
         - w ← parent.w
         - if vis[b] = true:
             - continue
         - vis[b] ← true
         - edgeList.append(parent)
         - for each (child, weight) in V[b]:
             - if vis[child] = false:
                 - pq.push(Edge(b, child, weight))
     - remove first element from edgeList
     - for each edge in edgeList
         - output edge.a, edge.b, edge.w
*/

/*
Procedure PRIMS(G, s):  -> O(V + E log V)   -> vertex-based heap
    - for each vertex v in G:
        - vis[v] ← false
    - pq ← empty priority queue     // min-heap ordered by edge weight
    - vec ← empty list of edges
    - insert (s, s, 0) into pq
    - while pq is not empty:
        - (a, b, cost) ← extract-min(pq)
        - if vis[b] = true:
            - continue
        - vis[b] ← true
        - add (a, b, cost) to vec
        - for each edge (b, v) with weight w in G.adj[b]:
            - if vis[v] = false:
                - insert (b, v, w) into pq
    - remove the first edge from vec
    - return vec
*/