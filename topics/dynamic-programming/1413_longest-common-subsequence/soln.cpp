#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m= text1.length();
        int n= text2.length();

        vector <int> dp(n+1, 0);

        for(int i=m-1; i>=0; i--){
            vector <int> current(n+1, 0);
            for(int j=n-1; j>=0; j--){
                if(text1[i]==text2[j]) current[j]=1+dp[j+1];
                else current[j]=max(current[j+1], dp[j]);
            }
            dp=current;
        }  
        return dp[0];
    }
};

struct TestCase {
    string text1;
    string text2;
    int expected;
};

void runTests() {
    vector<TestCase> tests = {
        {"abcde", "ace", 3},
        {"abc", "abc", 3},
        {"abc", "def", 0},
        {"AGGTAB", "GXTXAYB", 4},
        {"aaaa", "aa", 2},
        {"abcdef", "fbdamn", 2},
        {"", "", 0},
        {"a", "a", 1},
        {"a", "b", 0},
        {"bl", "yby", 1}
    };

    Solution sol;

    int passed = 0;

    for (int i = 0; i < tests.size(); i++) {
        int result = sol.longestCommonSubsequence(
            tests[i].text1,
            tests[i].text2
        );

        if (result == tests[i].expected) {
            cout << "Test Case " << i + 1 << ": PASS\n";
            passed++;
        } else {
            cout << "Test Case " << i + 1 << ": FAIL\n";
            cout << "Expected: " << tests[i].expected << "\n";
            cout << "Got: " << result << "\n";
        }
    }

    cout << "\nPassed " << passed << "/" << tests.size() << " test cases.\n";
}

int main() {
    runTests();
    return 0;
}