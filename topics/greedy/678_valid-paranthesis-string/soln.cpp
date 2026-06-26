
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {

        int low = 0;
        int high = 0;

        for(char c : s) {

            if(c == '(') {
                low++;
                high++;
            }
            else if(c == ')') {
                low--;
                high--;
            }
            else {
                low--;
                high++;
            }

            if(high < 0)
                return false;

            low = max(low, 0);
        }

        return low == 0;
    }
};

void runTest(int testNo,
             string s,
             bool expected) {

    Solution sol;

    bool ans = sol.checkValidString(s);

    if(ans == expected)
        cout << "Test " << testNo << " Passed\n";
    else
        cout << "Test " << testNo << " Failed\n"
             << "Expected: " << expected
             << " Got: " << ans << "\n";
}

int main() {

    runTest(1, "()", true);

    runTest(2, "(*)", true);

    runTest(3, "(*))", true);

    runTest(4, "(((*)", false);

    runTest(5, ")*(", false);

    return 0;
}

