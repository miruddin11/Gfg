class Solution {
  public:
    vector<string> ans;
    int n;
    vector<pair<vector<int>,char>> directions={{{0,1},'R'},{{0,-1},'L'},{{1,0},'D'},{{-1,0},'U'}};
    void solve(int i,int j,string curr,vector<vector<int>> &maze){
        if(i==n-1&&j==n-1){
            ans.push_back(curr);
            return;
        }
        maze[i][j]=0;
        for(auto &[dir,ch]:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];
            if(i_>=0&&i_<n&&j_>=0&&j_<n&&maze[i_][j_]==1){
                solve(i_,j_,curr+ch,maze);
            }
        }
        maze[i][j]=1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        n=maze.size();
        if(maze[0][0]==0) return {};
        ans.clear();
        string curr;
        solve(0,0,curr,maze);
        sort(ans.begin(),ans.end());
        return ans;
    }
};