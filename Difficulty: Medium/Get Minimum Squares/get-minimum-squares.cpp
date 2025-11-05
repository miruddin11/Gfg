class Solution {
  public:
    int f(int n,int i,vector<vector<int>>&dp){
      if(n==0) return 0;
      if(i==0) return 1e9;
      if(dp[n][i]!=-1 ) return dp[n][i];
      int pick=1e9;
      int notpick=1e9;
      if (n >= i * i)
            pick=1+f(n-i*i,i,dp);
      notpick=f(n,i-1,dp);
      return dp[n][i]=min(pick,notpick);
    }
    int minSquares(int n) {
        // Code here
        int maxroot=sqrt(n);
        vector<vector<int>>dp(n+1,vector<int>(maxroot+1,-1));
        return f(n,maxroot,dp);
    }
};