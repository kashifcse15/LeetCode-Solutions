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


//TABULATION
class Solution{
public:
   bool subsetSum(vector<int>& arr, int k){
      int n=arr.size();
      vector<vector<bool>>dp(n,vector<bool>(k+1,false));

      for(int i=0;i<n;i++){
         dp[i][0]=true;
      }
      if(arr[0]<=k){
         dp[0][arr[0]]=true;
      }

      for(int ind=1;ind<n;ind++){
         for(int target=1;target<k=k;target++){
             bool notPick=dp[n-1][k];
             bool pick=false;
             if(arr[ind] <= target){
             pick=dp[ind-1][target-arr[ind]];
             }
            dp[ind][target]=pick || notPick;
         }
      }
      return dp[n-1][k];
   }
};


// SPACE OPTIMIZATION-1
class Solution{
public:
   bool subsetSum(vector<int>& arr, int k){
      int n=arr.size();
      vector<bool>prev(k+1, false);
      vector<bool>curr(k+1, false);

      prev[0]=true;
      
      if(arr[0]<=k){
         prev[arr[0]]=true;
      }

      for(int ind=1;ind<n;ind++){
         curr[0]=true;
         for(int target=1;target<k=k;target++){
             bool notPick=prev[target];
             bool pick=false;
             if(arr[ind] <= target){
             pick=prev[target-arr[ind]];
             }
            curr[target]=pick || notPick;
         }
         prev=curr;
      }
      return prev[k];
   }
};

