//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[501][501];
    int solve(int i,int j,string &s,string &t)
    {
        if(i==s.size()){
            return t.size()-j;
        }
        if(j==t.size()){
            return s.size()-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=solve(i+1,j+1,s,t);
        }
        int replace=1+solve(i+1,j+1,s,t);
        int del=1+solve(i+1,j,s,t);
        int insert=1+solve(i,j+1,s,t);
        return dp[i][j]=min(insert,min(replace,del));
    }
    int editDistance(string str1, string str2) {
        // Code here
        memset(dp,-1,sizeof(dp));
        return solve(0,0,str1,str2);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends