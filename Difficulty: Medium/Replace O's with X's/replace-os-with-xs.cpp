class Solution {
  public:
    void fill(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        vector<vector<int>> direction={{0,1},{0,-1},{1,0},{-1,0}};
        auto pushToQue=[&](int i,int j){
            if(i<0||i>=n||j<0||j>=m||vis[i][j]==true||grid[i][j]!='O'){
                return;
            }
            q.push({i,j});
            vis[i][j]=true;
        };
        for(int i=0;i<n;i++){
            pushToQue(i,0);
            pushToQue(i,m-1);
        }
        for(int j=0;j<m;j++){
            pushToQue(0,j);
            pushToQue(n-1,j);
        }
        while(!q.empty()){
            auto &[i,j]=q.front();
            q.pop();
            for(auto &dir:direction){
                int ni=i+dir[0],nj=j+dir[1];
                pushToQue(ni,nj);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false&&grid[i][j]=='O'){
                    grid[i][j]='X';
                }
            }
        }
    }
};