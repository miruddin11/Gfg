class Solution {
  public:
    int n,m;
    vector<vector<int>> direction={{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(queue<pair<int,int>> &q,vector<vector<int>> &ans){
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int x=p.first,y=p.second;
            for(auto &dir:direction){
                int nx=x+dir[0],ny=y+dir[1];
                if(nx<0||nx>=n||ny<0||ny>=m||ans[nx][ny]!=-1){
                    continue;
                }
                q.push({nx,ny});
                ans[nx][ny]=ans[x][y]+1;
            }
        }
    }
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        bfs(q,ans);
        return ans;
    }
};