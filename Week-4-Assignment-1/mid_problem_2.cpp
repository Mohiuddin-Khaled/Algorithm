#include <bits/stdc++.h>
using namespace std;

const int N = 12;
vector<int> adj[N];

int main()
{
    int start = 2, end = 11;
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

/*
Yes, it will be a DAG.
Because in your graph edges only go from a smaller number to a larger number (u → v only when v > u),
so the direction is always increasing.
A path can never return to a smaller node,
which means no cycles can ever form, even with a million nodes.
*/
