//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=0;
        const int mod=1e9+7;
        for(auto &x:arr) sum+=x;
        if((d+sum)%2!=0) return 0;
        int targetSum=(d+sum)/2;
        vector<vector<int>> dp(n+1,vector<int>(targetSum+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=targetSum;j++)
            {
                if(arr[i-1]<=j){
                    dp[i][j]=(dp[i-1][j-arr[i-1]]%mod+dp[i-1][j]%mod)%mod;
                }
                else{
                    dp[i][j]=dp[i-1][j]%mod;
                }
            }
        }
        return dp[n][targetSum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends