class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        vector<string> a;
        for(auto &x : arr) {
            a.push_back(to_string(x));
        }
        auto comp = [&](string &a, string &b){
            return a + b > b + a;
        };
        sort(begin(a) , end(a) , comp);
        string ans = "";
        for(auto &s : a) {
            ans += s;
        }
        if(ans[0] == '0'){
            return "0";
        }
        return ans;
    }
};