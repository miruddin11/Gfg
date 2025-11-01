class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        unordered_map<int,vector<int>> adj;
        vector<int> inDegree(n,0);
        for(auto &vec:prerequisites){
            int u=vec[0],v=vec[1];
            adj[v].push_back(u);
            inDegree[u]+=1;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int> order;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            order.push_back(u);
            for(auto &v:adj[u]){
                inDegree[v]-=1;
                if(inDegree[v]==0){
                    q.push(v);
                }
            }
        }
        return order;
    }
};