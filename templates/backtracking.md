
# BACKTRACKING

WHEN TO THINK OF BACKTRACKING?

Keywords:
- Generate all
- Find all
- Enumerate
- Can we arrange?
- Can we partition?
- Can we choose some elements?
- Try every possibility

Backtracking = Choose -> Explore -> Undo


STANDARD TEMPLATE

```
bool backtrack(...) {

    if(base_case)
        return true;

    for(int i = start; i < n; i++) {

        if(!isValid(i))
            continue;

        // Choose
        makeChoice(i);

        if(backtrack(...))
            return true;

        // Undo
        undoChoice(i);
    }

    return false;
}
```

PATTERN 1: SUBSETS


Use When:
- Generate all subsets
- Power set
- Combination generation

```
void dfs(int start,
         vector<int>& nums,
         vector<int>& curr,
         vector<vector<int>>& ans) {

    ans.push_back(curr);

    for(int i = start; i < nums.size(); i++) {

        curr.push_back(nums[i]);

        dfs(i + 1, nums, curr, ans);

        curr.pop_back();
    }
}
```

Leetcode:
- 78 Subsets
- 90 Subsets II


PATTERN 2: PERMUTATIONS


Use When:
- Arrange elements
- Generate all orders

```
void dfs(vector<int>& nums,
         vector<bool>& used,
         vector<int>& curr,
         vector<vector<int>>& ans) {

    if(curr.size() == nums.size()) {
        ans.push_back(curr);
        return;
    }

    for(int i = 0; i < nums.size(); i++) {

        if(used[i]) continue;

        used[i] = true;
        curr.push_back(nums[i]);

        dfs(nums, used, curr, ans);

        curr.pop_back();
        used[i] = false;
    }
}
```

Leetcode:
- 46 Permutations
- 47 Permutations II


PATTERN 3: COMBINATION SUM


Use When:
- Reuse of elements allowed
- Unbounded choices
  
```
void dfs(int idx,
         int target,
         vector<int>& nums,
         vector<int>& curr) {

    if(target == 0) {
        ans.push_back(curr);
        return;
    }

    if(idx == nums.size())
        return;

    if(nums[idx] <= target) {

        curr.push_back(nums[idx]);

        dfs(idx,
            target - nums[idx],
            nums,
            curr);

        curr.pop_back();
    }

    dfs(idx + 1,
        target,
        nums,
        curr);
}
```
Leetcode:
- 39 Combination Sum


PATTERN 4: PARTITION / BUCKET FILLING


Use When:
- Partition array into groups
- Equal sum subsets
- Matchsticks problems

```
bool dfs(int start,
         int currSum,
         int k,
         int target,
         vector<bool>& used,
         vector<int>& nums) {

    if(k == 1)
        return true;

    if(currSum == target)
        return dfs(0,
                   0,
                   k - 1,
                   target,
                   used,
                   nums);

    for(int i = start; i < nums.size(); i++) {

        if(used[i]) continue;

        if(currSum + nums[i] > target)
            continue;

        used[i] = true;

        if(dfs(i + 1,
               currSum + nums[i],
               k,
               target,
               used,
               nums))
            return true;

        used[i] = false;

        // Important pruning
        if(currSum == 0)
            return false;
    }

    return false;
}


Driver:

sort(nums.rbegin(), nums.rend());

int total = accumulate(nums.begin(),
                       nums.end(),
                       0);

if(total % k != 0)
    return false;

int target = total / k;

vector<bool> used(nums.size(), false);

return dfs(0,
           0,
           k,
           target,
           used,
           nums);
```

Leetcode:
- 698 Partition to K Equal Sum Subsets
- 473 Matchsticks to Square


PATTERN 5: GRID / BOARD SEARCH


Use When:
- Word Search
- Maze
- Grid DFS

bool dfs(int r, int c, int idx) {

    if(idx == word.size())
        return true;

    if(out_of_bounds)
        return false;

    if(board[r][c] != word[idx])
        return false;

    char temp = board[r][c];
    board[r][c] = '#';

    bool found =
        dfs(r+1,c,idx+1) ||
        dfs(r-1,c,idx+1) ||
        dfs(r,c+1,idx+1) ||
        dfs(r,c-1,idx+1);

    board[r][c] = temp;

    return found;
}

Leetcode:
- 79 Word Search


MOST COMMON PRUNING TRICKS


1. Sort descending

sort(nums.rbegin(), nums.rend());

2. Skip already used

if(used[i]) continue;

3. Skip duplicates

if(i > start && nums[i] == nums[i-1])
    continue;

4. Capacity exceeded

if(currSum + nums[i] > target)
    continue;

5. Fail-fast bucket pruning

if(currSum == 0)
    return false;


RECOGNITION GUIDE


DP:
- Count ways
- Min/Max
- Existence
- Overlapping states

Backtracking:
- Generate all
- Find all
- Enumerate
- Try every possibility
- Partition/Arrange


MUST-KNOW BACKTRACKING PROBLEMS


78   Subsets
90   Subsets II
46   Permutations
47   Permutations II
39   Combination Sum
79   Word Search
131  Palindrome Partitioning
51   N-Queens
473  Matchsticks to Square
698  Partition to K Equal Sum Subsets

