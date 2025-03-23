//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(string &digits) {
        // Code here
        int n = digits.size();
        for(int i = 0; i < n; ++i) {
            if(digits[i] == '0') {
                if(!(i > 0 && (digits[i-1] == '1' || digits[i-1] == '2'))) {
                    return 0;
                }
            }
        }
        vector<int> dp(n + 1, -1);
        dp[n] = 1;
        for(int idx = n - 1; idx >= 0; --idx) {
            int ans = 0;
            for(int i = 1; i <= 2; ++i) {
                if(idx + i <= digits.size()) {
                    int num = stoi(digits.substr(idx, i)); 
                    if(num == 0) break;
                    if(num >= 1 && num <= 26) {
                        ans += dp[idx + i];
                    }
                }
            }
            dp[idx] = ans; 
        }
        return dp[0];
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends