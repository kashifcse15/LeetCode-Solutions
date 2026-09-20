class Solution{ // RECURSION
  public:
    int solve(int idx, int W, vector<int>&wt, vector<int>&val){
      if(idx<0 || W==0) return 0;
      int notTake=solve(idx-1,W,wt,val);
      int take=0;
      if(wt[ind]<W){
           take=val[idx]+ solve(idx-1,W-val[ind],wt,val);
      }
      return max(take,notTake);
    }

    int knapSack(vector<int>&wt, vector<int>&val, int W){
      int n=val.size();
      return solve(n-1,W,wt,val);
    }
}


class Solution{
  public:
    int solve(int idx, int W, vector<int>&wt, vector<int>&val, vector<vector<int>>& dp){
      if(idx<0 || W==0) return 0;
      if(dp[ind][W]!=-1) return dp[ind][val];
      int notTake=solve(idx-1,W,wt,val,dp);
      int take=0;
      if(wt[ind]<W){
           take=val[idx]+ solve(idx-1,W-val[ind],wt,val,dp);
      }
      return dp[ind][W]=max(take,notTake);
    }

    int knapSack(vector<int>&wt, vector<int>&val, int W){
      int n=val.size();
      vector<vector<int>dp(n,vector<int>(n+1,-1));
      return solve(n-1,W,wt,val,dp);
    }
}


class Solution { // TABULATION
public:
    int knapSack(vector<int>& wt, vector<int>& val, int W) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        // Base case: idx = 0
        for(int w = wt[0]; w <= W; w++) {
            dp[0][w] = val[0];
        }

        // Fill the table
        for(int idx = 1; idx < n; idx++) {
            for(int w = 0; w <= W; w++){
                int notTake = dp[idx - 1][w];
                int take = 0;
                if(wt[idx] <= w) {
                    take = val[idx] + dp[idx - 1][w - wt[idx]];
                }
                dp[idx][w] = max(take, notTake);
            }
        }
        return dp[n - 1][W];
    }
};
