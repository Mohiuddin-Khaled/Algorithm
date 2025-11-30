#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int adj[N][N];  // space: O(n*n)
int parent[N];  // space: O(n)
int level[N];   // space: O(n)
int visited[N]; // space: O(n)

void bfs(int src, int n)
{
    queue<int> q; // space: O(n)
    visited[src] = 1;
    parent[src] = -1;
    level[src] = 1;
    q.push(src);
    while (!q.empty()) // time: O(n)
    {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++) // time: O(n)
        {
            if (adj[u][v] == 1 && !visited[v])
            {
                visited[v] = 1;
                parent[v] = u;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) // time: O(m)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // u ---> v = 1
        adj[v][u] = 1; // v ---> u = 1
    }

    int src, dst;
    cin >> src >> dst;

    bfs(src, n);

    vector<int> path; // space: O(n)
    int curr = dst;
    while (curr != -1) // time: O(n)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    cout << level[curr] << endl;
    for (int value : path) // time: O(n)
        cout << value << " ";
    return 0;
}

/*
    Time Complexity: O(n^2) --> worst case complexity
    Space Complexity: O(n^2)
*/