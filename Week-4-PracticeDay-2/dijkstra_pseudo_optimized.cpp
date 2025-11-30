// Better Performance on Dense Graph

/*Pseudocode of Dijkstra
    - Create distance array 'd'
    - Initialize all values of 'd' to infinity(+) -> O(n)
    - d[src] = 0
    - Create a visited array and mark all node as unvisited -> O(n)
    - Take an empty max_heap priority_queue 'pq'
    - pq.push({0, src})
    - while the priority_queue is not empty: -> O(E)
        - neg_distance, head = pq.front()
        - pq.pop() -> O(log E)
        - head_distance = - neg_distance
        - if visited[head] == 1: Ignore
        - visited[head] = 1
        - for all adj_node of head: -> O(E)
            - if d[head] + c(head_distance, adj_node) < d[adj_node]:
                - d[adj_node] = d[head] + c(head_distance, adj_node)
                - pq.push({-d[adj_node], adj_node}) -> O(log E)
    - Output array 'd'

    - O(n) + O(E log E) + O(E log E)
    - O(|E| log |E|)
    - E => V^2
    - O(|E| log |V^2|)
    - O(2|E| log |V|)
    - O(|E| log |V|) [ log base 2 ]
    - Time Complexity: O(E log V) --> Binary Heap --> Max Heap <bigger to smaller>
    - Time Complexity: O(m log n) --> Binary Heap --> Max Heap
    - Space Complexity: O(E)
    - Space Complexity: O(m)
*/

// Time Complexity: O(m log n)
// Better Performance on Dense Graph
// Binary Heap --> Max Heap
// https://codeforces.com/problemset/problem/20/C
// n -> 10^5
// m -> 10^5
// w -> 10^6
// 10^6 * 10^5 -> 10^11
// O(E log V)

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 5;
// const long long int INF = 1e18;

// vector<pair<int, int>> adj_list[N];
// int visited[N];
// int parent[N];
// long long int d[N];
// int n, m;

// void dijkstra(int src)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         d[i] = INF;
//     }
//     d[src] = 0;
//     priority_queue<pair<long long int, int>> pq;
//     pq.push({0, src});
//     while (!pq.empty())
//     {
//         pair<long long int, int> head = pq.top();
//         pq.pop();
//         int selected_node = head.second;
//         if (visited[selected_node])
//             continue;
//         visited[selected_node] = 1;
//         for (auto adj_entry : adj_list[selected_node])
//         {
//             int adj_node = adj_entry.first;
//             int edge_cost = adj_entry.second;
//             if (d[selected_node] + edge_cost < d[adj_node])
//             {
//                 d[adj_node] = d[selected_node] + edge_cost;
//                 parent[adj_node] = selected_node;
//                 pq.push({-d[adj_node], adj_node});
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj_list[u].push_back({v, w});
//         adj_list[v].push_back({u, w});
//     }
//     int src = 1;
//     dijkstra(src);
//     if (visited[n] == 0)
//         cout << -1;
//     cout << d[n] << endl;
//     int current_node = n;
//     vector<int> path;
//     while (true)
//     {
//         path.push_back(current_node);
//         if (current_node == src)
//             break;
//         current_node = parent[current_node];
//     }
//     reverse(path.begin(), path.end());
//     for (int value : path)
//         cout << value << " ";
//     return 0;
// }

// Better Performance on Sparse Graph
// Optimized Dijkstra Module <smaller to bigger>
// Time Complexity : O(E + V log V)] --> Fibonacci Heap --> Min Heap
// Space Complexity: O(E)

// #include <bits/stdc++.h>
// using namespace std;
// typedef pair<int, int> pii;

// const int N = 1e5 + 5;
// vector<pair<int, int>> g[N];
// bool visited[N];
// int d[N];
// int n, m;

// void dijkstra(int src)
// {
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     pq.push({0, src});
//     d[src] = 0;
//     while (!pq.empty())
//     {
//         pii parent = pq.top();
//         pq.pop();
//         int parentNode = parent.second;
//         int parentCost = parent.first;
//         if (visited[parentNode])
//             continue;
//         visited[parentNode] = 1;
//         for (int i = 0; i < g[parentNode].size(); i++)
//         {
//             pii child = g[parentNode][i];
//             int childNode = child.first;
//             int childCost = child.second;
//             if (d[parentNode] + childCost < d[childNode])
//             {
//                 d[childNode] = d[parentNode] + childCost;
//                 pq.push({d[childNode], childNode});
//             }
//         }
//     }
// }
// int main()
// {
//     freopen("intput.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         d[i] = INT_MAX;
//     }
//     int src = 1;
//     dijkstra(src);
//     for (int i = 1; i <= n; i++)
//     {
//         cout << "Node " << i << ": " << d[i] << endl;
//     }
//     return 0;
// }

// Optimized Dijkstra Concept <smaller to bigger>
// Optimized Dijkstra Module
// Time Complexity : O(E + V log V)] --> Fibonacci Heap --> Min Heap
// Space Complexity: O(E)

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int N = 1e5 + 7;
vector<pii> g[N];
int dis[N];

void dijkstra(int src)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (distance > dis[node])
        {
            continue;
        }
        for (auto child : g[node])
        {
            int childNode = child.first;
            int childCost = child.second;
            int childDistance = distance + childCost;

            if (childDistance < dis[childNode])
            {
                dis[childNode] = childDistance;
                pq.push(make_pair(childDistance, childNode));
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    int src = 1;
    dijkstra(src);
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": " << dis[i] << endl;
    }
    return 0;
}
