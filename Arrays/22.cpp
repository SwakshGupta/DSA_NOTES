#include<iostream>
using namespace std;

vector<int>spiralMatrix(vector<vector<int>>&mat)
{
    int n=mat.size();
    int m=mat[0].size();

    int left=0;
    int top=0;
    int right=m-1;
    int bottom=m-1;

    vector<int>ans;

    while(top<=bottom && left <=right)
    {

    for(int  i=left; i<right; i++)
    {
        ans.push_back(mat[top][i]);
    }
    top++; // after the first row is done printing we have to increment the top index 

    for(int i=top; i<=bottom; i++)
    {
        ans.push_back(mat[i][right]);
    }
    right--;

    if(top<=bottom)
    {

    for(int i=right; i>=left; i--)
    {
    ans.push_back(mat[bottom][i]);
    }
    bottom--;
    }

    if(left<=right)

    {
    for(int i=bottom; i>=top; i--)
    {
        ans.push_back(mat[i][left]);
    }
    left++;
    }
}



}

// O(n*m);





int main()
{
    


    return 0;
}