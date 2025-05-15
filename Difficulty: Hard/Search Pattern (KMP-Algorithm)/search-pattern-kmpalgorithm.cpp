//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void computeLPS(string &pat, vector<int> &LPS, int M)
    {
        int len = 0;
        LPS[0] = 0;
        int i = 1;
        while (i < M) {
            if (pat[i] == pat[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = LPS[len-1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
    vector<int> search(string& pat, string& txt) {
        // code here
        int N = txt.size();
        int M = pat.size();
        vector<int> LPS(M);
        computeLPS(pat, LPS, M);
    
        vector<int> ans;
        int i = 0, j = 0;
        while (i < N) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }
            if (j == M) {
                ans.push_back(i - j);
                j = LPS[j - 1];
            } else if(i < N && pat[j] != txt[i]) {
                if (j != 0) {
                    j = LPS[j - 1];
                } else {
                    i++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends