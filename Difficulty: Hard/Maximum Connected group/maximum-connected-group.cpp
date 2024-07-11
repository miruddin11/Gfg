//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dfs(int ind,int i,int j,vector<vector<int>>& grid)
    {
        if(i>=grid.size()||i<0||j>=grid[0].size()||j<0||grid[i][j]==0||grid[i][j]==ind)
        {
            return 0;
        }
        grid[i][j]=ind;
        int up=dfs(ind,i-1,j,grid);
        int down=dfs(ind,i+1,j,grid);
        int left=dfs(ind,i,j-1,grid);
        int right=dfs(ind,i,j+1,grid);
        return 1+up+down+left+right;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int ind=2;
        int n=grid.size(),m=grid[0].size();
        map<int,int> mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1){
                    int group=dfs(ind,i,j,grid);
                    mp[ind]=group;
                    ind+=1;
                    ans=max(ans,group);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0){
                    int val=0;
                    set<int> st;
                    if(i>0) st.insert(grid[i-1][j]);
                    if(i<n-1) st.insert(grid[i+1][j]);
                    if(j>0) st.insert(grid[i][j-1]);
                    if(j<m-1) st.insert(grid[i][j+1]);
                    for(auto i:st){
                        val+=mp[i];
                    }
                    val+=1;
                    ans=max(ans,val);
                }
            }
        }
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
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends