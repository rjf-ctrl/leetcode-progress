# 763. Partition Labels

You are given a string `s`.

Partition the string into as many parts as possible so that each letter appears in **at most one** part.

Return a list containing the size of each partition.

---

## Solution: Greedy

### Key Observation

For every character, compute its **last occurrence** in the string.

While building a partition:

* The partition must extend at least until the last occurrence of its first character.
* As we scan the partition, we may encounter new characters whose last occurrences lie even farther.
* Therefore, we continuously extend the partition until every character inside it has all of its occurrences contained within it.

### Data Structure

Store the last occurrence of every character.

```text
last[c] = last index where character c appears
```

### Algorithm

1. Compute the last occurrence of every character.
2. Initialize:

   * `start = 0`
   * `end = 0`
3. Traverse the string.
4. At every character:

```text
end = max(end, last[currentCharacter])
```

5. When the current index reaches `end`:

   * Every character seen so far finishes within this partition.
   * Record the partition length.
   * Start a new partition.

### Analogy to Jump Game

This problem is surprisingly similar to **Jump Game**.

In Jump Game:

```text
farthest = max(farthest, i + nums[i])
```

As we scan reachable indices, the reachable boundary keeps expanding.

Here:

```text
end = max(end, last[s[i]])
```

As we scan the current partition, the partition boundary keeps expanding.

In both problems:

* Maintain a current boundary.
* While scanning within the boundary, update the farthest boundary discovered.
* Once the scan reaches the boundary, that segment is complete.
* Begin the next segment.

The only difference is what the boundary represents:

* **Jump Game:** farthest reachable index.
* **Partition Labels:** farthest required index to contain all characters.

### Why is it Greedy?

At every step we greedily construct the **smallest valid partition**.

Once the current index reaches `end`, every character inside the partition has had its final occurrence.

Closing the partition immediately is always optimal because:

* Making it smaller would split a character across partitions.
* Making it larger only reduces the total number of partitions.

Thus, closing the partition as soon as it becomes valid maximizes the number of partitions.

### Why It Works

Maintain the invariant:

> `end` always stores the farthest last occurrence of any character seen in the current partition.

Whenever `i == end`, every character introduced since `start` finishes within this interval.

Therefore the current partition is complete and can safely be closed.

### Complexity

* **Time:** `O(n)`
* **Space:** `O(1)` (26 lowercase letters)
