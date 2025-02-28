//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#define ll long long

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<ll> st;

        for (string& s : arr) {
            if (s != "+" && s != "-" && s != "/" && s != "*") {
                st.push(stoll(s));
            } else {
                ll a = st.top();
                st.pop();
                ll b = st.top();
                st.pop();

                if (s == "+") {
                    st.push(b + a);
                } else if (s == "-") {
                    st.push(b - a);
                } else if (s == "/") {
                    st.push(b / a);
                } else if (s == "*") {
                    st.push(b * a);
                }
            }
        }
        return st.top();
    }
};




//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends