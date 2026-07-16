// You are given the head of a singly linked list and an integer x.
// Delete the xth node (1-based indexing) from the singly linked list.

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;    
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* deleteInSLL(Node* head, int pos){
    if(head == NULL){
        cout << "List is empty! " << endl;
        return NULL;
    }

    if(pos <= 0){
        cout << "Invalid Position\n";
        return head;
    }

    if(pos == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;

    for(int i=1; i<pos && curr != NULL; i++){
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){
        cout << "Position out of range\n";
        return head;
    }

    prev->next = curr->next;

    delete curr;

    return head;
}

int main(){
    Node* head = new Node(8);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(7);

    int pos;
    cout << "Enter the position you want to delete : " << endl;
    cin >> pos;

    cout << "List before deletion : " << endl;
    printList(head);

    head = deleteInSLL(head, pos);

    cout << "List after deletion : " << endl;
    printList(head);

    return 0;
}