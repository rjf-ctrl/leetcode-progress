#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 3;

        vector <int> dp(n+1);
        dp[0]= 0;
        dp[1] = 1;
        dp[2]=2;
        dp[3] =3;
        for (int i=4; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        }
};

int main() {
    Solution sol;

    vector<pair<int, int>> testCases = {
        {2, 2},
        {3, 3},
        {5, 8}
    };

    for (int i = 0; i < testCases.size(); i++) {
        int n = testCases[i].first;
        int expected = testCases[i].second;

        int result = sol.climbStairs(n);

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