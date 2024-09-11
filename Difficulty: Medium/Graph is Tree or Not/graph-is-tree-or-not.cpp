//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    void DFS(int node,unordered_map<int,vector<int>> &mp,vector<bool> &vis)
    {
        vis[node]=true;
        for(auto &nbr:mp[node])
        {
            if(vis[nbr]==false){
                DFS(nbr,mp,vis);
            }
        }
    }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        if(m!=n-1) return 0;
        vector<bool> vis(n,false);
        unordered_map<int,vector<int>> mp;
        for(auto &e:adj)
        {
            int u=e[0];
            int v=e[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        DFS(0,mp,vis);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false){
                return 0;
            }
        }
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends