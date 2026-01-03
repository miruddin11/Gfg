/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class compare{
    public:
    bool operator()(Node* a, Node* b){
        if(a->data <= b->data)return false;
        return true;
    }
};
class Solution {
  public:
    Node *flatten(Node *root) {
        priority_queue<Node*, vector<Node*>, compare> q;
        Node* itr = root;
        while(itr)
        {
            q.push(itr);
            itr=itr->next;
        }
        
        Node* hook = new Node(-1);
        itr = hook;
        while(!q.empty()){
            Node* node = q.top();
            q.pop();
            
            itr->bottom = node;
            itr = itr->bottom;
            if(node->bottom)q.push(node->bottom);
        }
        return hook->bottom;
    }
};