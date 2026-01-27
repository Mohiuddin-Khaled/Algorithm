// kruskal algorithm
/*
Procedure kruskalMST(G):
    - St ← ∅
    - Esorted ← sort_by_weight(G.E)
    - for i ← 1 to |G.V| do
        parent[i] ← i
    - for each edge (u, v) in Esorted
        - if dsu_find(u) ≠ dsu_find(v)
            - Union(u, v)
                - add (u, v) to St
    - return St
*/

// 3 steps:
//  - sorting
//  - cycle detect
//  - union operation