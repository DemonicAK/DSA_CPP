#include <bits/stdc++.h> // Include every standard library
using namespace std;

class Solution
{
public:
    int f(int idx, vector<int> &dp, vector<int> &nums)
    {
        if (dp[idx] != -1)
            return dp[idx];
        if (idx < 0)
            return 0;
        if (idx == 0)
            return nums[idx];

        int pick = f(idx - 2, dp, nums) + nums[idx];
        int notpick = f(idx - 1, dp, nums);

        return dp[idx] = max(pick, notpick);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n - 1, dp, nums);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.rob(nums) << endl;
    return 0;
}
