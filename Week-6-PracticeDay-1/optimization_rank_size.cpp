/* Optimization
    - union by size
    - union by rank(height/level)
*/

// union by rank/height/level

// #include <bits/stdc++.h>
// using namespace std;

// int parent[1000];
// int parentLevel[1000];

// void dsu_set(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         parent[i] = -1;
//         parentLevel[i] = 0;
//     }
// }

// int dsu_find(int node)
// {
//     while (parent[node] != -1)
//     {
//         node = parent[node];
//     }
//     return node;
// }

// void dsu_union(int a, int b)
// {
//     int leaderA = dsu_find(a);
//     int leaderB = dsu_find(b);
//     if (leaderA != leaderB)
//     {
//         if (parentLevel[leaderA] > parentLevel[leaderB]) // leaderA is larger
//         {
//             parent[leaderB] = leaderA;
//         }
//         else if (parentLevel[leaderA] < parentLevel[leaderB]) // leaderB is larger
//         {
//             parent[leaderA] = leaderB;
//         }
//         else // both are equal
//         {
//             parent[leaderB] = leaderA;
//             parentLevel[leaderA]++;
//         }
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
//     cout << dsu_find(2) << endl;
//     return 0;
// }

// union by size

// #include <bits/stdc++.h>
// using namespace std;

// int parent[1000];
// int parentSize[1000];

// void dsu_set(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         parent[i] = -1;
//         parentSize[i] = 1;
//     }
// }

// int dsu_find(int node)
// {
//     while (parent[node] != -1)
//     {
//         node = parent[node];
//     }
//     return node;
// }

// void dsu_union(int a, int b)
// {
//     int leaderA = dsu_find(a);
//     int leaderB = dsu_find(b);
//     if (leaderA != leaderB)
//     {
//         if (parentSize[leaderA] > parentSize[leaderB])
//         {
//             parent[leaderB] = leaderA;
//             parentSize[leaderA] += parentSize[leaderB];
//         }
//         else
//         {
//             parent[leaderA] = leaderB;
//             parentSize[leaderB] += parentSize[leaderA];
//         }
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
//     cout << parentSize[2] << endl;
//     cout << dsu_find(6) << endl;
//     return 0;
// }
