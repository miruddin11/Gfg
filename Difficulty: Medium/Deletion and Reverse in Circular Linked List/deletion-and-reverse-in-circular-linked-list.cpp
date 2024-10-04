//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        // code here
        Node* next_=head->next;
        Node* temp=NULL;
        Node* last = head;
        
        while(next_!=last)
        {
            temp=next_->next;
            next_->next=head;
            head=next_;
            next_=temp;
        }
        
        last->next = head;
        
        return head;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        // code here
        if(!head->next)
        return NULL;
        
        Node* prev = head;
        Node* curr = head->next;
        Node* ansNode = NULL;
        
        if(head->data==key)
        {
            ansNode = head->next;
            while(curr!=head)
            {
                prev=curr;
                curr=curr->next;
            }
            
            prev->next=curr->next;
            
            return ansNode;
            
        }
        else
        ansNode = head;
        
        
        Node* flag = curr;
        
        do
        {
            if(curr->data==key)
            {
                prev->next = curr->next;
                return ansNode;
            }
            prev = curr;
            curr = curr->next;
            
        }
        while(curr!=flag);
        
        return ansNode;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends