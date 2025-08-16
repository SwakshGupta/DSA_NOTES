/*
Sort an array of 0,1,2

approch

1. First approach is via mapping count the number of 0,1,2  and store them in the map then push then replace the element in the array 



*/

#include<iostream>
#include<map>
using namespace std;

void solve(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int num : nums) {  // created a map and inserted all the element in the map 
            mpp[num]++;
        }

        int index = 0;
        for (int i = 0; i <= 2; ++i) { // pushing the number of 1,0,2 in the vector 
            while (mpp[i]--) {
                nums[index++] = i;
            }
        }
    }



int main()
{




    return 0;
}/*




void sum(vector<int>&sum)
{
    unordered_map<int,int<map
    for(int i=0; i<n; i++)
    {
        map[sum[i]]++;
    }

   index=0;
    for(int i=0; i<=2; i++)
    {
        while(map[i]--)
        {
            nums[index]=i;
        }
    }
}








*/