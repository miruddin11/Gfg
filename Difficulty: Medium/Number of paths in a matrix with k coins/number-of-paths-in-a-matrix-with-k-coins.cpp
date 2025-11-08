class Solution {
  public:
    int calcWays(int i, int j, int target, const vector<vector<int>>& mat, vector<vector<vector<int>>>& dp){
        if(i >= mat.size() || j >= mat[0].size()){
            return 0;
        }
        if(target < 0){
            return 0;
        }
        if(i == mat.size()-1 && j == mat[0].size()-1){
            return (mat[i][j] == target) ? 1 : 0;
        }
        if(dp[i][j][target] != -1){
            return dp[i][j][target];
        }
        int right = calcWays(i, j+1, target - mat[i][j], mat, dp);
        int down = calcWays(i+1, j, target - mat[i][j], mat, dp);
        return dp[i][j][target] = right + down;
    }
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        vector<vector<vector<int>>> dp(mat.size(), vector<vector<int>>(mat[0].size(), vector<int>(k+1, -1)));
        calcWays(0, 0, k, mat, dp);
        return dp[0][0][k];
    }
};