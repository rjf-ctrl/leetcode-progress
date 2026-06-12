#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(
            wordDict.begin(),
            wordDict.end()
        );

        int n = s.size();

        vector<bool> dp(n + 1, false);
        dp[n] = true;

        for(int start = n - 1; start >= 0; start--) {

            string temp = "";

            for(int i = start; i < n; i++) {

                temp += s[i];

                if(dict.count(temp) && dp[i + 1]) {
                    dp[start] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};

struct TestCase {
    string s;
    vector<string> dict;
    bool expected;
};

int main() {

    vector<TestCase> tests = {

        // LeetCode examples
        {"leetcode", {"leet", "code"}, true},
        {"applepenapple", {"apple", "pen"}, true},
        {"catsandog", {"cats","dog","sand","and","cat"}, false},

        // User example
        {"catsandogcat", {"cats","dog","sand","and","cat","an"}, true},

        // Edge cases
        {"", {}, true},
        {"a", {"a"}, true},
        {"a", {"b"}, false},

        // Repeated usage
        {"aaaaaaa", {"aaaa","aaa"}, true},
        {"aaaaaaa", {"aaaa","aa"}, false},

        // Multiple valid breaks
        {"pineapplepenapple",
         {"apple","pen","applepen","pine","pineapple"},
         true},

        // Prefix traps
        {"cars", {"car","ca","rs"}, true},
        {"cars", {"car","ars"}, false},

        // Large overlap
        {"aaaaaaaaaaaaaaaaaaaaab",
         {"a","aa","aaa","aaaa","aaaaa"},
         false}
    };

    Solution sol;

    int passed = 0;

    for(int i = 0; i < tests.size(); i++) {

        bool actual = sol.wordBreak(
            tests[i].s,
            tests[i].dict
        );

        if(actual == tests[i].expected) {
            cout << "[PASS] Test " << i + 1 << '\n';
            passed++;
        }
        else {
            cout << "[FAIL] Test " << i + 1
                 << " Expected: " << tests[i].expected
                 << " Got: " << actual << '\n';
        }
    }

    cout << "\nPassed "
         << passed << "/"
         << tests.size()
         << " tests\n";
}