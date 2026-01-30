/* pseudocode of union find operation
 - u = FindRepresentative(a)
 - v = FindRepresentative(b)
 - if u != v:
    - parent[u] = v
 - return
*/

// #include <bits/stdc++.h>
// using namespace std;
// int parent[1000];

// void dsu_set(int n) // makeset()
// {
//     for (int i = 1; i <= n; i++)
//     {
//         parent[i] = -1; // initialize parent set
//     }
// }

// int dsu_find(int node) // FindRepresentative()
// {
//     while (parent[node] != -1)
//     {
//         node = parent[node];
//     }
//     return node;
// }

// void dsu_union(int a, int b) // union()
// {
//     int leaderA = dsu_find(a);
//     int leaderB = dsu_find(b);
//     if (leaderA != leaderB)
//     {
//         parent[leaderB] = leaderA;
//     }
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     dsu_set(n);
//     while (m--)
//     {
//         int a, b;
//         cin >> a >> b;
//         dsu_union(a, b);
//     }
//     int node;
//     cin >> node;
/// leader find
//     cout << dsu_find(node); // FindRepresentative()
//     return 0;
// }
