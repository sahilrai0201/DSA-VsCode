//Given the root of a binary tree and an integer targetSum, return true if the tree has a 
//root-to-leaf path such that adding up all the values along the path equals targetSum.

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(){
    int data;
    cin >> data;

    if(data == -1) return NULL;
    
    Node* root = new Node(data);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

bool solve(Node* root, int k, vector<int> &path){
    //base case
    if(root == NULL) return false;

    path.push_back(root->data);

    //check only at leaf node
    if(root->left == NULL && root->right == NULL){
        int sum = 0;
        for(int i=0; i<(int)path.size(); i++){
            sum += path[i];
        }
        if(sum == k){
            path.pop_back();
            return true;
        }
    }

    if(solve(root->left, k, path)){
        path.pop_back();
        return true;
    }

    if(solve(root->right, k, path)){
        path.pop_back();
        return true;
    }

    path.pop_back();
    return false;
}

bool hasPathSum(Node* root, int k){      
    vector<int> path;     
    return solve(root, k, path);        //k is target sum
}

int main(){
    cout << "Enter tree nodes in preorder (-1 for null) : " << endl;
    //5 4 7 -1 -1 8 -1 9 -1 -1 3 22 -1 -1 27 29 -1 -1 -1

    Node* root = buildTree();

    int k;
    cout << "Enter the target sum : " << endl;
    cin >> k;

    if(hasPathSum(root, k)){
        cout << "path sum do exists!" << endl;
    }
    else{
        cout << "No path sum exists" << endl;
    }

    return 0;
}