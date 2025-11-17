// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
// Adjacency Matrix --> 2D Array
// unweighted graph
// int n, m;
// cin >> n >> m;
// int adjMatrix[n][m];
// int u, v;
// cin >> u >> v;
// adjMatrix[u][v] = 1;

// Adjacency Matrix --> 2D Array
// weighted graph
// int n, m;
// cin >> n >> m;
// int adjMatrix[n][m];
// int u, v, w;
// cin >> u >> v >> w;
// adjMatrix[u][v] = w;

// Adjacency List --> stl Vector
// directed graph
// int n;
// cin >> n;
// vector<int> adjList[n];
// int u, v;
// cin >> u >> v;
// adjList[u].push_back(v);

// Adjacency List --> stl Vector
// unirected graph
// int n;
// cin >> n;
// vector<int> adjList[n];
// int u, v;
// cin >> u >> v;
// adjList[u].push_back(v);
// adjList[v].push_back(u);
// return 0;
// }

// Adjacency Matrix
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
// int n, m;
// cin >> n >> m;
// int adjMat[n + 1][n + 1];
// for (int i = 0; i < m; i++)
// {
//     int u, v;
//     cin >> u >> v;
//     adjMat[u][v] = 1;
//     adjMat[v][u] = 1;
// }

// Adjacency List
// #include <bits/stdc++.h>
// using namespace std;

// void addEdge(vector<int> adj[], int u, int v)
// {
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }

// void printGraph(vector<int> adj[], int n)
// {
//     for (int i = 0; i < n; ++i)
//     {
//         cout << "\n Adjacency List of Vertex " << i << "\n head"
//              << endl;
//         for (auto x : adj[i])
//         {
//             cout << " --> " << x;
//         }
//         printf("\n");
//     }
// }

// int main()
// {
// int v = 5;
//     int v, sz;
//     cin >> v >> sz;
//     vector<int> adj[v];
// addEdge(adj, 0, 1);
// addEdge(adj, 0, 4);
// addEdge(adj, 1, 2);
// addEdge(adj, 1, 3);
// addEdge(adj, 1, 4);
// addEdge(adj, 2, 3);
// addEdge(adj, 3, 4);
//     for (int i = 0; i < sz; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     printGraph(adj, v);
//     return 0;
// }

// Adjacency Matrix
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
// int nodes = 4;
// int matrix[nodes][nodes];

// for (int i = 0; i < nodes; i++)
// {
//     for (int j = 0; j < nodes; j++)
//     {
//         matrix[i][j] = 0;
//     }
// }

//     int matrix[nodes][nodes] = {};

//     matrix[0][1] = 1;
//     matrix[1][0] = 1;

//     matrix[1][2] = 1;
//     matrix[2][1] = 1;

//     matrix[2][3] = 1;
//     matrix[3][2] = 1;

//     matrix[3][1] = 1;
//     matrix[1][3] = 1;

//     for (int i = 0; i < nodes; i++)
//     {
//         for (int j = 0; j < nodes; j++)
//         {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// Adjacency List
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int nodes = 4;
//     vector<int> adj_list[nodes];

//     adj_list[0] = {1};
//     adj_list[1] = {0, 2, 3};
//     adj_list[2] = {1, 3};
//     adj_list[3] = {1, 2};

//     for (int i = 0; i < nodes; i++)
//     {
//         cout << i << " -> ";
//         for (int j = 0; j < adj_list[i].size(); j++)
//         {
//             cout << adj_list[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// Adjacency List
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int nodes = 4;
//     vector<pair<int, int>> adj_list[nodes];
// way 1
//     adj_list[0] = {{1, 2}};
//     adj_list[1] = {{2, 4}};
//     adj_list[2] = {},
//     adj_list[3] = {{1, 7}, {2, 8}};

//      way 2
//      adj_list[0].push_back(pair<int, int>(1, 2));

//      adj_list[0].push_back({1, 2});
//      adj_list[1].push_back({2, 4});
//      adj_list[3].push_back({1, 7});
//      adj_list[3].push_back({2, 8});

//     for (int i = 0; i < nodes; i++)
//     {
//         cout << i << " -> ";
//         for (int j = 0; j < adj_list[i].size(); j++)
//         {
//             cout << "( " << adj_list[i][j].first << ", " << adj_list[i][j].second << "),  ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// Edge List
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int nodes = 4;
// vector<vector<int>> edge_list;
// edge_list.push_back({0, 1});
// edge_list.push_back({1, 2});
// edge_list.push_back({1, 3});
// edge_list.push_back({2, 3});

// vector<vector<int>> edge_list = {
//     {0, 1},
//     {1, 2},
//     {1, 3},
//     {2, 3},
// };

// vector<vector<int>> edge_list = {
//     {0, 1, 2},
//     {1, 2, 4},
//     {1, 3, 9},
//     {2, 3, 1},
// };
// for (int i = 0; i < edge_list.size(); i++)
// {
//     cout << i << " -> " << "[ " << edge_list[i][0] << ", " << edge_list[i][1] << " ]" << endl;
// }
//     for (int i = 0; i < edge_list.size(); i++)
//     {
//         cout << i << " -> " << "[ " << edge_list[i][0] << " --- " << edge_list[i][1] << " | " << edge_list[i][2] << " ]" << endl;
//     }
//     return 0;
// }
