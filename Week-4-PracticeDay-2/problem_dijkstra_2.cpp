/*
| Step | Selected Node | dist(A) | dist(B) | dist(C) | dist(D) | dist(E) | dist(F) |
   0        Start          0         ∞           ∞       ∞          ∞         ∞
   1          A            0         10          15      ∞          ∞         ∞
   2          B            0         10          15     22          ∞         25
   3          C            0         10          15     22          25        25
   4          D            0         10          15     22          24        23
   5          F            0         10          15     22          24        23
   6          E            0         10          15     22          24        23

Input from the Graph
    # A → B = 10
    # A → C = 15
    # B → D = 12
    # B → F = 15
    # D → F = 1
    # D → E = 2
    # F → E = 5
    # C → E = 10

Shortest paths (from A)
    # A → A = 0
    # A → B = A → B (10)
    # A → C = A → C (15)
    # A → D = A → B → D (22)
    # A → F = A → B → D → F (23)
    # A → E = A → B → D → E (24)
*/