/*
Below is the Bellman–Ford iteration table (distances from source A):
-------------------------------------------------
|    Iteration     | A | B  | C  | D  | E  | F  |
| ---------------- | - | -- | -- | -- | -- | -- |
|   0(Initial)     | 0 | ∞  | ∞  | ∞  | ∞  | ∞  |
|   1              | 0 | 0  | 2  | 2  | 2  | 3  |
|   2              | 0 | -1 | 1  | 1  | 1  | 2  |
|   3              | 0 | -2 | 0  | 0  | 0  | 1  |
|   4              | 0 | -3 | -1 | -1 | -1 | 0  |
|   5              | 0 | -4 | -2 | -2 | -2 | -1 |
|   6(Cycle check) | 0 | -5 | -3 | -3 | -3 | -2 |
-------------------------------------------------
    1st iteration: 0 0 2 2 2 3
    2nd iteration: 0 -1 1 1 1 2
    3rd iteration: 0 -2 0 0 0 1
    4th iteration: 0 -3 -1 -1 -1 0
    5th iteration: 0 -4 -2 -2 -2 -1
    6th iteration: 0 -5 -3 -3 -3 -2
Iteration 6 still improves distances ⇒ Negative cycle exists.
distance up .................-∞

Negative Cycle: B → C → D → B
    ​
Cycle weight: 1 + 0 − 2 = −1

Bellman–Ford detects a negative cycle since distances continue to decrease in the nth iteration.
Bellman–Ford correctly detects the negative cycle.

*/