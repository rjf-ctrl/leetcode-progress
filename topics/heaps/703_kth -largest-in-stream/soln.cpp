#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int> >q;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int x: nums){
            q.push(x);
            if(q.size()>k) q.pop();
        }
    }
    
    int add(int val) {
        
        q.push(val);
        if(q.size()>k) q.pop();
        return q.top();
    }
};



void runTest(int testNo, int k, vector<int> nums,
             vector<int> additions,
             vector<int> expected) {

    KthLargest obj(k, nums);

    bool pass = true;

    for (int i = 0; i < additions.size(); i++) {
        int ans = obj.add(additions[i]);
        if (ans != expected[i]) {
            pass = false;
            cout << "Test " << testNo << " Failed\n";
            cout << "Expected: " << expected[i]
                 << " Got: " << ans << "\n";
            break;
        }
    }

    if (pass)
        cout << "Test " << testNo << " Passed\n";
}

int main() {

    runTest(
        1,
        3,
        {4,5,8,2},
        {3,5,10,9,4},
        {4,5,5,8,8}
    );

    runTest(
        2,
        1,
        {},
        {-3,-2,-4,0,4},
        {-3,-2,-2,0,4}
    );

    runTest(
        3,
        2,
        {1},
        {2,3},
        {1,2}
    );

    runTest(
        4,
        3,
        {5,5,5},
        {5,5},
        {5,5}
    );

    runTest(
        5,
        4,
        {10,9,8},
        {7,6,20},
        {7,7,8}
    );

    return 0;
}