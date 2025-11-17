
// https://cses.fi/problemset/task/1193

/*
1 <= n, m <= 1000

Input:

5 8
########
#.A#...#
#.##.#B#
#......#
########
Output:

YES
9
LDDRRRRRU

# -> -1
. -> 0

(5, 6) -> right -> (5, 7)
(5, 6) -> left -> (5, 5)
(5, 6) -> up -> (4, 6)
(5, 6) -> down -> (6, 6)

Adjacent Nodes of (x, y)

(x, y) -> right ->(x, y+1)
       -> left -> (x, y-1)
       ->  up  -> (x-1, y)
       -> down -> (x+1, y)

check / steps
    1. is the cell within the maze?
    2. is the cell forbidden / wall?
    3. is the cell visited?

    x   y
    -   -
    0   1
    0   -1
    -1  0
    1   0

difference of x or y
direction array d
    dx[] = {0, 0, -1, 1}
    dy[] = {1, -1, 0, 0}

 4 -> left, right, up, down

for(int i = 0; i < 4; i++)
{
    int new_x = x + dx[i];
    int new_y = y + dy[i];
}

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int maze[N][N];
int visited[N][N];
int level[N][N];
int n, m;

// direction array
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int, int> coordinate)
{
    int x = coordinate.first;
    int y = coordinate.second;
    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true; // inside the maze
    }
    return false; // outside the maze
}

bool is_safe(pair<int, int> coordinate)
{
    int x = coordinate.first;
    int y = coordinate.second;
    if (maze[x][y] == -1)
    {
        return false; // forbidden cell
    }
    return true; // Not forbidden cell
}

void bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;
    while (!q.empty())
    {
        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;
        // check (x , y+1), (x, y-1), (x-1, y), (x+1, y)
        // adjacent node
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            pair<int, int> adj_node = {new_x, new_y};
            // adjacent node check
            if (is_inside(adj_node) && is_safe(adj_node) && !visited[new_x][new_y])
            {
                visited[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    pair<int, int> src, dst;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            level[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++)
        {
            if (input[j] == '#')
            {
                maze[i][j] = -1;
            }
            else if (input[j] == 'A')
            {
                src = {i, j};
            }
            else if (input[j] == 'B')
            {
                dst = {i, j};
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << maze[i][j] << "";
    //     }
    //     cout << endl;
    // }

    bfs(src);

    if (level[dst.first][dst.second] == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << level[dst.first][dst.second] << endl;
    }

    return 0;
}