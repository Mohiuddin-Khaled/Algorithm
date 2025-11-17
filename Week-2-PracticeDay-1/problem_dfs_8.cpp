#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];

bool dfs(int start, int target)
{
    visited[start] = true;
    for (auto adjNode : adjList[start])
    {
        if (adjNode == target)
            return true;
        if (visited[adjNode] == true)
        {
            continue;
        }
        dfs(adjNode, target);
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
    if (dfs(start, target))
        cout << "Connected!" << endl;
    else
        cout << "Not Connected!" << endl;
    return 0;
}
