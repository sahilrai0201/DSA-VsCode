// Remove Nth Node From End of List

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
    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << val << endl;
    }
};

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* removeKthNode(Node* head, int n){
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* slow = dummy;
    Node* fast = dummy;

    for(int i=0; i<n; i++){
        fast = fast->next;
    }

    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    Node* nodeToRemove = slow->next;

    slow->next = slow->next->next;

    nodeToRemove->next = NULL;   // Break the link
    delete nodeToRemove;

    return dummy->next;
}

int main(){

    Node* node1 = new Node(10);
    node1->next = new Node(20);
    node1->next->next = new Node(30);
    node1->next->next->next = new Node(40);
    node1->next->next->next->next = new Node(50);

    int n;
    cout << "Enter the node you want to delete from last : " << endl;
    cin >> n;

    cout << "List before deletion : " << endl;
    printList(node1);

    removeKthNode(node1, n);

    cout << "List after deletion : " << endl;
    printList(node1);

    return 0;
}