#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node* left = nullptr, *right = nullptr;
 
    Node() {}
    Node(int data): data(data) {}
};
 
// Function to print the inorder traversal on a given binary tree
void inorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}
 
// Recursive function to build a binary search tree from its postorder sequence
Node* buildTree(vector<int> const &postorder, int &pIndex,
                int min, int max)
{
    // Base case
    if (pIndex < 0) {
        return nullptr;
    }
 
    // Return if the next element of postorder traversal from the end
    // is not in the valid range
    int curr = postorder[pIndex];
    if (curr < min || curr > max) {
        return nullptr;
    }
 
    // Construct the root node and decrement `pIndex`
    Node* root = new Node(curr);
    pIndex--;
 
    /* Construct the left and right subtree of the root node.
       Build the right subtree before the left subtree since the values
       are being read from the end of the postorder sequence. */
 
    // Since all elements in the right subtree of a BST must be greater
    // than the root node's value, set range as `[curr+1…max]` and recur
    root->right = buildTree(postorder, pIndex, curr + 1, max);
 
    // Since all elements in the left subtree of a BST must be less
    // than the root node's value, set range as `[min, curr-1]` and recur
    root->left = buildTree(postorder, pIndex, min, curr - 1);
 
    return root;
}
 
// Build a binary search tree from its postorder sequence
Node* buildTree(vector<int> const &postorder)
{
    // start from the root node (last element in postorder sequence)
    int postIndex = postorder.size() - 1;
 
    // set the root node's range as [-INFINITY, INFINITY] and recur
    return buildTree(postorder, postIndex, INT_MIN, INT_MAX);
}
 
int main()
{
    /* Construct the following BST
              15
            /    \
           /      \
          10       20
         /  \     /  \
        /    \   /    \
       8     12 16    25
    */
 
    // postorder traversal of BST
    vector<int> postorder = { 8, 12, 10, 16, 25, 20, 15 };
 
    // construct the BST
    Node* root = buildTree(postorder);
 
    // print the BST
    cout << "Inorder traversal of BST is ";
 
    // inorder on the BST always returns a sorted sequence
    inorder(root);
 
    return 0;
}