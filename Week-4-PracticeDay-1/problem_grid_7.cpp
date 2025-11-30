// https://leetcode.com/problems/max-area-of-island/description/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool visited[51][51];
    int n, m, cnt, mx = 0;

    vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isValid(int ci, int cj)
    {
        return (ci >= 0 && ci < n && cj >= 0 && cj < m);
    }

    void dfs(int si, int sj, vector<vector<int>> &grid)
    {
        visited[si][sj] = true;
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> d = direction[i];
            int ci = si + d.first;
            int cj = sj + d.second;
            if (isValid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == 1)
            {
                dfs(ci, cj, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    cnt = 0;
                    dfs(i, j, grid);
                    mx = max(cnt, mx);
                }
            }
        }
        return mx;
    }
};
