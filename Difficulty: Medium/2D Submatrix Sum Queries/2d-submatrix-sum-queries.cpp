class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> prefSum(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                prefSum[i][j]=mat[i-1][j-1]+prefSum[i-1][j]+prefSum[i][j-1]-prefSum[i-1][j-1];
            }
        }
        vector<int> ans;
        for(auto &vec:queries){
            int r1=vec[0],c1=vec[1],r2=vec[2],c2=vec[3];
            int res=prefSum[r2+1][c2+1]-prefSum[r1][c2+1]-prefSum[r2+1][c1]+prefSum[r1][c1];
            ans.push_back(res);
        }
        return ans;
    }
};
