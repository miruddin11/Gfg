//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int mxLen=1;
        int n=s.size();
        int i=0,j=0;
        unordered_set<int> st;
        while(j<n)
        {
            while(st.find(s[j])!=st.end()&&i<n)
            {
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            mxLen=max(mxLen,j-i+1);
            j++;
        }
        return mxLen;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends