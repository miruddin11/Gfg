class Solution {
  public:
    string caseSort(string& s) {
        // code here
        string hi = "", lo = "";
        for(auto x:s){
            if(isupper(x)) hi += x;
            else lo += x;
        }
        sort(hi.begin(),hi.end());
        sort(lo.begin(),lo.end());
        int i=0,j=0;
        for(int k = 0;k<s.size();k++){
            if(isupper(s[k]))s[k]=hi[i++];
            else s[k] = lo[j++];
        }
        return s;
    }
};