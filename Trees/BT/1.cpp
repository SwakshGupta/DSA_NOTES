// LNR LRN and other traversal are there is other notes ..... Here we have level order Traversal 

/*


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]



*/

#include<iostream>
#include<queue>
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

 vector<vector<int>> levelOrder(node* root) {
        vector<vector<int>>result;

        if(root==NULL)
        {
            return result;
        }

        queue<node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size(); // created a queue
            vector<int>same;

            for(int i=0; i<size; i++)
            {
                node*currentNode=q.front();
                q.pop();

                same.push_back(currentNode->val);

                if(currentNode->left)
                {
                    q.push(currentNode->left);
                }
                if(currentNode->right)
                {
                    q.push(currentNode->right);
                }

                
            }
            result.push_back(same);
           
        }


return result;
        
    }
};

int main()
{




    return 0;
}