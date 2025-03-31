//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int x[26]={0};
        for(int i=0;i<s.length();i++) {
            x[s[i]-'a'] = i;
        }
        int y = 0;
        int last = 0;
        for(int i=0;i<s.size();i++) {
            char ch = s[i];
            last = max(last, x[ch - 'a']);
            if(last == i){
                y++;
            }
        }
        return y;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends