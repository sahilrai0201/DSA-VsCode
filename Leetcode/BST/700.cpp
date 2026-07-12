//You are given the root of a binary search tree (BST) and an integer val.
//Find the node in the BST that the node's value equals val and return the subtree rooted with 
//that node. If such a node does not exist, return null.

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Helper to insert nodes in BST
Node* insertIntoBST(Node* root, int d){
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        //insert in right part
        root->right = insertIntoBST(root->right, d);
    }
    else{
        //insert in left part
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

// Inorder traversal (to verify BST)
void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

Node* searchInBST(Node* root, int val){
    //base case
    if(root == NULL || root->data == val){
        return root;
    }

    if(val < root->data){
        return searchInBST(root->left, val);
    }
    else{
        return searchInBST(root->right, val);
    }
}

int main(){
    Node* root = NULL;

    cout << "Enter data to create BST" << endl;
    //10 8 21 7 27 5 4 3 -1
    takeInput(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    int val;
    cout << "Enter the target : " << endl;
    cin >> val;

    Node* result = searchInBST(root, val);

    if(result != NULL){
        cout << "Node found: " << result->data << endl;
    } else {
        cout << "Node not found" << endl;
    }

    return 0;
}