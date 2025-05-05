//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int l = 0, r = arr.size()-1;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (target == arr[mid]) return mid;
            else if (arr[mid] > target){
                if (arr[mid+1] == target) return mid+1;
                r = mid - 1;
            }
            else{
                if (arr[mid - 1] == target) return mid - 1;
                l = mid + 1;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends