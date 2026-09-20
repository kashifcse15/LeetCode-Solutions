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
