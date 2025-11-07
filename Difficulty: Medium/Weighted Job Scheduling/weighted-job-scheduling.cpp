class Solution {
  public:
    int dp[50001];
    int nextJob(vector<vector<int>> &jobs,int target,int low)
    {
        int high=jobs.size()-1;
        int result=jobs.size()+1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(jobs[mid][0]>=target){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>> &jobs,int i)
    {
        if(i>=jobs.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        //take
        int next=nextJob(jobs,jobs[i][1],i+1);
        int take=jobs[i][2]+solve(jobs,next);
        //not take
        int notTake=solve(jobs,i+1);
        return dp[i]=max(take,notTake);
    }
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
        memset(dp,-1,sizeof(dp));
        sort(begin(jobs),end(jobs));
        return solve(jobs,0);
    }
};
