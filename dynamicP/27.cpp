/*


1048. Longest String Chain


we will be using the code of longest increasing subsequence 


*/

#include<iostream>
using namespace std;

bool checkPossible(string &s1,string &s2)
{
if(s1.size()!=s2.size()+1) // if  s1!=s2+1   then string chain is not possible hence 
return false;

int first=0;
int second=0;

while(first<s1.size())
{
    if(s1[first]==s2[second])
    {
        first++;
        second++;
    }
    else
    {
        first++; // if they dont match then we only increment the first pointer
    }
}

if(first==s1.size() && second==s2.size())
{
    return true;
}


}


bool comp(string &s1,string &s2)
{
    return s1.size()<s2.size();
}



int longestIncreasingSubsequence(vector<string>&arr,int n)
{

    // since we are asked for sequence not subsequence so order does not matter so we will just sort them in increasing order

    sort(arr.begin(),arr.end(),comp); // comp will sort according to the 

 vector<int>dp(n,1);

int maxi=1;
int lastIndex=0;

for(int i=0; i<n; i++)
{

    // initially we have mapped every element with himself 

    for(int prev=0; prev<i; prev++)
    {
        if(checkPossible(arr[i],arr[prev]) && 1+dp[prev]>dp[i] ) // here we will check for the possiblity whether arr[j] can increase to arr[i]

        // if arr[j] plus one element is equal to the arr[i] then the chain is possible 
        {
            dp[i]=1+dp[prev];

          
        }
    }
  if(dp[i]>maxi)
  {
    maxi=dp[i];
    lastIndex=i; 

  }
}
return maxi; // this will reutrn us the max size using dp;
}




int main()
{




    return 0;
}