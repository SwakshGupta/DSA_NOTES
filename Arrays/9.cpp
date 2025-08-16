/* 3 Sum problem 

 Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets
  [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

Approach1:

a+b+c=0; 
a=-(b+c) so we will use two loops and one mapping appraoch is written in the notebook how i have done that 


Approach 2:

This is a better approach  and the appraoch is written in the notebook so yeah 

*/

#include<iostream>
#include <set>
using namespace std;

vector<vector<int> >tripets(int n,vector<int>&num)
{

set<vector<int> >st; // set automatically stores elements in sorted order and doesn't allow duplicates. that is why we are including the set 

for(int i=0; i<n; i++)
{

set<int>hashset; // this is the hashset we have created to avoid duplication 

    for(int j=i+1; j<n; j++)
    {
    int third=-(num[i]+num[j]); // we found the third element 

    if(hashset.find(third)!=hashset.end()) // checks whether the third element is present in the hashset if it is then push that into the temp vector 
          
    {
        vector<int>temp={num[i],num[j],third};

        sort(temp.begin(),temp.end());

        st.insert(temp); // st is the 2D array where we are storing all the possible combinations

    }
    hashset.insert(num[j]); // that element is not present in the hashset then push nums[j];
    }
}

vector<vector<int>>result(st.begin(),st.end()); // created a result 2d vector where we will store all the numbers 

return result;


}


vector<vector<int> >tripets(int n,vector<int>&num)
{

vector<vector<int>>ans;

sort(num.begin(),num.end());

for(int i=0; i<n; i++)
{
    if(i>0 && num[i]==num[i-1]) continue; // means if num[i]==num[i-1] then dont go down to the code just keep increasing the i till they become non equal

// see the notes what i did jumping i from -2 to -1 that is what continue do it will keep increasing i till they are not equal 


int j=i+1; // j is next to i 
int k=n-1; // k is the last element of the array 

while(j<k)
{
    int sum=num[i]+num[j]+num[k];

    if(sum<0) // if the sum is less then zero then we have to move the  j pointer i pointer keeps the same so yeah 
    {
        j++;
    }

    else if(sum>0) // again  if sum was greater then we can move the k pointer backwards as well 
    {
        k--;
    }

    else
    {
        vector<int>temp={num[i],num[j],num[k]}; // this is one of our triplet formed where the sum is equal to zero 
        ans.push_back(temp);
        j++;
        k--;

        while(j<k && num[j]==num[j-1]) j++; // here we are moving j in forward direction keeping in mind  j<k

        while(j<k && num[k]==num[k+1]) k--; // so we will be moving k backwards to get all the posibble triplets making sure that j<k

 // These two are done to avoid repetetion 


    }
}


}





}



int main()
{




    return 0;
}

/*
// here i will write how this problem can be solved via two pointers 

vector<vector<int>>3sum(vector<int>nums)
{
vector<vector<int>>temp;

for(int i=0; i<n; i++)
{
if(i>0 && nums[i]==nums[i-1])
continue;

int j=i+1;
int k=n-1;

while(j<k)
{
sum=nums[i]+nums[j]+nums[k];

if(sum<0)
{
j++
}

if(sum>0)
{
k--;
}
else
{
    vector<int>temp={nums[i],nums[j],nums[k]};
    j++;
    k--;

    while(j<k && nums[j]==nums[j-1])
    {
        j++;
    }
    while(j<k && nums[k])==numsk-1
    {
        k--;
    }
}





}





}





}









*/