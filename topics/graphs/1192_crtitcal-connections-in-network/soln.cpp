#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> bridges;
    int timer=0;
    void dfs(int u, int parent, vector<int>&tin, vector<int>&low, vector<int>&visited, vector<vector<int>>&adj){
        visited[u]=1;
        low[u]=tin[u]=timer++;

        for(int nei: adj[u]){
            if(nei==parent) continue;

            if(visited[nei]==0){
                dfs(nei, u, tin, low, visited, adj);
                low[u]=min(low[u], low[nei]);
                if(low[nei]>tin[u]) bridges.push_back({u, nei});
            }
            else{
                low[u]=min(low[u], tin[nei]);
            }
        }
        return;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector <vector<int>> adj(n);
        for(auto &x: connections){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
        }

        vector <int> low(n);
        vector <int> tin(n);
        vector <int> visited(n);

        for(int i=0; i<n; i++){
            if(visited[i]==0){
                dfs(i, i, tin, low, visited, adj);
            }
        }
        return bridges;
    

    }
};

int main() {

    Solution sol;

    // PASS 1
    {
        int n = 4;
        vector<vector<int>> connections = {
            {0,1},
            {1,2},
            {2,0},
            {1,3}
        };

        vector<vector<int>> expected = {
            {1,3}
        };

        auto ans = sol.criticalConnections(n, connections);

        cout << "PASS 1\n";
        cout << "Expected: [[1,3]]\n";
        cout << "Actual  : <your output>\n\n";
    }

    // PASS 2
    {
        int n = 2;
        vector<vector<int>> connections = {
            {0,1}
        };

        vector<vector<int>> expected = {
            {0,1}
        };

        auto ans = sol.criticalConnections(n, connections);

        cout << "PASS 2\n";
        cout << "Expected: [[0,1]]\n";
        cout << "Actual  : <your output>\n\n";
    }

    // PASS 3
    {
        int n = 5;
        vector<vector<int>> connections = {
            {0,1},
            {1,2},
            {2,0},
            {1,3},
            {3,4}
        };

        vector<vector<int>> expected = {
            {1,3},
            {3,4}
        };

        auto ans = sol.criticalConnections(n, connections);

        cout << "PASS 3\n";
        cout << "Expected: [[1,3],[3,4]] (order may vary)\n";
        cout << "Actual  : <your output>\n\n";
    }

    // PASS 4
    {
        int n = 6;
        vector<vector<int>> connections = {
            {0,1},
            {1,2},
            {2,0},
            {2,3},
            {3,4},
            {4,5},
            {5,3}
        };

        vector<vector<int>> expected = {
            {2,3}
        };

        auto ans = sol.criticalConnections(n, connections);

        cout << "PASS 4\n";
        cout << "Expected: [[2,3]]\n";
        cout << "Actual  : <your output>\n\n";
    }

    // PASS 5
    {
        int n = 7;
        vector<vector<int>> connections = {
            {0,1},
            {1,2},
            {2,0},
            {1,3},
            {3,4},
            {4,5},
            {5,3},
            {5,6}
        };

        vector<vector<int>> expected = {
            {1,3},
            {5,6}
        };

        auto ans = sol.criticalConnections(n, connections);

        cout << "PASS 5\n";
        cout << "Expected: [[1,3],[5,6]] (order may vary)\n";
        cout << "Actual  : <your output>\n\n";
    }


    return 0;
}