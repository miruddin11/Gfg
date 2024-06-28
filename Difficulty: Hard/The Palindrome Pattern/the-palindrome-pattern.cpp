//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n=arr.size();
        string s="";
        for(int i=0;i<n;i++)
        {
            bool flag=true;
            for(int j=0;j<n/2;j++)
            {
                if(arr[i][j]!=arr[i][n-j-1]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                s+=to_string(i);
                s+=" R";
                return s;
            }
        }
        for(int j=0;j<n;j++)
        {
            bool flag=true;
            for(int i=0;i<n/2;i++)
            {
                if(arr[i][j]!=arr[n-i-1][j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                s+=to_string(j);
                s+=" C";
                return s;
            }
        }
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends