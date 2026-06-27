# LC 79 - Word Search

### Problem

Given an `m × n` board of characters and a string `word`, determine if the word exists in the grid.

Rules:

* Letters must be connected horizontally or vertically.
* The same cell **cannot be used more than once** in a single path.

---

## Approach - DFS + Backtracking

### Key Observation

Every cell containing the first character of the word is a possible starting point.

From each starting cell, we perform a DFS to check whether the remaining characters can be matched.

---

## State

Each recursive call keeps track of:

* Current row
* Current column
* Current index in the word

```cpp id="tv2v8u"
dfs(row, col, index)
```

where

```text id="2h35dl"
word[index]
```

is the next character we need to match.

---

## Base Case

If every character has been matched,

```cpp id="9lqm89"
if(index == word.size())
```

return

```cpp id="kzthpj"
true
```

---

## Invalid States

Return `false` if:

* Outside the grid.
* Character does not match.
* Cell has already been visited.

---

## Why do we mark cells as visited?

Suppose

```text id="a4dudc"
A B
```

Word

```text id="x9gf4k"
ABA
```

Without marking visited,

the DFS could do

```text id="zjkxvw"
A → B → A
↑
same cell
```

which is illegal.

---

## Marking Visited

Instead of creating a separate visited matrix, we temporarily modify the board.

Before recursion:

```cpp id="ftjlwm"
char temp = board[r][c];
board[r][c] = '#';
```

Now this cell cannot be revisited during the current DFS path.

---

## Why is changing the board safe?

The cell is marked only for the **current recursion path**.

After exploring every possible continuation,

we restore it.

```cpp id="m1ln4y"
board[r][c] = temp;
```

This is the **backtracking step**.

---

## Example

Suppose

```text id="2jlwmr"
A B
C D
```

Searching

```text id="qh9sy8"
ABD
```

Visit A

```text id="h50i1r"
# B
C D
```

Visit B

```text id="nnsln4"
# #
C D
```

Visit D

Word found.

Now recursion returns.

Restore D

```text id="b93s8o"
# B
C D
```

Restore B

```text id="2xq6xw"
# B
C D
```

Restore A

```text id="jlwm5h"
A B
C D
```

The board is exactly the same as before.

---

## What if another path needs that letter?

Consider

```text id="e5c4an"
A B C
A D E
```

Suppose the DFS starting from the first `A` fails.

Before returning, we restore every modified cell.

When the outer loop later starts DFS from the second `A`, the board is unchanged.

No information is lost.

---

## The Backtracking Invariant

Every recursive call must leave the board exactly as it found it.

Pattern:

```cpp id="tp6hwp"
Choose

Recurse

Undo
```

For this problem:

```cpp id="bglzv5"
board[r][c] = '#';

dfs(...);

board[r][c] = originalCharacter;
```

This ensures different DFS paths never interfere with one another.

---

## Exploring Neighbors

After matching the current character,

search all four directions:

* Up
* Down
* Left
* Right

If **any** recursive call returns `true`, the word exists.

---

## Complexity

Let

* `m` = rows
* `n` = columns
* `L` = word length

Time:

**O(m × n × 4ᴸ)**

A tighter bound is approximately **O(m × n × 3ᴸ)** after the first move because we don't immediately revisit the previous cell.

Space:

**O(L)**

due to the recursion stack.

---

## Pattern Recognition

Whenever a problem involves:

* Searching for a sequence in a grid
* Moving in four directions
* Cells cannot be reused

Think:

**Grid DFS + Backtracking**

Pattern:

1. Start DFS from every valid starting cell.
2. Match the current character.
3. Mark the cell as visited.
4. Explore all four neighbors.
5. Restore the cell before returning.

This same pattern is used in:

* Word Search II
* Path with Maximum Gold
* Unique Paths III
* Many grid-based DFS/backtracking problems.

