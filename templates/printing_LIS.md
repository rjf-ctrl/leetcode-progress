# Printing Longest Increasing Subsequence

Keep track of parent array and end of list and backtrack to print
````
int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    int n = nums.size();

    vector<int> dp(n, 1);
    vector<int> parent(n, -1);

    int lisEnd = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }

        if(dp[i] > dp[lisEnd])
            lisEnd = i;
    }

    vector<int> lis;

    while(lisEnd != -1) {
        lis.push_back(nums[lisEnd]);
        lisEnd = parent[lisEnd];
    }

    reverse(lis.begin(), lis.end());

    cout << "Length = " << lis.size() << "\n";
    cout << "LIS = ";

    for(int x : lis)
        cout << x << " ";

    cout << "\n";
}
````