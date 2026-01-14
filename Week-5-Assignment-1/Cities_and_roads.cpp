// problem link: https://eolymp.com/en/problems/992

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
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((adj[i][j] == 1) && (adj[i][j] == adj[j][i]))
            {
                cnt++;
            }
        }
    }
    cout << cnt / 2;
    return 0;
}
