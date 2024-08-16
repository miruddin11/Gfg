//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    vector<int> dp;
    //Function to find the maximum number of cuts.
    int solve(int n,int x,int y,int z)
    {
        if(n==0){
            return 0;
        }
        if(n<x&&n<y&&n<z){
            return INT_MIN;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int a=solve(n-x,x,y,z)+1;
        int b=solve(n-y,x,y,z)+1;
        int c=solve(n-z,x,y,z)+1;
        return dp[n]=max(a,max(b,c));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        dp.resize(n+1,-1);
        int ans=solve(n,x,y,z);
        return (ans<0)?0:ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends