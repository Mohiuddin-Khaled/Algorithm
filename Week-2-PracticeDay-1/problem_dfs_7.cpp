#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];
int checked[N];

void dfs(int node)
{
    visited[node] = true;
    for (int adjNode : adjList[node])
    {
        checked[adjNode]++;
        if (visited[adjNode])
        {
            continue;
        }
        dfs(adjNode);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    dfs(0);
    for (int i = 0; i <= n; i++)
    {
        cout << "Node of " << i << ": " << checked[i] << " times!" << endl;
    }
    return 0;
}