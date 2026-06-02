#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.length();
        int n=str2.length();

        vector <vector <int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(str1[i]==str2[j]) 
                    dp[i][j]=1+dp[i+1][j+1];
                else
                    dp[i][j]=max(dp[i+1][j], dp[i][j+1]); 
            }
        }

        string res;
        int i=0, j=0;

        while(i<m && j<n){
            if(str1[i]==str2[j]){
                res+=str1[i];
                i++;
                j++;
            }
            else if(dp[i+1][j]>dp[i][j+1])
                res+=str1[i++];

            else res+=str2[j++];            
        }

        while(i<m) res+=str1[i++];
        while(j<n) res+=str2[j++];

        return res;
    }
};

bool isSubsequence(const string& sub, const string& s) {
    int i = 0, j = 0;

    while (i < (int)sub.size() && j < (int)s.size()) {
        if (sub[i] == s[j]) i++;
        j++;
    }

    return i == (int)sub.size();
}

void runTest(string str1, string str2, int expectedLength, int testNum) {
    Solution sol;
    string ans = sol.shortestCommonSupersequence(str1, str2);

    bool valid =
        isSubsequence(str1, ans) &&
        isSubsequence(str2, ans) &&
        (int)ans.size() == expectedLength;

    cout << "Test " << testNum << ": "
         << (valid ? "PASS" : "FAIL")
         << "\n";

    if (!valid) {
        cout << "  str1 = " << str1 << "\n";
        cout << "  str2 = " << str2 << "\n";
        cout << "  Returned = " << ans << "\n";
        cout << "  Expected Length = " << expectedLength << "\n";
    }
}

int main() {

    runTest("abac", "cab", 5, 1);

    runTest("aaaaaaaa", "aaaaaaaa", 8, 2);

    runTest("abc", "def", 6, 3);

    runTest("geek", "eke", 5, 4);

    runTest("AGGTAB", "GXTXAYB", 9, 5);

    runTest("abc", "abc", 3, 6);

    runTest("a", "b", 2, 7);

    runTest("", "", 0, 8);

    runTest("abc", "", 3, 9);

    runTest("", "xyz", 3, 10);

    return 0;
}