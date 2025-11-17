#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];

bool bfs(int start, int target)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int head = q.front();
        if (head == target)
        {
            return true;
        }
        q.pop();
        for (int adjNode : adjList[head])
        {
            if (!visited[adjNode])
            {
                q.push(adjNode);
                visited[adjNode] = true;
            }
        }
    }
    return false;
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

    int start, target;
    cin >> start >> target;

    if (bfs(start, target))
    {
        cout << "Connected!" << endl;
    }
    else
    {
        cout << "Not Connected!" << endl;
    }
    return 0;
}