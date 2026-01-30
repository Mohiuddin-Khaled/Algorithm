/*
 - DS DS (Disjoint set Data structure)
 - DSU (Disjoint set union)
 - Disjoint Set
 - Find union
 - Grouping
 - Disjoint Set (Graph)
 - Ex. A = {1, 2, 3} , B = {4, 5, 6}
      - A intersection B = {} -> empty set
 - find connected components in graph using DSU
*/

/* pseudocode of initial disjoint set

- procedure makeset(u):
   - parent[u] = u
   - return

- procedure dsu_set(n):
   - for i from 1 to n:
      - makeset(i)
   - retrun
*/

/* pseudocode of union

- procedure Union(a, b):
   - u = FindRepresentative(a)
   - v = FindRepresentative(b)
   - if u != v:
      - parent[u] = v
   - return
*/

/* Pseudocode of Representative

- procedure FindRepresentative(r): // without path compression
   - if parent[r] = r
      - return r
   - return FindRepresentative(parent[r])
*/

/* Pseudocode of Representative(Optimized)

- procedure FindRepresentative(r): // with path compression
   - if parent[r] = r
      - retrun r
   - parent[r] = FindRepresentative(parent[r])
   - return parent[r]
*/

// Find Representative
// Find Operation
#include <bits/stdc++.h>
using namespace std;

int parent[8] = {-1, -1, 1, 1, 6, 4, -1, -1};

int find(int n)
{
   while (parent[n] != -1)
   {
      n = parent[n];
   }
   return n;
}

int main()
{
   int n;
   cin >> n;
   cout << find(n) << endl;
   return 0;
}