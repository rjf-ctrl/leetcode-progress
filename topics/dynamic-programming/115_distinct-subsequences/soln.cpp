#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.length();
        int n = t.length();

        vector<unsigned long> dp(n+1, 0);
        dp[n]=1;

        for(int i=m-1; i>=0; i--){
            vector<unsigned long> curr(n+1, 0);
            curr[n]=1;
            for(int j=n-1; j>=0; j--){
                if(s[i]==t[j] && j<n)
                curr[j] = dp[j]+ dp[j+1];
                else curr[j] =dp[j];
            }
            dp=curr;
        }
        return (int)dp[0];
    }
};

void runTest(
    int testNum,
    string s,
    string t,
    long long expected
){
    Solution sol;
    long long result = sol.numDistinct(s, t);

    if(result == expected){
        cout << "[PASS] Test " << testNum << "\n";
    }
    else{
        cout << "[FAIL] Test " << testNum
             << " | Expected: " << expected
             << " | Got: " << result << "\n";
    }
}

int main(){

    runTest(
        1,
        "rabbbit",
        "rabbit",
        3
    );

    runTest(
        2,
        "babgbag",
        "bag",
        5
    );

    runTest(
        3,
        "a",
        "a",
        1
    );

    runTest(
        4,
        "a",
        "b",
        0
    );

    runTest(
        5,
        "aa",
        "a",
        2
    );

    runTest(
        6,
        "aaa",
        "aa",
        3
    );

    runTest(
        7,
        "abcdef",
        "ace",
        1
    );

    runTest(
        8,
        "abcdef",
        "xyz",
        0
    );

    runTest(
        9,
        "",
        "",
        1
    );

    runTest(
        10,
        "",
        "a",
        0
    );

    runTest(
        11,
        "abc",
        "",
        1
    );

    runTest(
        12,
        "aaaaa",
        "aaa",
        10
    );

    return 0;
}