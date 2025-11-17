#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, value;
    cin >> n >> value;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 0;
    while (i < n)
    {
        if (arr[i] == value)
        {
            cout << arr[i] << endl;
        }
        i++;
    }
    return 0;
}