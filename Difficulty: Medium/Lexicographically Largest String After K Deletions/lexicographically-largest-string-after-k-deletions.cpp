class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        stack<char> st;
        for(auto z : s){
          while((!st.empty()) && k && (st.top() < z)){
              st.pop();
              k--;
          }
          st.push(z);
        }
        while((!st.empty()) && k){
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
