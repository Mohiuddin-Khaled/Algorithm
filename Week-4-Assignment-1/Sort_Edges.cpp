#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 7;
vector<pii> g;

int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.push_back(make_pair(u, v));
    }
    sort(g.begin(), g.end());
    for (auto value : g)
    {
        cout << value.first << " " << value.second << endl;
    }
    return 0;
}