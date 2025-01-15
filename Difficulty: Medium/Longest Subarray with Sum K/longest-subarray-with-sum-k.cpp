//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int maxLen=0;
        int n=arr.size();
        unordered_map<int,int> mp;
        mp[0]=-1;
        int currSum=0;
        for(int i=0;i<n;i++)
        {
            currSum+=arr[i];
            if(mp.find(currSum-k)!=mp.end()){
                maxLen=max(maxLen,i-mp[currSum-k]);
            }
            
            if(mp.find(currSum)==mp.end()){
                mp[currSum]=i;
            }
            
        }
        return maxLen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends