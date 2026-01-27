#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v;
    long long w;
    Edge(int u, int v, long long w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> v;

    while (e--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }

    int s;
    cin >> s;
    vector<long long> dis(n + 1, LLONG_MAX);
    dis[s] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            int a = ed.u;
            int b = ed.v;
            long long w = ed.w;

            if (dis[a] != LLONG_MAX && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    bool isCycle = false;
    for (int j = 0; j < v.size(); j++)
    {
        Edge ed = v[j];
        int a = ed.u;
        int b = ed.v;
        long long w = ed.w;

        if (dis[a] != LLONG_MAX && dis[a] + w < dis[b])
        {
            isCycle = true;
            break;
        }
    }

    int t;
    cin >> t;
    if (isCycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        while (t--)
        {
            int d;
            cin >> d;

            if (dis[d] == LLONG_MAX)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[d] << endl;
            }
        }
    }
    return 0;
}
