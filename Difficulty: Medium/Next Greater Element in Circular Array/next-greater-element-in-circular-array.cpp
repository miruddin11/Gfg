class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            int idx=i%n;
            while(!st.empty()&&st.top()<=arr[idx]){
                st.pop();
            }
            if(i<n&&!st.empty()){
                ans[idx]=st.top();
            }
            st.push(arr[idx]);
        }
        return ans;
    }
};