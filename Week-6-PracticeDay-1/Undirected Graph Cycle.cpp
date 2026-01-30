// problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// union by rank/level/height

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> parent;
    vector<int> parentLevel;

    void dsu_set(int n)
    {
        parent.assign(n + 1, -1);
        parentLevel.assign(n + 1, 0);
    }

    int dsu_find(int node)
    {
        if (parent[node] == -1)
            return node;
        return parent[node] = dsu_find(parent[node]);
    }

    void dsu_union(int a, int b)
    {
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA == leaderB)
            return;

        if (parentLevel[leaderA] > parentLevel[leaderB])
            parent[leaderB] = leaderA;
        else if (parentLevel[leaderA] < parentLevel[leaderB])
            parent[leaderA] = leaderB;
        else
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        dsu_set(V);
        for (auto &e : edges)
        {
            int a = e[0];
            int b = e[1];
            if (dsu_find(a) == dsu_find(b))
                return true;
            dsu_union(a, b);
        }
        return false;
    }
};
