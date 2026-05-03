class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        auto comp = [&] (auto &a, auto &b) {
            int x=__builtin_popcount(a.first);
            int y=__builtin_popcount(b.first);
            if(x>y) return true;
            else if(x==y) return a.second<b.second;
            else return false;
        };
        int n=arr.size();
        vector<pair<int, int>>tmp;
        for(int i=0; i<n; i++){
            tmp.push_back({arr[i], i});
        }
        sort(tmp.begin(), tmp.end(),comp);
        vector<int>ans;
        for(auto &it:tmp){
            ans.push_back(it.first);
        }
        return ans;
    }
};