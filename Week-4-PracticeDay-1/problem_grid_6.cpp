// https://leetcode.com/problems/flood-fill/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool visited[51][51];
    int n, m;
    vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isValid(int ci, int cj)
    {
        return (ci >= 0 && ci < n && cj >= 0 && cj < m);
    }

    void dfs(int si, int sj, int sColor, int color, vector<vector<int>> &image)
    {
        visited[si][sj] = true;
        if (image[si][sj] == sColor)
            image[si][sj] = color;
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> d = direction[i];
            int ci = si + d.first;
            int cj = sj + d.second;
            if (isValid(ci, cj) && !visited[ci][cj] && image[ci][cj] == sColor)
                dfs(ci, cj, sColor, color, image);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        n = image.size(), m = image[0].size();
        dfs(sr, sc, image[sr][sc], color, image);
        return image;
    }
};
