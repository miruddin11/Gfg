//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& nums) {
        // Your code here
        unordered_set<int> st(nums.begin(),nums.end());
        int ans=0;
        for(auto &x:nums)
        {
            if(st.find(x-1)==st.end())
            {
                int curr=x,len=1;
                while(st.find(curr+1)!=st.end())
                {
                    curr+=1;
                    len++;
                }
                ans=max(ans,len);
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
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends