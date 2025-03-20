//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int helper(int idx, vector<int>& prices, int k, bool canBuy,  vector<vector<vector<int>>> &dp)
    {
        if(idx >= prices.size() || k <= 0)
            return 0;
        int pick = INT_MIN, notPick = INT_MIN;
        if(dp[idx][k][canBuy] != -1)
            return dp[idx][k][canBuy];
        if(canBuy)
        {
            pick = -prices[idx] + helper(idx+1, prices, k, false, dp);
            notPick  = helper(idx+1, prices, k, canBuy,dp);
        }
        else
        {
            pick = prices[idx] + helper(idx+1, prices, k-1, true, dp);
            notPick  = helper(idx+1, prices, k, canBuy,dp);
        }
        return dp[idx][k][canBuy] = max(pick,notPick);
    }
    int maxProfit(vector<int> &prices) {
        // code here
        int k=2;
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return helper(0,prices,k,true,dp);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends