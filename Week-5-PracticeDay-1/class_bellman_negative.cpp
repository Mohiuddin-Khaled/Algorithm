// class and constructor

// #include <bits/stdc++.h>
// using namespace std;

// class edge
// {
// public:
//     int u;
//     int v;
//     int w;
//     edge(int u, int v, int w)
//     {
//         this->u = u;
//         this->v = v;
//         this->w = w;
//     }
// };

// vector<edge> vec;

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     while (m--)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         edge ed(u, v, w);
//         vec.push_back(ed);
//         cout << ed.u << " " << ed.v << " " << ed.w << endl;
//     }
//     int dis[n + 1];
//     for (int i = 1; i <= n; i++)
//     {
//         dis[i] = INT_MAX;
//     }
//     dis[1] = 0;
//     for (int i = 1; i <= n - 1; i++)
//     {
//         for (int j = 0; j < vec.size(); j++)
//         {
//             edge ed = vec[j];
//             int u = ed.u;
//             int v = ed.v;
//             int w = ed.w;
//             if (dis[u] != INT_MAX && (dis[u] + w < dis[v]))
//             {
//                 dis[v] = dis[u] + w;
//             }
//         }
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         cout << "Node " << i << ": " << dis[i] << endl;
//     }
//     return 0;
// }

// find negative cycle
#include <bits/stdc++.h>
using namespace std;

class edge
{
public:
    int u, v, w;
    edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

vector<edge> vec;

int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge ed(u, v, w);
        vec.push_back(ed);
    }
    int dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            edge ed = vec[j];
            int u = ed.u, v = ed.v, w = ed.w;
            if (dis[u] != INT_MAX && (dis[u] + w < dis[v]))
            {
                dis[v] = dis[u] + w;
            }
        }
    }
    // check cycle
    bool cycle = false;
    for (int j = 0; j < vec.size(); j++)
    {
        edge ed = vec[j];
        int u = ed.u;
        int v = ed.v;
        int w = ed.w;
        if (dis[u] != INT_MAX && (dis[u] + w < dis[v]))
        {
            cycle = true;
            break;
            dis[v] = dis[u] + w;
        }
    }
    if (cycle)
    {
        cout << "Cycle Exists!" << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "Node " << i << ": " << dis[i] << endl;
        }
    }
    return 0;
}