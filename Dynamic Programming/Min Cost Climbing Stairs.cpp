class Solution { //This one is the most Optimized One , T(n), S(1)
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2=0;
        int prev1=0;

        for(int i=2;i<=cost.size();i++){
            int curr=min(cost[i-1]+prev1, cost[i-2]+prev2);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};
