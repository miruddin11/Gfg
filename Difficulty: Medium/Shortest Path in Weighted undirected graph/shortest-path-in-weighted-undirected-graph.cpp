//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        unordered_map<int, vector<pair<int,int>> > adj;
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }  
        vector<int> result(n+1,INT_MAX);
        vector<int> parent(n+1);
        for(int i=1;i<n+1;i++){
            parent[i]=i;
        }
        
        pq.push({0,1});// source is 1 and distance from source to source is 0
        result[1]=0;
        while(!pq.empty())
        {
            int curr=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto &nbr:adj[curr])
            {
                int node=nbr.first;
                int d=nbr.second;
                if(d+dis<result[node]){
                    result[node]=d+dis;
                    pq.push({d+dis,node});
                    parent[node]=curr;
                }
            }
        }
        if(result[n]==INT_MAX){
            return {-1};
        }
        vector<int> ans;
        ans.push_back(result[n]);
        int node=n;
        while(parent[node]!=node){
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin()+1,ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends