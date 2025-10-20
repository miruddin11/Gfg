class Solution {
  public:
    vector<long long> precomputeCatalan(int n){
        vector<long long>catalan(n+1,0);
        catalan[0]=1;
        catalan[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                catalan[i]+=catalan[j]*catalan[i-j-1];
            }
        }
        return catalan;
    }
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<long long> catalan=precomputeCatalan(n);
        vector<int> a=arr;
        sort(a.begin(),a.end());
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[a[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            int leftCount=mp[arr[i]];
            int rightCount=n-1-leftCount;
            long long bstCount=catalan[leftCount]*catalan[rightCount];
            ans.push_back(bstCount);
        }
        return ans;
    }
};