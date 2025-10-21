class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        map<int,int> mp;
        for(auto &num:arr){
            mp[num]+=1;
        }
        vector<pair<int,int>> vec;
        for(auto &[e,f]:mp){
            vec.push_back({f,e});
        }
        sort(vec.rbegin(),vec.rend());
        vector<int> ans;
        int cnt=0;
        for(auto &v:vec){
            if(cnt>=k){
                break;
            }
            ans.push_back(v.second);
            cnt+=1;
        }
        return ans;
    }
};
