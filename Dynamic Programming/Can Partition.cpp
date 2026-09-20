class Solution {
public:

    bool solve(int i, int target, vector<int>& nums) {

        // Target achieved
        if(target == 0)
            return true;

        // No elements left
        if(i == nums.size())
            return false;

        // Don't take
        bool notTake = solve(i + 1, target, nums);

        // Take
        bool take = false;

        if(nums[i] <= target)
            take = solve(i + 1, target - nums[i], nums);

        return take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for(int x : nums)
            sum += x;

        // Equal partition impossible if total is odd
        if(sum % 2 != 0)
            return false;

        int target = sum / 2;

        return solve(0, target, nums);
    }
};

//MEMOIZATION 
class Solution {
public:

    bool solve(int i, int target, vector<int>& nums,
               vector<vector<int>>& dp) {

        // Target achieved
        if(target == 0)
            return true;

        // No elements left
        if(i == nums.size())
            return false;

        // Already calculated
        if(dp[i][target] != -1)
            return dp[i][target];

        // Don't take
        bool notTake = solve(i + 1, target, nums, dp);

        // Take
        bool take = false;

        if(nums[i] <= target)
            take = solve(i + 1, target - nums[i], nums, dp);

        return dp[i][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for(int x : nums)
            sum += x;

        // Odd sum → cannot divide equally
        if(sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(
            nums.size(),
            vector<int>(target + 1, -1)
        );

        return solve(0, target, nums, dp);
    }
};

//TABULATION 
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for(int x : nums)
            sum += x;

        if(sum % 2 != 0)
            return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n + 1,
                                vector<bool>(target + 1, false));

        // Base case:
        // target = 0 is always possible
        for(int i = 0; i <= n; i++)
            dp[i][0] = true;

        // Fill table
        for(int i = n - 1; i >= 0; i--) {

            for(int t = 1; t <= target; t++) {

                // Don't take
                bool notTake = dp[i + 1][t];

                // Take
                bool take = false;

                if(nums[i] <= t)
                    take = dp[i + 1][t - nums[i]];

                dp[i][t] = take || notTake;
            }
        }

        return dp[0][target];
    }
};

