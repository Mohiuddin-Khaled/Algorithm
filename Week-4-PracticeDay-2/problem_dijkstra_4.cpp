// https://cses.fi/problemset/task/1672

#include <bits/stdc++.h>
using namespace std;
typedef pair<long long int, int> pii;

const int N = 1e3 + 5;
vector<pair<int, int>> g[N];
bool visited[N];
int d[N];
int n;
long long int m;

void dijkstra(int src)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (distance > d[node])
            continue;
        for (auto adj_entry : g[node])
        {
            int childNode = adj_entry.first;
            int childCost = adj_entry.second;
            int childDistance = childCost + distance;
            if (childDistance < d[childNode])
            {
                d[childNode] = childDistance;
                pq.push(make_pair(childDistance, childNode));
            }
        }
    }
}

int main()
{
    int x;
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    fill(d, d + n + 1, INT_MAX);
    vector<int> path;
    int src, dst;
    while (x--)
    {
        cin >> src >> dst;
        fill(visited, visited + n + 1, false);
        fill(d, d + n + 1, INT_MAX);
        dijkstra(src);
        if (d[dst] == INT_MAX)
            path.push_back(-1);
        else
            path.push_back(d[dst]);
    }
    for (int value : path)
        cout << value << " ";
    return 0;
}
