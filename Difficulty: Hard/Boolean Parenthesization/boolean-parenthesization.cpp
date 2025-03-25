//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    vector<vector<vector<long long>>> dp;
    int solve(string &s,int i,int j,bool isTrue)
    {
        if(i>j) return 0;
        if(i==j){
            if(isTrue) return s[i]=='T';
            else return s[i]=='F';
        }
        if(dp[i][j][isTrue]!=-1){
            return dp[i][j][isTrue];
        }
        int ways=0;
        for(int k=i+1;k<=j-1;k+=2)
        {
            long long leftT=solve(s,i,k-1,true);
            long long leftF=solve(s,i,k-1,false);
            long long rightT=solve(s,k+1,j,true);
            long long rightF=solve(s,k+1,j,false);
            if(s[k]=='|'){
                if(isTrue) ways=(ways+leftT*rightF + leftF*rightT+ leftT*rightT);
                else ways=(ways+leftF*rightF);
            }
            else if(s[k]=='&'){
                if(isTrue) ways= (ways+leftT*rightT);
                else ways= (ways+leftT*rightF + leftF*rightT + leftF*rightF);
            }
            else if(s[k]=='^'){
                if(isTrue) ways=(ways+leftT*rightF + leftF*rightT);
                else ways= (ways+leftT*rightT + leftF*rightF);
            }
        }
        return dp[i][j][isTrue]=ways;
    }
    int countWays(string &s) {
        // code here
        int n=s.size();
        dp.resize(n,vector<vector<long long>>(n,vector<long long>(2,-1)));
        return solve(s,0,n-1,true);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends