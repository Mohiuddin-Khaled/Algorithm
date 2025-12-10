// problem link: https://www.spoj.com/problems/ABCPATH/

#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int N = 55;
char adjMat[N][N];
bool visited[N][N] = {false};
int n, m, nodeCnt;

bool isValid(int di, int dj)
{
    return (di >= 0 && di < n && dj >= 0 && dj < m);
}

int bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    visited[si][sj] = false;
    q.push({si, sj});
    nodeCnt = 1; // for char 'A'
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        char nextCh = adjMat[x][y] + 1;
        for (int i = 0; i < 8; i++)
        {
            int di = x + dx[i], dj = y + dy[i];
            if (isValid(di, dj) && adjMat[di][dj] == nextCh && !visited[di][dj])
            {
                visited[di][dj] = true;
                q.push({di, dj});
                nodeCnt = max(nodeCnt, (nextCh - 'A' + 1));
            }
        }
    }
    return nodeCnt;
}

int main()
{
    cin >> n >> m;
    if (n == 0 && m == 9)
        return 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adjMat[i][j];
        }
    }
    int h, w;
    cin >> h >> w;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adjMat[i][j] == 'A')
            {
                ans = max(ans, bfs(i, j));
            }
        }
    }
    cout << "Case 1: " << ans;
    return 0;
}