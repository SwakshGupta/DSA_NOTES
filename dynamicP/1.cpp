/*
Ninja training problem 

1. We are given some activities each day and there are some poins attach to it [1 2 3] ,[4 5 6] activity a,b,c have points on two different days

2. Now the ninja cannot take same activity in two cosecutive days so we have to return the maximum points collected 


here we have two parameters changing



*/

#include<iostream>
using namespace std;


// This is the reccursive approach

int f(int day,int last,vector<vector<int>>&points)
{

// we are traversing from n-1 to 0

if(day==0) // this is the base condtion if we come to the day 0  then we will check for the task which was performed in the previous day and then we will just find max from remaing task 
{
    int maxi=0;
    for(int task=0; task<3; task++)
    {
        if(task!=last)
        maxi=max(maxi,points[0][task]);
    }

    return maxi;
}

int maxi=0;

for(int task=0; task<3; task++)
{
if(task!=last) // if the task is not equal to 3 then
{
    int point=points[day][task]+f(day-1,task,points);
    maxi=max(maxi,point);
}

}
return maxi;
}



// now lets do the memorization approach 

int solve(int day,int last, vector<vector<int>>&points,vector<vector<int>>&dp)
{
    if(day==0) // this is the base condtion if we come to the day 0  then we will check for the task which was performed in the previous day and then we will just find max from remaing task 
{
    int maxi=0;
    for(int task=0; task<3; task++)
    {
        if(task!=last)
        maxi=max(maxi,points[0][task]);
    }

    return dp[day][last] =maxi;
}


if(dp[day][last]!=-1)
return dp[day][last];

int maxi=0;

for(int task=0; task<3; task++)
{
if(task!=last) // if the task is not equal to 3 then
{
    int point=points[day][task]+solve(day-1,task,points,dp);
    maxi=max(maxi,point);
}

}
return dp[day][last]=maxi;
}




// now lets do the tabulation process

int ninjaTraining (int n,vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,0)); // here we have created a 2d vector with n rows and 4 columns

    // base conditions

    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][2],points[0][3]);
    dp[0][2]=max(points[0][1],points[0][0]);
    dp[0][3]=max(points[0][1],points[0][2],points[0][0]);
   
   for(int day=1; day<n; day++)
   {
    for(int last=0; last<4; last++) // these are the number of last we can have for a day 
    {
        dp[day][last]=0;
        int maxi=0;

        for(int task=0; task<3; task++)
        {
            if(task!=last) // if our task is not equal to the last then we will compute the points
            {
                int point=points[day][task]+dp[day-1][task]; // this is how we compute the point by adding the current point and then calling the dp vector of previous array 
                dp[day][last]=max(dp[day][last],point);
                
            }
        }
    }
   }

   return dp[n-1][3]; // the last index will give us the max value 

}




int ninjaTraining(int n,vector<vector<int>>points)
{

    vector<vector<int>>dp(n,vector<int>(4,-1)); // ohk so  thing is storing day and 4 last indices  initially all the last indices are initialized with -1

return f(n-1,3,points);




}




int main()
{



    return 0;
}