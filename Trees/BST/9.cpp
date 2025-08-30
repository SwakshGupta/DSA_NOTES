/*
FIND LCA in case of binary search tree 

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == NULL || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;

        return (left ? left : right);
    }

    this was the code which works for any subtree but we can optimize it  since in BST all the left nodes and smaller than the root
and the right side and are greater than the root 


if(p and q are lesser than the root)
explore the left side 

if(p and q are greater than the root)
explore the right side 

else 
this is the answer if one is lesser and other is greater then the given root is the LCA




*/