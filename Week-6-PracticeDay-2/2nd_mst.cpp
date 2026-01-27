// Minimum Spanning Tree: O(E log E)
// Second Best Minimum Spanning Tree: O(V * E log E)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N], parentSize[N];

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

class Cmp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return a.w < b.w;
    }
};

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

pair<int, vector<Edge>> kruskal_skip_edge(int n, vector<Edge> &edges, Edge skip)
{
    dsu_set(n);
    int cost = 0, cnt = 0;
    vector<Edge> mstEdges;

    for (Edge e : edges)
    {
        if (e.a == skip.a && e.b == skip.b && e.w == skip.w)
            continue;

        int leaderA = dsu_find(e.a);
        int leaderB = dsu_find(e.b);

        if (leaderA != leaderB)
        {
            dsu_union(e.a, e.b);
            cost += e.w;
            mstEdges.push_back(e);
            cnt++;
        }
    }

    if (cnt == n - 1)
        return {cost, mstEdges};

    return {INT_MAX, {}};
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;
    vector<Edge> mst;

    dsu_set(n);

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back(Edge(a, b, w));
    }

    sort(edges.begin(), edges.end(), Cmp());

    // Find 1st MST
    int mstCost = 0;
    for (Edge val : edges)
    {
        int leaderA = dsu_find(val.a);
        int leaderB = dsu_find(val.b);
        if (leaderA != leaderB)
        {
            dsu_union(val.a, val.b);
            mst.push_back(val);
            mstCost += val.w;
        }
    }

    cout << "MST Cost: " << mstCost << endl;
    cout << "MST Edges:" << endl;
    for (Edge val : mst)
        cout << val.a << " " << val.b << " " << val.w << endl;

    // Find 2nd MST
    int secondMSTCost = INT_MAX;
    vector<Edge> secondMSTEdges;

    for (Edge skip : mst)
    {
        pair<int, vector<Edge>> child = kruskal_skip_edge(n, edges, skip);
        if (child.first > mstCost && child.first < secondMSTCost)
        {
            secondMSTCost = child.first;
            secondMSTEdges = child.second;
        }
    }

    cout << "Second MST Cost: " << secondMSTCost << endl;
    cout << "Second MST Edges:" << endl;

    for (Edge val : secondMSTEdges)
        cout << val.a << " " << val.b << " " << val.w << endl;

    return 0;
}
