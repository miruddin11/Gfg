class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        vector<int> ans;
        sort(arr.begin(),arr.end());
        for(auto &q:queries){
            int a=q[0],b=q[1];
            auto left=lower_bound(arr.begin(),arr.end(),a);
            auto right=upper_bound(arr.begin(),arr.end(),b);
            int count=right-left;
            ans.push_back(count);
        }
        return ans;
    }
};