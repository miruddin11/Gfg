class Solution {
  public:
    bool isMatch(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
        if (i < 0 && j < 0) return true;
        if (j < 0 && i >= 0) return false;          
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = isMatch(s, p, i - 1, j - 1, dp);
        if (p[j] == '*')
            return dp[i][j] = isMatch(s, p, i, j - 1, dp) || isMatch(s, p, i - 1, j, dp);
        return dp[i][j] = false;
    }
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = txt.size(), m = pat.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return isMatch(txt, pat, n - 1, m - 1, dp);
    }
};