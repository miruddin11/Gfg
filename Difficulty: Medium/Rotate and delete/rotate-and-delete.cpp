//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        
        int x=n/2;
        
        bool flag=false;
        int ct=1;
        for(int i=n-1; i>=0; i--)
        {
           
          if(ct==x)
                return arr[i];
             ct++;
            if(flag)
            {
                flag=false;
                continue;
            }
            else
            {
                i--;
                flag=true;
            }
              
           
        }
        
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends