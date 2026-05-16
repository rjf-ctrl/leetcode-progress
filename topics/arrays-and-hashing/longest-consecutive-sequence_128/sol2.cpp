#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<int, int> parent;
    unordered_map<int, int> sz;
public:

    int find(int x) {
        if(parent[x]==x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return;

        //union by size
        if(sz[pa]<sz[pb]) 
            swap(pa, pb);

            parent[pb] = pa;
            sz[pa] += sz[pb];
    }

    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> seen;

        for(int x: nums){
            if(seen.count(x)) continue;

            seen.insert(x);

            parent[x]=x;
            sz[x] = 1;
        }
        
        for (int x: seen){
            if (seen.count(x+1)) unite(x, x+1);
        }

        int res=0;

        for(int x: seen){
            res= max(res, sz[x]);
        }

        return res;

    }
};





int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Test Case 1 Output: "
         << sol.longestConsecutive(nums1)  << endl;
    // Expected: 4  (sequence: 1,2,3,4)

    // Test Case 2
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Test Case 2 Output: "
         << sol.longestConsecutive(nums2) << endl;
    // Expected: 9  (sequence: 0 to 8)

    // Test Case 3
    vector<int> nums3 = {9, 1, 4, 7, 3, 2, 6, 8, 5};
    cout << "Test Case 3 Output: "
         << sol.longestConsecutive(nums3) << endl;
    // Expected: 9  (sequence: 1 to 9)

    return 0;
}