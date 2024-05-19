#include<bits/stdc++.h>
using namespace std;


class treeNode{
    int data;
    treeNode *leftChild;
    treeNode *RightChild;

    treeNode(int value){
        data = value;
        leftChild = NULL;
        RightChild = NULL;
    }
};

treeNode* insertionBST(treeNode* root, int value){
    treeNode* newNode = new treeNode(value);

    if(root == NULL){
        root = newNode;
        return root;
    }
    // value < root->data
    if(value < root->data){

    }


    // value > root->data
    else if(value > root->data){

    }

}


int main(){
    int n;
    cin>>n;
    treeNode *root = NULL;
    for(int i = 0; i< n; i++){
        int value;
        cin>>value;
        root = insertionBST(root, value);
    }
}