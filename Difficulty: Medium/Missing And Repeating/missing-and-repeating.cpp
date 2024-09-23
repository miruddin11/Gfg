//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_set<int> st;
        int v1;
        for(auto &x:arr){
            if(st.find(x)!=st.end()){
                v1=x;
            }
            st.insert(x);
        }
        int v2;
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()){
                v2=i;
                break;
            }
        }
        return {v1,v2};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends