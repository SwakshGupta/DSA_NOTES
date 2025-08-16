/*
Pascal trianglle  problem

Three types of question could be made from this topic 

1. Give the row and column print the element at that place (r-1  C c-1) is the answer combination
     )

2. Print the whole nth row of pascal triangle 


3. Print the whole pascal triangle 



*/
#include<iostream>
using namespace std;

int solve1(int row,int column)
{
    // we have to simply find r-1 C c-1 logic is written in the notebook 

}


vector<int>generateRows(int row)
{
long long ans=1;
vector<int>ansRow;
ansRow.push_back(1); // since the first and last element of the pascal row is same 

for(int col=1; col<row; col++)
{
    ans=ans*(row-col);  // this formula is written in my text book to calculate element of rows 
    ans=ans/(col);
    ansRow.push_back(ans);


}
return ansRow; 

}



vector<vector<int> >pascalTriangle(int N)
{
vector<vector<int>> ans;

for(int i=0; i<=N; i++)
{
    ans.push_back(generateRows(i)); // ohk so we have called the other function which will calculate the rows 
}


return ans;

}



int main()
{




    return 0;
}