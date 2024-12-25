//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &matrix) {
        // code here
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0&&vis[i][j]==0){
                    for(int k=0;k<n;k++){
                        if(matrix[k][j]!=0){
                            matrix[k][j]=0;
                            vis[k][j]=1;
                        }
                    }
                    for(int k=0;k<m;k++){
                        if(matrix[i][k]!=0)
                        {
                            matrix[i][k]=0;
                            vis[i][k]=1;
                        }
                    }
                }
            }
        }
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends