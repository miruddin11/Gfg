//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int,int> mp;
        for(auto &x:arr) mp[x]+=1;
        vector<pair<int,int>> v;
        for(auto &it:mp){
            v.push_back({it.first,it.second});
        }
        auto comp=[&](auto &a,auto &b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second>b.second;
        };
        sort(v.begin(),v.end(),comp);
        vector<int> ans;
        for(auto &it:v)
        {
            int f=it.second;
            while(f--){
                ans.push_back(it.first);
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

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends