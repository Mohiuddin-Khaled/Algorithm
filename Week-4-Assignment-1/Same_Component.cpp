#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

char grid[N][N];
bool visited[N][N];

bool isValid(int nx, int ny, int n, int m)
{
    return (nx >= 0 && nx < n && ny >= 0 && ny < m);
}

void dfs(int x, int y, int n, int m)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, n, m) && grid[nx][ny] == '.' && !visited[nx][ny])
        {
            dfs(nx, ny, n, m);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    dfs(si, sj, n, m);

    (visited[di][dj]) ? cout << "YES" << endl : cout << "NO" << endl;

    return 0;
}
