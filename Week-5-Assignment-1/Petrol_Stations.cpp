// Problem Link: https://eolymp.com/en/problems/1388

#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tp;
const int INF = 1e9;

int main()
{
    int n;
    cin >> n;
    vector<int> price(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> price[i];
    int m;
    cin >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // dist[city][fuel]
    // fuel = 0 -> no fuel
    // fuel = 1 -> has fuel
    vector<vector<int>> dist(n + 1, vector<int>(2, INF));
    priority_queue<tp, vector<tp>, greater<tp>> pq;
    dist[1][0] = 0;
    pq.push({0, 1, 0});
    while (!pq.empty())
    {
        int cost = get<0>(pq.top()), city = get<1>(pq.top()), fuel = get<2>(pq.top());
        pq.pop();
        if (cost > dist[city][fuel])
            continue;
        if (fuel == 0)
        {
            int newCost = cost + price[city];
            if (newCost < dist[city][1])
            {
                dist[city][1] = newCost;
                pq.push({newCost, city, 1});
            }
        }
        if (fuel == 1)
        {
            for (int nxt : graph[city])
            {
                if (cost < dist[nxt][0])
                {
                    dist[nxt][0] = cost;
                    pq.push({cost, nxt, 0});
                }
            }
        }
    }
    int ans = min(dist[n][0], dist[n][1]);
    if (ans == INF)
        cout << -1 << endl;
    cout << ans << endl;
    return 0;
}
