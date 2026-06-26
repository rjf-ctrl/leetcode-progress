# 295. Find Median from Data Stream
Design a data structure that supports the following operations:

addNum(int num) — Add an integer from the data stream to the data structure.
findMedian() — Return the median of all elements seen so far.

The median is:

The middle element if the number of elements is odd.
The average of the two middle elements if the number of elements is even.

Your solution should efficiently support repeated insertions and median queries.

---

## Solution Logic 
Approach: Two Heaps (Max Heap + Min Heap)

### Key Observation
The median depends only on the middle element(s).
We do not need the entire array to be sorted.
We only need:
The largest element in the smaller half.
The smallest element in the larger half.

### Data Structures
Max Heap (leftHeap)
Stores the smaller half of the numbers.
Top contains the largest element of the smaller half.
Min Heap (rightHeap)
Stores the larger half of the numbers.
Top contains the smallest element of the larger half.

### Invariants
Maintain the following after every insertion:

Every element in leftHeap is less than or equal to every element in rightHeap.
leftHeap either has the same number of elements as rightHeap or exactly one more element.
addNum(num)
If the left heap is empty or num <= leftHeap.top(), insert into the left heap.
Otherwise, insert into the right heap.
Rebalance the heaps:
If the left heap has more than one extra element, move its top to the right heap.
If the right heap has more elements than the left heap, move its top to the left heap.

### findMedian()
If both heaps have equal size:
Median = average of both heap tops.
Otherwise:
Left heap contains one extra element.
Median = leftHeap.top().

### Why It Works
The max heap always stores the lower half.
The min heap always stores the upper half.
Since the heaps remain balanced, the median is always available from the heap tops without sorting the entire stream.

### Complexity
addNum(): O(log n)
findMedian(): O(1)
Space: O(n)