/*
Deleting a node in binary search tree 


three cases will be made for the deletion of node 

1. no children in that case you have to remove the root node only

2. second case when there is one children in that case you have to remove  the root and return that children 

3. third case when there are 2 children in this case you have to go to the go leftmost side of the right node and 
then replace that node with the root ndoe and then just remove the leftmost node  

4. 



*/

#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;

    node(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

// Function to find the minimum value node in a subtree (used to replace deleted node)
node* findMin(node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from BST
node* deleteNode(node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->val) {
        root->left = deleteNode(root->left, key); // if key is greater than we will  call the right child
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            node* temp = root->right; // the right part is stored in the temp variable which would be returned after deleting the root node 
            delete root;
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left; // the right part is stored in the temp varibale so it will be reuned after deleting the root node 
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            node* temp = findMin(root->right); // Find inorder successor
            root->val = temp->val;             // Replace current node with successor's value

            root->right = deleteNode(root->right, temp->val); // Delete the successor (temp->val is present at the left side of right subtree so we will delete )
        }

        /*

     50   this is the inital tree  and we have to delete 50 
    /  \
  30    70
        /
      60
 
  
 
     60    we have replaced 50 with the inorder successor (that is the leftmost node to the root->rigt)
    /  \
  30    70
        /
      60

        
     60     we have deleted 60 
    /  \
  30    70

        
        
        
        
        
        
        */
    }

    return root;
}

// Inorder traversal to check structure
void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    int key = 50;
    root = deleteNode(root, key);

    cout << "Inorder after deleting " << key << ": ";
    inorder(root);
    cout << endl;

    return 0;
}







int main()
{




    return 0;
}