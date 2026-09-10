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


//SPACE OPTIMIZE TO O(1)
class Solution {
public:
    int rob(vector<int>& nums) {

        int prev2 = 0;
        int prev1 = 0;

        for (int i = 0; i < nums.size(); i++) {

            int rob = nums[i] + prev2;
            int skip = prev1;

            int curr = max(rob, skip);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};



