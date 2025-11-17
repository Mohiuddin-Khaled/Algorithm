#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];
int level[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (int adjNode : adjList[head])
        {
            if (!visited[adjNode])
            {
                q.push(adjNode);
                visited[adjNode] = true;
            }
            level[adjNode] = level[head] + 1;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bfs(1);
    int levelNode;
    cin >> levelNode;
    cout << "Level of " << levelNode << " = " << level[levelNode];
    return 0;
}