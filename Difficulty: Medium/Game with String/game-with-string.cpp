class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        vector<int> dp(26, 0);
        for(auto &e : s){
            dp[e - 'a']++;
        }
        priority_queue<int> pq;
        for(auto &e : dp){
            if(e != 0){
                pq.push(e);
            }
        }
        int count = 0;
        while(count < k && !pq.empty()){
            int tp = pq.top();
            pq.pop();
            tp--;
            if(tp != 0){
                pq.push(tp);
            }
            count++;
        }
        int ans = 0;
        while(!pq.empty()){
            int curr = pq.top();
            pq.pop();
            ans += curr*curr;
        } 
        return ans;
    }
};