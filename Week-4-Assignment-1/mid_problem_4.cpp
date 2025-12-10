#include <bits/stdc++.h>
using namespace std;

vector<int> combination;

void recursive(int n, int maxNum)
{
    if (n == 0)
    {
        for (int i = 0; i < combination.size(); i++)
        {
            cout << combination[i] << " ";
        }
        cout << endl;
        return;
    }
    int end = min(n, maxNum);
    for (int i = end; i >= 1; i--)
    {
        combination.push_back(i);
        recursive(n - i, i);
        combination.pop_back();
    }
}

int main()
{
    int n;
    cin >> n;
    recursive(n, n);
    return 0;
}
