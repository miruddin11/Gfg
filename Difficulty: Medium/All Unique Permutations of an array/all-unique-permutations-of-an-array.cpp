class Solution {
  public:
   vector<vector<int>> ans;
   int n;
   void solve(vector<int> &temp,vector<int> &arr,vector<bool> &vis)
   {
       if(temp.size()==n){
           ans.push_back(temp);
           return;
       }
       for(int i=0;i<n;i++){
           if(vis[i]==false){
               temp.push_back(arr[i]);
               vis[i]=true;
               solve(temp,arr,vis);
               temp.pop_back();
               vis[i]=false;
           }
       }
   }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        vector<int> temp;
        n=arr.size();
        vector<bool> vis(n,false);
        solve(temp,arr,vis);
        sort(ans.begin(),ans.end());
        ans.erase( unique(ans.begin(),ans.end()) , ans.end());
        return ans;
    }
};