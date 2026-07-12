// Delete All Occurrences in a Singly Linked list : 

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next; 

    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    //deconstructor
    ~Node() {
        cout << "Memory is freed from data : " << data << endl;
    }
};

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* deleteKey(Node* head, int key){
    Node* dummy = new Node(-1);
    dummy->next = head;

    Node* prev = dummy;
    Node* curr = head;

    while(curr != NULL){
        if(curr->data == key){
            prev->next = curr->next;

            Node* temp = curr;
            curr = curr->next;

            temp->next = NULL;
            delete temp;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }

    Node* ans = dummy->next;
    delete dummy;

    return ans;
}

int main(){
    Node* head = new Node(2);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(4);

    int key;
    cout << "Enter the element you want to be deleted : " << endl;
    cin >> key;

    cout << "Original List : ";
    printList(head);

    head = deleteKey(head, key);

    cout << "List after deletion : ";
    printList(head);

    return 0;
}

// Output : 
// Enter the element you want to be deleted : 
// 4
// Original List : 2 2 1 4 4 
// Memory is freed from data : 4
// Memory is freed from data : 4
// Memory is freed from data : -1
// List after deletion : 2 2 1 