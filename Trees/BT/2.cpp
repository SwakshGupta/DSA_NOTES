/*

Max path sum of the binary tree 

*/

#include<iostream>
using namespace std;


struct node{

int val;
struct node*left;
struct node*right;

node(int x)
{
    val=x;
    left=NULL;
    right=NULL;
}
int maxPathSum(node*root)
{
int maxi=INT_MIN;
maxPath(root,maxi);

return maxi;
}


int maxPath(node*root,int&maxi)
{

int left=max(0,maxPath(root->left,maxi)); // since we want to return only positive value so if we are getting negative path then we will return zero instead 

int right=max(0,maxPath(root->right,maxi));

maxi=max(maxi,left+right+root->val); // here we will calulate the max Sum path 

return root->val+max(left,right); 
}

};
int main()

{





    return 0;
}