//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPS(string &s) {
        // code here
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0,k=i;k<n;k++,j++){
                if(j==k) dp[j][k]=1;
                else if(i==1){
                    dp[j][k]=s[j]==s[k]?2:0;
                    if(dp[j][k]>1) count++;
                }
                else{
                    int dia=dp[j+1][k-1];
                    dp[j][k]=s[j]==s[k] and dia?2+dia:0;
                    if(dp[j][k]>1) count++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends