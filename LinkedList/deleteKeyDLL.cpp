// Delete all occurrences in a doubly linked list

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    //destructor
    ~Node(){
        cout << "Memory is freed from data : " << data << endl;
    }
};

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* deleteKey(Node* head, int key){
    Node* dummy = new Node(-1);
    dummy->next = head;
    if(head != NULL){
        head->prev = dummy;
    }

    Node* last = dummy;
    Node* curr = head;

    while(curr != NULL){
        if(curr->data == key){
            last->next = curr->next;

            Node* temp = curr;
            curr = curr->next;

            if(curr != NULL){
                curr->prev = last;
            }

            delete temp;
        }
        else{
            last = curr;
            curr = curr->next;
        }
    }

    Node* ans = dummy->next;
    if(ans != NULL){
        ans->prev = NULL;
    }
    delete dummy;

    return ans;
}

int main(){
    Node* head = new Node(2);
    head->next = new Node(2);
    head->next->next = new Node(10);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next->next = new Node(2);

    int key;
    cout << "Enter the element you want to be deleted : " << endl;
    cin >> key;

    cout << "Original list : ";
    printList(head);

    head = deleteKey(head, key);

    cout << "List after deletion : ";
    printList(head);

    return 0;
}

// Output : 
// Enter the element you want to be deleted : 
// 2
// Original list : 2 2 10 8 4 2 5 2 
// Memory is freed from data : 2
// Memory is freed from data : 2
// Memory is freed from data : 2
// Memory is freed from data : 2
// Memory is freed from data : -1
// List after deletion : 10 8 4 5 