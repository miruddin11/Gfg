class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        sort(x.rbegin(),x.rend());
        sort(y.rbegin(),y.rend());
        int i=0,j=0;
        long long vp=1,hp=1;
        long long ans=0;
        while(i<m-1&&j<n-1)
        {
            if(y[j]<=x[i]){
                ans= ans + (long long) x[i]*vp;
                hp++;
                i++;
            }else{
                ans = ans+ (long long) y[j]*hp;
                vp++;
                j++;
            }
        }
        
        while(i<m-1){
            ans= ans + (long long) x[i]*vp;
            hp++;
            i++;
        }
        while(j<n-1){
            ans = ans+ (long long) y[j]*hp;
            vp++;
            j++;
        }
        return ans;
    }
};
