//Given a root of a Binary Tree, return its boundary traversal in the following order:
//Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over 
//the right and excluding leaves.
//Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.
//Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right 
//child over the left, excluding leaves, and added in reverse order.
//Note: The root is included once, leaves are added separately to avoid repetition, and the right 
//boundary follows traversal preference not the path from the rightmost leaf.

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void traverseLeft(TreeNode* root, vector<int> &ans){
    //base case
    if((root == NULL) || (root->left == NULL && root->right == NULL)) return;
    
    ans.push_back(root->data);
    if(root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);    
}

void traverseLeaf(TreeNode* root, vector<int> &ans){
    //base case
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(TreeNode* root, vector<int> &ans){
    //base case
    if((root == NULL) || (root->left == NULL && root->right == NULL)) return;

    if(root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);  
    
    ans.push_back(root->data);    
}

vector<int> boundaryTraversal(TreeNode* root){
    vector<int> ans;
    if(root == NULL) return ans;

    ans.push_back(root->data);

    //traverse left part
    traverseLeft(root->left, ans);

    //traverse leaf
    traverseLeaf(root->left, ans);     //left subtree
    traverseLeaf(root->right, ans);   //right subtree

    //traverse right part
    traverseRight(root->right, ans);

    return ans;
}

int main(){
    //creating tree
    TreeNode* root = new TreeNode(1);
    
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result = boundaryTraversal(root);
    for(int i : result){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}