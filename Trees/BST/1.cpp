/*
Given a root of binary search tree and a key(node) value, find the floor and ceil value for that particular key value.

Floor Value Node: Node with the greatest data lesser than or equal to the key value. 
Ceil Value Node: Node with the smallest data larger than or equal to the key value.
If a particular floor or ceil value is not present then output -1.

*/







#include<iostream>
using namespace std;


struct node{

int data;
struct node*left;
struct node*right;

node(int x)
{
   data=x;
    left=NULL;
    right=NULL;
}


 vector<int> floorCeilOfBST(node* root, int key) {
        int floor = -1;
        int ceil = -1;

        node* curr = root; // we have created a current element and now we will traverse across the whole tree 

        while (curr) {
            if (curr->data == key) {  
                floor = key;
                ceil = key;
                break;
            }

            if (curr->data < key) {
                floor = curr->data;  // this is  the possible value of the floor 
                curr = curr->right;
            } else {
                ceil = curr->data;  // if key is greater then that value is possibly the cei
                curr = curr->left;
            }
        }

        return {floor, ceil};
    }
};
int main()
{





    return 0;
}