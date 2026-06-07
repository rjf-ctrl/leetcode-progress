#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string r=s;
        reverse(r.begin(), r.end());
        int n=s.length();
        vector<int> dp(n+1, 0);
        int result=0;
        for(int i=1; i<=n; i++){
            vector <int> curr(n+1, 0);
            for(int j=1; j<=n; j++){
                if(s[i-1]==r[j-1]) curr[j]=1+dp[j-1];
                else curr[j]=max(curr[j-1], dp[j]);
            }
            dp=curr;
            result=max(result, dp[i]);
        }
        return result;

    }
};

void runTest(string s, int expected) {
    Solution sol;
    int result = sol.longestPalindromeSubseq(s);

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
    runTest("bbbab", 4);
    runTest("cbbd", 2);
    runTest("a", 1);
    runTest("aa", 2);
    runTest("ab", 1);
    runTest("racecar", 7);
    runTest("abcdef", 1);
    runTest("agbdba", 5);
    runTest("character", 5);
    runTest("euazbipzncptlduekgxygtm", 7);

    return 0;
}