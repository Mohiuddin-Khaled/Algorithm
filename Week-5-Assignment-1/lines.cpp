// problem link: https://eolymp.com/en/problems/1060

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int maze[N][N];
int visited[N][N];
int level[N][N];
int n;

vector<string> str;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool is_inside(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool is_safe(int x, int y)
{
    return maze[x][y] != -1;
}

void bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);

    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (is_inside(nx, ny) && is_safe(nx, ny) && !visited[nx][ny])
            {
                visited[nx][ny] = 1;
                level[nx][ny] = level[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    cin >> n;
    str.resize(n);

    pair<int, int> src, dst;

    for (int i = 0; i < n; i++)
        cin >> str[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
            level[i][j] = -1;
            if (str[i][j] == 'O')
                maze[i][j] = -1;
            else if (str[i][j] == '@')
                src = {i, j};
            else if (str[i][j] == 'X')
                dst = {i, j};
            else
                maze[i][j] = 0;
        }
    }

    bfs(src);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (str[i][j] == '.' || str[i][j] == 'X')
            {
                str[i][j] = '+';
            }
        }
    }

    if (level[dst.first][dst.second] == -1)
    {
        cout << "N" << endl;
    }
    else
    {
        cout << "Y" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << str[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}