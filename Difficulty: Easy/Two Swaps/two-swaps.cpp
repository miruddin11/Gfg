//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findIndex(vector<int>&arr,int ele)
    {
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==ele)
            {
                return i;
            }
        }
        return -1;
    }
    bool checkSorted(vector<int> &arr) {
        // code here.
        bool flag=true;
      for(int i=0;i<arr.size();i++)
      {
          if(arr[i]!=(i+1))
          {
              
              flag=false;
          }
      }
      if(flag)return true;
      int cnt=0;
      for(int i=0;i<arr.size();i++)
      {
          if(arr[i]!=(i+1))
          {
              cnt++;
              if(cnt==3)
              {
                  break;
              }
              int ind=findIndex(arr,i+1);
              swap(arr[i],arr[ind]);  
          }
      }
      if(cnt<2)
      {
          return false;
      }
      for(int i=0;i<arr.size();i++)
      {
          if(arr[i]!=(i+1))
          {
              return false;
          }
      }
      return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends