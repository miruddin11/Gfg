//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<vector<int>> dp;
    int solve(int e,int f)
    {
        if(f==1||f==0) return f;
        if(e==1) return f;
        if(dp[e][f]!=-1) return dp[e][f];
        int ans=INT_MAX;
        int low=1,high=f;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int a=solve(e-1,mid-1);
            int b=solve(e,f-mid);
            int x=max(a,b)+1;
            ans=min(ans,x);
            if(a>b) high=mid-1;
            else low=mid+1;
        }
        return dp[e][f]=ans;
    }
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        dp.resize(n+1,vector<int>(k+1,-1));
        return solve(n,k);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends