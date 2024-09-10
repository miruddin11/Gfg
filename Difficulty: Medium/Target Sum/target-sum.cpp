//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    long long findTargetSumWays(int n, vector<int>& arr, int target) {
        // Your code here
        int sum=0;
        int d=target;
        const int mod=1e9+7;
        for(auto &x:arr) sum+=x;
        if(sum<d||d<-sum||(d+sum)%2!=0) return 0;
        int targetSum=(d+sum)/2;
        vector<vector<long long>> dp(n+1,vector<long long>(targetSum+1,0));
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
        int N;

        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(N, arr, target);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends