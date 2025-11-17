#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
bool visited[N];
bool adjMat[N][N];
int n, m;

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int head = q.front();
        cout << head << " ";
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
            {
                continue;
            }
            if (adjMat[head][i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = true;
        adjMat[v][u] = true;
    }
    bfs(1);
    return 0;
}