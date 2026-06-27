## Copy-pastable 1: Question Description + Solution Logic

### LC 22 - Generate Parentheses

### Problem

Given `n` pairs of parentheses, generate all combinations of well-formed (valid) parentheses.

---

## Approach - Backtracking

### Key Observation

At every step we have **at most two choices**:

1. Add `'('`
2. Add `')'`

However, we can only make a choice if it keeps the string valid.

---

## State

Maintain two counters:

```cpp
open
close
```

where

* `open` = number of `'('` used so far.
* `close` = number of `')'` used so far.

---

## Why not just use `balance`?

`balance` tells us

```text
balance = open - close
```

which is simply the number of unmatched `'('`.

It **does not tell us how many opening brackets have already been used.**

Example:

```text
"(("

open = 2
close = 0
balance = 2
```

and

```text
"()(("

open = 3
close = 1
balance = 2
```

Both have

```text
balance = 2
```

but they have used a different number of `'('`.

Therefore, `balance` alone cannot determine whether another `'('` may still be added.

We must track `open` and `close` separately.

---

## When can we place `'('`?

We still have opening brackets available.

```cpp
if(open < n)
```

Choose

```cpp
s += '(';
dfs(open+1, close);
```

---

## When can we place `')'`?

Only if there is an unmatched `'('` available.

```cpp
if(close < open)
```

Choose

```cpp
s += ')';
dfs(open, close+1);
```

---

## Important Observation

Sometimes **both choices are valid**.

Example:

Current string

```text
"("
```

We may build

```text
"(("
```

or

```text
"()"
```

Therefore we use

```cpp
if(...)
    dfs(...);

if(...)
    dfs(...);
```

**Not**

```cpp
if(...)
    ...
else
    ...
```

Using `else` would explore only one branch and miss valid combinations.

---

## Base Case

When the string reaches length

```text
2 * n
```

every opening bracket has been matched.

Store the current string.

```cpp
if(s.size()==2*n)
```

---

## Recursion Tree (n = 2)

```text
                 ""
               /
             "("
           /     \
        "(("     "()"
          |        |
       "(())"   "()()"
```

Each branch corresponds to choosing either `'('` or `')'` whenever that choice is valid.

---

## Complexity

The number of valid strings is the **n-th Catalan number**.

Time:

**O(Cₙ × n)**

where `Cₙ` is the Catalan number (approximately `4ⁿ / (n^(3/2))`).

Space:

* Recursion stack: **O(n)**
* Current string: **O(n)**

(Output excluded.)

---

## Pattern Recognition

Whenever a backtracking problem asks you to generate **only valid sequences**, think:

* Maintain the minimum state needed to verify validity.
* Only recurse into **valid** states.
* Never generate invalid states and filter them later.

For Generate Parentheses:

* `open < n` → we may place `'('`.
* `close < open` → we may place `')'`.

These two conditions prune the recursion tree so that only well-formed parentheses are generated.


