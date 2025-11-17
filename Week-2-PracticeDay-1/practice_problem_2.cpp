#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int adjMat[n + 1][n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> adjMat[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "List of " << i << ": ";
        for (int j = 1; j <= n; j++)
        {
            if (adjMat[i][j] == 1)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
