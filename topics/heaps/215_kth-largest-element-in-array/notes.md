# 215. Kth Largest Element in an Array

Find the kth largest element in an unsorted array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Return the kth largest element.

---

## Solution 1: Min Heap (Optimal General Solution)

Approach: Min Heap of Size k

Maintain a min-heap containing the largest k elements seen so far.
Iterate through every number:
Push it into the min-heap.
If heap size exceeds k, remove the smallest element.
After processing all numbers, the heap contains exactly the largest k elements.
The smallest element in the heap is the kth largest element overall.

### Why a Min Heap?
We only care about the largest k elements.
The smallest among those k elements is exactly the kth largest.
Whenever a larger element appears, it replaces the current smallest in the heap.

### Complexity
Time: O(n log k)
Space: O(k)

## Solution 2: Counting Sort (Constraint-Based Optimization)

Approach: Frequency Counting
Observation: Every number lies within the range [-10000, 10000].
Create a frequency array of size 20001.
Use an offset of 10000 to map negative values to valid indices.
Count the occurrence of every number.
Traverse the frequency array from largest value to smallest.
Keep a running count of elements encountered.
Once the cumulative count reaches k, return the corresponding value.

### Why It Works
Instead of sorting the array, we count the occurrences of every possible value.
Traversing from largest to smallest naturally finds the kth largest element.

### Complexity
Time: O(n + R) where R = 20001 (effectively O(n) for this problem)
Space: O(R)