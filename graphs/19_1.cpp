
/*
here we are doing union via rank 


1. So i am making everyndoe its own parent and putting the rank as zero for all the cases

2.Find ultiate parent for each matrix 

3. 3 is union by rank which calls the parent function and then check conditions to make the union 

*/




#include<iostream>
using namespace std;


class DisjointSet{


vector<int>rank,parent;
public:

DisjointSet(int n)
{
    rank.resize(n+1,0);
    parent.resize(n+1); // created rank vector marked as zero and parent vector as i

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

void unionByRank(int u,int v)
{
int ulp_u=findUpar(u); // finds ultimate parent of u
int ulp_v=findUpar(v);

if(ulp_u==ulp_v) return;

if(rank[ulp_u]<rank[ulp_v])
{
    parent[ulp_u]=ulp_v; // the one which has greater rank would be the child
}
else if(rank[ulp_u]>rank[ulp_v])
{
parent[ulp_v]=ulp_u;
}
else
{
    parent[ulp_v]=ulp_u;
    rank[ulp_u]++;
}

}
};

int main()
{




    return 0;
}
