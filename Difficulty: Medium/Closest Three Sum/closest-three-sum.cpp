//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int closestSum=INT_MAX;
        int resultSum=0;
        for(int i=0;i<=n-3;i++)
        {
            int l=i+1,r=n-1;
            while(l<r)
            {
                int sum=arr[i]+arr[l]+arr[r];
                if(abs(target-sum)<abs(target-closestSum)){
                    closestSum=sum;
                    resultSum=sum;
                }
                else if(abs(target-sum)==abs(target-closestSum)){
                    resultSum=max(sum,resultSum);
                }
                if(sum<target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return resultSum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends