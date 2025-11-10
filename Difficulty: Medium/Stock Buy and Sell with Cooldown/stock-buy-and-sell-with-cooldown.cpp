class Solution {
  public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<int> &arr,int idx,bool buy){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        int profit=0;
        if(buy){
            int take=solve(arr,idx+1,false)-arr[idx];
            int notTake=solve(arr,idx+1,true);
            profit=max({profit,take,notTake});
        }
        else{
            int sell=solve(arr,idx+2,true)+arr[idx];
            int notSell=solve(arr,idx+1,false);
            profit=max({profit,sell,notSell});
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& arr) {
        // code here
        n=arr.size();
        dp.resize(n+1,vector<int>(2,-1));
        return solve(arr,0,true);
    }
};