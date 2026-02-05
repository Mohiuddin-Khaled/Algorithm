/*
    MX.....XB.
    ..X..X.X..
    ...X.X.X..
    .....X....
    M - source
    B - destination
    X - wall
    . - walk
*/

#include <bits/stdc++.h>
using namespace std;

char grid[101][101];
bool visited[101][101];
int n, m;
bool found = false;

void dfs(int i, int j)
{
    // boundary check
    if (i < 0 || j < 0 || i >= n || j >= m)
        return;
    // wall or already visited
    if (grid[i][j] == 'X' || visited[i][j])
        return;
    // destination found
    if (grid[i][j] == 'B')
    {
        found = true;
        return;
    }
    visited[i][j] = true;
    // 4 directions
    dfs(i - 1, j); // up
    dfs(i + 1, j); // down
    dfs(i, j - 1); // left
    dfs(i, j + 1); // right
}

int main()
{
    cin >> n >> m;
    int start_i = -1, start_j = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'M')
            {
                start_i = i;
                start_j = j;
            }
        }
    }
    dfs(start_i, start_j);
    if (found)
        cout << "Path exists" << endl;
    else
        cout << "No path" << endl;
    return 0;
}
