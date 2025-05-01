//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#define ll int
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<ll> prev;
        ll mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            vector<ll> curr(i+1,1);
            for(int j=1;j<i;j++)
            {
                curr[j]=(prev[j-1]+prev[j])%mod;
            }
            prev=curr;
        }
       
        return prev;
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends