//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        int cnt=0;
        unordered_map<int,int> mp;
        for(int i=0;i<str.size();i++)
        {
            if(isalpha(str[i])){
                cnt+=1;
                mp[str[i]]+=1;
            }
        }
        int unique_element=mp.size();
        if(unique_element+k>=26&&cnt>=26){
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends