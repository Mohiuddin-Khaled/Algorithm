// problem link: https://cses.fi/problemset/task/1666

// union by size

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N], parentSize[N];

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
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

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    dsu_set(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }
    map<int, bool> mp;
    for (int i = 1; i <= n; i++)
    {
        int ldr = dsu_find(i);
        mp[ldr] = true;
    }
    vector<int> vec;
    for (auto p : mp)
    {
        vec.push_back(p.first);
    }
    cout << vec.size() - 1 << endl;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        cout << vec[i] << " " << vec[i + 1] << endl;
    }
    return 0;
}