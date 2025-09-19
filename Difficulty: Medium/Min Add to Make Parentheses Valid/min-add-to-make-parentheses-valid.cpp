class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                if(!st.empty()&&st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(')');
                }
            }
            else{
                st.push('(');
            }
        }
        return st.size();
    }
};