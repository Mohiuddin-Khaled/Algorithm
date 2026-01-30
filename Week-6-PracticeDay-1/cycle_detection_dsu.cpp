// dsu properly work in undirected graph
// dsu detect cycle in  graph

#include <bits/stdc++.h>
using namespace std;

int parent[1000], parentLevel[1000];

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentLevel[i] = 0;
    }
}

int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}

// optimized approach
// int dsu_find(int u)
// {
//     if (u == parent[u])
//         return u;
//     return parent[u] = dsu_find(parent[u]);
// }

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentLevel[leaderA] > parentLevel[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if (parentLevel[leaderA] < parentLevel[leaderB])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    dsu_set(n);
    int flag = false;
    int from, to;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        cout << leaderA << " " << leaderB << endl;
        if (leaderA == leaderB)
        {
            flag = true;
            from = a, to = b;
        }
        else
        {
            dsu_union(a, b);
        }
    }
    (flag) ? cout << "cycle detect in between: " << from << " " << to : cout << "no cycle detected!";
    return 0;
}