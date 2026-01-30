// path compression -> long path converted to short path
// basic concept of dsu

// #include <bits/stdc++.h>
// using namespace std;

// int parent[101];
// unionRank[101];

// naive approach
// int dsu_find(int u)
// {
//     if (u == parent[u])
//         return u;
//     else
//         return dsu_find(parent[u]);
// }

// optimized approach
// int dsu_find(int u)
// {
//     if (u == parent[u])
//         return u;
//     return parent[u] = dsu_find(parent[u]);
// }

// naive approach
// void dsu_union(int u, int v)
// {
//     int p = dsu_find(u);
//     int q = dsu_find(v);
//     if (p != q)
//     {
//         parent[q] = p;
//     }
// }

// optimized approach -  union by rank/height/level
// void dsu_union(int u, int v)
// {
//     int p = dsu_find(u);
//     int q = dsu_find(v);
//     if (p != q)
//     {
//         if (unionRank[p] > unionRank[q])
//         {
//             parent[q] = p;
//         }
//         else if (unionRank[p] < unionRank[q])
//         {
//             parent[p] = q;
//         }
//         else
//         {
//             parent[q] = p;
//             unionRank[p]++;
//         }
//     }
// }

// int main()
// {
//     for (int i = 1; i <= 8; i++)
//     {
//         parent[i] = i;
//         unionRank[i] = 0;
//     }

//     dsu_union(1, 2);
//     dsu_union(2, 3);
//     dsu_union(3, 4);
//     dsu_union(4, 5);
//     dsu_find(5, 6);
//     dsu_find(6, 7);
//     dsu_find(7, 8);
//     cout << dsu_find(8) << endl;
//     cout << dsu_find(1) << " " << dsu_find(2) << " " << dsu_find(3) << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int parent[100];
int parentLevel[100];
int parentSize[100];
bool flag = false;

int Find(int u)
{
    if (flag)
        cout << "Node value " << u << "\n";
    if (u == parent[u])
        return u;
    else
        return parent[u] = Find(parent[u]);
}

void UnionRank(int u, int v)
{
    int p = Find(u);
    int q = Find(v);
    if (p != q)
    {
        if (parentLevel[p] > parentLevel[q])
        {
            parent[q] = p;
        }
        else if (parentLevel[p] < parentLevel[q])
        {
            parent[p] = q;
        }
        else
        {
            parent[q] = p;
            parentLevel[p]++;
        }
    }
}

void UnionSize(int u, int v)
{
    int p = Find(u);
    int q = Find(v);
    if (p != q)
    {
        if (parentSize[p] > parentSize[q])
        {
            parent[q] = p;
            parentSize[p] += parentSize[q];
        }
        else
        {
            parent[p] = q;
            parentSize[q] += parentSize[p];
        }
    }
}

void Union(int u, int v)
{
    int p = Find(u);
    int q = Find(v);

    if (p != q)
    {
        parent[q] = p;
    }
}

bool isFriend(int u, int v)
{
    int p = Find(u);
    int q = Find(v);

    return p == q;
}

int main()
{
    for (int i = 1; i <= 8; i++)
    {
        parent[i] = i;
        parentLevel[i] = 0;
        parentSize[i] = 1;
    }

    UnionRank(7, 8);
    UnionRank(6, 7);
    UnionRank(5, 6);
    UnionRank(4, 5);
    UnionRank(3, 4);
    UnionRank(2, 3);
    UnionRank(1, 2);

    flag = true;
    Find(8);
    cout << "------\n";
    Find(8);

    cout << "------\n";
    Find(8);

    cout << "------\n";
    Find(3);

    return 0;
}