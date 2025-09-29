class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        // code here
        int n=arr.size();
        vector<int> values(n+1,0);
        for(int i=1;i<=n;i++) values[i]=values[i-1]+arr[i-1];
        multiset<int> st;
        for(int i=a;i<=b&&i<=n;i++) st.insert(values[i]);
        int mxSum=INT_MIN;
        for(int i=0;i<=n-a;i++){
            mxSum=max(mxSum,*st.rbegin()-values[i]);
            st.erase(st.find(values[i+a]));
            if(i+b+1<=n) st.insert(values[i+b+1]);
        }
        return mxSum;
    }
};