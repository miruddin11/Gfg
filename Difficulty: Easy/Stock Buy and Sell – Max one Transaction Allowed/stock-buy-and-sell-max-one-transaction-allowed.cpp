//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int buyPrice=INT_MAX;
        int mxProfit=INT_MIN;
        for(auto &price:prices)
        {
            if(price<buyPrice){
                buyPrice=price;
            }
            else{
                int profit=price-buyPrice;
                mxProfit=max(mxProfit,profit);
            }
        }
        return mxProfit==INT_MIN?0:mxProfit;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends