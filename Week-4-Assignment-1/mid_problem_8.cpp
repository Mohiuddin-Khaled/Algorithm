/*
    |   Step   |  node   | Dist A | Dist B | Dist C | Dist D | Dist E | Dist F |
    | -------  | ------- | -----  | -----  | -----: | -----: | -----: | -----: |
    |    0     |   —     |   ∞    |  (0)   |   ∞    |   ∞    |   ∞    |   ∞    |
    |    1     |   B     |  (4)   |   0    |  (4)   |   ∞    |   ∞    |   ∞    |
    |    2     |   C     |   4    |   0    |   4    |  (10)  |  (7)   |  (5)   |
    |    3     |   A     |   4    |   0    |   4    |   10   |   7    |   5    |
    |    4     |   F     |   4    |   0    |   4    |   (8)  |   7    |   5    |
    |    5     |   E     |   4    |   0    |   4    |    8   |   7    |   5    |
    |    6     |   D     |   4    |   0    |   4    |    8   |   7    |   5    |


    Input
    -----
    A B 4
    A C 2
    B C 4
    C E 3
    C D 6
    C F 1
    E D 2
    F D 3

    output
    ------
    # B → B
    # B → A
    # B → C
    # B–C–F
    # B–C–E
    # B–C–F–D

 # shortest path: B → C → F → D

 */
