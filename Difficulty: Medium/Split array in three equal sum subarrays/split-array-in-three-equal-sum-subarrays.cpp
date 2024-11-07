//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        int sum=0;
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            mp[sum]=i;
        }
        if(sum%3==0)
        {
            if(mp.find(sum/3)!=mp.end()&&mp.find(2*(sum/3))!=mp.end()){
                int i=mp[sum/3];
                int j=mp[2*(sum/3)];
                return {i,j};
            }
            else 
            {
                return {-1,-1};
            }
        }
        else{
            return {-1,-1};
        }
    }
};

//{ Driver Code Starts.

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends