/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int moves;
    int solve(Node* root){
        if(root==nullptr){
            return 0;
        }
        int l=solve(root->left);
        int r=solve(root->right);
        moves+=abs(l)+abs(r);
        return (l+r+root->data)-1;
    }
    int distCandy(Node* root) {
        // code here
        moves=0;
        solve(root);
        return moves;
    }
};