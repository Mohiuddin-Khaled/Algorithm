// problem link: https://codeforces.com/contest/25/problem/D

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int parent[N], parentLevel[N];

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
        else if (parentLevel[leaderB] > parentLevel[leaderA])
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
    int n;
    cin >> n;

    int e = n - 1;
    dsu_set(n);

    vector<pair<int, int>> extra;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA == leaderB)
        {
            extra.push_back({a, b});
        }
        else
            dsu_union(a, b);
    }

    vector<int> leaders;
    for (int i = 1; i <= n; i++)
    {
        if (dsu_find(i) == i)
            leaders.push_back(i);
    }

    int days = leaders.size() - 1;

    if (days > 0)
    {
        cout << days << endl;
        for (int i = 0; i < leaders.size() - 1; i++)
        {
            cout << extra[i].first << " " << extra[i].second << " "
                 << leaders[i] << " " << leaders[i + 1] << endl;
        }
    }
    else
    {
        cout << days << endl;
    }
    return 0;
}
