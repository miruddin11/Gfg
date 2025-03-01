//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<int>st;  
        stack<string>stt;  
        string currVal="";
        int count=0;
        
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            
            if(isdigit(ch)){
                count=count*10+(ch-'0');
            }else if(ch=='['){
                st.push(count);
                stt.push(currVal);
                currVal="";
                count=0;
            }else if(ch==']'){ 
                int x =st.top();  
                st.pop();
                
                string y=stt.top();  
                stt.pop();
                
                for(int j=0;j<x;j++){
                    y+=currVal;
                }
                currVal=y;
            }else{
                currVal+=ch;
            }
        }
        return currVal;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends