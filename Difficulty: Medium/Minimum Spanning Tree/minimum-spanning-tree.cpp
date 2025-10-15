class Solution {
  public:
    typedef pair<int,int> P;
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<P>> adj;
        for(auto &e:edges){
            int u=e[0],v=e[1],wt=e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<bool> inMST(V,false);
        pq.push({0,0});//wt,node
        int sum=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int node=p.second,wt=p.first;
            if(inMST[node]==true){
                continue;
            }
            inMST[node]=true;
            sum+=wt;
            for(auto &[nbr,nbr_w]:adj[node]){
                if(inMST[nbr]==false){
                    pq.push({nbr_w,nbr});
                }
            }
        }
        return sum;
    }
};