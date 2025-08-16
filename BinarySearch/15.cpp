
/*

 row with max number of 1 row in a matrix where each row is sorted 

 1. the brute force is creating two for loops and then count number of 1's for each row and then update it 


2. We can optimize the inner row by doing binary search since it is sorted so we can find first ocurance of 1
where it is happening and then 

number of 1s = total - index at which first one occured 



*/

#include<iostream>
using namespace std;

int lowerBound(vector<int>arr,int n,int x)
{
int low=0;
int high=n-1;

int ans=n;

while(low<=high)
{
    int mid=(low+high)/2;

    if(arr[mid]>=x) // x=1 if arr[mid]==1 then we will decrease our index to check for lower bound 
    {
        ans=mid;
        high=mid-1;
    }
    else
    {
        low=mid+1;
    }
}
return ans;
}


int rowWithMax1(vector<vector<int>>&matrix,int n,int m)
{
    int cnt_max=0;
    int index=-1;

    for(int i=0; i<n; i++)
    {
        int cnt=m-lowerBound(matrix[i],m,1); // total size -lower bound of 1  will give me the total number of 1's

        if(cnt>cnt_max)
        {
            index=i;
            cnt_max=cnt;
        }

        return i;
    }
}





int main()
{




    return 0;
}