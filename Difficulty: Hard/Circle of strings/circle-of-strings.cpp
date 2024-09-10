//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        for(auto &adjNode : adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode, adj, vis);
            }
        }
    }
    int isCircle(vector<string> &arr) {
        int n = arr.size();
        vector<int> adj[26];
        vector<int> inDeg(26, 0), outDeg(26, 0);
        for(auto it : arr){
            int u = it[0] - 'a';
            int v = it[it.size() - 1] - 'a';
            adj[u].push_back(v);
            inDeg[v]++;
            outDeg[u]++;
        }
        for(int i=0; i<26; i++){
            if(inDeg[i] != outDeg[i])
               return 0;
        }
        vector<int> vis(26, 0);
        dfs(arr[0][0] - 'a', adj, vis);
        for(int i=0; i<26; i++){
            if(inDeg[i] and !vis[i])
               return 0;
        }
        return 1;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends