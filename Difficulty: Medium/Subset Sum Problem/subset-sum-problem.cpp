//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<vector<int>> dp;
    int solve(vector<int> &arr,int sum,int n)
    {
        if(sum==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(arr[n-1]<=sum){
            return dp[n][sum]=solve(arr,sum-arr[n-1],n-1)||solve(arr,sum,n-1);
        }else{
            return dp[n][sum]=solve(arr,sum,n-1);
        }
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        dp.resize(n+1,vector<int>(sum+1,-1));
        return solve(arr,sum,n)==1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends