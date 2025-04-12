//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int sr,int sc,vector<vector<int>>& image, int newColor,int m,int n,int col){
         image[sr][sc]=newColor;
         vector<int> dx={1,0,-1,0};
         vector<int> dy={0,-1,0,1};
         for(int i=0;i<4;i++){
             int r=sr+dx[i];
             int c=sc+dy[i];
             if(r>=0 and r<m and c>=0 and c<n and image[r][c]==col){
                 dfs(r,c,image,newColor,m,n,col);
             }
         }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int m=image.size();
        int n=image[0].size();
        int col=image[sr][sc];
        if (col == newColor) return image;
        dfs(sr,sc,image,newColor,m,n,col);
        return image;
    }
};




//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends