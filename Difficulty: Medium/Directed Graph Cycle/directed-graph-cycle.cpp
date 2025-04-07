//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   bool isCycleDFS(unordered_map<int,vector<int>> &adj,int u,vector<bool> &visited,vector<bool> &inRecursion)
    {
        visited[u]=true;
        inRecursion[u]=true;
        for(auto v:adj[u]){
            if(!visited[v]&&isCycleDFS(adj,v,visited,inRecursion)){
                return true;
            }
            else if(inRecursion[v]==true){
                return true;
            }
        }
        inRecursion[u]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,vector<int>> adj;
        for(auto &vec:edges)
        {
            adj[vec[0]].push_back(vec[1]);
        }
        vector<bool> visited(V,false),inRecursion(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i]){
                if(isCycleDFS(adj,i,visited,inRecursion)){
                    return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends