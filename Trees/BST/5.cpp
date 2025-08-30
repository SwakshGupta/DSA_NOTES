
/*
Recover BST so two nodes of BST are swapped now we have to make it correct 

1. One method is via creating a inorder vector and sort it that would be our correct BST now we will compare that vector with the BST and correct all the value 
simultaneously 

2.If we have 2 voilation  then we will swap the first and the last elements 

3. IF we have 1 voilation then we will swap fist and middle element 
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};


class Solution {
    TreeNode* first;  // these all will tell us about first and second voilation 
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

private:
    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);

        if (prev != NULL && (root->val < prev->val)) // this means there is a voilation here
        {
            // 

            if (first == NULL) // if this is the first voilation then we will mark first=prev and middle=root (first==NULL means first voilation otherwise we would have stored something in the first variable)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root; // if this is the second voilation then we will mark last=root
            }
        }

        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);

        if (first && last) {
            swap(first->val, last->val); // if this is the second voilation then we will have first and last !=NULL and we will simply swap them 
        }
        else if (first && middle) {
            swap(first->val, middle->val); // if only one voilation found
        }
    }
};
