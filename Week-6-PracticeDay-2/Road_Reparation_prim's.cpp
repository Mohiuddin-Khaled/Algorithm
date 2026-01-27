// problem link: https://cses.fi/problemset/task/1675/

// Prim's Algorithm

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long int

const int N = 1e5 + 5;
vector<pii> vec[N];
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

void prims(int s, int n)
{
    priority_queue<Edge, vector<Edge>, Cmp> pq;
    vector<Edge> edgeList;
    pq.push(Edge(s, s, 0));
    int cnt = 0;
    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int a = parent.a, b = parent.b;
        if (vis[b])
            continue;
        vis[b] = true;
        cnt++;
        edgeList.push_back(parent);
        for (auto child : vec[b])
        {
            if (!vis[child.first])
            {
                pq.push(Edge(b, child.first, child.second));
            }
        }
    }
    edgeList.erase(edgeList.begin());
    ll sum = 0;
    for (Edge val : edgeList)
    {
        sum += (ll)val.w;
    }
    if (cnt == n)
        cout << sum;
    else
        cout << "IMPOSSIBLE";
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        vec[a].push_back({b, w});
        vec[b].push_back({a, w});
    }
    prims(1, n);
    return 0;
}