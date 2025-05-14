//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string fun( int n )
    {
        if( n == 1 ) return "1" ;
        string s = fun( n-1) ;
        string res = "";
        int i = 0 ;
        int j = 0 ;
        while( j < s.length() )
        {
            if( s[j] == s[i] )j++ ;
            else 
            {  
                res += to_string(j-i) ;
                res += s[i] ;
                i = j ;
            }
        }
        
        res +=  to_string(j-i) ;
        res +=  s[i] ;
        return res ;
    }
    string countAndSay(int n) {
        // code here
        return fun(n);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends