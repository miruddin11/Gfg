//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool DFS(vector<int> adj[],int node,vector<bool> &visited,vector<bool> &inRecursion)
  {
      visited[node]=true;
      inRecursion[node]=true;
      for(auto &nbr:adj[node])
      {
          if(visited[nbr]==true && inRecursion[nbr]==true) return true;
          if(visited[nbr]==false && DFS(adj,nbr,visited,inRecursion)) return true;
      }
      inRecursion[node]=false;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V,false);
        vector<bool> inRecursion(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(DFS(adj,i,visited,inRecursion)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends