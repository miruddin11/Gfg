//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int> pos;
        vector<int> neg;
        for(auto &x:arr)
        {
            if(x>=0) pos.push_back(x);
            else neg.push_back(x);
        }
        int i=0,j=0,k=0;
        while(j<pos.size()&&k<neg.size())
        {
            arr[i++]=pos[j++];
            arr[i++]=neg[k++];
        }
        while(j<pos.size()){
            arr[i++]=pos[j++];
        }
        while(k<neg.size()){
            arr[i++]=neg[k++];
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends