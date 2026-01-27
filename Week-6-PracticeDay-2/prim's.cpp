#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
vector<pii> V[N];
bool vis[N];

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
        return a.w > b.w;
    }
};

void prims(int s)
{
    priority_queue<Edge, vector<Edge>, Cmp> pq;
    vector<Edge> edgeList;
    pq.push(Edge(s, s, 0));
    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int a = parent.a, b = parent.b, w = parent.w;
        if (vis[b] == true)
            continue;
        vis[b] = true;
        edgeList.push_back(parent);
        for (int i = 0; i < V[b].size(); i++)
        {
            pii child = V[b][i];
            if (!vis[child.first])
            {
                pq.push({Edge(b, child.first, child.second)});
            }
        }
    }
    edgeList.erase(edgeList.begin());
    for (Edge val : edgeList)
    {
        cout << val.a << " " << val.b << " " << val.w << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        V[a].push_back({b, w});
        V[b].push_back({a, w});
    }
    prims(1);
    return 0;
}