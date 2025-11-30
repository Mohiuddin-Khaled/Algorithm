// 4.   In a graph of  n  nodes, what can the largest length  of a path be? Why?

/*

In a graph of n nodes, the maximum possible length of a simple path is: Maximum Path Length = n − 1

Why?
   # A simple path means a path that does not repeat nodes.

   # If the graph has n nodes, the most you can do is visit each node once.

   # Each step in the path moves from one node to a new node.

So the maximum number of edges you can traverse is: (Linear Graph)

    # start node: node_1
    # end node: node_n

    # node_1 -> node_2 -> node_3 → node_4 -> ... → node_n

    # n nodes -> (n − 1) edges

The largest length of a path in a graph with n nodes is n − 1,
because once you visit all nodes exactly once, you cannot extend the path without repeating a node.

*/