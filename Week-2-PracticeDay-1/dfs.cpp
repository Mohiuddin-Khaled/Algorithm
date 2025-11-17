/*
    Pseudocode of DFS
        - DFS(graph, source):
            - Initiated an array called 'visited' and empty 'st' - O(v)
            - print the node 'source'
            - st.push(source) - O(1)
            - while the stack is not empty:
                - tmp = q.top() - O(1)
                - st.pop() - O(1)
                - if visited[tmp] == 0
                    - print the node 'tmp' - O(1)
                    - visited[tmp] = 1
                - for all adjacent nodes of 'tmp': - O(E)
                    - if visited[adj_node] == 0: - O(1)
                        - q.push(adj_node) - O(1)
        - Input: Connect graph and a 'source'
        - output: Traverse all node and print the traversal node
*/

// Iterative approach using stack
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e3;
// vector<int> graph[N];
// bool visited[N];

// void dfs(int node)
// {
//     cout << node << endl;
//     stack<int> st;
//     st.push(node);
//     while (!st.empty())
//     {
//         int tmp = st.top();
//         st.pop();
//         if (!visited[tmp])
//         {
//             cout << tmp << " ";
//             visited[tmp] = true;
//         }
//         for (auto i : graph[tmp])
//         {
//             if (!visited[i])
//             {
//                 st.push(i);
//             }
//         }
//     }
// }

// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     for (int i = 0; i < e; i++)
//     {
//         int v1, v2;
//         cin >> v1 >> v2;
//         graph[v1].push_back(v2);
//         graph[v2].push_back(v1);
//     }
//     0 is source node
//     dfs(0);
//     return 0;
// }

// Recursive approach

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e3;
// vector<int> graph[N];
// bool visited[N];

// void recursiveDfs(int node)
// {
//     cout << node << " ";
//     visited[node] = true;
//     for (auto child : graph[node]) // adjacent node search
//     {
/*      if (!visited[child])
        {
            recursiveDfs(child);
        }
*/
//         if (visited[child])
//         {
//             continue;
//         }
//         recursiveDfs(child);
//     }
// }

// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     for (int i = 0; i < e; i++)
//     {
//         int v1, v2;
//         cin >> v1 >> v2;
//         graph[v1].push_back(v2);
//         graph[v2].push_back(v1);
//     }
//     recursiveDfs(0);
//     return 0;
// }

// DFS code
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 5;
// vector<int> adj[N];
// bool visited[N];
// int height[N];
// int depth[N];

// calculate height
// void dfs(int u)
// {
//     visited[u] = true;
//     for (int v : adj[u])
//     {
//         if (visited[v] == true)
//         {
//             continue;
//         }
//         dfs(v);
//         if (height[v] + 1 > height[u])
//         {
//             height[u] = height[v] + 1;
//         }
//     }
// }

// void dfs(int u)
// {
//     visited[u] = true;
//     for (int v : adj[u])
//     {
//         if (!visited[v])
//             dfs(v);
//         height[u] = max(height[v] + 1, height[u]);
//     }
// }

// calculate depth
// void dfs(int u)
// {
//     visited[u] = true;
//     for (int v : adj[u])
//     {
//         if (visited[v] == true)
//         {
//             continue;
//         }
//         depth[v] = depth[u] + 1;
//         dfs(v);
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
//     dfs(1);
//     for (int i = 1; i <= n; i++)
//     {
//         cout << "Height of Node " << i << ": " << height[i] << endl;
//     }
//     return 0;
// }
