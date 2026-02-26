class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        if(n!=m) return false;
        int m1[256]={0};
        int m2[256]={0};
        for(int i=0;i<n;i++){
            if(!m1[s1[i]] && !m2[s2[i]]){
                m1[s1[i]]=s2[i];
                m2[s2[i]]=s1[i];
            }
            else if(m1[s1[i]]!=s2[i]) return false;
        }
        return true ; 
    }
};