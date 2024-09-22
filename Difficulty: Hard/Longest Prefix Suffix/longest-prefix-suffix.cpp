//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    using ll = unsigned long long int;
    int lps(string str) {
        // Your code goes here
        ll n = str.size();
        ll prefix = 0, suffix = 0, base = 101, power = 1, mod = 1e9+7;
        int maxLen = 0;
        for(int i = 0; i < n - 1; i++){
            ll f = str[i] - 'a' + 1, s = str[n - i - 1] - 'a' + 1;
            prefix = (prefix * base + f) % mod;
            suffix = (suffix + power * s) % mod;
            power = (power * base) % mod;
            if(prefix == suffix){
                maxLen = i + 1;
            }
        }
        return maxLen;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends