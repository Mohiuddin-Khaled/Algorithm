// https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int N = 1e3 + 5;
vector<string> g;
int visited[N][N], level[N][N];
pii parent[N][N];
int n, m;
vector<pii> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int si = -1, sj = -1, di = -1, dj = -1;

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pii head = q.front();
        int i = head.first;
        int j = head.second;
        q.pop();
        for (auto d : direction)
        {
            int ai = i + d.first;
            int aj = j + d.second;
            if (isValid(ai, aj) && !visited[ai][aj] && g[ai][aj] != '#')
            {
                q.push({ai, aj});
                visited[ai][aj] = true;
                level[ai][aj] = level[i][j] + 1;
                parent[ai][aj] = {i, j};
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 'A')
            {
                si = i, sj = j;
            }
            if (x[j] == 'B')
            {
                di = i, dj = j;
            }
        }
        g.push_back(x);
    }
    bfs(si, sj);
    if (!visited[di][dj])
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        cout << "YES" << endl;
        cout << level[di][dj] << endl;
    }
    vector<pii> path;
    pii curr = {di, dj};
    while (!(curr.first == si && curr.second == sj))
    {
        path.push_back(curr);
        curr = parent[curr.first][curr.second];
    }
    path.push_back({si, sj});
    reverse(path.begin(), path.end());
    int k = path.size();
    for (int i = 1; i < k; i++)
    {
        if (path[i - 1].first == path[i].first)
        {
            if (path[i - 1].second == path[i].second - 1)
            {
                cout << 'R';
            }
            else
            {
                cout << 'L';
            }
        }
        else
        {
            if (path[i - 1].first == path[i].first - 1)
            {
                cout << 'D';
            }
            else
            {
                cout << 'U';
            }
        }
    }
    return 0;
}