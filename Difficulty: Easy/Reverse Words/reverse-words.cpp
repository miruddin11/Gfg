//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution

{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here
        vector<string> temp;
        string t="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='.'){
                if(t.size()!=0){
                    temp.push_back(t);
                    t="";
                }
            }
            else{
                t+=s[i];
            }
        }
        if(t.size()!=0){
            temp.push_back(t);
        }
        string ans="";
        for(int i=temp.size()-1;i>=0;i--)
        {
            ans=ans+temp[i]+".";
        }
        ans.pop_back();
        return ans;
    } 
};





//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends