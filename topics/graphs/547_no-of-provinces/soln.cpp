#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    void dfs(int v, vector<int> &visited, vector <vector<int>> &graph){
        visited[v]=1;

        for(int u=0; u<graph.size(); u++){
            if(graph[v][u]==1){
                if(visited[u]==0) dfs(u, visited, graph);
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector <vector<int>> graph=isConnected;
        int n=graph.size();
        vector <int> visited(n+1, 0);
        int provinces=0;
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                dfs(i, visited, graph);
                provinces++;
            }
        }
        return provinces;
    }
};

void runTest(vector<vector<int>> isConnected,
             int expected,
             int testNo) {

    Solution sol;
    int result = sol.findCircleNum(isConnected);

    cout << "Test " << testNo << ": "
         << (result == expected ? "PASS" : "FAIL")
         << endl;

    if(result != expected) {
        cout << "Expected: " << expected << endl;
        cout << "Got: " << result << endl;
    }
}

int main() {

    runTest(
        {
            {1,1,0},
            {1,1,0},
            {0,0,1}
        },
        2,
        1
    );

    runTest(
        {
            {1,0,0},
            {0,1,0},
            {0,0,1}
        },
        3,
        2
    );

    runTest(
        {
            {1,1,1},
            {1,1,1},
            {1,1,1}
        },
        1,
        3
    );

    runTest(
        {
            {1}
        },
        1,
        4
    );

    runTest(
        {
            {1,1,0,0},
            {1,1,0,0},
            {0,0,1,1},
            {0,0,1,1}
        },
        2,
        5
    );

    return 0;
}