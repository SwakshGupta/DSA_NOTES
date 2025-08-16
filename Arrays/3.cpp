/*
Kadane algorithm to calculate  maximum sum of subarray

Keep adding elements to the sum if the sum becomes less than zero then reset the sum to zero


*/
#include<iostream>
using namespace std;

int MaxSum(vector<int>&nums)
{
    int n=nums.size();
    int maxi=0;
    int sum=0;

for(int i=0; i<n; i++)
{
    sum+=nums[i];

    if(sum>maxi)
    {
       maxi=sum;
    }
    if(sum<0)   // this was the approach if our sum become less than zero then we reset our sum to zero cuz it is going to decrease our sum 
    {
        sum=0;  
    }
    

}

return maxi;

}


// the previous function was calculating the sum but what if we want to print the arry itself 

// this code introduces two more variable start and end index which will calculate the array 
long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }
    
    return ansEnd=ansStart+1;
    
    
    
    }

int main()
{




    return 0;
}



/*

long long maxSubarraySum(int arr[], int n) {

  int sum=0;
  int start=0;

  int startAns=-1;
  int endAns=-1;


  for(int i=0 ; i<arr.size(); i++)
  {
  if(sum==0)
  {
    start=i;
  }

  if





  }



*/