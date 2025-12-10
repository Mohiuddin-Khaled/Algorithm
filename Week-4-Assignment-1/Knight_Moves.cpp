#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int N = 1e3 + 5;
const int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
const int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int d[N][N];

bool isValid(int x, int y, int n, int m)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int bfs(int n, int m, int ki, int kj, int qi, int qj)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            d[i][j] = -1;
        }
    }
    queue<pii> q;
    q.push(make_pair(ki, kj));
    d[ki][kj] = 0;

    while (!q.empty())
    {
        int si = q.front().first;
        int sj = q.front().second;
        q.pop();

        if (si == qi && sj == qj)
            return d[si][sj];

        for (int i = 0; i < 8; i++)
        {
            int di = si + dx[i];
            int dj = sj + dy[i];
            if (isValid(di, dj, n, m) && d[di][dj] == -1)
            {
                d[di][dj] = d[si][sj] + 1;
                q.push(make_pair(di, dj));
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, ki, kj, qi, qj;
        cin >> n >> m >> ki >> kj >> qi >> qj;
        int steps = bfs(n, m, ki, kj, qi, qj);
        cout << steps << endl;
    }
    return 0;
}