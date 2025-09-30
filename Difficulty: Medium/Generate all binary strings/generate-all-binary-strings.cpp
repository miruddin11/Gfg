class Solution {
  public:
    vector<string> ans;
    int len;
    void solve(string temp){
        if(temp.size()==len){
            ans.push_back(temp);
            return;
        }
        //take 0
        temp.push_back('0');
        solve(temp);
        temp.pop_back();
        //take 1
        temp.push_back('1');
        solve(temp);
        temp.pop_back();
    }
    vector<string> binstr(int n) {
        // code here
        len=n;
        ans={};
        string temp="";
        solve(temp);
        return ans;
    }
};