//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        long long ans=0;
        int l=0,r=n-1;
        vector<int> temp;
        while(l<r)
        {
            temp.push_back(arr[l]);
            temp.push_back(arr[r]);
            l++;
            r--;
        }
        if(n%2!=0){
            temp.push_back(arr[l]);
        }
        for(int i=1;i<n;i++)
        {
            ans+=abs(temp[i]-temp[i-1]);
        }
        ans+=abs(temp[0]-temp[n-1]);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends