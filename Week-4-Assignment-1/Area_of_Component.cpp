#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

char grid[N][N];
bool visited[N][N];
int n, m, componentCount;

bool isValid(int nx, int ny)
{
    return (nx >= 0 && nx < n && ny >= 0 && ny < m);
}

void dfs(int si, int sj)
{
    visited[si][sj] = true;
    componentCount++;
    for (int i = 0; i < 4; i++)
    {
        int nx = si + dx[i];
        int ny = sj + dy[i];
        if (isValid(nx, ny) && grid[nx][ny] == '.' && !visited[nx][ny])
        {
            dfs(nx, ny);
        }
    }
}

int main()
{
    cin >> n >> m;
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                componentCount = 0;
                dfs(i, j);
                mn = min(mn, componentCount);
            }
        }
    }

    (mn == INT_MAX) ? cout << -1 : cout << mn;

    return 0;
}
