//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> dp;
    int solve(int i,int j,string &s,string &t)
    {
        if(i<0||j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]=1+solve(i-1,j-1,s,t);
        }
        return 0;
    }
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        int n=str1.size(),m=str2.size();
        dp.resize(n,vector<int>(m,-1));
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,solve(i,j,str1,str2));
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends