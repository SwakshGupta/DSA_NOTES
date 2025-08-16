
/*Longest substring with K distict character 


*/



#include<iostream>
using namespace std;

// this below is similar to previous algorithm with TC-O(2N) but now we will optimize it further with o(N) TC by get ridding of the inner loop 
int Longest(vector<int>nums,int k)
{
int n=nums.size();
int l=0;
int r=0;
unordered_map<char,int>hashmap;
int maxi=0;

while(r<n)
{
hashmap[nums[r]]++;

while(hashmap.size()>2) // if the size of the map>2 then we will start trimming the map from the left side 
{
    hashmap[nums[l]]--;
    if(hashmap[nums[l]]==0)
    {
        hashmap.erase(nums[r]);
    }
     l++;
}
if(hashmap.size()<=k)
{
    maxi=max(maxi,r-l+1); // if less than k then calculate teh max lenght 

}
r++;



}






}


// explanation is give in the notebook  This is the updated code 

int Longest2(vector<int>nums,int k)
{
int n=nums.size();
int l=0;
int r=0;
unordered_map<char,int>hashmap;
int maxi=0;

while(r<n)
{
hashmap[nums[r]]++;

if(hashmap.size()>2)  // so we have changed  the while loop to if condition  rest is same 
{
    hashmap[nums[l]]--;
    if(hashmap[nums[l]]==0)
    {
        hashmap.erase(nums[r]);
    }
     l++;
}
if(hashmap.size()<=k)
{
    maxi=max(maxi,r-l+1);

}
r++;



}
}



int main()
{




    return 0;
}

/*










*/