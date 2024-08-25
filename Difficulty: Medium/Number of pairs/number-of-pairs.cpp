//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double transformedValue(int x) {
        return x / log2(x);
    }
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
        int n = arr.size();
        int m = brr.size();
        vector<double> bin(m);
        for (int i = 0; i < m; i++) {
            bin[i] = transformedValue(brr[i]);
        }
        sort(bin.begin(), bin.end());
        
        long long ans = 0LL;
        for (auto x : arr) {
            double value = transformedValue(x);
            int l = 0, r = m;
            int validPairs = 0;
        
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (bin[mid] > value) {
                    r = mid;
                } else {
                    l = mid + 1;
                    validPairs = mid + 1;
                }
            }
            ans += m-validPairs;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends