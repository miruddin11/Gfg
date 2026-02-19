class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        unordered_set<int> st(begin(arr) , end(arr));
        vector<int> ans;
        for(int i = low; i <= high; i++) {
            if(!st.count(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};