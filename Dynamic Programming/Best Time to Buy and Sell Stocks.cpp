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
