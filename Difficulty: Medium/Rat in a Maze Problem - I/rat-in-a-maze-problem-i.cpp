//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<string> ans;
    vector<int>row= { 1 ,-1 , 0 , 0 };
    vector<int>col= { 0 , 0 , 1 ,-1 };
    vector<char>dir= {'D','U','R','L'};
    void solve(int i,int j,vector<vector<int>> &mat,string &temp)
    {
        if(i<0||j<0||i==mat.size()||j==mat.size()||mat[i][j]==0)
        {
            return;
        }
        if(i==mat.size()-1&&j==mat.size()-1){
            ans.push_back(temp);
            return;
        }
        mat[i][j]=0;
        for(int x=0;x<4;x++)
        {
            temp.push_back(dir[x]);
            solve(i+row[x],j+col[x],mat,temp);
            temp.pop_back();
        }
        mat[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        string temp="";
        solve(0,0,mat,temp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends