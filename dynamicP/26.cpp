#include<iostream>
using namespace std;

/*
Printing Longest Increasing Subsequence | Tabulation | Algorithm
*/



// through this code we can figure out the longest increaing subsequence 

int longestIncreasingSubsequence(int arr[],int n)
{

vector<int>dp(n,1);

int maxi=1;

for(int i=0; i<n; i++)
{
    for(int prev=0; prev<i; prev++)
    {
        if(arr[prev]<arr[i])
        {
            dp[i]=max(dp[i],1+dp[prev]);
        }
    }
    maxi=max(maxi,dp[i]);
}

return maxi;



}

// here we will print the LIS


int longestIncreasingSubsequence(int arr[],int n)
{

 vector<int>dp(n,1),hash; //created a hashmap and dp of n size 

int maxi=1;
int lastIndex=0;

for(int i=0; i<n; i++)
{

   hash[i]=i; // initially we have mapped every element with himself 

    for(int prev=0; prev<i; prev++)
    {
        if(arr[prev]<arr[i] && 1+dp[prev]>dp[i] )
        {
            dp[i]=1+dp[prev]; // upadted our dp array index

            hash[i]=prev; // mapped the current index wiht the previous index 
        }
    }
  if(dp[i]>maxi)
  {
    maxi=dp[i];
    lastIndex=i; // now through this last index we will backtrack our LIS using hashmaps 

  }
// here we will print our LIS

vector<int>temp;
temp.push_back(arr[lastIndex]);

while(hash[lastIndex]!=lastIndex) // this loop will run till we reach to that index who is mapped with itself which means there is no other element mapped with hm
{
    lastIndex=hash[lastIndex];
    temp.push_back(arr[lastIndex]);
    
}
reverse(temp.begin(),temp.end());
return maxi;



}

return maxi;


}



int main()
{




    return 0;
}