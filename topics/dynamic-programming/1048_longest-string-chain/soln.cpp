#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPredecessor(string a, string b){
        if(b.length()-a.length()!=1) return false;
        int i=0, j=0;
        while(i<a.length() && j<b.length()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else j++;
        }
        if(i==a.length()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
            [](const string& a, const string& b) {
                return a.size() < b.size();
            });

        int n=words.size();
        vector<int> dp(n+1, 1);
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>i; j--){
                if(isPredecessor(words[i], words[j])) dp[i]=max(dp[i], 1+dp[j]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

struct TestCase {
    vector<string> words;
    int expected;
};

int main() {

    Solution sol;

    vector<TestCase> tests = {
        {{"a","b","ba","bca","bda","bdca"}, 4},
        {{"xbc","pcxbcf","xb","cxbc","pcxbc"}, 5},
        {{"abcd","dbqca"}, 1},
        {{"a","ab","ac","bd","abc","abd","abdd"}, 4},
        {{"a"}, 1},
        {{"a","ab","abc","abcd","abcde"}, 5},
        {{"xbc","cxbc","pcxbc","pcxbcf"}, 4},
        {{"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","qsqvsyq","ksqvsq","ksqvsyq"}, 4}
    };

    int passed = 0;

    for(int i = 0; i < tests.size(); i++) {

        int result = sol.longestStrChain(tests[i].words);

        if(result == tests[i].expected) {
            cout << "Test " << i + 1 << ": PASS\n";
            passed++;
        }
        else {
            cout << "Test " << i + 1 << ": FAIL\n";
            cout << "Expected: " << tests[i].expected
                 << ", Got: " << result << "\n";
        }
    }

    cout << "\nPassed " << passed << "/" << tests.size() << " test cases.\n";

    return 0;
}