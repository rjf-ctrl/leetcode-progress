#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool dfs(int v, vector<int> &state, vector<vector<int>> &adj){
        state[v]=1; //VISTING

        for(int nei: adj[v]){
            if(state[nei]==1) return true;
            if(state[nei]==0){
                if(dfs(nei, state,adj)) return true;
            }
        }
        state[v]=2; //PROCESSED
        return false;

    }   

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> state (numCourses, 0);
        bool result;
        vector <vector<int>> adj(numCourses);
        for(auto &x: prerequisites)
            adj[x[0]].push_back(x[1]);

        for(int i=0; i<numCourses; i++){
            if(state[i]==0){
                if(dfs(i, state, adj)) return false;
            }         
        }
        return true;
    }
};

void runTest(int testNo,
             int numCourses,
             vector<vector<int>> prerequisites,
             bool expected) {

    Solution sol;
    bool result = sol.canFinish(numCourses, prerequisites);

    cout << "Test " << testNo << ": ";

    if (result == expected)
        cout << "PASS\n";
    else {
        cout << "FAIL\n";
        cout << "Expected: " << expected
             << ", Got: " << result << "\n";
    }
}

int main() {

    runTest(
        1,
        2,
        {{1,0}},
        true
    );

    runTest(
        2,
        2,
        {{1,0},{0,1}},
        false
    );

    runTest(
        3,
        4,
        {{1,0},{2,1},{3,2}},
        true
    );

    runTest(
        4,
        4,
        {{1,0},{2,1},{0,2}},
        false
    );

    runTest(
        5,
        5,
        {},
        true
    );

    runTest(
        6,
        5,
        {{1,0},{2,0},{3,1},{3,2}},
        true
    );

    runTest(
        7,
        5,
        {{1,0},{2,1},{3,2},{1,3}},
        false
    );

    runTest(
        8,
        1,
        {},
        true
    );

    runTest(
        9,
        3,
        {{1,0},{2,1},{0,2}},
        false
    );

    runTest(
        10,
        6,
        {{1,0},{2,1},{3,2},{4,3},{5,4}},
        true
    );

    return 0;
}