class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n=arr.size();
        
        stack<int>st;
        
        vector<int>ls(n,-1),rs(n,n);
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                rs[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                ls[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            int idx=rs[i]-ls[i]-1;
            if(ans[idx-1]<arr[i]){
                ans[idx-1]=arr[i];
            }
        }
        
        for(int i=n-2;i>=0;i--){
            if(ans[i]<ans[i+1])
            {
                ans[i]=ans[i+1];
            }
        }
        return ans;
    }
};