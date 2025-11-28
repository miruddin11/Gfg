class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        vector<int> ans;
        int totalXOR = 0;
        for (int i = 1; i <= n; i++) {
            totalXOR ^= i;
        }
        if (totalXOR == n) {
            for (int i = 1; i <= n; i++) ans.push_back(i);
        } else {
            int x = totalXOR ^ n;
            for (int i = 1; i <= n; i++) {
                if (i != x) ans.push_back(i);
            }
        }
        return ans;
    }
};
