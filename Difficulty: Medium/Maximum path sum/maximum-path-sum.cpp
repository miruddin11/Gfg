/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// User Fuction template for C++
/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int maxSum;
    int solve(Node *root)
    {
        if(root==nullptr){
            return 0;
        }
        int l=solve(root->left);
        int r=solve(root->right);

        int niche_hi_milgaya_ans= l + r + root->data;// (1)
        int koi_ek_accha= max(l,r) + root->data;// (2)
        int only_root_accha= root->data;// (3)

        maxSum=max({ maxSum, niche_hi_milgaya_ans, koi_ek_accha, only_root_accha });

        return max( koi_ek_accha, only_root_accha );
    }
    int findMaxSum(Node *root) {
        // code here
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
    }
};