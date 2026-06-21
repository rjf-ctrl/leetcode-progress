#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int find(int x, vector <int> &parent){
        if(parent[x]==x) return x;
        parent[x]=find(parent[x], parent);
        return parent[x];
    }

    void union_find(int a, int b, vector <int> &parent, vector<int> &rank){
        int A=find(a, parent);
        int B=find(b, parent);

        if(A==B) return;

        if(rank[A]<rank[B]){
            int temp=A;
            A=B;
            B=temp;
        }

        parent[B]=A;
        rank[A]+=rank[B];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector <int> result;
        vector <int> rank(n+1, 1);
        vector <int> parent(n+1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
        
            for(auto&x: edges){
                int u=x[0];
                int v=x[1];

                if(find(u, parent)==find(v,parent)){
                    result=x;
                }

                else union_find(u, v, parent, rank);
            }
        
        return result;
    }
};

void runTest(vector<vector<int>> edges,
             vector<int> expected,
             int testNo) {

    Solution sol;
    vector<int> result = sol.findRedundantConnection(edges);

    bool pass =
        result.size() == expected.size();

    if(pass) {
        for(int i = 0; i < result.size(); i++) {
            if(result[i] != expected[i]) {
                pass = false;
                break;
            }
        }
    }

    cout << "Test " << testNo << ": "
         << (pass ? "PASS" : "FAIL")
         << endl;

    if(!pass) {
        cout << "Expected: ["
             << expected[0] << ", "
             << expected[1] << "]\n";

        if(result.size() == 2) {
            cout << "Got: ["
                 << result[0] << ", "
                 << result[1] << "]\n";
        }
        cout << endl;
    }
}

int main() {

    runTest(
        {{1,2},{1,3},{2,3}},
        {2,3},
        1
    );

    runTest(
        {{1,2},{2,3},{3,4},{1,4},{1,5}},
        {1,4},
        2
    );

    runTest(
        {{1,2},{2,3},{3,1}},
        {3,1},
        3
    );

    runTest(
        {{1,2},{2,3},{3,4},{4,5},{2,5}},
        {2,5},
        4
    );

    runTest(
        {{1,2},{1,3},{3,4},{2,4}},
        {2,4},
        5
    );

    return 0;
}