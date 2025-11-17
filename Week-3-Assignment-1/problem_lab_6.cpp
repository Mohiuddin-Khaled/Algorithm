// https://cses.fi/problemset/task/1679/

/* Pseudocode of BFS
- create an array "indegree" to maintain the number of indegrees to a node.
    i.e. for every edge a -> b perform indegree[b]++

- create an empty stack to store the topsort order

- create a queue and push all the nodes in the queue with indegree[node] == 0

- while the queue is not empty:
    - pop "head" from queue

    - stack.push(head)

    - for adj_node in adj_list[head]:
        - decrement indegree[adj_node] by 1

        - if indegree[adj_node] == 0:
            - queue.push(adj_node)

- pop every node in the stack and print in the output
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj_list[N];
int inDegree[N];
stack<int> st;
vector<int> result;

void bfs(int n, int m)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        st.push(u);
        q.pop();
        for (int v : adj_list[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v); // u ---> v
        inDegree[v]++;
    }
    bfs(n, m);
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());
    if ((int)result.size() != n)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (int value : result)
            cout << value << " ";
    }
    return 0;
}