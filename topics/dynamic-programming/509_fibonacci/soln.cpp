#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n<2) return n;

        vector <int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        
        return dp[n];
    }
};

int main() {
    Solution sol;

    vector<pair<int, int>> testCases = {
        {2, 1},
        {3, 2},
        {5, 5}
    };

    for (int i = 0; i < testCases.size(); i++) {
        int n = testCases[i].first;
        int expected = testCases[i].second;

        int result = sol.fib(n);

        cout << "Test Case " << i + 1 << ": ";

        if (result == expected) {
            cout << "Passed";
        } else {
            cout << "Failed";
        }

        cout << " | Input: " << n
             << " | Expected: " << expected
             << " | Got: " << result << endl;
    }

    return 0;
}