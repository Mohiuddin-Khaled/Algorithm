#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 5;

vector<pii> adj[N];
bool vis[N];

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

class Cmp
{
public:
    bool operator()(const Edge &a, const Edge &b)
    {
        return a.w > b.w;
    }
};

vector<Edge> prims(int s)
{
    memset(vis, false, sizeof(vis));
    priority_queue<Edge, vector<Edge>, Cmp> pq;
    vector<Edge> vec;
    pq.push(Edge(s, s, 0));

    while (!pq.empty())
    {
        Edge cur = pq.top();
        pq.pop();
        int a = cur.u;
        int b = cur.v;
        int cost = cur.w;
        if (vis[b])
            continue;
        vis[b] = true;
        vec.push_back(cur);
        for (auto child : adj[b])
        {
            int v = child.first;
            int w = child.second;
            if (!vis[v])
            {
                pq.push(Edge(b, v, w));
            }
        }
    }
    if (!vec.empty())
        vec.erase(vec.begin());
    return vec;
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    vector<Edge> value = prims(1);
    for (Edge child : value)
    {
        cout << child.u << " " << child.v << " " << child.w << endl;
    }
    return 0;
}
