class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        int n=arr1.size(),m=arr2.size();
        int i=0,j=m-1,mindiff=INT_MAX;
        vector<int>best;
        while(i<n && j>=0){
            int sum=arr1[i]+arr2[j];
            if(mindiff>abs(sum-x)){
                mindiff=abs(sum-x);
                best={arr1[i],arr2[j]};
            }
            if(sum>x){
                j--;
            } else if(sum<x){
                i++;
            } else {
                return {arr1[i],arr2[j]};
            }
        }
        return best;
    }
};