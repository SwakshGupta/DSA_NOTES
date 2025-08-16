/*
FInd the largest BST from a binary tree 

*/




#include <iostream>
#include <climits>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;

    node(int x) {
        val = x;
        left = right = NULL;
    }
};

int maxBSTSize = 0;

int postorder(node* root, int& minVal, int& maxVal, bool& isBST) { // this function will calculate the maxBST size 
    if (root == NULL) {
        isBST = true;
        minVal = INT_MAX;
        maxVal = INT_MIN;
        return 0;  // if root==NULL then it a leaf and leaf always forms a binary tree so we have put the values accordinly 
    }

    int leftMin, leftMax, rightMin, rightMax;
    bool leftBST, rightBST;

    int leftSize = postorder(root->left, leftMin, leftMax, leftBST);
    int rightSize = postorder(root->right, rightMin, rightMax, rightBST);

    // Check if current node forms a BST with its subtrees
    if (leftBST && rightBST && root->val > leftMax && root->val < rightMin) { // left and right bst should be true left<root<right then only we have a BST 
        isBST = true;
        minVal = min(root->val, leftMin);
        maxVal = max(root->val, rightMax);
        int currSize = leftSize + rightSize + 1;
        maxBSTSize = max(maxBSTSize, currSize);
        return maxBSTSize;
    }

    isBST = false;
    return 0;
}

int findLargestBST(node* root) {
    maxBSTSize = 0;
    int minVal, maxVal;
    bool isBST;
    postorder(root, minVal, maxVal, isBST);
    return maxBSTSize;
}

// Example usage
int main() {
    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(15);
    root->left->left = new node(1);
    root->left->right = new node(8);
    root->right->right = new node(7); // violates BST property

    cout << "Size of the largest BST is: " << findLargestBST(root) << endl;

    return 0;
}
