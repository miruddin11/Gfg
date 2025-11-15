class Solution {
  public:
    int dp[101][101];
    int solve(int l,int r,vector<int> &cuts)
    {
        if(r-l<2){
            return 0;
        }
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=INT_MAX;
        for(int index=l+1;index<r;index++)
        {
            int cost=cuts[r]-cuts[l]+solve(l,index,cuts)+solve(index,r,cuts);
            ans=min(ans,cost);
        }
        return dp[l][r]=ans;
    }
    int minCutCost(int n, vector<int>& cuts) {
        // code here
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        return solve(0,cuts.size()-1,cuts);
    }
};