//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int m=mat.size();
        int n=mat[0].size();
        int i=0,j=n-1;
        while(i<m&&j>=0){
            if(mat[i][j]<x){
                i++;
            }else if(mat[i][j]>x){
                j--;
            }else{
                return true;
            }
        }
        return false;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends