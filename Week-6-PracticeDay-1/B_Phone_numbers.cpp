// problem link: https://codeforces.com/contest/25/problem/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;

    int i = 0;
    while (i < n)
    {
        int value = n - i;

        if (value == 3)
        {
            cout << str.substr(i, 3);
            i += 3;
        }
        else
        {
            cout << str.substr(i, 2);
            i += 2;
        }
        if (i < n)
            cout << "-";
    }
    return 0;
}
