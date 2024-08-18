//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    vector<vector<int>> ans;
    void solve(int idx,vector<int> &candidates,vector<int> &temp,int target)
    {
        if(idx>=candidates.size()){
            return;
        }
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0){
            return;
        }
        temp.push_back(candidates[idx]);
        solve(idx,candidates,temp,target-candidates[idx]);
        temp.pop_back();
        solve(idx+1,candidates,temp,target);
    }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        set<int> st(A.begin(),A.end());
        vector<int> a;
        for(auto &x:st) a.push_back(x);
        vector<int> temp;
        solve(0,a,temp,B);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends