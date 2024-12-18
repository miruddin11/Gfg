//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findPages(vector<int> &nums, int m) {
        // code here
        int n = nums.size();
        if(m > n){
            return -1;
        }
        int start = 0;
        int end = 0;
        for (int i = 0; i < n; i++) {
            start = max(start,nums[i]);
            end += nums[i];
        }
        while (start<end){
            int mid = start+ (end -start)/2;
            int sum = 0;
            int pieces = 1;
            for(int num: nums){
                if (sum+num > mid){
                    sum = num;
                    pieces++;

                }  else {
                    sum+= num;
                }
            }
            if(pieces>m){
                start= mid + 1;
            } else {
                end = mid;
            }
        }
        return end;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends