/*
minimum number of coins to create a change  

we are given with a array of coins and we have to find minimum number of coins required to create that change 




*/

#include<iostream>
using namespace std;


int findMin(vector<int>coins,int target)
{
    int n=coins.size();
    int count=0;

for(int i=n-1; i>=0; i--)
{
while(coins[i]<target)
{
    target-=coins[i];
    count++;
}

}

return target==0?count:-1; // if target equals zero then return count otherwise -1;
}

int main()
{




    return 0;
}