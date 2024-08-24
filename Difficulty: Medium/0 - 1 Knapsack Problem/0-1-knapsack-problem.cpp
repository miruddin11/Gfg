//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[1001][1001];
    int solve(int idx,int target,vector<int> &wt,vector<int> &val)
    {
        if(idx==wt.size()){
            return 0;
        }
        if(target==0){
            return 0;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        int take=INT_MIN,notTake=INT_MIN;
        if(wt[idx]<=target){
            take=val[idx]+solve(idx+1,target-wt[idx],wt,val);
        }
        notTake=solve(idx+1,target,wt,val);
        return dp[idx][target]=max(take,notTake);
    }
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        memset(dp,-1,sizeof(dp));
        return solve(0,W,wt,val);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends