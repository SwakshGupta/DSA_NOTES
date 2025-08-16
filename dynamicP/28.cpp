/*

Longest Bitonic subsequence 

1. Bitonic means  a sequence which is first increasing and then it can decrease 


2. We will be using the code of LIS to solve this  

3. We will create two dp here one from arr and one from reverse array both are using the LIS code

4. then we will add the 2 dp to form the new array and then substract each element by 1 the largest eleent in this new array formed is the longest bitonic subsequence 

*/

#include<iostream>
using namespace std;


int LongestBitonicSuquence(vector<int>&arr,int n)
{

vector<int>dp(n,1);

int maxi=1;

for(int i=0; i<n; i++)
{
    for(int prev=0; prev<i; prev++)
    {
        if(arr[prev]<arr[i] && 1+dp[prev]>dp[i])
        {
            dp[i]=1+dp[prev];
        }
    }
     if(dp[i]>maxi)
  {
    maxi=dp[i];
    
  }
}

vector<int>dp2(n,1); // here we have creatted the next dp


for(int i=n-1; i>=0; i--)
{
    for(int prev=n-1; prev>i; prev--)
    {
        if(arr[prev]>dp[i])
        {
            dp[i]=1+dp[prev];
        }
    }
}

int maxo=0;

for(int i=0; i<n; i++)
{
    maxo=max(maxi,dp[i]+dp2[i]-1);
}

return maxo;


}





int main()
{




    return 0;
}