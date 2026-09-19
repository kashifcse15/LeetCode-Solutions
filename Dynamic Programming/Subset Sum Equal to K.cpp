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
    return solve(n-1,k,arr);
  }
};
