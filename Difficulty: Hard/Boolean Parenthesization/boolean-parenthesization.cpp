//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<vector<long long>>> dp;
    int mod=1003;
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
                if(isTrue) ways=(ways%mod+leftT*rightF + leftF*rightT+ leftT*rightT)%mod;
                else ways=(ways%mod+leftF*rightF)%mod;
            }
            else if(s[k]=='&'){
                if(isTrue) ways= (ways%mod+leftT*rightT)%mod;
                else ways= (ways%mod+leftT*rightF + leftF*rightT + leftF*rightF)%mod;
            }
            else if(s[k]=='^'){
                if(isTrue) ways=(ways%mod+leftT*rightF + leftF*rightT)%mod;
                else ways= (ways%mod+leftT*rightT + leftF*rightF)%mod;
            }
        }
        return dp[i][j][isTrue]=ways%mod;
    }
    int countWays(int n, string s){
        // code here
        dp.resize(n,vector<vector<long long>>(n,vector<long long>(2,-1)));
        return solve(s,0,n-1,true);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends