#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    int turnRight(int i){
        if(i==9) return 0;
        return i+1;
    }

    int turnLeft(int i){
        if(i==0) return 9;
        return i-1;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set <string> ded(
            deadends.begin(),
            deadends.end()
        );
        if(ded.count("0000")) return -1;

        queue<string> q;
        unordered_set <string> visited;
        q.push("0000");
        visited.insert("0000");
        int turns=0;
        while(!q.empty()){
            int n=q.size();
            
            for(int i=0; i<n; i++){
                string curr=q.front();
                q.pop();
                if(curr==target) return turns;
                for(int i=0; i<4; i++){
                    string combo1=curr;
                    string combo2=curr;
                    int digit = curr[i] - '0';
                    combo1[i] = turnLeft(digit) + '0';
                    combo2[i] = turnRight(digit) + '0';
                    if(!ded.count(combo1)){
                        if(!visited.count(combo1)) {q.push(combo1); visited.insert(combo1);}
                        //cout << turns <<". "<<combo1<<endl;
                    } 
                    if(!ded.count(combo2)){
                        if(!visited.count(combo2)) {q.push(combo2); visited.insert(combo2);}
                        //cout << turns <<". "<<combo2<<endl;
                    } 
                }
            }
            turns++;

        }
        return -1;
    }
};

struct TestCase {
    vector<string> deadends;
    string target;
    int expected;
};

int main() {

    vector<TestCase> tests = {

        {
            {"0201","0101","0102","1212","2002"},
            "0202",
            6
        },

        {
            {"8888"},
            "0009",
            1
        },

        {
            {"8887","8889","8878","8898","8788","8988","7888","9888"},
            "8888",
            -1
        },

        {
            {"0000"},
            "8888",
            -1
        },

        {
            {},
            "0000",
            0
        }
    };

    Solution sol;

    int passed = 0;

    for(int i = 0; i < tests.size(); i++) {

        int result =
            sol.openLock(
                tests[i].deadends,
                tests[i].target
            );

        bool ok =
            result == tests[i].expected;

        cout
            << "Test "
            << i + 1
            << ": "
            << (ok ? "PASS" : "FAIL")
            << " | Expected = "
            << tests[i].expected
            << " | Got = "
            << result
            << endl;

        if(ok) passed++;
    }

    cout
        << "\nPassed "
        << passed
        << "/"
        << tests.size()
        << " tests\n";

    return 0;
}