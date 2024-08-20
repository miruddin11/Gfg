//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        if(n==1){
            return {0};
        }
        stack<int> st;
        st.push(arr[0]);
        vector<int> ls(n,0);
        ls[0]=0;
        for(int i=1;i<n;i++)
        {
            while(!st.empty()&&st.top()>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ls[i]=st.top();
            }
            st.push(arr[i]);
        }
        stack<int> s;
        s.push(arr[n-1]);
        vector<int> rs(n,0);
        rs[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty()&&s.top()>=arr[i]){
                s.pop();
            }
            if(!s.empty()){
                rs[i]=s.top();
            }
            s.push(arr[i]);
        }
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,abs(ls[i]-rs[i]));
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends