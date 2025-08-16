/*Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

The Range of all the numbers in ASCII format vary from 0 to 255

To solve this question we be using two pointers and hashmaps we will be creating two pointer L and R and thorugh that we will find the length(R-L+1) and we will chnage 
the position of the L and R using  the hashmaps 
*/


#include <iostream>
#include <unordered_map>
using namespace std;

int LongestSub(string s)
{
    unordered_map<char, int> hashmap;
    int n = s.size();

    for (int i = 0; i < 256; ++i)
    {
        hashmap[i] = -1; // initialized our hashmap with -1 that will tell us whether the element is there in the map
    }

    int l = 0;
    int r = 0;
    int maxLen = 0;

    while (r < n)
    {
        if (hashmap[s[r]] != -1) // it means it is there in the map  so we have to update the L
        {
            if (hashmap[s[r]] >= l) // now the hashmap with which we are updating should be greater than L
            {
                l = hashmap[s[r]] + 1;
            }
        }

        int len = r - l + 1;
        maxLen = max(len, maxLen); // finding the max length

        hashmap[s[r]] = r; // pushing the right index element to the hashmap if it is not already present in the hashmap 
        r++; // incrementing the value of r 
    }

    return maxLen;
}



int main()
{



    return 0;
}

/*
int LongestSub(string s)
{
unordered_map<char,int>map;

for(int i=0; i<255; i++)
{
    map[i]=-1;
}
int l=0;
int r=0;
int maxi=0;

while(r<n)
{
    if(map[i]!=-1)
    {
        if(map[r]>l)
        {
            l=map[r]+1;
        }
    }
}
len=r-l+1;
maxi=max(maxi.len);
map[r]=r;
r++;





}










*/