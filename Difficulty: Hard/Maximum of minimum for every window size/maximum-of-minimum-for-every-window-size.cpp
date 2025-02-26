//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        
        stack<int>st;
        
        vector<int>ls(n,-1),rs(n,n);
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                rs[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                ls[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            int idx=rs[i]-ls[i]-1;
            if(ans[idx-1]<arr[i]){
                ans[idx-1]=arr[i];
            }
        }
        
        for(int i=n-2;i>=0;i--){
            if(ans[i]<ans[i+1])
            {
                ans[i]=ans[i+1];
            }
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
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends