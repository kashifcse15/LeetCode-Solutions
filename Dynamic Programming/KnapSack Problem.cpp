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
