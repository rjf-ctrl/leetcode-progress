#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26,0);

        for(char c : tasks)
            freq[c-'A']++;

        int maxFreq = *max_element(freq.begin(), freq.end());

        int maxCount = 0;

        for(int f : freq)
            if(f == maxFreq)
                maxCount++;

        return max(
            (int)tasks.size(),
            (maxFreq-1)*(n+1)+maxCount
        );
    }
};

void runTest(int testNo, vector<char> tasks, int cooldown, int expected) {
    Solution sol;
    int ans = sol.leastInterval(tasks, cooldown);

    if (ans == expected)
        cout << "Test " << testNo << " Passed\n";
    else
        cout << "Test " << testNo << " Failed\n"
             << "Expected: " << expected
             << " Got: " << ans << "\n";
}

int main() {

    runTest(
        1,
        {'A','A','A','B','B','B'},
        2,
        8
    );

    runTest(
        2,
        {'A','A','A','B','B','B'},
        0,
        6
    );

    runTest(
        3,
        {'A','A','A','A','B','C'},
        2,
        10
    );

    runTest(
        4,
        {'A','A','B','B','C','C','D','D'},
        2,
        8
    );

    runTest(
        5,
        {'A'},
        3,
        1
    );

    return 0;
}