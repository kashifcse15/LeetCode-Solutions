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
