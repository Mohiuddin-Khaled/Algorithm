// #include <bits/stdc++.h>
// #define pub push_back
// using namespace std;

// bool completed[1000];
// vector<int> v[1000];
// int level[1000];

// void bfs(int source)
// {
//     memset(completed, false, sizeof(completed));
//     memset(level, -1, sizeof(level));
//     queue<int> q;
//     q.push(source);
//     level[source] = 0;
//     while (!q.empty())
//     {
//         int parent = q.front();
//         q.pop();
//         if (completed[parent] == true)
//         {
//             continue;
//         }
// cout << parent << endl;
//         completed[parent] = true;
//         for (int i = 0; i < v[parent].size(); i++)
//         {
//             int children = v[parent][i];
//             if (level[children] == -1)
//             {
//                 level[children] = level[parent] + 1;
//             }
//             if (completed[children] == false)
//             {
//                 q.push(children);
//             }
//         }
//     }
// }
// void solve()
// {
//     int nodes, edges;
//     cin >> nodes >> edges;
//     while (edges--)
//     {
//         int x, y;
//         cin >> x >> y;
//         v[x].pub(y);
//         v[y].pub(x);
//     }
// bfs(1);
// cout << level[0] << endl;

// bfs(3);
// cout << level[2] << endl;

//     bfs(0);
//     cout << level[1] << endl;
// }

// int main()
// {
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

vector<int> V[1000];
bool visited[1000];
int level[1000];

#define pub push_back

void bfs(int source)
{
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(source);
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        if (visited[parent])
        {
            continue;
        }
        // cout << parent << endl;
        visited[parent] = true;
        for (int i = 0; i < V[parent].size(); i++)
        {
            int children = V[parent][i];
            if (level[children] == -1)
            {
                level[children] = level[parent] + 1;
            }
            if (!visited[children])
            {
                q.push(children);
            }
        }
    }
}

int main()
{
    int nodes, edges, srcNode;
    cin >> nodes >> edges >> srcNode;

    while (edges--)
    {
        int u, v;
        cin >> u >> v;
        V[u].pub(v);
        V[v].pub(u);
    }
    bfs(srcNode);

    cout << "Minimum distance of specific node is " << level[4] << endl;

    return 0;
}