// problem link: https://eolymp.com/en/problems/2470

#include <bits/stdc++.h>
using namespace std;

int adj[101][101];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (adj[i][i] != 0)
        {
            flag = false;
            break;
        }
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] != adj[j][i])
            {
                flag = false;
                break;
            }
        }
    }
    (flag) ? cout << "YES" : cout << "NO";

    return 0;
}
