class Solution {
  public:
    vector<string> ans;
    int n;
    void solve(int idx,string curr,string s,int target,long long prev,long long res){
        if(idx==n){
            if(res==target){
                ans.push_back(curr);
            }
            return;
        }
        string currSt="";
        long long currRes=0;
        for(int i=idx;i<n;i++){
            if(s[idx]=='0'&&i>idx) break;
            currSt+=s[i];
            currRes=(currRes*10)+(s[i]-'0');
            if(idx==0){
                solve(i+1,currSt,s,target,currRes,currRes);
            } else{
                solve(i+1,curr+"+"+currSt,s,target,currRes,res+currRes);
                solve(i+1,curr+"-"+currSt,s,target,-currRes,res-currRes);
                solve(i+1,curr+"*"+currSt,s,target,prev*currRes,res-prev+(prev*currRes));
            }
        }
    }
    vector<string> findExpr(string &s, int target) {
        // code here
        n=s.size();
        ans.clear();
        string curr;
        solve(0,curr,s,target,0,0);
        sort(begin(ans),end(ans));
        return ans;
    }
};