# LeetCode 1520 - Maximum Number of Non-Overlapping Substrings

## Problem

Given a string `s`, find the maximum number of non-overlapping substrings such that:

For every substring chosen:

* If a character appears in the substring, then **all occurrences** of that character in the entire string must also lie inside the substring.

If multiple answers have the same maximum count, return the one with minimum total length.

---

## Key Observation

Suppose a substring contains character `c`.

Then it must contain:

```text
[first[c], last[c]]
```

Otherwise some occurrence of `c` would lie outside the substring, violating the condition.

Therefore every valid substring is closely related to character occurrence intervals.

---

## Step 1: Compute First and Last Occurrence

For each character:

```text
first[c]
last[c]
```

Example:

```text
s = "adefaddaccc"

a : [0,7]
d : [1,6]
e : [2,2]
f : [3,3]
c : [8,10]
```

---

## Step 2: Generate Candidate Intervals

For every character that appears:

Start with:

```text
L = first[c]
R = last[c]
```

Now scan all positions inside `[L,R]`.

For every character encountered:

### Case 1

```text
first[ch] < L
```

Then the interval is invalid.

Reason:

To include all occurrences of `ch`, we would need to move left of `L`.

But `L` is fixed.

Therefore this interval cannot be a valid minimal interval.

Reject it.

### Case 2

```text
last[ch] > R
```

Then we must extend the interval:

```text
R = max(R, last[ch])
```

because all occurrences of `ch` must be included.

Continue scanning until the final expanded `R`.

---

## Why Only Expand R?

Suppose:

```text
Current interval = [L,R]
```

If a character forces us to go further right:

```text
last[ch] > R
```

we can simply expand.

If a character forces us to go left:

```text
first[ch] < L
```

the interval is invalid.

Therefore:

```text
R can grow.
L never changes.
```

This is the core trick of the problem.

---

## Example

```text
s = "adefaddaccc"
```

Start from:

```text
a : [0,7]
```

Characters inside:

```text
a d e f a d d a
```

Intervals:

```text
d : [1,6]
e : [2,2]
f : [3,3]
```

All already fit inside `[0,7]`.

Valid interval:

```text
[0,7]
```

---

Start from:

```text
e : [2,2]
```

Only contains:

```text
e
```

Valid interval:

```text
[2,2]
```

Substring:

```text
"e"
```

---

Start from:

```text
f : [3,3]
```

Valid interval:

```text
[3,3]
```

Substring:

```text
"f"
```

---

Start from:

```text
c : [8,10]
```

Valid interval:

```text
[8,10]
```

Substring:

```text
"ccc"
```

---

Generated intervals:

```text
[0,7]
[2,2]
[3,3]
[8,10]
```

---

## Step 3: Greedy Selection

Now the problem becomes:

```text
Choose the maximum number of
non-overlapping intervals.
```

This is the classic interval scheduling problem.

---

### Greedy Rule

Sort intervals by ending position.

Pick intervals greedily.

Example:

```text
[0,7]
[2,2]
[3,3]
[8,10]
```

Sorted by end:

```text
[2,2]
[3,3]
[0,7]
[8,10]
```

Pick:

```text
[2,2]
[3,3]
(skip [0,7])
[8,10]
```

Result:

```text
"e"
"f"
"ccc"
```

Answer size:

```text
3
```

which is maximum.

---

## Why Greedy Works

Exactly the same proof as:

* Activity Selection
* Non-overlapping Intervals (LC 435)

Choosing the interval with the earliest finishing time leaves the most room for future intervals.

---

## Pseudocode

```text
Compute first[] and last[]

intervals = []

for every character c:

    L = first[c]
    R = last[c]

    valid = true

    for i from L to R:

        ch = s[i]

        if first[ch] < L:

            valid = false
            break

        R = max(R, last[ch])

    if valid:

        intervals.push([L,R])

Sort intervals by end position

answer = []

prevEnd = -1

for interval in intervals:

    if interval.start > prevEnd:

        take interval

        prevEnd = interval.end

Return selected substrings
```

---

## Complexity

Number of characters:

```text
26
```

Building intervals:

```text
O(26 * n)
```

Sorting:

```text
O(26 log 26)
```

Overall:

```text
O(n)
```

Space:

```text
O(26)
```

---

## Interview Summary

1. Compute first and last occurrence of every character.
2. For each character, build the smallest valid interval by expanding its right boundary.
3. Reject intervals that need to expand left.
4. Generate all valid intervals.
5. Sort by ending index.
6. Greedily select non-overlapping intervals.

Mental model:

```text
Partition Labels
+
Interval Expansion
+
Activity Selection Greedy
=
LeetCode 1520
```
