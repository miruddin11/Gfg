class Solution {
  public:
    vector<int> bfs(int node,unordered_map<int,vector<int>> &adj,int V){
        queue<int> q;
        q.push(node);
        vector<int> dist(V,-1);
        int farNode=node;
        dist[node]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &v:adj[u]){
                if(dist[v]==-1){
                    q.push(v);
                    dist[v]=dist[u]+1;
                    if(dist[v]>dist[farNode]){
                        farNode=v;
                    }
                }
            }
        }
        return {dist[farNode],farNode};
    }
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>> adj;
        for(auto &e:edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> a=bfs(0,adj,V);
        int nd=a[1];
        vector<int> b=bfs(nd,adj,V);
        return b[0];
    }
};
