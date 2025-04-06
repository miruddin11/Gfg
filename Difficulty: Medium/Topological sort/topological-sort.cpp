//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<int>> adj;
        for(auto &vec:edges)
        {
            adj[vec[0]].push_back(vec[1]);
            // adj[vec[1]].push_back(vec[0]);
        }
        vector<int> result;
	    vector<int> inDegree(V,0);
	    for(int u=0;u<V;u++)
	    {
	        for(auto &v:adj[u])
	        {
	            inDegree[v]+=1;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(inDegree[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty())
	    {
	        int curr=q.front();
	        q.pop();
	        result.push_back(curr);
	        for(auto &nbr:adj[curr])
	        {
	            inDegree[nbr]--;
	            if(inDegree[nbr]==0){
	                q.push(nbr);
	            }
	        }
	    }
	    return result;
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(V, res, adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends