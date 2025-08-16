/*

Longest Subarray with sum K Generate subarray 

subarray is contigous part of the array 

 

*/

#include<iostream>
#include<map>
using namespace std;

int longestSubarray(vector<int>a,long long k)
{
unordered_map<long long,int>preSumMap;
long long sum=0;
int maxLen=0;
for(int i=0; i<a.size();i++)
{
    sum+=a[i]; // finding the sum till that point 

    if(sum==k)
    {
        maxLen=max(maxLen,i+1); // updaye the maxLen
    }

    // if sum is not equal to k then we calculate the remaing explained in the notebook 

    int rem=sum-k; 

if(preSumMap.find(rem)!=preSumMap.end()) // if tthe remaning exist  and is not equal ot the end then there exist a subarray whose sum is equal to the k
{
    int len=i-preSumMap[rem]; // found the length of the remainig subarray 
    maxLen=max(maxLen,len);
}

preSumMap[sum]=i; // if both above case is not there then  create a mapping of sum 

}




}

// This above code is correct but we are including the edge case in this which is including zeros 

// explanation in notebook 


int longestSubarray(vector<int>a,long long k)
{
unordered_map<long long,int>preSumMap;
long long sum=0;
int maxLen=0;
for(int i=0; i<a.size();i++)
{
    sum+=a[i]; // finding the sum till that point 

    if(sum==k)
    {
        maxLen=max(maxLen,i+1); // updaye the maxLen
    }

    // if sum is not equal to k then we calculate the remaing explained in the notebook 

    int rem=sum-k; 

if(preSumMap.find(rem)!=preSumMap.end()) // if tthe remaning exist  and is not equal ot the end then there exist a subarray whose sum is equal to the k
{
    int len=i-preSumMap[rem]; // found the length of the remainig subarray 
    maxLen=max(maxLen,len);
}

if(preSumMap.find(sum)== preSumMap.end())
preSumMap[sum]=i;
}




}


// more optimized code (2 pointer approach) explanaton in the notebook

int longestSubarray(vector<int>a,long long k)
{
int left=0;  // two pointers we have created 
int right=0; 
long long sum=a[0];
int maxLen=0;
int n=a.size();

while(right<n) // first constrain
{
while(left<=right && sum>k) // if left is less than right and the sum we calculated is greater than k then we have to trim from the left side
{
sum-=a[left]; // we start trimming from the left side 
left++;
}

if(sum==k)
{
    maxLen=max(maxLen,right-left+1); // if sum=k then we calculate the max length 
}
right++; // if sum is not equal to k then we will increment the right and add it to our sum 
if(right<n)
{
    sum+=a[right];  // calculating the sum itself 
}

return maxLen;

}

}

 




int main()
{
    return 0;
}


/*

int longestSubarray(vector<int>a,long long k)
{

int right=0;
int left=0
int sum=a[0];
int maxi=0;

while(right<n)
{

while(left<=right && sum>k)
{
    sum-=a[left];
    left++;
}

if(sum==k)
{
    maxi=max(maxi,right-left+1);

}


right++;
if(right<n)
{
    sum+=a[right];
}




}





}




}














*/