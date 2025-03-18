//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;
    int solve(vector<int> &arr,int targetSum,int n)
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
    bool equalPartition(vector<int>& arr) {
        // code here
        int N=arr.size();
        int sum=0;
        for(int i=0;i<N;i++) sum+=arr[i];
        int targetSum=sum/2;
        dp.resize(N+1,vector<int>(targetSum+1,-1));
        int t=solve(arr,targetSum,N);
        return t==sum-t;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends