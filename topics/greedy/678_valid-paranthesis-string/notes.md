### LeetCode 678. Valid Parenthesis String

## Question Description

Given a string `s` containing only the characters `'('`, `')'`, and `'*'`, return `true` if `s` is a valid parentheses string.

The character `'*'` can represent:

* `'('`
* `')'`
* An empty string `""`

A valid parentheses string satisfies the usual matching rules.

---

## Solution: Greedy (Range of Balances)

### From Regular Parentheses to This Problem

For the regular Valid Parentheses problem, maintain a single variable:

```text
balance = number of unmatched '('
```

* `'('` → `balance++`
* `')'` → `balance--`
* If `balance < 0`, return `false`.
* At the end, `balance` must be `0`.

With `'*'`, the balance is no longer fixed because `'*'` may act as `'('`, `')'`, or an empty string.

Instead of tracking one balance, maintain the **range of all possible balances**.

### Variables

* `low` = Minimum possible balance.
* `high` = Maximum possible balance.

At any point, every valid balance lies within the interval:

```text
[low, high]
```

### State Transitions

For each character:

**If `'('`:**

```text
low++
high++
```

Every possible balance increases.

---

**If `')'`:**

```text
low--
high--
```

Every possible balance decreases.

---

**If `'*'`:**

`'*'` may become `'('`, `')'`, or empty.

Therefore:

```text
low--
high++
```

* Minimum balance decreases if `'*'` acts as `')'`.
* Maximum balance increases if `'*'` acts as `'('`.

### Why Clamp `low`?

Whenever:

```text
low < 0
```

we set:

```text
low = 0
```

Reason:

A negative minimum balance simply means we chose too many previous `'*'` characters as `')'`.

We can always reinterpret some of those `'*'` as empty strings (or `'('`) instead.

Therefore, the minimum meaningful balance can never be below zero.

### Why Check `high < 0`?

If:

```text
high < 0
```

then even the **largest possible balance** is negative.

That means every possible interpretation contains more `')'` than `'('`.

No future characters can fix this.

Immediately return `false`.

### Why Return `low == 0`?

At the end of the scan:

* `low` is the **smallest possible unmatched `'('` count**.
* `high` is the **largest possible unmatched `'('` count**.

A valid parentheses string requires a final balance of exactly `0`.

Since `low` is always clamped to be non-negative:

* If `low == 0`, then balance `0` is achievable.
* If `low > 0`, every possible interpretation leaves unmatched `'('`.

Thus:

```text
return low == 0
```

### Why is it Greedy?

Instead of exploring all possible assignments of every `'*'`, the algorithm greedily keeps only the **minimum and maximum possible balances**.

Every intermediate balance is automatically represented by this interval.

Whenever `low` becomes negative, we greedily reinterpret previous `'*'` characters to prevent the balance from going below zero.

Whenever `high` becomes negative, every possible interpretation has already failed.

### Why It Works

Maintain the invariant:

> After processing every prefix, every achievable balance lies inside the interval `[low, high]`.

Each character updates only the boundaries of this interval.

If the interval ever becomes empty (`high < 0`), no valid interpretation exists.

At the end, if `0` belongs to the interval (`low == 0`), at least one interpretation forms a valid parentheses string.

### Complexity

* **Time:** `O(n)`
* **Space:** `O(1)`
