## nlogn soln for LIS

````
vector<int> getLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> tails;
    vector<int> dp(n);

    for(int i = 0; i < n; i++) {

        int pos = lower_bound(
            tails.begin(),
            tails.end(),
            nums[i]
        ) - tails.begin();

        if(pos == tails.size())
            tails.push_back(nums[i]);
        else
            tails[pos] = nums[i];

        dp[i] = pos + 1;
    }

    return dp;
}
````

Whenever a new number x arrives:
- Find the first tail ≥ x.
- Replace it with x.
- If no such tail exists, append x.
- The position where x lands tells you the LIS length ending at that element.