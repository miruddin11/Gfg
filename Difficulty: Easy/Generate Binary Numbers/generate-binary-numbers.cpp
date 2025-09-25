class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string> v={"1"};
        for(int i=1,j=0,x=0;i<n;i++){
            v.push_back(v[j] + to_string(x));
            x^=1;
            if(x==0) j++;
        }
        return v;
    }
};