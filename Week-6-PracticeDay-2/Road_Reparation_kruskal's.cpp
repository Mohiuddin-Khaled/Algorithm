// problem link: https://cses.fi/problemset/task/1675/
// Kruskal's Algorithm

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 1e5 + 5;
int parent[N];
int parentSize[N];

class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

bool Cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

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
        node = parent[node];
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
    int n, e;
    cin >> n >> e;
    vector<Edge> vec;
    vector<Edge> ans;
    dsu_set(n);
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        vec.push_back(Edge(a, b, w));
    }
    sort(vec.begin(), vec.end(), Cmp);
    for (Edge val : vec)
    {
        int a = val.a, b = val.b, w = val.w;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
            continue;
        ans.push_back(val);
        dsu_union(a, b);
    }
    ll sum = 0;
    for (Edge val : ans)
    {
        sum += (ll)val.w;
    }
    (ans.size() == n - 1) ? cout << sum : cout << "IMPOSSIBLE";
    return 0;
}
