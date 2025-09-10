
/*
Recover BST so two nodes of BST are swapped now we have to make it correct 

1. Find inorder of BST then we will check for the elements which are not sorted in the ascending order

2. And then we can either sort them that would be brute force method or either check for voilation 1 and voilation 2

3. We will create four variables prev,middle,first,last which will store these voilation if there are two voilations

4. Then we will swap first and last variable else we will swap first and the middle variable 




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
    TreeNode* first;  // we have made four pointers which will be poiting to the voilating nodes 
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
