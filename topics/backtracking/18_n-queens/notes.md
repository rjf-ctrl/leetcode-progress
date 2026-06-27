# 51 - N Queens

### Problem

Place `n` queens on an `n × n` chessboard such that no two queens attack each other.

Queens attack along:

* Row
* Column
* Main diagonal (`r - c`)
* Anti-diagonal (`r + c`)

Return all valid board configurations.

---

## Approach - Backtracking + Constraint Checking

### Key Observation

We place **exactly one queen per row**.

Therefore:

* Rows are handled by recursion.
* We only need to check whether a column or diagonal is already occupied.

---

## State

The recursion state is simply:

```cpp id="l4s1gt"
dfs(currentRow)
```

Each recursive call decides **which column** to place the queen in for the current row.

---

## Constraint Tracking

Instead of scanning the board every time (O(n) per placement), maintain three hash sets.

### Occupied Columns

```cpp id="6em4wf"
unordered_set<int> col;
```

Contains every occupied column.

---

### Main Diagonal

```cpp id="jlwmzh"
unordered_set<int> negDiag;
```

Each main diagonal has constant

```text id="pzc2ze"
row - col
```

Example:

```text id="rbmxf4"
0 1 2 3

Q . . .
. Q . .
. . Q .
```

All queens lie on the same

```text id="aqs3pa"
row - col = 0
```

---

### Anti-Diagonal

```cpp id="ukomf7"
unordered_set<int> posDiag;
```

Each anti-diagonal has constant

```text id="vgpr3n"
row + col
```

Example:

```text id="3tnzrp"
. . Q
. Q .
Q . .
```

All have

```text id="91v8my"
row + col = 2
```

---

## Checking Validity

A position

```text id="6kcmyu"
(row, col)
```

is valid if

```cpp id="rl8jeo"
!columns.count(col)

!negDiag.count(row-col)

!posDiag.count(row+col)
```

All three checks are **O(1)**.

---

## Recursion Logic

For the current row:

1. Try every column.
2. Skip columns that violate any constraint.
3. Place a queen.
4. Mark its column and diagonals as occupied.
5. Recurse to the next row.
6. Remove the queen (backtrack).

---

## Recursion Tree (n = 4)

```text id="k8gggi"
Row 0

      []
    / | | \
   Q  Q Q  Q
```

Each branch chooses a different column for Row 0.

For every valid placement, continue with Row 1.

Eventually

```text id="4e3l0x"
Row == n
```

means every queen has been placed successfully.

Store the board.

---

## Backtracking

Choose

```cpp id="ktwl9v"
board[row][col] = 'Q';

columns.insert(col);

negDiag.insert(row-col);

posDiag.insert(row+col);
```

Undo

```cpp id="apgqf7"
board[row][col] = '.';

columns.erase(col);

negDiag.erase(row-col);

posDiag.erase(row+col);
```

Every recursive call restores the board before returning.

---

## Why hash sets?

Without them,

checking whether a queen can be placed requires scanning:

* the column
* both diagonals

which costs **O(n)**.

Using hash sets reduces each validity check to

```text id="j72z5j"
O(1)
```

making the search significantly faster.

---

## Complexity

Worst case:

Approximately

```text id="upnwnc"
O(N!)
```

because each row chooses among progressively fewer valid columns.

Space:

* Board: **O(N²)**
* Hash sets: **O(N)**
* Recursion stack: **O(N)**

---

## Pattern Recognition

Unlike previous backtracking problems:

* We are **not** generating combinations.
* We are **not** searching a grid.

Instead, we repeatedly ask:

> **Can I legally place an object here?**

This is **constraint-based backtracking**.

General pattern:

```text id="vx8oik"
Try every possible placement

↓

Check constraints

↓

Choose

↓

Recurse

↓

Undo
```

Many classic problems (Sudoku Solver, Graph Coloring, Crossword Fill, etc.) use this same pattern.
