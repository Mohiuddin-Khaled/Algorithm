// problem link: https://eolymp.com/en/problems/1389
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> pii;

struct Bus
{
    int from, departure, to, arrival;
};

int main()
{
    int n, d, v;
    cin >> n;
    cin >> d >> v;
    int r;
    cin >> r;
    vector<Bus> buses(r);
    for (int i = 0; i < r; i++)
    {
        cin >> buses[i].from >> buses[i].departure >> buses[i].to >> buses[i].arrival;
    }
    vector<int> dist(n + 1, INF);
    dist[d] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, d});
    while (!pq.empty())
    {
        int time = pq.top().first, u = pq.top().second;
        pq.pop();
        if (time > dist[u])
            continue;
        for (auto &b : buses)
        {
            if (b.from == u && time <= b.departure)
            {
                if (b.arrival < dist[b.to])
                {
                    dist[b.to] = b.arrival;
                    pq.push({b.arrival, b.to});
                }
            }
        }
    }
    if (dist[v] == INF)
        cout << -1 << endl;
    else
        cout << dist[v] << endl;
    return 0;
}