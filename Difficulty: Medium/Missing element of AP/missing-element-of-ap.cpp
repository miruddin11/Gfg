//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n = arr.size();
        int diff = (arr[1] - arr[0] == arr[n-1] - arr[n-2]) ? arr[1] - arr[0] : 
              ((arr[1] - arr[0] == (arr[n-1] - arr[0])/n) ? arr[1] - arr[0] : 
               arr[n-1] - arr[n-2]);
        if(diff == 0)
            return arr[0];
      	int lo = 0, hi = n - 1;
        while (lo <= hi) {     
          	int mid = (lo + hi) / 2;
            if ((arr[mid] - arr[0]) / diff == mid)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return arr[hi] + diff;
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
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends