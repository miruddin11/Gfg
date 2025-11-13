class Solution {
  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        int n=s1.size(),m=s2.size(),len=s3.size();
        if(n+m!=len){
            return false;
        }
        int i=0,j=0;
        while(i<n&&j<len){
            if(s1[i]==s3[j]){
                i++;
            }
            j++;
        }
        if(i!=n) return false;
        
        i=0,j=0;
        while(i<m&&j<len){
            if(s2[i]==s3[j]){
                i++;
            }
            j++;
        }
        if(i!=m) return false;
        
        return true;
    }
};