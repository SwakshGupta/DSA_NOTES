/*
Find kth misisng number 


*/


#include<iostream>
using namespace std; 


int f(vector<int>nums,int k)
{
int n=nums.size();
int low=0;
int high=n-1;

while(low<=high)
{
int mid=low+(high-low)/2;

int missing=nums[mid]-(mid+1); // this is the formula to calaculate the nunmber of missing numbers

if(missing<k)
low=mid+1;

else
{
    high=mid-1;
}
}
return k+high+1; // this is going to be the answer since when loop will stop the kth missing number will lie b/w low and high 

}




int main()
{





    return 0;
}