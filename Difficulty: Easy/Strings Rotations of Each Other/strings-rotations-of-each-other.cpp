//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        string combined = s1 + s1;
        return isSubstringKMP(combined, s2);
    }
    
private:
    // KMP-based substring search
    bool isSubstringKMP(const string &text, const string &pattern) {
        int n = text.size();
        int m = pattern.size();
        
        // Build the LPS array
        vector<int> lps = computeLPSArray(pattern);
        
        int i = 0, j = 0; // i -> text index, j -> pattern index
        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
                if (j == m) {
                    return true; // Match found
                }
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }
    
    // Compute the LPS (Longest Prefix Suffix) array for KMP
    vector<int> computeLPSArray(const string &pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);
        int len = 0; // Length of previous LPS
        
        for (int i = 1; i < m;) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends