
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> result;
    bool cycle=false;
    void dfs(int v, vector<int>& visited, vector<vector <int>> &adj){
        visited[v]=1;

        for(int nei: adj[v]){
            if(visited[nei]==2) continue;
            if(visited[nei]==1){ cycle=true; return;}
            if(visited[nei]==0){
                dfs(nei, visited, adj);
            }
        }
        visited[v]=2;
        result.push_back(v);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        if(n==1) return {0};
        vector <int> visited(n, 0);
        vector<vector<int>> adj(n);
        for(auto &x: prerequisites){
            adj[x[0]].push_back(x[1]);
        }
        for(int i=0;i<n; i++){
                if(cycle) return {};
            if(visited[i]==0) dfs(i, visited, adj);
        }
        if(cycle) return {};
        return result;
    }
};

bool isValidOrder(int n,
                  const vector<vector<int>>& prerequisites,
                  const vector<int>& order) {

    if ((int)order.size() != n)
        return false;

    vector<int> pos(n);

    for (int i = 0; i < n; i++)
        pos[order[i]] = i;

    for (const auto& p : prerequisites) {
        int course = p[0];
        int prereq = p[1];

        if (pos[prereq] > pos[course])
            return false;
    }

    return true;
}

void runTest(int testNo,
             int n,
             vector<vector<int>> prereq,
             bool shouldExist) {

    Solution sol;
    auto ans = sol.findOrder(n, prereq);

    bool valid = isValidOrder(n, prereq, ans);

    if (valid == shouldExist) {
        cout << "Test " << testNo << " PASSED\n";
    } else {
        cout << "Test " << testNo << " FAILED\n";
    }
}

int main() {

    runTest(
        1,
        2,
        {
            {1,0}
        },
        true
    );

    runTest(
        2,
        4,
        {
            {1,0},
            {2,0},
            {3,1},
            {3,2}
        },
        true
    );

    runTest(
        3,
        1,
        {},
        true
    );

    runTest(
        4,
        2,
        {
            {1,0},
            {0,1}
        },
        false
    );

    runTest(
        5,
        3,
        {
            {1,0},
            {2,1}
        },
        true
    );

    runTest(
        6,
        3,
        {
            {0,1},
            {1,2},
            {2,0}
        },
        false
    );

    return 0;
}