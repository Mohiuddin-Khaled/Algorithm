// Adjacency list
// #include <bits/stdc++.h>

// This line cin, cout of c++ converted to printf, scanf of c
// #define fast iso_base::sync_with_stdio(0) cin.tie(NULL);

// #define pub push_back
// using namespace std;

// void solve()
// {
//     vector<int> a[5];
//     a[0].push_back(2);
//     a[0].pub(2);
//     a[2].pub(0);

//     a[0].pub(3);
//     a[3].pub(0);

//     a[1].pub(2);
//     a[2].pub(1);

//     a[1].pub(3);
//     a[3].pub(1);

//     a[2].pub(4);
//     a[4].pub(2);

//     a[3].pub(4);
//     a[4].pub(3);
// }

/*
    Pseudocode of BFS
        - BFS(graph, source):
            - Initiated an array called 'visited' and empty 'q' - O(v)
            - mark visited[source] = 1 and q.push(source) - O(1)
            - while the queue is not empty:
                - head = q.front() - O(1)
                - q.pop() - O(1)
                - print the node 'head' - O(1)
                - for all adjacent nodes of 'head': - O(E)
                    - if visited[adj_node] == 0: - O(1)
                        - visited[adj_node] = 1 and q.push(adj_node) - O(1)
        - Input: Connect graph and a 'source'
        - output: Traverse all node and print the traversal node
*/

// visited boolean array declare globally
// bool completed[1000];

// vector of array declare globally
// vector<int> v[1000];

// void bfs(int source)
// {
//     memset(completed, false, sizeof(completed));
//     queue<int> q;
//     q.push(source);
//     while (!q.empty())
//     {
//         int frnt = q.front();
//         q.pop();
// cout << frnt << endl;
//         if (completed[frnt] == true)
//         {
//             continue;
//         }
//         cout << frnt << endl;

// ja kaj korar ei frnt diya hobe
// completed[frnt] = true;

// v[frnt] is array of vector
//         for (int i = 0; i < v[frnt].size(); i++)
//         {
//             int val = v[frnt][i];
// q.push(val);
//             if (completed[val] == false)
//             {
//                 q.push(val);
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
//     bfs(1);
// }

// int main()
// {
// int t;
// fast;
//     solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e3 + 5;

// vector<int> adj[N];
// bool visited[N];
// int level[N];
// void bfs(int s)
// {
//     queue<int> q;
//     q.push(s);
//     visited[s] = true;
//     level[s] = 0;
//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         cout << u << " ";
//         cout << endl;
//         for (int v : adj[u])
//         {
//             if (visited[v])
//                 continue;
//             q.push(v);
//             visited[v] = true;
//             level[v] = level[u] + 1;
//             cout << "Child node " << v << ", level is: " << level[v] << endl;
//         }
//     }
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     bfs(1);
//     return 0;
// }

