/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    unordered_map<Node*,int> dp;
    int solve(Node* node){
        if(node==nullptr){
            return 0;
        }
        if(dp.count(node)>0){
            return dp[node];
        }
        // if root is taken
        int sum=node->data;
        if(node->left!=nullptr){
            sum+=solve(node->left->left);
            sum+=solve(node->left->right);
        }
        if(node->right!=nullptr){
            sum+=solve(node->right->left);
            sum+=solve(node->right->right);
        }
        // if root not taken
        int res=solve(node->left)+solve(node->right);
        return dp[node]=max(sum,res);
    }
    int getMaxSum(Node *root) {
        // code here
        dp.clear();
        return solve(root);
    }
};