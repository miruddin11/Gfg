class Solution {
  public:
    int solve(string s)
    {
        int n=s.length();
        int dp[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        dp[i][i]=1;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(i==j-1)
                    dp[i][j]=2;
                    else
                    dp[i][j]=2+dp[i+1][j-1];
                }
                else
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
    int minDeletions(string s) {
        // code here
        int lenofPal=solve(s);
        return (int) s.size()-lenofPal;
    }
};