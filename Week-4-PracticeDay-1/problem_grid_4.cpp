// problem link - https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int maze[1001][1001];
bool visited[1001][1001];
int n, m, roomCount = 0;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pii coordinate)
{
    int x = coordinate.first;
    int y = coordinate.second;
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool is_safe(pii coordinate)
{
    int x = coordinate.first;
    int y = coordinate.second;
    if (maze[x][y] == -1)
        return false;
    return true;
}

void bfs(pii src)
{
    queue<pii> q;
    visited[src.first][src.second] = true;
    q.push(src);
    while (!q.empty())
    {
        pii head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            pii adj_node = {new_x, new_y};
            if (is_inside(adj_node) && is_safe(adj_node) && !visited[new_x][new_y])
            {
                visited[new_x][new_y] = true;
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string st;
        cin >> st;
        for (int j = 0; j < m; j++)
        {
            if (st[j] == '#')
            {
                maze[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!maze[i][j] && !visited[i][j])
            {
                bfs({i, j});
                roomCount++;
            }
        }
    }
    cout << roomCount;
    return 0;
}
