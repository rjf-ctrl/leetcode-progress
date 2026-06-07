#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        string r =s;
        reverse(r.begin(), r.end());
        vector<int> dp(n+1, 0);
        int lps=0;
        for(int i=1; i<=n; i++){
            vector <int> curr(n+1, 0);
            for(int j=1; j<=n; j++){
                if(s[i-1]==r[j-1]) curr[j]=1+dp[j-1];
                else curr[j]=max(dp[j], curr[j-1]); 
            }
            dp=curr;
        }
        lps=dp[n];

        return n-lps;
    }
};

void runTest(string s, int expected) {
    Solution sol;
    int result = sol.minInsertions(s);

    cout << "Input: \"" << s << "\"\n";
    cout << "Expected: " << expected << "\n";
    cout << "Got: " << result << "\n";

    if (result == expected)
        cout << "PASS\n";
    else
        cout << "FAIL\n";

    cout << "-------------------------\n";
}

int main() {
    runTest("zzazz", 0);
    runTest("mbadm", 2);
    runTest("leetcode", 5);
    runTest("g", 0);
    runTest("no", 1);
    runTest("race", 3);
    runTest("abcda", 2);
    runTest("aabaa", 0);
    runTest("abcd", 3);
    runTest("banana", 1);

    return 0;
}