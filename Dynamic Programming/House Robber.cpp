class Solution { //PURE RECURSION
public:
    int solve(int i, vector<int>& nums) {
        
        if (i < 0)
            return 0;

        int rob = nums[i] + solve(i - 2, nums);
        int skip = solve(i - 1, nums);

        return max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        return solve(n - 1, nums);
    }
};

//MEMOIZATION
class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>&dp) {
        
        if (i < 0)
            return 0;
        if(dp[i]!=-1){
            return dp[i];
        }    

        int rob = nums[i] + solve(i - 2, nums,dp);
        int skip = solve(i - 1, nums,dp);

        return dp[i]= max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);

        return solve(n - 1, nums,dp);
    }
};


