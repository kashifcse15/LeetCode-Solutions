class Solution { // RECURSION
public:
    int solve(int i, int buy, vector<int>& prices) {

        if(i == prices.size())
            return 0;

        if(buy) {
            // Buy OR skip
            return max(
                -prices[i] + solve(i + 1, 0, prices),
                solve(i + 1, 1, prices)
            );
        }
        else {
            // Sell OR skip
            return max(
                prices[i],
                solve(i + 1, 0, prices)
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        return solve(0, 1, prices);
    }
};


class Solution { // MEMOIZATION
public:
    int solve(int i, int buy, vector<int>& prices,
              vector<vector<int>>& dp) {

        if(i == prices.size())
            return 0;

        if(dp[i][buy] != -1)
            return dp[i][buy];

        if(buy) {
            return dp[i][buy] = max(
                -prices[i] + solve(i + 1, 0, prices, dp),
                solve(i + 1, 1, prices, dp)
            );
        }
        else {
            return dp[i][buy] = max(
                prices[i],
                solve(i + 1, 0, prices, dp)
            );
        }
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, 1, prices, dp);
    }
};


class Solution { // TABULATION
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for(int i = n - 1; i >= 0; i--) {

            // Can buy
            dp[i][1] = max(
                -prices[i] + dp[i + 1][0],
                dp[i + 1][1]
            );

            // Already bought → sell OR wait
            dp[i][0] = max(
                prices[i],
                dp[i + 1][0]
            );
        }

        return dp[0][1];
    }
};


class Solution { // prev+curr
public:
    int maxProfit(vector<int>& prices) {

        int nextBuy = 0;
        int nextHold = 0;

        for(int i = prices.size() - 1; i >= 0; i--) {

            int currBuy = max(
                -prices[i] + nextHold,
                nextBuy
            );

            int currHold = max(
                prices[i],
                nextHold
            );

            nextBuy = currBuy;
            nextHold = currHold;
        }

        return nextBuy;
    }
};
