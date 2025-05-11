//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++){
            int x=0;
            for(int j=i;j<n;j++){
                x+=arr[j];
                if(pq.size()<k) pq.push(x);
                else if(pq.top()<x) pq.pop(),pq.push(x);
                
            }
        }
        return pq.top();
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends