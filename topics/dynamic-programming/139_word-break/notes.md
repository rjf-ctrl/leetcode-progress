# 139. Word Break
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

---
## SOLN
MEMOIZATION

State:
dfs(start)

Meaning:
Can the suffix s[start...n-1] be segmented?

Base Case:
if(start == n) return true;

Transition:
Try every word starting at start.

dfs(start) = OR of dfs(i+1) for every valid dictionary word s[start...i]

Memo:
dp[start] stores answer for dfs(start)

IMPORTANT:
Memo key must match the recursive state.

dfs(start)
    ↓
dp[start]

NOT:

dp[i] = dfs(i+1)   

because dp[i] and dfs(i+1) represent different states.


------------------------------------

MEMOIZATION → TABULATION

1. Keep the same state

dfs(start)
    ↓
dp[start]

Meaning:
Can suffix s[start...n-1] be segmented?


2. Convert base case

dfs(n) = true
    ↓
dp[n] = true


3. Convert recursive calls

dfs(i+1)
    ↓
dp[i+1]


4. Find dependency direction

dp[start] depends on dp[i+1]

Current state depends on larger indices.

Therefore fill:
RIGHT → LEFT

for(start = n-1; start >= 0; start--)


5. Convert transition

Memo:

if(dict.count(temp) && dfs(i+1))
    return true;

Tabulation:

if(dict.count(temp) && dp[i+1]) {
    dp[start] = true;
    break;
}


------------------------------------

GENERAL DP CONVERSION TEMPLATE

dfs(state)
    ↓
dp[state]

Base case
    ↓
DP initialization

Recursive call
    ↓
DP lookup

dp[i] depends on larger indices
    → Fill right to left

dp[i] depends on smaller indices
    → Fill left to right

```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> dict(
            wordDict.begin(),
            wordDict.end()
        );

        int n = s.size();

        vector<int> dp(n + 1, 0);

        dp[n] = 1;

        for(int start = n - 1; start >= 0; start--) {

            string temp = "";

            for(int i = start; i < n; i++) {

                temp += s[i];

                if(dict.count(temp)) {
                    dp[start] |= dp[i + 1];
                }
            }
        }

        return dp[0];
    }
};
```

```
class Solution {
public:

    int dfs(int start, string s, unordered_set <string> &dict, vector <int> &dp){
        if(start==s.length()){
            return 1;
            
        }
        if(dp[start]!=-1) return dp[start];
        bool result=false;
        string temp="";
        for(int i=start; i<s.length(); i++){
            temp+=s[i];
            if(dict.find(temp)!=dict.end()){
                if(dfs(i + 1, s, dict, dp)!=0)
                    return dp[start] = 1;
            }  
        }
        return dp[start]=0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> dict;
        for(int i=0; i<wordDict.size(); i++)
            dict.insert(wordDict[i]);
        vector <int> dp(s.length(), -1);
        if(dfs(0, s, dict, dp)==1)return true;
        return false; 
    }
};
```