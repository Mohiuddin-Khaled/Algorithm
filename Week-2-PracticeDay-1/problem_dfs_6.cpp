#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
bool adjMat[N][N]; // use less space
// int adjMat[N][N]; // use more space
bool visited[N];
int n, m;

void dfs(int node)
{
    cout << node << " ";
    visited[node] = true;
    for (int i = 0; i <= n; i++)
    {
        if (visited[i])
        {
            continue;
        }
        if (adjMat[node][i])
        {
            dfs(i);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = true;
        adjMat[v][u] = true;
    }
    dfs(1);
    return 0;
}

/*
    Time Complexity: O(n^2)
    Space Complexity: O(n^2) less
*/