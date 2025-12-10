#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int N = 16 * 1e3;
vector<pii> adj[N];
int d[N], n, m, t;

void dijkstra(int src)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++)
    {
        d[i] = INT_MAX;
    }
    d[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty())
    {
        int dist = pq.top().first, u = pq.top().second;
        pq.pop();
        if (dist != d[u])
            continue;
        for (pii adj_node : adj[u])
        {
            int v = adj_node.first, w = adj_node.second;
            int childCost = max(dist, w);
            if (childCost < d[v])
            {
                d[v] = childCost;
                pq.push(make_pair(childCost, v));
            }
        }
    }
}

int main()
{
    cin >> t;
    for (int test = 1; t >= test; test++)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        int src;
        cin >> src;
        dijkstra(src);
        cout << "Case " << test << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            if (d[i] == INT_MAX)
                cout << "Impossible" << endl;
            else
                cout << d[i] << endl;
        }
    }
    return 0;
}