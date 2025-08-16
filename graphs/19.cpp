
/*
here we are doing union via size 


1. So i am making everyndoe its own parent and putting the size as zero for all the cases

2.Find ultiate parent for each matrix 

3. 3 is union by size which calls the parent function and then check conditions to make the union 

*/




#include<iostream>
using namespace std;


class DisjointSet{


vector<int>size,parent;
public:

DisjointSet(int n)
{
    size.resize(n+1,1);
    parent.resize(n+1); // here we have created size vector and initiated with size 1

    for(int i=0; i<n; i++)
    {
        parent[i]=i;
    }
}

int findUpar(int node) // this function finds the ultimate parent 
{
    if(node==parent[node])
    return node;
    return parent[node]=findUpar(parent[node]);
}

void unionBysize(int u,int v)
{
int ulp_u=findUpar(u); // finds ultimate parent of u
int ulp_v=findUpar(v);

if(ulp_u==ulp_v) return;

if(size[ulp_u]<size[ulp_v])
{
    parent[ulp_u]=ulp_v; // the one which has greater size would be the child
}
else if(size[ulp_u]>size[ulp_v])
{
parent[ulp_v]=ulp_u;
}
else
{
    parent[ulp_v]=ulp_u;
    size[ulp_u]++;
}

}
};

int main()
{




    return 0;
}
