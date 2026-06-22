#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int distance(const vector<int>& a, const vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> minDist(n, 1e9);
        minDist[0]=0;
        unordered_set <int> MST;
        int result=0;
        while(MST.size()<n){
            int node=-1;
            for(int i = 0; i < n; i++) {
                if(MST.count(i)) continue;
                if(node == -1 || minDist[i] < minDist[node])
                    node = i;
            }
            result+=minDist[node];
            MST.insert(node);
            for(int i=0; i<n; i++){
                if(MST.count(i)) continue;
                if(node==i) continue;
                minDist[i]=min(minDist[i], distance(points[i], points[node]));
            }
        }

        return result;
    }
};

void runTest(vector<vector<int>> points, int expected) {
    Solution sol;
    int result = sol.minCostConnectPoints(points);

    if (result == expected) {
        cout << "PASS\n";
    } else {
        cout << "FAIL\n";
        cout << "Expected: " << expected << "\n";
        cout << "Got:      " << result << "\n";
    }
}

int main() {

    runTest(
        {{0,0},{2,2},{3,10},{5,2},{7,0}},
        20
    );

    runTest(
        {{3,12},{-2,5},{-4,1}},
        18
    );

    runTest(
        {{0,0},{1,1},{1,0},{-1,1}},
        4
    );

    runTest(
        {{-1000000,-1000000},{1000000,1000000}},
        4000000
    );

    runTest(
        {{0,0}},
        0
    );

    runTest(
        {{0,0},{1,0}},
        1
    );

    runTest(
        {{0,0},{2,0},{4,0},{6,0}},
        6
    );

    runTest(
        {{0,0},{0,1},{1,0},{1,1}},
        3
    );

    runTest(
        {{2,-3},{-17,-8},{13,8},{-17,-15}},
        53
    );

    runTest(
        {{1,1},{3,4},{-1,0}},
        7
    );

    return 0;
}
