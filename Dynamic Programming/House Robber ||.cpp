class Solution { //RECURSION 
public:
    int solve(vector<int>& nums, int i, int end) {
        if (i > end) return 0;

        int rob = nums[i] + solve(nums, i + 2, end);
        int skip = solve(nums, i + 1, end);

        return max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        int case1 = solve(nums, 0, n - 2);
        int case2 = solve(nums, 1, n - 1);

        return max(case1, case2);
    }
};

//MEMORIZATION 
class Solution {
public:
    int solve(vector<int>& nums, int i, int end,
              vector<int>& dp) {
        
        if (i > end) return 0;

        if (dp[i] != -1) return dp[i];

        int rob = nums[i] + solve(nums, i + 2, end, dp);
        int skip = solve(nums, i + 1, end, dp);

        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> dp(n, -1);

        int case1 = solve(nums, 0, n - 2);

        fill(dp.begin(), dp.end(), -1);

        int case2 = solve(nums, 1, n - 1);

        return max(case1, case2);
    }
};
