//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[10001];
    int solve(int idx,int k,vector<int> &arr,int n)
    {
        if(idx>=n-1){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans=1e9;
        for(int j=idx+1;j<=idx+k;j++)
        {
            if(j<n){
                ans=min(ans,abs(arr[idx]-arr[j])+solve(j,k,arr,n));
            }
        }
        return dp[idx]=ans;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        memset(dp,-1,sizeof(dp));
        int n=arr.size();
        return solve(0,k,arr,n);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends