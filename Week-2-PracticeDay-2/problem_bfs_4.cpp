#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];
int checked[N];

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (int adjNode : adjList[head])
        {
            checked[adjNode]++;
            if (visited[adjNode])
            {
                continue;
            }
            q.push(adjNode);
            visited[adjNode] = true;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Checked of Node " << i << ": " << checked[i] << " times!" << endl;
    }
    return 0;
}