/* Pseudocode of Floyd Warshall Path Finding
- Input: A weighted graph as an adjacency matrix
- Output: All pair shortest distance
- procedure of FloydWarshall(next, matrix, n):
    - Create a distance matrix 'd' where d[i][j] = x where there is direct
        edge from node 'i' to node 'j' and the cost is 'x' --> O(v^2)
    - for all node 'i' d[i][i] = 0
    - for all nodes 'i' & 'j' where there isn't any direct edge from 'i' to 'j'
        d[i][j] = INF
    - for all node 'k' - O(n)
        - for all node 'u' - O(n)
            - for all node 'v' - O(n)
                - d[u][v] = min(d[u][v], d[u][k] + d[k][v]) - O(1)

- output all pair shortest distance 'd'

- procedure of PathFinding(i, j, next):
    - create a empty vector is 'path'
    - if next[i][j] == -1:
        - return "no path exists from node i to node j"
    - push the node i in the vector 'path'
    - while i != j:
        - i <- next[i][j]
        - append i to path
    - print the path

*** Time Complexity: O(v^3) -> O(n^3)
** Space Complexity: O(v^2) -> O(n^2)
*/

/* Graph Does not contain negative weight cycle
Example Code:
    5 7
    1 2 4
    1 3 2
    2 4 -3
    3 2 1
    4 5 3
    2 5 10
    3 4 -5
*/

/* Transitive Closure
matrix[i][j] = 1 // if has distance from i to j
matrix[i][j] = 0 // if has not distance from i to j
matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j])
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1005;

int d[N][N];
int nxt[N][N];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                d[i][j] = 0;
                nxt[i][j] = i;
            }
            else
            {
                d[i][j] = INF;
                nxt[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        nxt[u][v] = v;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] == INF || d[k][j] == INF)
                    continue;

                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    int start = 1, end = n;
    if (nxt[start][end] == -1)
    {
        cout << "No path exists!" << endl;
        return 0;
    }

    vector<int> path;
    int curr = start;
    while (curr != end)
    {
        path.push_back(curr);
        curr = nxt[curr][end];
    }
    path.push_back(end);

    for (int node : path)
        cout << node << " ";
    cout << endl;

    return 0;
}