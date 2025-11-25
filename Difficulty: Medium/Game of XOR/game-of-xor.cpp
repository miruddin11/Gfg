class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n%2==0) return 0;
        int ans=0;
        int i=0;
        while(i<n)
        {
            ans^=arr[i];
            i+=2;
        }
        return ans;
    }
};