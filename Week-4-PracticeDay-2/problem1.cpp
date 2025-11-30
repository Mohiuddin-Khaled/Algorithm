// Module 10.5: Practice Day 01
//  (Practice Questions)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

vector<pair<int, int>> adj_list[N];
int visited[N];
int parent[N], d[N];
int n, m;

void dijkstra(int src)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }
    d[src] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        pair<int, int> head = pq.top();
        pq.pop();
        int selected_node = head.second;
        if (visited[selected_node])
            continue;
        visited[selected_node] = 1;
        for (auto adj_entry : adj_list[selected_node])
        {
            int adj_node = adj_entry.first;
            int edge_cost = adj_entry.second;
            if (d[selected_node] + edge_cost < d[adj_node])
            {
                d[adj_node] = d[selected_node] + edge_cost;
                parent[adj_node] = selected_node;
                pq.push({-d[adj_node], adj_node});
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
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }
    int src, dst;
    cin >> src >> dst;
    dijkstra(src);
    if (visited[n] == 0)
        cout << -1;
    cout << d[dst] << endl;
    int current_node = dst;
    vector<int> path;
    while (true)
    {
        path.push_back(current_node);
        if (current_node == src)
            break;
        current_node = parent[current_node];
    }
    reverse(path.begin(), path.end());
    for (int value : path)
    {
        // cout << value << " ";
    }
    return 0;
}