#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
         vector <int> first(26, n);
         vector <int> last(26, -1);

         //find first and last occurence
         for(int i=0; i<n; i++){
            int c=s[i]-'a';
            first[c]=min(first[c], i);
            last[c]=i;
         }

         vector <pair<int, int>> intervals;

         //Generate valus interval for each character

         for(int c=0; c<26; c++){
            if(last[c]==-1) continue;

            int L=first[c];
            int R=last[c];

            bool valid=true;

            for(int i=L; i<=R; i++){
                int ch = s[i]-'a';
                if(first[ch]<L) {
                    valid=false;
                    break;
                }

                R=max(R, last[ch]);
            }

            if(valid) intervals.push_back({L, R});
         }

         //Sort by ending position
         sort(intervals.begin(), intervals.end(), [](auto&a, auto&b){
            return a.second<b.second;
         });

         vector <string> ans;

         int prevEnd =-1;

         for(auto &[L,R]: intervals){
            if(L>prevEnd){
            
                ans.push_back(s.substr(L, R-L+1));
                prevEnd=R;
                
            }
         }

         return ans;
    }
};

bool compareAnswers(
    vector<string> actual,
    vector<string> expected
) {
    return actual == expected;
}

void printVector(const vector<string>& v) {
    cout << "[";

    for(size_t i = 0; i < v.size(); i++) {
        cout << "\"" << v[i] << "\"";

        if(i + 1 < v.size())
            cout << ", ";
    }

    cout << "]";
}

void runTest(
    int testNum,
    string s,
    vector<string> expected
) {
    Solution sol;

    vector<string> result =
        sol.maxNumOfSubstrings(s);

    cout << "Test " << testNum << ": ";

    if(compareAnswers(result, expected))
        cout << "PASS\n";
    else
        cout << "FAIL\n";

    cout << "Input:    \"" << s << "\"\n";

    cout << "Expected: ";
    printVector(expected);
    cout << "\n";

    cout << "Got:      ";
    printVector(result);
    cout << "\n\n";
}

int main() {

    runTest(
        1,
        "adefaddaccc",
        {"e", "f", "ccc"}
    );

    runTest(
        2,
        "abbaccd",
        {"bb", "cc", "d"}
    );

    runTest(
        3,
        "abab",
        {"abab"}
    );

    runTest(
        4,
        "abc",
        {"a", "b", "c"}
    );

    runTest(
        5,
        "aaaa",
        {"aaaa"}
    );

    runTest(
        6,
        "a",
        {"a"}
    );

    runTest(
        7,
        "abca",
        {"b", "c"}
    );

    runTest(
        8,
        "cabcccbaa",
        {"cabcccbaa"}
    );

    return 0;
}