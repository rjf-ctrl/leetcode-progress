# 703. Kth Largest Element in a Stream

Implement a class KthLargest that maintains the kth largest element in a stream of integers.

Implement the following methods:

KthLargest(int k, vector<int>& nums) initializes the object with the integer k and the stream of integers nums.
int add(int val) appends the integer val to the stream and returns the element representing the kth largest element in the stream.

You must support multiple calls to add() efficiently.

---
## Approach: Min Heap

Observation: We do not need to store every number in the stream.
We only need to keep track of the largest k elements seen so far.
Use a min-heap of size at most k.
The smallest element in this heap is exactly the kth largest element overall.

### Constructor
Iterate through every number in nums.
Push each number into the min-heap.
If heap size exceeds k, pop the smallest element.
After processing all numbers, the heap contains only the largest k elements.

### add(val)
If the heap contains fewer than k elements, simply push val.
Otherwise, compare val with the heap's top (current kth largest).
If val is larger, remove the smallest element and insert val.
Otherwise, ignore val since it cannot affect the kth largest element.
Return the heap's top.

### Why a Min Heap?
The heap stores exactly the largest k elements.
The smallest among them is the kth largest element.
top() always gives the answer in O(1) time.

### Complexity
Constructor: O(n log k)
add(): O(log k)
Space: O(k)