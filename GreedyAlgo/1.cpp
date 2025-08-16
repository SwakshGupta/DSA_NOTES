/*
JUMP GAME

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.


we will be using greedy algo here 


*/





#include<iostream>
using namespace std;

bool fun(vector<int>arr)
{
    int maxIdx=INT_MIN;

for(int i=0; i<arr.size(); i++)
{
    if(i>maxIdx) // if i is greater than the max index then return false
    {
        return false;
    }

    maxIdx=max(maxIdx,i+arr[i]); // updating the maxindex here 
}

if(maxIdx>=arr.size())
{
    return true;
}


}







                 

int main()
{




    return 0;
}