class Solution {
  public:
    unordered_map<int,string> digitWordMap;
    vector<string> ans;
    int n;
    void solve(int idx,string &temp,vector<int> &arr){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        if(arr[idx]==0||arr[idx]==1){
            solve(idx+1,temp,arr);
            return;
        }
        for(int i=0;i<digitWordMap[arr[idx]].size();i++){
            temp.push_back(digitWordMap[arr[idx]][i]);
            solve(idx+1,temp,arr);
            temp.pop_back();
        }
    }
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        ans.clear();
        n=arr.size();
        digitWordMap={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        string temp="";
        solve(0,temp,arr);
        return ans;
    }
};