#include <bits/stdc++.h>
using namespace std;

typedef pair<long long int, long long int> pii;
typedef long long int ll;

const int N = 1e5 + 7;
vector<pii> g[N];
ll dis[N];
ll n, m;

void dijkstra(ll src)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty())
    {
        ll distance = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        if (distance > dis[node])
            continue;
        for (auto adj_entry : g[node])
        {
            ll childNode = adj_entry.first;
            ll childCost = adj_entry.second;
            ll childDistance = childCost + distance;
            if (childDistance < dis[childNode])
            {
                dis[childNode] = childDistance;
                pq.push(make_pair(childDistance, childNode));
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    ll src, test;
    cin >> src >> test;
    while (test--)
    {
        ll dst, w;
        cin >> dst >> w;
        dijkstra(src);
        (dis[dst] <= w) ? cout << "YES" : cout << "NO";
        cout << endl;
    }
    return 0;
}