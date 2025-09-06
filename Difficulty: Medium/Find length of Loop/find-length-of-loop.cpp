/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node *slow = head, *fast = head;
        if(!fast || !fast->next) 
            return 0;
        do {
            slow = slow->next;
            fast = fast->next->next;
        } while(fast && fast->next && slow != fast);
        if(!fast || !fast->next)
            return 0;
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        int len = 0;
        do {
            len++;
            slow = slow->next;
        } while(slow != fast);
        return len;
    }
};