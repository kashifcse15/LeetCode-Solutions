class Solution{ // RECURSION
public:
bool solve(int ind, int target, vector<int>& arr,  vector<vector<int>>&dp){
   if(target==0) return true;
   if(ind == 0) return arr[0]==target;
   if(dp[ind][target]!=-1)  return dp[ind][target];
   bool notPick=solve(ind-1, target, arr);
   bool pick=false;
   if(arr[ind] <= target){
     pick=solve(ind-1, target-arr[ind],arr);
   }

  return dp[ind][target]=pick || notPick;
}
  bool subsetSum(vector<int>& arr, int k){
    int n=arr.size();
    return solve(n-1,k,arr);
  }
};

// MEMOIZATION
class Solution{
public:
bool solve(int ind, int target, vector<int>& arr){
   if(target==0) return true;
   if(ind == 0) return arr[0]==target;

   bool notPick=solve(ind-1, target, arr);
   bool pick=false;
   if(arr[ind] <= target){
     pick=solve(ind-1, target-arr[ind],arr);
   }

  return pick || notPick;
}
  bool subsetSum(vector<int>& arr, int k){
    int n=arr.size();
     vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return solve(n-1,k,arr,dp);
  }
};

