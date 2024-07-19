//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define os tree < int ,  null_type ,  less_equal<int> ,  rb_tree_tag ,  tree_order_statistics_node_update >

class Solution {
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
        os a;
        int n=arr.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i]=a.order_of_key(arr[i]);
            a.insert(arr[i]);
        }
        return ans;
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
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends