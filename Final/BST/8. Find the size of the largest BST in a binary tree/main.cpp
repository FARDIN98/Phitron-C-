#include <iostream>
#include <climits>
using namespace std;
 
// Data structure to store a BST node
struct Node
{
    // stores value of this node
    int data;
 
    // stores left and right child pointer for this node
    Node *left, *right;
 
    // constructor
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Recursive function to calculate the size of a given binary tree
int size(Node* root)
{
    // base case: empty tree has size 0
    if (root == nullptr) {
        return 0;
    }
 
    // recursively calculate the size of the left and right subtrees and
    // return the sum of their sizes + 1 (for root node)
    return size(root->left) + 1 + size(root->right);
}
 
// Recursive function to determine if a given binary tree is a BST or not
// by keeping a valid range (starting from [-INFINITY, INFINITY]) and
// keep shrinking it down for each node as we go down recursively
bool isBST(Node* node, int min, int max)
{
    // base case
    if (node == nullptr) {
        return true;
    }
 
    // if the node's value falls outside the valid range
    if (node->data < min || node->data > max) {
        return false;
    }
 
    // recursively check left and right subtrees with updated range
    return isBST(node->left, min, node->data) &&
        isBST(node->right, node->data, max);
}
 
// Recursive function to find the size of the largest BST in a given binary tree
int findLargestBST(Node* root)
{
    if (isBST(root, INT_MIN, INT_MAX)) {
        return size(root);
    }
 
    return max(findLargestBST(root->left), findLargestBST(root->right));
}
 
int main()
{
    /* Construct the following tree
 
              10
            /    \
           /      \
          15       8
         /  \     / \
        /    \   /   \
       12    20 5     2
    */
 
    Node* root = new Node(10);
 
    root->left = new Node(15);
    root->right = new Node(8);
 
    root->left->left = new Node(12);
    root->left->right = new Node(20);
 
    root->right->left = new Node(5);
    root->right->right = new Node(2);
 
    cout << "The size of the largest BST is " << findLargestBST(root);
 
    return 0;
}