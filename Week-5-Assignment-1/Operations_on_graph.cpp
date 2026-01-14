// problem link: https://vjudge.net/problem/EOlymp-2472

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> adj[N];
    while (k--)
    {
        int ops;
        cin >> ops;
        if (ops == 1)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else
        {
            int u;
            cin >> u;
            for (int node : adj[u])
            {
                (node) ? cout << node << " " : cout << " ";
            }
        }
    }
    return 0;
}