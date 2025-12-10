/* Pseudocode of Dijkstra(Second Shortest Distance)---> Fibonacci Heap(Min Heap)
- create two distance array : dst1[], dst2[]
- for each node of v:
    - dst1[v] = +∞
    - dst2[v] = +∞
- dst1[src] = 0
- create min heap priority_queue pq
- pq.push(0, src)
- while pq is not empty:
    - dst, u = pq.top()
    - pq.pop()
    - if dst > dst2[u]
        - continue
    - for each edge(u, v, w)
        - newDst = dst + w
        - if newDst < dst1[v]
            - dst2[v] = dst1[v]
            - dst1[v] = newDst
            - pq.push(dst1[v], v) --> shortest distance
        - else if dist1[v] < newDist && newDist < dist2[v] --> second shortest distance
            - dst2[v] = newDst
            - pq.push(dst2[v], v)

- output dst1[]
- output second shortest distance dst2[]
- Time Complexity: O(E + V log V) -->(Min Heap)
- Space Complexity: O(E)
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 7;
vector<pii> g[N];
int dist1[N], dist2[N];
int n, m;

void dijkstra(int src)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 1; i <= n; i++)
    {
        dist1[i] = INT_MAX;
        dist2[i] = INT_MAX;
    }
    dist1[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist2[u])
            continue;
        for (auto edge : g[u])
        {
            int v = edge.first;
            int w = edge.second;

            int newDist = d + w;
            if (newDist < dist1[v])
            {
                dist2[v] = dist1[v];
                dist1[v] = newDist;
                pq.push({dist1[v], v});
            }
            else if (dist1[v] < newDist && newDist < dist2[v])
            {
                dist2[v] = newDist;
                pq.push({dist2[v], v});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int src = 1;
    dijkstra(src);
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << " second shortest = " << dist2[i] << "\n";
    }
}
