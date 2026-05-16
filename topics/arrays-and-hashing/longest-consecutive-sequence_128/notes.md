#128.Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

'''
Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:

Input: nums = [1,0,1,2]
Output: 3
'''

*-------------------------------------------------------------------------*

##SOLN1
best soln
use unordered set
note: loop over the unordered set s, not nums so as to avoid hitting duplicates, it will improve time

##SOLN2
much slower
use union find + unordered map and unordered set
connect (or union) consecutive nodes keep track of connected component size (union Not by rank but by size) largest connected component is longest consecutive sequence
