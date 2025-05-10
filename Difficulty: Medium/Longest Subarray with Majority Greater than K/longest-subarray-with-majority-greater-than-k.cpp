//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int>mp;
        mp[0]=-1;
        int prefixsum=0,maxlen=0;
        for(int i=0;i<arr.size();i++){
            prefixsum+=(arr[i]>k)?1:-1;
            if(prefixsum>0) maxlen=i+1;
            
            if(mp.count(prefixsum-1)){
                maxlen=max(maxlen,i-mp[prefixsum-1]);
            }
            
            if(!mp.count(prefixsum)) mp[prefixsum]=i;
        }
        return maxlen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends