//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
    int solve(int arr[],int targetSum,int n)
    {
        if(targetSum==0||n==0){
            return 0;
        }
        if(dp[n][targetSum]!=-1){
            return dp[n][targetSum];
        }
        if(arr[n-1]<=targetSum){
            return dp[n][targetSum]=max(arr[n-1]+solve(arr,targetSum-arr[n-1],n-1),solve(arr,targetSum,n-1));
        }else{
            return dp[n][targetSum]=solve(arr,targetSum,n-1);
        }
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++) sum+=arr[i];
        int targetSum=sum/2;
        dp.resize(N+1,vector<int>(targetSum+1,-1));
        int t=solve(arr,targetSum,N);
        return t==sum-t;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends