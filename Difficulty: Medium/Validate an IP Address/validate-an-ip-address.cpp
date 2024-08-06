//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        int cntDot=count(str.begin(),str.end(),'.');
        if(cntDot!=3){
            return false;
        }
        string temp="";
        int n=str.size();
        for(int i=0;i<n;i++)
        {
            if(isdigit(str[i])||str[i]=='.'){
                if(str[i]!='.'){
                    temp+=str[i];
                }
                else{
                    if(temp.empty()||(temp[0]=='0'&&temp.size()>1)){
                        return false;
                    }
                    int val=stoi(temp);
                    if(val>255||val<0){
                        return false;
                    }
                    temp="";
                }
            }else{
                return false;
            }
        }
        int val=256;
        if(temp.empty()){
            return false;
        }else{
            val=stoi(temp);
        }
        if((temp[0]=='0'&&temp.size()>1)||val>255||val<0) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends