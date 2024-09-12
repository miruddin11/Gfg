//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> dp;
    bool isPallindrome(string &s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,int j,string &s)
    {
        if(i>=j) return 0;
        if(isPallindrome(s,i,j)) return 0;
        if(dp[i]!=-1) return dp[i];
        int mnCuts=INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            if(isPallindrome(s,i,k)){
                int cuts=solve(k+1,j,s)+1;
                mnCuts=min(cuts,mnCuts);
            }
        }
        return dp[i]=mnCuts;
    }
    int palindromicPartition(string s)
    {
        // code here
        int n=s.size();
        dp.resize(n+1,-1);
        return solve(0,n-1,s);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends