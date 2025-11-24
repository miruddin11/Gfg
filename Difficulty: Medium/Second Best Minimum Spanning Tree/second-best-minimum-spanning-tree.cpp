class Solution {
  public:
    vector<int> parent,rank;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent==y_parent){
            return;
        }
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]+=1;
        }
    }
    int kruskal(int V,vector<vector<int>>&edges,int block){
        for(int i=0;i<V;i++){parent[i]=i;rank[i]=1;}
        int c=0,s=0;
        for(int i=0;i<edges.size();i++){
            if(i==block)continue;
            int a=edges[i][0],b=edges[i][1],w=edges[i][2];
            if(find(a)!=find(b)){
                Union(a,b);
                s+=w;
                c++;
            }
        }
        if(c!=V-1)return 1e9;
        return s;
    }
    int secondMST(int V, vector<vector<int>> &edges) {
        // code here
        parent.resize(V);
        rank.resize(V,1);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        auto comp=[&](auto &a,auto &b){
            return a[2]<b[2];
        };
        sort(edges.begin(),edges.end(),comp);
        int n=edges.size();
        vector<int>use;
        int mst=0;
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0],b=edges[i][1],w=edges[i][2];
            if(find(a)!=find(b)){
                Union(a,b);
                mst+=w;
                use.push_back(i);
            }
        }
        int ans=1e9;
        for(int x:use){
            int v=kruskal(V,edges,x);
            if(v>mst)ans=min(ans,v);
        }
        return ans==1e9?-1:ans;
    }
};