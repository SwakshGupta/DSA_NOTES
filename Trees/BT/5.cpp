/*
Find all nodes which are at distance K from the target 

1. We will create a parent-child mapping to track all the elements 

2. Then we will create visited node which will keep track of all the visited elements in the queueu 

3. 





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

void markparent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>parent,TreeNode*target) // function to create a mapping of parent node 
{
queue<TreeNode*>queue;
queue.push(root);

while(!queue.empty())  // standared level order tarversal if left exist then push the left element into the queue and vice versa 
{
    TreeNode*current=queue.front();
    queue.pop();
    
    if(current->left)
    {
        parent[current->left]=current;
        queue.push(current->left);

    }
    if(current->right)
    {
        parent[current->right]=current;  //  if current->right exist then the parent of right is going to be current 
        queue.push(current->right);
    }
}




}




vector<int>distanceK(TreeNode*root,TreeNode*target,int k)
{

unordered_map<TreeNode*,TreeNode*>parent;
markparent(root,parent,target); // this function will give is the mapping for the parent and children mapping

unordered_map<TreeNode*,bool>visited; // keep track of the visited node 

queue<TreeNode*>q;
q.push(target);
int level=0;

while(!q.empty()) // then we are doing the regular thing of checking left and right elemetn and marking that as true 
{
int size=q.size();
if(level++==k)   // if the level is equal to k then we will break the loop and the elements present in  the queue will be our answer 
break;

for(int i=0; i<size; i++)
{
    TreeNode*temp=q.front();
    q.pop();

    if(temp->left && !visited[temp->left]) // if  left is present then push that to queue and mark that as true 
    {
        q.push(temp->left);
        visited[temp->left]=true;
    }

     if(temp->right && !visited[temp->right])
    {
        q.push(temp->right);
        visited[temp->right]=true;
    }

     if(parent[temp] && !visited[parent[temp]])
    {
        q.push(parent[temp]);
        visited[parent[temp]]=true;
    }
}
// now the queue will contain all the elements which are at distance k  so we will push that to our final  vector

vector<int>ans;
while(!q.empty())
{
    TreeNode*temp=q.front();
    q.pop();

    ans.push_back(temp->val);
}
}

}

};







int main()
{




    return 0;
}