/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

 

Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
*/








#include<iostream>
using namespace std;

int canComplete(vector<int>&gas,vector<int>&cost)
{
int totalGas=0;
int totalCost=0;
int tank=0;
int start=0;


for(int i=0; i<gas.size(); i++)
{
totalGas+=gas[i];
totalCost+=cost[i];

 tank+=gas[i]-cost[i];

if(tank<0) // checking all the negative cases if found any then staring point is i+1
{
    start=i+1;
    tank=0;
}
}

return (totalGas<totalCost)? -1:start; // if totalGas-totalCost<0 then we won't be able to complete a circle cuz we will run out of gas 


// so this was our main case if after reaching at the end if our totalgas<totalcost then there is no way we can complete the circle 




// if we run at the  end of array and our totalgas>=total cost then it garentee that we complete full loop 

}

int main()
{




    return 0;
}
