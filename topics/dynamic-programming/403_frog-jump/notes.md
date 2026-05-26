# 403. Frog Jump
A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

Example 1:
cpp
cpp
cpp
cpp
Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.

Example 2:

Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.

---

## SOLN

# Why Your LeetCode 403 Solution Fails

I tried:

```
class Solution {
public:
    bool cross(vector <int> & stones, int i, int k){
        if(i==0) return true; 
        int I=-1, K=-1;
        if(stones[i]-stones[i-1] ==k+1) {I=i-1; K=k+1;}
        else if(stones[i]-stones[i-1] ==k-1) {I=i-1; K=k-1;}
        else if(stones[i]-stones[i-1] ==k) {I=i-1; K=k;}
        if(I>=0 && K>=0) return cross(stones, I, K);
        I=-1, K=-1;
         if(i-2>=0){
        if(stones[i]-stones[i-2] ==k+1) {I=i-2; K=k+1;}
        else if(stones[i]-stones[i-2] ==k-1) {I=i-2; K=k-1;}
        else if(stones[i]-stones[i-2] ==k) {I=i-2; K=k;}
        if(I>=0 && K>=0) return cross(stones, I, K);
        }
        I=-1, K=-1;
        if(i-3>=0){
        if(stones[i]-stones[i-3] ==k+1) {I=i-3; K=k+1;}
        else if(stones[i]-stones[i-3] ==k-1) {I=i-3; K=k-1;}
        else if(stones[i]-stones[i-3] ==k) {I=i-3; K=k;}
        if(I>=0 && K>=0) return cross(stones, I, K);
        }

        return false;
    }
    bool canCross(vector<int>& stones) {
      int n=stones.size();
      if(n==2){ if(stones[1]-stones[0]==1) return true;
      else return false;}
      return cross(stones, stones.size()-2, stones[n-1]-stones[n-2]);
    }
};
```

* You only check:

  ```
  i-1, i-2, i-3
  ```

  but the frog can jump from ANY earlier stone.

* You assume the last stone was reached from:

  ```
  stones[n-2]
  ```

  which is not guaranteed.

* You explore only ONE path because of:

  ```
  if ... else if ...
  ```

  instead of trying all valid possibilities.

* Your state logic is inconsistent:

  ```
  stones[i]-stones[j] == k+1
  ```

  mixes up current jump and previous jump.

* The same stone can be reached with different jump sizes, but your recursion does not properly model:

  ```
  (stone index, last jump)
  ```

  as the DP state.

* No memoization:
  repeated states are recomputed many times.

* Backtracking approach is incomplete:
  you stop at first possible predecessor instead of checking all.

* The frog problem is about:

  ```
  reachable positions
  ```

  not nearby indices.

* Your recursion assumes local structure in the array, but valid jumps can skip many stones.

* You never verify whether the FIRST jump is exactly:

  ```
  1
  ```

  which is a required condition.

### BEST APPROACH

* State of the dp depends on current index and last jump size. dp[i][k] if u may.

```
class Solution {
public:
    unordered_map<int, int> pos;
    unordered_map <string, bool> cross;

    bool solve(vector<int>& stones, int i, int k) {

        if(i == stones.size() - 1)
            return true;
        
        string key = to_string(i) + "," + to_string(k);
        if(cross.find(key) != cross.end()) return cross[key];


        for(int j = k - 1; j <= k + 1; j++) {

            if(j <= 0)
                continue;

            int next = stones[i] + j;

            if(pos.find(next) != pos.end()) {

                if(solve(stones, pos[next], j))
                    return cross[key]=true;
            }
        }

        return cross[key] = false;
    }

    bool canCross(vector<int>& stones) {

        if(stones.size() < 2)
            return true;

        if(stones[1] != 1)
            return false;

        for(int i = 0; i < stones.size(); i++)
            pos[stones[i]] = i;

        return solve(stones, 1, 1);
    }
};

```

Explore other solutions also
