//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n=str.size();
        int val=str[n-1]-'0';
        if(val<=5){
            str[n-1]='0';
        }else{
            val=10-val;
            int carry=0;
            for(int i=n-1;i>=0;i--){
                int temp=val+carry+(str[i]-'0');
                str[i]=(temp%10)+'0';
                carry=temp/10;
                val=0;
            }
            if(carry>0)str="1"+str;
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends