//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        if(arr[0]==0) return -1;
        int jump = 1;
        int pos = 0;
        while (pos + arr[pos] < arr.size() - 1) {
            int max = 0;
            int tpos = pos;
            for (int i = pos + 1; i <= pos + arr[pos]; i++) {
                if (i > arr.size()) {
                    break;
                }
                if (max < i + arr[i]) {
                    max = i + arr[i];
                    tpos = i;
                }
            }
            if (pos == tpos) {
                return -1;
            } else {
                pos = tpos;
                jump += 1;
            }
        }
        return jump;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends