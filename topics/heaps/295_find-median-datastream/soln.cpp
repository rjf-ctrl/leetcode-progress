#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private: 
    priority_queue<int> leftHeap;
    priority_queue< int, vector<int> , greater<int> > rightHeap;
public:
    int l, r;
    MedianFinder() {}
    
    void addNum(int num) {
        if (leftHeap.empty())
            leftHeap.push(num);
        else if (num <= leftHeap.top())
            leftHeap.push(num);
        else
            rightHeap.push(num);
        int l=leftHeap.size();
        int r=rightHeap.size();
        if(abs(l-r)>1){
            if(l>r){
                while(l-r>1){
                    rightHeap.push(leftHeap.top());
                    leftHeap.pop();
                    l--;
                    r++;
                }
            }
            if(r>l){
                while(r-l>1){
                    leftHeap.push(rightHeap.top());
                    rightHeap.pop();
                    l++;
                    r--;
                }
            }
        }
        this->l=l;
        this->r=r;
    }
    
    double findMedian() {
        if(l==r)
        return (leftHeap.top() + rightHeap.top()) / 2.0;
        if(l>r) return leftHeap.top();
        else return rightHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
bool equalDouble(double a, double b) {
    return fabs(a - b) < 1e-9;
}

void runTest(int testNo,
             vector<int> insertions,
             vector<double> expectedMedians) {

    MedianFinder mf;
    bool pass = true;

    for (int i = 0; i < insertions.size(); i++) {

        mf.addNum(insertions[i]);

        double ans = mf.findMedian();

        if (!equalDouble(ans, expectedMedians[i])) {
            pass = false;

            cout << "Test " << testNo << " Failed\n";
            cout << "After inserting "
                 << insertions[i]
                 << "\nExpected Median: "
                 << expectedMedians[i]
                 << "\nGot: "
                 << ans << "\n";

            break;
        }
    }

    if (pass)
        cout << "Test " << testNo << " Passed\n";
}

int main() {

    runTest(
        1,
        {1,2,3},
        {1.0,1.5,2.0}
    );

    runTest(
        2,
        {5,15,1,3},
        {5.0,10.0,5.0,4.0}
    );

    runTest(
        3,
        {2},
        {2.0}
    );

    runTest(
        4,
        {-1,-2,-3,-4},
        {-1.0,-1.5,-2.0,-2.5}
    );

    runTest(
        5,
        {10,20,30,40,50},
        {10.0,15.0,20.0,25.0,30.0}
    );

    return 0;
}