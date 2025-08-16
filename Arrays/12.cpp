/*Find the repeating and missing number

Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array,
 except for A, which appears twice and B which is missing.



Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index


*/

#include<iostream>
using namespace std;

// this is one of the brute force soltion using hashmaps 

 vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        int repeating = -1, missing = -1;

        for (int num : nums) {
            map[num]++;
        }

        for (int i = 1; i <= n; i++) {
            if (map[i] == 2) repeating = i;
            if (map[i] == 0) missing = i;
        }

        return {repeating, missing};
    }


// approach 2 is the mathematical approach  which is more optimal appraoch 


vector<int>solve2(vector<int>a)
{

long long n=a.size();

long long SN=(n*(n+1))/2;

long long S2N=(n*(n+1)*(2*n+1))/6;

long long S=0,S2=0;

for(int i=0; i<n; i++)
{
 S+=a[i]; // this is sum of all the elements 
 S2+=(long long)a[i]*(long long)a[i]; // this is the square of all the elements 
}

long long val1=S-SN;   // x-y
long long val2=S2-S2N;

val2=val2/val1;           // x+y
long long x=(val1+val2)/2; // here we have calulated x by simple maths and yeah 
long long y=x-val1;

return {(int)x,(int)y};







}


int main()
{




    return 0;
}

