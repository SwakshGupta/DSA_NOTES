/*
You’re given a row of fruit trees. Each tree has only one type of fruit, and you're carrying two baskets.
Each basket can hold only one type of fruit, but as many of that type as you want.

Input: [1, 2, 1]

Tree 1 has fruit type 1 → ✅

Tree 2 has fruit type 2 → ✅

Tree 3 has fruit type 1 again → ✅

You only used two baskets: one for type 1 and one for type 2.
✅ You picked all 3 fruits → Answer: 3


So we can pick only two type of fruit and we  have to find maximum length subarray 

so instead we have to calculate the maximum length subarray having atmost 2 type of elements 



*/

#include<iostream>
using namespace std;

int FruitBasket(vector<int>nums)
{
unordered_map<int,int>hashmap; // creating an  hashmap which have element,frequency pair in it 

int l=0;
int r=0;
int n=nums.size();
int maxLen=0;

while(r<n)
{
hashmap[nums[r]]++;

if(hashmap.size()>2)
{
     while(hashmap.size()>2)  // if we have  more than two different fruits than we have to trim them 
     {
        hashmap[nums[r]]--;
        if(hashmap[nums[r]]==0) // if that element frequency is equalt to zero than we will remove that element 
        {
            hashmap.erase(nums[r]); 
        }
        l++;
     }
}

if(hashmap.size()<=2)
{
    maxLen=max(maxLen,r-l+1);
}
r++;
}
return maxLen;

}





int main()
{



    return 0;
}

/*
int FruitBasket(vector<int>nums)
{
int i=0;
int j=0;
int sum=nums[0];
int len=1;
int n=nums.size();

while(j<n)
{
while(len<2)
{
    i++;
    len--;
    sum-=nums[i];
}

sum+=nums[j];
maxi=max(max,sum);
j++;

}
return maxi;
}







*/