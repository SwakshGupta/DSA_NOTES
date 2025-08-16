/*
Width means maximnum number of nodes between any two nodes 

The maximum width of a binary tree is the maximum number of nodes present between the leftmost and rightmost non-null nodes at any level, 
including the null positions in between


/*

so we are using level order traversal to find the indexes of the nodes (we are also normalizing  the node) and  then finidng the maxi =max(right-left+1)


*/

#include<iostream>
#include<queue>
using namespace std;

struct TreeNode
{
int val;
TreeNode*left;
TreeNode*right;

TreeNode( int data)
{
    val=data;
    left=NULL;
    right=NULL;
}

 int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int maxi = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});  // start with index 0

        while (!q.empty()) {
            int size = q.size();
            unsigned long long minIndex = q.front().second;
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();

                // Normalize the index to prevent overflow
                index -= minIndex; // reducing the index to prevent the overflow 

                if (i == 0) first = index;       // calculated index for first variable 
                if (i == size - 1) last = index;

                if (node->left)
                    q.push({node->left, 2 * index + 1}); // created the index for the left and right for 1 based indexing 
                if (node->right)
                    q.push({node->right, 2 * index + 2});
            }

            maxi = max(maxi, (int)(last - first + 1));
        }

        return maxi;
    }









};
int main()
{




    return 0;
}