class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> isFlipped(n, 0);
        int flips = 0;
        int res = 0; 
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flips ^= isFlipped[i - k];
            }
            if ((arr[i] ^ flips) == 0) {
                if (i + k > n) return -1;
                res++;
                flips ^= 1;
                isFlipped[i] = 1;
            }
        }
        return res;
    }
};