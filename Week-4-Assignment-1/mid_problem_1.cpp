#include <bits/stdc++.h>
using namespace std;

const int N = 102;
vector<int> adj[N];

int main()
{
    int start = 2, end = 101;
    for (int u = start; u <= end; u++)
    {
        for (int v = u; v <= end; v++)
        {
            if (v % u == 0 && v != u)
            {
                adj[u].push_back(v);
            }
        }
    }

    for (int u = start; u <= end; u++)
    {
        cout << "Node " << u << ": ";
        for (int v : adj[u])
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}