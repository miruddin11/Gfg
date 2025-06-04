class Solution {
  public:
    int lcsOf3(string& A, string& B, string& C) {
        // Code here
        int n1=A.size(),n2=B.size(),n3=C.size();
        int dp[n1+1][n2+1][n3+1];
            for(int i=0;i<=n1;i++)
            {
                for(int j=0;j<=n2;j++)
                {
                    for(int k=0;k<=n3;k++)
                    {
                        if(i==0||j==0||k==0) dp[i][j][k]=0;
                        else if(A[i-1]==B[j-1]&&B[j-1]==C[k-1]){
                            dp[i][j][k]=1+dp[i-1][j-1][k-1];
                        }
                        else{
                            dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                        }
                    }
                }
            }
            return dp[n1][n2][n3];
    }
};
