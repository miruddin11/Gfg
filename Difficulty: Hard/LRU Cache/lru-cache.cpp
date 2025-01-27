//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

struct Node {
    int key, val;
    Node *next;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = nullptr;
    }
};

class LRUCache {
  private:
    int cap;
    Node *head, *tail;
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        this->cap = cap;
        head = tail = nullptr;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if(!head) return -1;
        else if(tail->key == key) return tail->val;
        else if(head->key == key) {
            tail->next = head;
            head = head->next;
            tail = tail->next;
            tail->next = nullptr;
            return tail->val;
        }
        else {
            Node *prev = head, *cur = head->next;
            while(cur) {
                if(cur->key == key) {
                    prev->next = cur->next;
                    tail->next = cur;
                    tail = tail->next;
                    tail->next = nullptr;
                    return tail->val;
                }
                
                prev = cur;
                cur = cur->next;
            }
        }
        
        return -1;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if(!head) {
            head = tail = new Node(key, value);
            cap--;
            return;
        }
        else if(tail->key == key) {
            tail->val = value;
            return;
        }
        else if(head->key == key) {
            tail->next = head;
            head = head->next;
            tail = tail->next;
            tail->next = nullptr;
            tail->val = value;
            return;
        }
        else {
            Node *prev = head, *cur = head->next;
            while(cur) {
                if(cur->key == key) {
                    prev->next = cur->next;
                    tail->next = cur;
                    tail = tail->next;
                    tail->next = nullptr;
                    tail->val = value;
                    return;
                }
                
                prev = cur;
                cur = cur->next;
            }
        }
        
        // if not found
        tail->next = new Node(key, value);
        tail = tail->next;
        cap--;
        
        // if there was no space
        if(cap<0) {
            Node *temp = head;
            head = head->next;
            delete temp;
            cap++;
        }
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends