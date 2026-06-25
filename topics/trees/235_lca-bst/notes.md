LC 134. Gas Station

Difficulty: Medium

Problem

There are n gas stations arranged in a circle.

gas[i] = amount of gas available at station i.
cost[i] = gas required to travel from station i to (i + 1) % n.

Return the starting gas station's index if you can travel around the circuit exactly once in the clockwise direction.
Otherwise, return -1.

If a solution exists, it is guaranteed to be unique.

--------------------------------------------------

Approach: Greedy

Observation 1

If the total gas available is less than the total cost required, completing the circuit is impossible.

If

sum(gas) < sum(cost)

return -1 immediately.

--------------------------------------------------

Observation 2

Suppose we start from station s and fail at station i.

This means that somewhere between s and i, our fuel became negative.

None of the stations between s and i can be a valid starting point.

Why?

If starting from s cannot even reach i, then starting from any station after s (but before i) would have even less fuel accumulated before reaching i.

Therefore, once we fail at i, we can safely skip every station between s and i and try i + 1 as the next starting station.

--------------------------------------------------

Algorithm

1. Compute totalGas and totalCost.
2. If totalGas < totalCost, return -1.
3. Traverse the stations while maintaining:
   - currentFuel
   - candidate starting station.
4. Add gas[i] - cost[i] to currentFuel.
5. If currentFuel becomes negative:
      - Current start cannot work.
      - Set start = i + 1.
      - Reset currentFuel = 0.
6. After one traversal, return start.

--------------------------------------------------

Pseudo Code

totalGas = sum(gas)
totalCost = sum(cost)

if totalGas < totalCost:
    return -1

start = 0
fuel = 0

for i = 0 to n-1:

    fuel += gas[i] - cost[i]

    if fuel < 0:
        start = i + 1
        fuel = 0

return start

--------------------------------------------------

Correctness

The greedy reset works because when we fail at station i, every station between the previous candidate start and i is also impossible as a starting point.

Thus each station is discarded at most once.

--------------------------------------------------

Time Complexity: O(N)

Single pass after checking totals.

Space Complexity: O(1)