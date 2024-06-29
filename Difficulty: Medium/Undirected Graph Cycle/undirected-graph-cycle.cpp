//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool BFS(vector<int> adj[],int node,vector<bool> &visited)
    {
        queue<pair<int,int>> q;
        q.push({node,-1});
        visited[node]=true;
        while(!q.empty())
        {
            int curr=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto &nbr:adj[curr])
            {
                if(nbr==parent) continue;
                if(visited[nbr]==true) return true;
                q.push({nbr,curr});
                visited[nbr]=true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(BFS(adj,i,visited)){
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
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends