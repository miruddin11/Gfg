class Solution {
  public:
    int solve(vector<vector<int>> &grid, int i, int j,  vector<vector<int>> &dp) 
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i == n-1 && j == m-1)
            return 1;
        if(i >=n || j >= m)
            return 0;
        if(grid[i][j] == 1)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int right = solve(grid,i,j+1,dp);
        int down =  solve(grid, i+1,j,dp);
        return dp[i][j] = right + down;
        
    }
    int uniquePaths(vector<vector<int>> &grid) 
    {
         int n = grid.size();
         int m = grid[0].size();
         if(grid[n-1][m-1] == 1 || grid[0][0] == 1)
            return 0;
         vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));
         return solve(grid,0,0,dp);
    }
};