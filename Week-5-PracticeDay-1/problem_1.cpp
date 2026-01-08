/*
A graph may contain negative cycles,
but that does not automatically make shortest distances impossible for all nodes.
The shortest distance to a node becomes undefined only if that
node is reachable through a negative cycle.
If the negative cycle is not on any path from the source to that node,
the shortest distance can still be determined.

Example where shortest distance is not defined
S → A (1)
A → B (-2)
B → A (-2)

# The cycle A → B → A has total weight −4 (negative).
# From S, you can reach this cycle.
# By looping the cycle repeatedly, the path cost to A can be reduced indefinitely.


Example where shortest distance is defined
S → T (5)
A → B (-2)
B → A (-2)

# The graph has a negative cycle, but it is disconnected from S and T.
# The shortest distance from S to T is clearly 5.


It is impossible to get the shortest distance to a node only if that
node is reachable through a negative cycle.

*/