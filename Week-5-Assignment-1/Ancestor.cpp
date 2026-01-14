// problem link: https://eolymp.com/en/problems/1941

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> parent[i];
    }
    int m;
    cin >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        bool flag = false;
        while (b != 0)
        {
            if (b == a)
            {
                flag = true;
                break;
            }
            b = parent[b];
        }

        (flag) ? cout << 1 << endl : cout << 0 << endl;
    }
    return 0;
}