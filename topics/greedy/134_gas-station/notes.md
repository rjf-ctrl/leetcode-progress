### LeetCode 134. Gas Station

## Question Description

There are `n` gas stations arranged in a circular route.

* `gas[i]` represents the amount of gas available at station `i`.
* `cost[i]` represents the gas required to travel from station `i` to station `(i + 1) % n`.

You have an initially empty gas tank and may start at any station.

Return the starting gas station's index if you can travel around the circuit exactly once in the clockwise direction. Otherwise, return `-1`.

If a solution exists, it is guaranteed to be unique.

---

## Solution: Greedy (Optimal)

### Key Observation

Instead of trying every station as a starting point, maintain a candidate starting station while traversing the array once.

At every station compute the net gain:

```text
gain = gas[i] - cost[i]
```

Maintain:

* `tank` → Current gas remaining from the candidate starting station.
* `total` → Total gas surplus/deficit over the entire circuit.
* `start` → Current candidate starting station.

### Greedy Idea

Traverse all stations once.

For every station:

* Add the current gain to both `tank` and `total`.
* If `tank` becomes negative:

  * The current starting station cannot complete the circuit.
  * More importantly, **every station between the current start and this station is also impossible as a starting point.**
  * Therefore:

    * Set `start = i + 1`
    * Reset `tank = 0`

After the traversal:

* If `total < 0`, the total gas is insufficient to complete the circuit. Return `-1`.
* Otherwise, return `start`.

### Why is it Greedy?

Suppose starting at station `start` causes the tank to become negative at station `i`.

Then every station between `start` and `i` must also fail.

Reason:

* Starting later loses all the gas accumulated before reaching that station.
* Therefore those stations can never have more fuel than the original start.
* Since the original start already failed, all intermediate stations are impossible.

Thus, one failure eliminates an entire range of candidate starting stations, allowing us to skip them.

### Why It Works

Maintain the invariant:

> `tank` stores the remaining gas if we start from the current candidate station.

Whenever `tank` becomes negative, the current candidate is invalid, so the next station becomes the only possible new candidate.

The total gas check guarantees that a valid solution exists.

### Complexity

* **Time:** `O(n)`
* **Space:** `O(1)`
