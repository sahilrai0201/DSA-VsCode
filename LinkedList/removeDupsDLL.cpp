// Remove duplicates from a sorted DLL

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    
    // constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    // deconstructor
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

Node* removeDups(Node* head){
    if(head == NULL) return head;

    Node* temp = head;

    while(temp->next != NULL){
        if(temp->data == temp->next->data){
            Node* duplicate = temp->next;
            temp->next = duplicate->next;

            if(duplicate->next != NULL){
                duplicate->next->prev = temp;
            }

            duplicate->next = NULL;
            duplicate->prev = NULL;
            delete duplicate;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    Node* node1 = new Node(1);

    node1->next = new Node(1);
    node1->next->prev = node1;

    node1->next->next = new Node(1);
    node1->next->next->prev = node1->next;

    node1->next->next->next = new Node(2);
    node1->next->next->next->prev = node1->next->next;

    node1->next->next->next->next = new Node(3);
    node1->next->next->next->next->prev = node1->next->next->next;

    node1->next->next->next->next->next = new Node(4);
    node1->next->next->next->next->next->prev = node1->next->next->next->next;

    cout << "Original List : " << endl;
    printList(node1);

    node1 = removeDups(node1);

    cout << "Updated List : " << endl;
    printList(node1);

    return 0;
}