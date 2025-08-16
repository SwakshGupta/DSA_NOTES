/*
Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t 
(including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.


*/







#include<iostream>
using namespace std;
string minWindow(string s,string t)
{
int l=0;
int r=0;
int m=t.size();
int n=s.size();
int count=0; // this will count whether the elements of t are covered  in the substring (explained in the notebook)
int minLen=INT_MAX;
int sIndex=-1; // initially we have set the starting index to be -1 (this starting index will give us the answer )

unordered_map<char,int>map;

for(int i=0; i<=256; i++)
{
    map[i]=0;
}

for(int i=0; i<m; i++) // initially we have   increased the frequency of all the t elements 
{
    map[t[i]]++; 
}
while(r<n)
{
    if(map[s[r]]>0) // if the  r is at element which has positive frequency in map then that is element of string t so increase the count and decrease its mapping
    {
        count++;
        map[s[r]]--;
    }

    while(count==m) // then this is a possible answer since it all contains all the elements of string t. We have used while loop so that we can shrink it as much we can 
    {
        if(r-l+1<minLen)
        {
            minLen=r-l+1;
        }
        sIndex=l;
        map[s[l]]--;


        if(map[s[l]]>0) // if any element has a positive frequency that means the  substring does not contain all string t 
        {
            count--;
        }
        l++;

    }
    r++;

}
return sIndex==-1 ? "":s.substr(sIndex,minLen); // if the value of sIndex is never updated tehn return value -1 means no substring containing all the elements of t is detected 





}



int main()
{




    return 0;
}