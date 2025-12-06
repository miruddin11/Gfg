class Solution {
  public:
    long long f(int left, int right , int n , vector<int> &arr , vector<vector<int>> &dp){
        if(left>right) return 0;
        if(dp[left][right] != -1) return dp[left][right];
        long long takeLeft = arr[left] + min(f(left+2,right,n,arr,dp),f(left+1,right-1,n,arr,dp));
        long long takeRight = arr[right] + min(f(left,right-2,n,arr,dp),f(left+1,right-1,n,arr,dp));
        return dp[left][right] =  max(takeLeft,takeRight);
    }
    int maximumAmount(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,n-1,n,arr , dp);
    }
};