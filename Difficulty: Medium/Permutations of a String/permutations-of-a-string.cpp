//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    void backtrack(string &s, vector<string> &result, int index) {
        if (index == s.size()) {
            result.push_back(s);
            return;
        }

        unordered_set<char> seen;
        for (int i = index; i < s.size(); i++) {
            if (seen.find(s[i]) != seen.end()) {
                continue;
            }
            seen.insert(s[i]);
            swap(s[i], s[index]);
            backtrack(s, result, index + 1);
            swap(s[i], s[index]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string> result;
        backtrack(s, result, 0);
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends