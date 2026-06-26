#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<int> last(26);

        for (int i = 0; i < s.size(); i++)
            last[s[i]-'a'] = i;

        vector<int> ans;

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); i++) {

            end = max(end, last[s[i]-'a']);

            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};

void runTest(int testNo,
             string s,
             vector<int> expected) {

    Solution sol;
    vector<int> ans = sol.partitionLabels(s);

    if(ans == expected)
        cout << "Test " << testNo << " Passed\n";
    else {
        cout << "Test " << testNo << " Failed\n";
        cout << "Expected: ";
        for(int x : expected) cout << x << " ";
        cout << "\nGot: ";
        for(int x : ans) cout << x << " ";
        cout << "\n";
    }
}

int main() {

    runTest(
        1,
        "ababcbacadefegdehijhklij",
        {9,7,8}
    );

    runTest(
        2,
        "eccbbbbdec",
        {10}
    );

    runTest(
        3,
        "abc",
        {1,1,1}
    );

    runTest(
        4,
        "aaaaa",
        {5}
    );

    runTest(
        5,
        "abac",
        {3,1}
    );

    return 0;
}