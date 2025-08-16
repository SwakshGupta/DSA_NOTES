/*
SO we have array of cards we can either take cards from back or front we have to choose n cards now we have to return the maximum sum 

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. 
The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.




*/


#include<iostream>
using namespace std;

int maxSum(vector<int>nums,int k)
{
int lsum=0;
int rsum=0;
int maxSum=0;
int n=nums.size();

for(int i=0; i<k; i++) // first we will calculate the sum for the first four indexes 
{
    lsum+=nums[i];
    maxSum=lsum;
}

int rightIndx=n-1;

for(int i=k-1; i>=0; i--) // then we will start  decreasing the index from back  and increasing the index from the front 
{
    lsum=lsum-nums[i];
    rsum=rsum+nums[rightIndx];
    rightIndx--;
    maxSum=max(maxSum,lsum+rsum);

}


return maxSum;

}


int main()
{




    return 0;
}