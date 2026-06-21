#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <unordered_set>
#include <climits>
using namespace std;

struct TestCase {
    vector<vector<int>> times;
    int n;
    int k;
    int expected;
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) { 
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> d(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(vector<int>& time : times)
            adj[time[0]].push_back({time[2], time[1]});

        d[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {
            auto [cost, v] = pq.top();
            pq.pop();

            if(cost > d[v])
                continue;
                
            for(auto& [b, a] : adj[v])
                if(d[v] + b < d[a])
                    d[a] = d[v] + b, pq.push({d[a], a});
        }

        int ans = 0;
        for(int i = 1; i <=n ; i++) {
            if(d[i] == INT_MAX)
                return -1;

            ans = max(ans, d[i]);
        }

        return ans;
    }
};

int main() {
    vector<TestCase> tests = {

        // Example 1
        {
            {{2,1,1},{2,3,1},{3,4,1}},
            4,
            2,
            2
        },

        // Example 2
        {
            {{1,2,1}},
            2,
            1,
            1
        },

        // Example 3
        {
            {{1,2,1}},
            2,
            2,
            -1
        },

        // Single Node
        {
            {},
            1,
            1,
            0
        },

        // Disconnected Graph
        {
            {{1,2,5}},
            3,
            1,
            -1
        },

        // Multiple Paths
        {
            {{1,2,5},{1,3,1},{3,2,1}},
            3,
            1,
            2
        },

        // Directed Graph
        {
            {{1,2,1},{2,3,2},{1,3,10}},
            3,
            1,
            3
        },

        // Star Graph
        {
            {{1,2,1},{1,3,2},{1,4,3},{1,5,4}},
            5,
            1,
            4
        },

        // Chain
        {
            {{1,2,1},{2,3,1},{3,4,1},{4,5,1}},
            5,
            1,
            4
        },

        // Cycle
        {
            {{1,2,1},{2,3,1},{3,1,1}},
            3,
            1,
            2
        }
    };

    int passed = 0;
    Solution sol;
    for(int i = 0; i < tests.size(); i++) {
        int result =
            sol.networkDelayTime( 
                tests[i].times,
                tests[i].n,
                tests[i].k
            );

        if(result == tests[i].expected) {
            cout << "Test " << i + 1 << ": PASS\n";
            passed++;
        } else {
            cout << "Test " << i + 1
                 << ": FAIL"
                 << " | Expected = "
                 << tests[i].expected
                 << ", Got = "
                 << result
                 << '\n';
        }
    }

    cout << "\nPassed "
         << passed
         << "/"
         << tests.size()
         << " tests\n";

    return 0;
}