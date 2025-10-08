/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
// preorder =>  root left right
// postorder => left right root
class Solution {
  public:
    int idx;
    int n;
    Node* solve(int l,int r,vector<int> &pre,vector<int> &post){
        Node* root=new Node(pre[idx++]);
        if(l==r||idx>=n){
            return root;
        }
        auto it=find(post.begin()+l,post.begin()+r,pre[idx]);
        int index=it-post.begin();
        if(index<=r){
            root->left=solve(l,index,pre,post);
            root->right=solve(index+1,r-1,pre,post);
        }
        return root;
    }
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        idx=0;
        n=pre.size();
        return solve(0,n-1,pre,post);
    }
};