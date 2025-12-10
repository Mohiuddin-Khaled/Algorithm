/*
|   Step   |  Node  | Dist A | Dist B | Dist C | Dist D | Dist E |
|:--------:| :----: | :----: | :----: | :----: | :----: | :----: |
|        0 |    —   |    0   |    ∞   |    ∞   |    ∞   |    ∞   |
|        1 |    A   |    0   |    ∞   |    3   |    ∞   |   −9   |
|        2 |    E   |    0   |    ∞   |    3   |   −4   |   −9   |
|        3 |    D   |    0   |   −2   |   −8 |     −4   |   −9   |
|        4 |    C   |    0   |   −2   |   −8   |   −4   |   −9   |
|        5 |    B   |    0   |   −2   |   −8   |   −4   |   −9   |

why?
Dijkstra requires all edge weights ≥ 0. 
This graph has negative edges (A---E = −9 and C---D = −4) and a reachable negative cycle 
A --> E --> D --> C --> A whose total weight is −9 + 5 + (−4) + 3 = −5. 
Because you can loop that cycle and make path cost arbitrarily smaller, 
there is no finite shortest path from A to B. 
Dijkstra finalizes nodes and never revisits them, 
so it cannot handle negative edges or detect negative cycles.
*/