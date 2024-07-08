//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findRotation(vector<int> &arr)
    {
        int l=0,r=arr.size()-1;
        while(l<r)
        {
            int mid=l+ (r-l)/2;
            if(arr[mid]>arr[r]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return r;
    }
    int binarySearch(int l,int r,vector<int> &arr,int target)
    {
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& arr, int key) {
        // complete the function here
        int pivot=findRotation(arr);
        int i=binarySearch(0,pivot-1,arr,key);
        if(i!=-1) return i;
        return binarySearch(pivot,arr.size()-1,arr,key);
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
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends