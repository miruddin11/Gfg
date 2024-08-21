//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        unordered_map<int,vector<int>> adj;
        for(auto &vec:edges)
        {
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dis(N,-1);
        queue<int> q;
        q.push(src);
        dis[src]=0;
        vector<bool> vis(N,false);
        vis[src]=true;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto &nbr:adj[curr])
            {
                if(!vis[nbr]){
                    dis[nbr]=dis[curr]+1;
                    vis[nbr]=true;
                    q.push(nbr);
                }
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends