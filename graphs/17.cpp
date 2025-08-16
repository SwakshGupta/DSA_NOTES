/*
Floyd Warshall Algorithm - THis algo help us the calculate shortest distance from multiple sources 



*/

#include<iostream>
using namespace std;

void shortest_distance(vector<vector<int>>&matrix)
{
// we will modify this matrix by making the diagonal elements zero and if mat==-1 then mat=1e9
int n=matrix.size();

for(int i=0; i<n; i++)
{
    for(int j=0; j<n; j++)
    {
        if(matrix[i][j]==-1) // if -1 then we will make the distance infinity
        {
            matrix[i][j]=1e9;
        }
        if(i==j)
        matrix[i][j]=0; // if diagonal element we will make distance zero 
    }
}

// here is the main logic of the algorithm where we will be using three loops 

for(int k=0; k<n; k++) // k are the nodes via which we have to find the minimum distance 
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; i<n; j++)
        {
            matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]); // here again we are going via node  k  
        }
    }
}
// before returning our matrix we will do the opposite of what we have did in the beginning

for(int i=0; i<n; i++)
{
    for(int j=0; j<n; j++)
    {
        if(matrix[i][j]==1e9) 
        {
            matrix[i][j]=-1;
        }
         
    }
}





}


int main()
{





    return 0;
}