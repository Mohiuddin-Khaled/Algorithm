// https://cses.fi/problemset/task/1192/

/*
 . (floor) or # (wall)

Constraints
    1 <= n, m <= 1000

Input:
    5 8
    ########
    #..#...#
    ####.#.#
    #..#...#
    ########

Output:
    3

while there exist empty cell
    - Find an empty unvisited cell
    - Run bfs() from that cell
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2002;

int maze[N][N];
int visited[N][N];
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
                q.push(adj_node);
            }
        }
    }
}

pair<int, int> find_visited()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && maze[i][j] == 0)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main()
{
    cin >> n >> m;
    string input;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        for (int j = 0; j < m; j++)
        {
            if (input[j] == '#')
            {
                maze[i][j] = -1;
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << maze[i][j] << "\t";
    //     }
    // }
    int room_cnt = 0;
    while (1)
    {
        pair<int, int> unvisted_pos = find_visited();
        if (unvisted_pos == pair<int, int>(-1, -1))
        {
            break;
        }
        bfs(unvisted_pos);
        room_cnt++;
    }
    cout << room_cnt;
    return 0;
}